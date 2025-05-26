package pl.jm.lab3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ActivityResultLauncher<Intent> editPhoneLauncher;
    private ActivityResultLauncher<Intent> addPhoneLauncher;
    private PhoneViewModel mPhoneViewModel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ViewModel + RecyclerView setup
        mPhoneViewModel = new ViewModelProvider(this).get(PhoneViewModel.class);

        RecyclerView recyclerView = findViewById(R.id.recyclerView);
        PhoneAdapter adapter = new PhoneAdapter(phone -> {
            // Edycja po kliknięciu
            Intent intent = new Intent(MainActivity.this, AddPhoneActivity.class);
            intent.putExtra("EXTRA_NAME", "Edycja telefonu");
            intent.putExtra("EXTRA_ID", phone.getId());
            intent.putExtra("EXTRA_MANUFACTURER", phone.getManufacturer());
            intent.putExtra("EXTRA_MODEL", phone.getModel());
            intent.putExtra("EXTRA_ANDROID_VERSION", phone.getAndroidVersion());
            intent.putExtra("EXTRA_WEBSITE", phone.getWebsite());
            editPhoneLauncher.launch(intent);
        });
        recyclerView.setAdapter(adapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        // Obserwuj dane
        mPhoneViewModel.getAllPhones().observe(this, adapter::setPhones);

        // Swipe do usuwania
        new ItemTouchHelper(new ItemTouchHelper.SimpleCallback(0,
                ItemTouchHelper.LEFT | ItemTouchHelper.RIGHT) {
            @Override
            public boolean onMove(@NonNull RecyclerView recyclerView,
                                  @NonNull RecyclerView.ViewHolder viewHolder,
                                  @NonNull RecyclerView.ViewHolder target) {
                return false;
            }

            @Override
            public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
                Phone phoneToDelete = adapter.getPhoneAt(viewHolder.getAdapterPosition());
                mPhoneViewModel.delete(phoneToDelete);
                Toast.makeText(MainActivity.this, "Usunięto telefon", Toast.LENGTH_SHORT).show();
            }
        }).attachToRecyclerView(recyclerView);

        // Obsługa edycji telefonu
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

                            Phone updatedPhone = new Phone(id, manufacturer, model, androidVersion, website);
                            mPhoneViewModel.update(updatedPhone);
                            Toast.makeText(this, "Telefon zaktualizowany", Toast.LENGTH_SHORT).show();
                        }
                    }
                }
        );

        // Obsługa dodawania telefonu
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

        // FAB do dodawania nowego telefonu
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

}
