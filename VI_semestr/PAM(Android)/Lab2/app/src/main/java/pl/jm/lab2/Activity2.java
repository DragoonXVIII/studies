package pl.jm.lab2;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.LinearLayout;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import java.io.Console;

import pl.jm.lab2.databinding.Activity2Binding;

public class Activity2 extends AppCompatActivity {

    private Activity2Binding binding;
    private EditText editFirstName, editLastName, editGradesCount;
    private Button btnGrades, btnResult;
    private ConstraintLayout activity2Layout;

    private boolean isBtnResultVisible = false;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // ViewBinding
        binding = Activity2Binding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        SharedPreferences prefs = getSharedPreferences("UserPrefs", MODE_PRIVATE);
        String firstName = prefs.getString("firstName", "");
        String lastName = prefs.getString("lastName", "");
        String gradesCount = prefs.getString("gradesCount", "");

        //setContentView(R.layout.activity_2);

        Button btnBack2 = binding.btnBack2;
        editFirstName = binding.editFirstName;
        editLastName = binding.editLastName;
        editGradesCount = binding.editGradesCount;
        btnGrades = binding.btnGrades;
        btnResult = binding.btnResult;
        activity2Layout = binding.activity2layout;

        if (getSupportActionBar() != null) {
            getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        }

        //custom kod do uzupleniania a2
        editFirstName.setText(firstName);
        editLastName.setText(lastName);
        editGradesCount.setText(gradesCount);

        //handlowanie ekstu z srednia studenta tez jest yu xD
        TextView textViewA2 = findViewById(R.id.textViewA2);
        //handlowanie widocznosci przycisku result
        double gradesAverage  = getIntent().getDoubleExtra("GRADES_AVERAGE", 0.0);
        isBtnResultVisible = gradesAverage > 2.0;
        //ustawienie tekstu przycisku przed wyswietleniem
        if(gradesAverage >= 3.0) {
            btnResult.setText(R.string.btn_result_succes);
        }
        else {
            btnResult.setText(R.string.btn_result_fail);
        }

        //wyswietlenie przycisku
        btnResult.setVisibility(isBtnResultVisible ? Button.VISIBLE : Button.GONE);
        if(isBtnResultVisible) {
            String buttonText = getString(R.string.activity2nameAverage, gradesAverage);
            textViewA2.setText(buttonText);
        }
        else {
            textViewA2.setText(R.string.activity2_name);
        }

        //handlowanie zakonczenia aplikajci
        btnResult.setOnClickListener(view -> {
            if(gradesAverage >= 3.0){
                Toast.makeText(this,"Gratulacje! Otrzymujesz zaliczenie!", Toast.LENGTH_SHORT).show();
                //Toast.makeText(this, "Gratulacje! Średnia ocen wynosi: " + gradesAverage, Toast.LENGTH_SHORT).show();
            }
            else if(gradesAverage < 3.0){
                Toast.makeText(this,"Wysyłam podanie o zaliczenie warunkowe", Toast.LENGTH_SHORT).show();
                //Toast.makeText(this, "Niestety średnia ocen wynosi: " + gradesAverage, Toast.LENGTH_SHORT).show();
            }
            finishAffinity();
        });

        btnGrades.setOnClickListener(view -> {
            // valdiate przy kliknieciu check
            if(!validateFields())
                return;

            String input = editGradesCount.getText().toString();

            // wlasny kod zeby niue usuwal w a2 dane
            SharedPreferences.Editor editor = prefs.edit();
            editor.putString("firstName", editFirstName.getText().toString());
            editor.putString("lastName", editLastName.getText().toString());
            editor.putString("gradesCount", editGradesCount.getText().toString());
            editor.apply();

            if (!input.isEmpty()) {
                int gradesCountVal = Integer.parseInt(input); // Zamiana na liczbę
                Intent intent = new Intent(Activity2.this, Activity3.class);
                intent.putExtra("GRADES_COUNT", gradesCountVal); // Przekazanie wartości
                startActivity(intent);
            } else {
                Toast.makeText(Activity2.this, "Podaj liczbę ocen!", Toast.LENGTH_SHORT).show();
            }
        });

        View.OnFocusChangeListener focusChangeListener = new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View v, boolean hasFocus) {
                if (!hasFocus) {
                    validateFields();
                }
            }
        };

        // nie wiem czy to tak mozna zostawic ale dziaa XD
        /*activity2Layout.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                hideKeyboard();
                validateFields();
                return false;
            }
        });*/

        editGradesCount.setOnEditorActionListener((v, actionId, event) -> {
            hideKeyboard();
            validateFields();
            return false;
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

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);

        outState.putString("firstName", editFirstName.getText().toString());
        outState.putString("lastName", editLastName.getText().toString());
        outState.putString("gradesCount", editGradesCount.getText().toString());
        outState.putBoolean("btnGradesVisible", btnGrades.getVisibility() == Button.VISIBLE);

    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);

        editFirstName.setText(savedInstanceState.getString("firstName"));
        editLastName.setText(savedInstanceState.getString("lastName"));
        editGradesCount.setText(savedInstanceState.getString("gradesCount"));

        boolean isBtnVisible = savedInstanceState.getBoolean("btnGradesVisible");
        btnGrades.setVisibility(isBtnVisible ? Button.VISIBLE : Button.GONE);

        double gradesAverage  = getIntent().getDoubleExtra("GRADES_AVERAGE", 0.0);
        isBtnResultVisible = gradesAverage > 2.0;
        btnResult.setVisibility(isBtnResultVisible ? Button.VISIBLE : Button.GONE);
    }


    private boolean validateFields() {
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
        return isValid;
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
