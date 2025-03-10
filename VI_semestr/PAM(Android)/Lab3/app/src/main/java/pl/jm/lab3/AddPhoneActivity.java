package pl.jm.lab3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;

import com.google.android.material.textfield.TextInputEditText;

import java.util.List;

public class AddPhoneActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.add_phone_activity);

        Button btnOpenWebsite = findViewById(R.id.btnOpenWebsite);
        Button btnCancel = findViewById(R.id.btnCancel);
        Button btnSave = findViewById(R.id.btnSave);

        btnOpenWebsite.setOnClickListener(v -> {
            Log.d("AddPhoneActivity", "Open website");
        });

        btnCancel.setOnClickListener(v -> {
            Intent intent = new Intent(AddPhoneActivity.this, MainActivity.class);
            startActivity(intent);
            //finish();
        });

        btnSave.setOnClickListener(view -> {

            EditText etProducer = findViewById(R.id.etProducer);
            EditText etModel = findViewById(R.id.etModel);
            EditText etAndroidVersion = findViewById(R.id.etAndroidVersion);
            EditText etWebsite  = findViewById(R.id.etWebsite);


            String manufacturer = etProducer.getText().toString();
            String model = etModel.getText().toString();
            String androidVersion = etAndroidVersion.getText().toString();
            String www = etWebsite.getText().toString();

            if (manufacturer.isEmpty() || model.isEmpty() || androidVersion.isEmpty() || www.isEmpty()) {
                Toast toast = Toast.makeText(this, "Wprowadź poprawnie wszystkie dane", Toast.LENGTH_SHORT);
                toast.show();
                return;
            }


            Intent resultIntent = new Intent(AddPhoneActivity.this, MainActivity.class);
            resultIntent.putExtra("EXTRA_MANUFACTURER", manufacturer);
            resultIntent.putExtra("EXTRA_MODEL", model);
            resultIntent.putExtra("EXTRA_ANDROID_VERSION", androidVersion);
            resultIntent.putExtra("EXTRA_WEBSITE", www);
            setResult(RESULT_OK, resultIntent);
            startActivity(resultIntent);
            // gdyby sie dalo normalmnie na androdia w javie to bym zrobil
            // # qt(c++) lepsze
            //finish();
        });

    }

}

