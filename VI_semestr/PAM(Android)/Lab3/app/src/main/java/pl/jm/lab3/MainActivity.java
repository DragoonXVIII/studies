package pl.jm.lab3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
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

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ActivityResultLauncher<Intent> editPhoneLauncher;
    private ActivityResultLauncher<Intent> addPhoneLauncher;
    private PhoneViewModel mPhoneViewModel;
    private RecyclerView recyclerView;
    private PhoneAdapter phoneAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        phoneAdapter = new PhoneAdapter(new ArrayList<>(), phone -> {
            Intent intent = new Intent(MainActivity.this, AddPhoneActivity.class);
            intent.putExtra("EXTRA_ID", phone.getId());
            intent.putExtra("EXTRA_MANUFACTURER", phone.getManufacturer());
            intent.putExtra("EXTRA_MODEL", phone.getModel());
            intent.putExtra("EXTRA_ANDROID_VERSION", phone.getAndroidVersion());
            intent.putExtra("EXTRA_WEBSITE", phone.getWebsite());
            editPhoneLauncher.launch(intent);
        });

        recyclerView.setAdapter(phoneAdapter);

        // ViewModel
        mPhoneViewModel = new ViewModelProvider(this).get(PhoneViewModel.class);
        mPhoneViewModel.getAllPhones().observe(this, phones -> phoneAdapter.updateList(phones));

        // Swipe-to-delete
        new ItemTouchHelper(new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.LEFT | ItemTouchHelper.RIGHT) {
            @Override
            public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
                return false;
            }

            @Override
            public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
                int position = viewHolder.getAdapterPosition();
                Phone phoneToDelete = phoneAdapter.getItem(position);
                mPhoneViewModel.delete(phoneToDelete);
                Toast.makeText(MainActivity.this, "Usunięto telefon", Toast.LENGTH_SHORT).show();
            }
        }).attachToRecyclerView(recyclerView);

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

        // FAB - dodawanie telefonu
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
            Toast.makeText(this, "Usunięto wszystkie telefony", Toast.LENGTH_SHORT).show();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
