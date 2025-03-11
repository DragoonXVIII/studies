package pl.jm.lab3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.result.ActivityResultCaller;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    private static final int REQUEST_EDIT_PHONE = 1;

    private PhoneViewModel mPhoneViewModel;
    private TableLayout mTableLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTableLayout = findViewById(R.id.tableLayout);

        mPhoneViewModel = new ViewModelProvider(this).get(PhoneViewModel.class);
        mPhoneViewModel.getAllPhones().observe(this, new Observer<List<Phone>>() {
            @Override
            public void onChanged(List<Phone> phones) {
                updateTable(phones);
            }
        });



        // FAB
        FloatingActionButton fabMain = findViewById(R.id.fabMain);
        fabMain.setOnClickListener(v -> {
            Intent intent = new Intent(MainActivity.this, AddPhoneActivity.class);
            startActivity(intent);
        });
    }

    @Override
    protected void onResume() {
        super.onResume();

        // dodawanie nowego tele
        if (getIntent().hasExtra("EXTRA_MANUFACTURER") &&
            getIntent().hasExtra("EXTRA_MODEL") &&
            getIntent().hasExtra("EXTRA_ANDROID_VERSION") &&
            getIntent().hasExtra("EXTRA_WEBSITE")) {

            String extra_manufacturer = getIntent().getStringExtra("EXTRA_MANUFACTURER");
            String extra_model = getIntent().getStringExtra("EXTRA_MODEL");
            String extra_android_version = getIntent().getStringExtra("EXTRA_ANDROID_VERSION");
            String extra_website = getIntent().getStringExtra("EXTRA_WEBSITE");

            if (extra_manufacturer != null && extra_model != null &&
                    extra_android_version != null && extra_website != null) {

                Phone phone = new Phone(extra_manufacturer, extra_model, extra_android_version, extra_website);
                mPhoneViewModel.insert(phone);
                Log.d("TAG", "onResume: dodanoMODEL");

                getIntent().removeExtra("EXTRA_MANUFACTURER");
                getIntent().removeExtra("EXTRA_MODEL");
                getIntent().removeExtra("EXTRA_ANDROID_VERSION");
                getIntent().removeExtra("EXTRA_WEBSITE");
            }
        } else {
            Log.d("TAG", "onResume: Brak nowych danych do dodania");
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        Log.d("main","activityresult");
        if (resultCode == RESULT_OK) {
            int id = data.getIntExtra("EXTRA_ID", -1);
            String manufacturer = data.getStringExtra("EXTRA_MANUFACTURER");
            String model = data.getStringExtra("EXTRA_MODEL");
            String androidVersion = data.getStringExtra("EXTRA_ANDROID_VERSION");
            String website = data.getStringExtra("EXTRA_WEBSITE");
            Phone updatedPhone = new Phone(id, manufacturer, model, androidVersion, website);
            mPhoneViewModel.update(updatedPhone);
            Toast.makeText(this, "Telefon zaktualizowany", Toast.LENGTH_SHORT).show();
            ;
        }
    }

    private void updateTable(List<Phone> phones) {
        // Usun stare wiersze, zostaw naglowek(0)
        int childCount = mTableLayout.getChildCount();
        if (childCount > 1) {
            mTableLayout.removeViews(1, childCount - 1);
        }
        // zarabisty debbugging (co moglo pojsc nie tak xDDD)
        /*
        Log.d("MainActivity","first childCount: " + childCount);
        Log.d("MainActivity","second childCount: " + phones.size());
        */

        // zarabisty debbugging (co moglo pojsc nie tak xDDD)
        /*
        Log.d("MainActivity","first childCount: " + childCount);
        Log.d("MainActivity","second childCount: " + phones.size());
        */
        int index = 0;  //to tak dla mnie for fun do debuga, nie musi by idexa wgl

        for (Phone phone : phones) {
            TableRow row = new TableRow(this);

            TextView producerTextView = new TextView(this);
            producerTextView.setText(index + ". " + phone.getManufacturer());
            producerTextView.setPadding(8, 8, 8, 8);

            TextView modelTextView = new TextView(this);
            modelTextView.setText(phone.getModel());
            modelTextView.setPadding(8, 8, 8, 8);

            row.addView(producerTextView);
            row.addView(modelTextView);

            row.setOnClickListener(v -> {
                Log.d("rowListener","elozelo wariaciku");
                Intent intent = new Intent(MainActivity.this, AddPhoneActivity.class);
                intent.putExtra("EXTRA_ID", phone.getId());
                intent.putExtra("EXTRA_MANUFACTURER", phone.getManufacturer());
                intent.putExtra("EXTRA_MODEL", phone.getModel());
                intent.putExtra("EXTRA_ANDROID_VERSION", phone.getAndroidVersion());
                intent.putExtra("EXTRA_WEBSITE", phone.getWebsite());
                ActivityResultCaller(intent, REQUEST_EDIT_PHONE);
            });

            mTableLayout.addView(row);
            index++;
        }

        // zarabisty debbugging (co moglo pojsc nie tak xDDD)
        /*
        Log.d("MainActivity","first childCount: " + childCount);
        Log.d("MainActivity","second childCount: " + phones.size());
        */

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == R.id.action_delete_all) {
            mPhoneViewModel.deleteAll();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}

