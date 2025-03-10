package pl.jm.lab3;

import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import java.util.List;

public class MainActivity extends AppCompatActivity {

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
    }

    private void updateTable(List<Phone> phones) {
        // Usun stare wiersze, zostaw naglowek(0)
        int childCount = mTableLayout.getChildCount();
        // zarabisty debbugging (co moglo pojsc nie tak xDDD)
        /*
        Log.d("MainActivity","first childCount: " + childCount);
        Log.d("MainActivity","second childCount: " + phones.size());
        */
        if (childCount > 1) {
            mTableLayout.removeViews(1, childCount - 1);
        }
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

