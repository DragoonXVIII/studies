package pl.jm.lab1;


import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class Activity2 extends AppCompatActivity {

    private EditText editFirstName, editLastName, editGradesCount;
    private Button btnGrades;
    private LinearLayout activity2Layout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_2);

        Button btnBack2 = findViewById(R.id.btnBack2);
        editFirstName = findViewById(R.id.editFirstName);
        editLastName = findViewById(R.id.editLastName);
        editGradesCount = findViewById(R.id.editGradesCount);
        btnGrades = findViewById(R.id.btnGrades);
        activity2Layout = findViewById(R.id.activity2layout);

        View.OnFocusChangeListener focusChangeListener = new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View v, boolean hasFocus) {
                if (!hasFocus) {
                    validateFields();
                }
            }
        };

        // nie wiem czy to tak mozna zostawic ale dziaa XD
        activity2Layout.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                hideKeyboard();
                validateFields();
                return false;
            }
        });

        editFirstName.setOnFocusChangeListener(focusChangeListener);
        editLastName.setOnFocusChangeListener(focusChangeListener);
        editGradesCount.setOnFocusChangeListener(focusChangeListener);
        activity2Layout.setOnFocusChangeListener(focusChangeListener);

        btnBack2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Activity2.this, MainActivity.class);
                startActivity(intent);
            }
        });
    }

    private void validateFields() {
        boolean isValid = true;
        //imie
        if (editFirstName.getText().toString().trim().isEmpty()) {
            editFirstName.setError("Imię nie może być puste!");
            Toast.makeText(this, "Imię nie może być puste!", Toast.LENGTH_SHORT).show();
            isValid = false;
        } else {
            editFirstName.setError(null);
        }

        //nazwisko
        if (editLastName.getText().toString().trim().isEmpty()) {
            editLastName.setError("Nazwisko nie może być puste!");
            Toast.makeText(this, "Nazwisko nie może być puste!", Toast.LENGTH_SHORT).show();
            isValid = false;
        } else {
            editLastName.setError(null);
        }

        //oceny
        String gradesStr = editGradesCount.getText().toString().trim();
        if (gradesStr.isEmpty()) {
            editGradesCount.setError("Podaj liczbę ocen!");
            Toast.makeText(this, "Podaj liczbę ocen!", Toast.LENGTH_SHORT).show();
            isValid = false;
        } else {
            int grades = Integer.parseInt(gradesStr);
            if (grades < 5 || grades > 15) {
                editGradesCount.setError("Liczba ocen musi być w zakresie 5-15!");
                Toast.makeText(this, "Liczba ocen musi być w zakresie 5-15!", Toast.LENGTH_SHORT).show();
                isValid = false;
            } else {
                editGradesCount.setError(null);
            }
        }

        btnGrades.setVisibility(isValid ? View.VISIBLE : View.GONE);
    }

    private void hideKeyboard() {
        View view = this.getCurrentFocus();
        if (view != null) {
            InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
            imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
            view.clearFocus();
        }
    }

}
