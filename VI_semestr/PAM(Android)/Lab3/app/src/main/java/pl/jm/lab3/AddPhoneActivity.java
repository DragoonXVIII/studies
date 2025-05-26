package pl.jm.lab3;

import android.content.Intent;
import android.net.Uri;
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

    private int phoneId = -1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.add_phone_activity);

        Button btnOpenWebsite = findViewById(R.id.btnOpenWebsite);
        Button btnCancel = findViewById(R.id.btnCancel);
        Button btnSave = findViewById(R.id.btnSave);
        EditText etProducer = findViewById(R.id.etProducer);
        EditText etModel = findViewById(R.id.etModel);
        EditText etAndroidVersion = findViewById(R.id.etAndroidVersion);
        EditText etWebsite = findViewById(R.id.etWebsite);

        // chceck na edcje/dodawanie
        Intent er_intent = getIntent();
        if (er_intent.hasExtra("EXTRA_ID")) {
            setTitle("Edycja telefonu");
        } else {
            setTitle("Dodawanie telefonu");
        }

        // obsluga edycji wiersza
        if (er_intent.hasExtra("EXTRA_ID")) {
            phoneId = er_intent.getIntExtra("EXTRA_ID", -1);
            etProducer.setText(er_intent.getStringExtra("EXTRA_MANUFACTURER"));
            etModel.setText(er_intent.getStringExtra("EXTRA_MODEL"));
            etAndroidVersion.setText(er_intent.getStringExtra("EXTRA_ANDROID_VERSION"));
            etWebsite.setText(er_intent.getStringExtra("EXTRA_WEBSITE"));
        }


        btnOpenWebsite.setOnClickListener(v -> {
            Log.d("AddPhoneActivity", "Open website");
            //EditText etWebsite = findViewById(R.id.etWebsite);
            String adres = etWebsite.getText().toString();
            if (adres.startsWith("http://") || adres.startsWith("https://")) {
                Log.d("AddPhoneActivity", "Open website");
                Intent zamiarPrzegladarki = new Intent("android.intent.action.VIEW", Uri.parse(adres));
                startActivity(zamiarPrzegladarki);
            } else {
                Log.d("AddPhoneActivity", "ERROR: website string is not valid");
                Toast toast = Toast.makeText(this, "Strona nie zaczyna się od http", Toast.LENGTH_SHORT);
                toast.show();
            }


        });

        btnCancel.setOnClickListener(v -> {
            Intent intent = new Intent(AddPhoneActivity.this, MainActivity.class);
            finish();
        });

        btnSave.setOnClickListener(view -> {

            Intent resultIntent = new Intent();

            if (phoneId != -1) {  // Jeśli edycja istniejący telefon
                resultIntent.putExtra("EXTRA_ID", phoneId);
            }


            String manufacturer = etProducer.getText().toString();
            String model = etModel.getText().toString();
            String androidVersion = etAndroidVersion.getText().toString();
            String www = etWebsite.getText().toString();

            // zad 3.3 wymaga innej walidacji wiec zegnamy sie z toastami :<<<<
            boolean isValid = true;
            if (manufacturer.isEmpty()) {
                etProducer.setError("Wprowadź producenta");
                isValid = false;
            }
            if (model.isEmpty()) {
                etModel.setError("Wprowadź model");
                isValid = false;
            }
            if (androidVersion.isEmpty()) {
                etAndroidVersion.setError("Wprowadź wersję Androida");
                isValid = false;
            }
            if (www.isEmpty()) {
                etWebsite.setError("Wprowadź stronę internetową");
                isValid = false;
            } else if (!android.util.Patterns.WEB_URL.matcher(www).matches()) {
                etWebsite.setError("Wprowadź poprawny adres strony internetowej");
                isValid = false;
            }

            if (!isValid) return;

            resultIntent.putExtra("EXTRA_MANUFACTURER", manufacturer);
            resultIntent.putExtra("EXTRA_MODEL", model);
            resultIntent.putExtra("EXTRA_ANDROID_VERSION", androidVersion);
            resultIntent.putExtra("EXTRA_WEBSITE", www);
            setResult(RESULT_OK, resultIntent);
            finish();
            // gdyby sie dalo normalmnie na androdia w javie to bym zrobil
            // # qt(c++) lepsze
            //finish();
            //o jednak sie da tylko jestem glupi
            //i tak qt lepsze <3
        });

    }

}

