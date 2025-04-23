package pl.jm.lab2;

import android.content.Intent;
import android.widget.Button;
import android.os.Bundle;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;
import pl.jm.lab2.databinding.Activity3Binding;


public class Activity3 extends AppCompatActivity {

    private RecyclerView mListaOcen;
    private List<ModelOceny> mDane;
    private Button btnObliczSrednia;
    private Activity3Binding binding;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = Activity3Binding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        //setContentView(R.layout.activity_3);

        if (getSupportActionBar() != null) {
            getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        }

        // przycisk do srendiej ocen
        btnObliczSrednia = binding.obliczButton;

        // ile ocen z intenta
        int gradesCount = getIntent().getIntExtra("GRADES_COUNT", 0);
        // nazwy z tabvlicy
        String[] nazwyPrzedmiotow = getResources().getStringArray(R.array.oceny_array);

        // Inicjalizacja listy - domyślnie 0 = brak oceny
        mDane = new ArrayList<>();
        for (int i = 0; i < gradesCount; i++) {
            mDane.add(new ModelOceny());
        }

        // RecyclerView
        mListaOcen = binding.recyclerViewOceny;
        InteraktywnyAdapterTablicy adapter = new InteraktywnyAdapterTablicy(this, mDane, nazwyPrzedmiotow);
        mListaOcen.setAdapter(adapter);
        mListaOcen.setLayoutManager(new LinearLayoutManager(this));

        btnObliczSrednia.setOnClickListener(v -> {
            double sumaOcen = 0;
            int liczbaOcen = 0;
            for (ModelOceny ocena : mDane) {
                if (ocena.getOcena() == 0) {
                    Toast.makeText(this, "Wprowadź wszystkie oceny", Toast.LENGTH_SHORT).show();
                    return;
                } else {
                    sumaOcen += ocena.getOcena();
                    liczbaOcen++;
                }
            }
            double srednia = sumaOcen / liczbaOcen;

            Intent intent = new Intent(Activity3.this, Activity2.class);
            intent.putExtra("GRADES_AVERAGE", srednia); // Przekazanie wartości
            startActivity(intent);

        });

    }
}





