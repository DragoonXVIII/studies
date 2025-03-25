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
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ActivityResultLauncher<Intent> editPhoneLauncher;
    private ActivityResultLauncher<Intent> addPhoneLauncher;
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


        // EditPhoneActivity
        editPhoneLauncher = registerForActivityResult(
            new ActivityResultContracts.StartActivityForResult(),
            result -> {
                if (result.getResultCode() == RESULT_OK) {
                    Intent data = result.getData();
                    if (data != null) {
                        int id = data.getIntExtra("EXTRA_ID", -1);
                        if (id == -1) {
                            Toast.makeText(this, "Błąd aktualizacji: brak ID", Toast.LENGTH_SHORT).show();
                            return;
                        }
                        String manufacturer = data.getStringExtra("EXTRA_MANUFACTURER");
                        String model = data.getStringExtra("EXTRA_MODEL");
                        String androidVersion = data.getStringExtra("EXTRA_ANDROID_VERSION");
                        String website = data.getStringExtra("EXTRA_WEBSITE");
                        Log.d("EDIT_PHONE", "onActivityResult: " + id + " " + manufacturer + " " + model + " " + androidVersion + " " + website);
                        Phone updatedPhone = new Phone(id, manufacturer, model, androidVersion, website);
                        mPhoneViewModel.update(updatedPhone);
                        Toast.makeText(this, "Telefon zaktualizowany", Toast.LENGTH_SHORT).show();
                    }
                }
            }
        );

        // AddPhoneActivity
        addPhoneLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                result -> {
                    if (result.getResultCode() == RESULT_OK) {
                        Intent data = result.getData();
                        if (data != null) {
                            String manufacturer = data.getStringExtra("EXTRA_MANUFACTURER");
                            String model = data.getStringExtra("EXTRA_MODEL");
                            String androidVersion = data.getStringExtra("EXTRA_ANDROID_VERSION");
                            String website = data.getStringExtra("EXTRA_WEBSITE");

                            Phone newPhone = new Phone(manufacturer, model, androidVersion, website);
                            mPhoneViewModel.insert(newPhone);
                            Toast.makeText(this, "Telefon dodany", Toast.LENGTH_SHORT).show();
                        }
                    }
                }
        );

        // FAB
        FloatingActionButton fabMain = findViewById(R.id.fabMain);
        fabMain.setOnClickListener(v -> {
            Intent intent = new Intent(MainActivity.this, AddPhoneActivity.class);
            addPhoneLauncher.launch(intent);
        });


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

    private void updateTable(List<Phone> phones) {
        // Usun stare wiersze, zostaw naglowek(0)
        int childCount = mTableLayout.getChildCount();
        if (childCount > 1) {
            mTableLayout.removeViews(1, childCount - 1);
        }

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
                editPhoneLauncher.launch(intent);
            });

            mTableLayout.addView(row);
            index++;
        }

    }


    // deprecated
    /*
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
    */

    // deprecated
    /*
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
    */
}

