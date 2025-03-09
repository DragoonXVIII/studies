package pl.jm.lab2;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RadioGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import java.util.List;

public class InteraktywnyAdapterTablicy extends RecyclerView.Adapter<InteraktywnyAdapterTablicy.ViewHolder> {
    private final Context context;
    private final List<ModelOceny> listaOcen;

    private final String[] nazwyPrzedmiotow;

    //InteraktywnyAdapterTablicy
    public InteraktywnyAdapterTablicy(Context context, List<ModelOceny> listaOcen, String[] nazwyPrzedmiotow) {
        this.context = context;
        this.listaOcen = listaOcen;
        this.nazwyPrzedmiotow = nazwyPrzedmiotow;
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.wiersz_oceny, parent, false);
        return new ViewHolder(view);
    }

    //tu sie wsm robi load wartosci do widoku
    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        ModelOceny aktualnaOcenaM = listaOcen.get(position);
        String nazwaPrzedmiotu = nazwyPrzedmiotow[position];

        int aktualnaOcena = aktualnaOcenaM.getOcena();

        holder.nazwaPrzedmiotuTv.setText(nazwaPrzedmiotu);

        //reset stanu na wszelki
        holder.radioGroup.setOnCheckedChangeListener(null);

        // ustawienie stanu
        holder.radioGroup.clearCheck();
        if (aktualnaOcena == 2) holder.radio2.setChecked(true);
        else if (aktualnaOcena == 3) holder.radio3.setChecked(true);
        else if (aktualnaOcena == 4) holder.radio4.setChecked(true);
        else if (aktualnaOcena == 5) holder.radio5.setChecked(true);

        // Obsługa zmiany oceny
        holder.radioGroup.setOnCheckedChangeListener((group, checkedId) -> {
            int nowaOcena = 0;
            if (checkedId == R.id.ocena2Button) nowaOcena = 2;
            else if (checkedId == R.id.ocena3Button) nowaOcena = 3;
            else if (checkedId == R.id.ocena4Button) nowaOcena = 4;
            else if (checkedId == R.id.ocena5Button) nowaOcena = 5;

            ModelOceny nowaOcenaM = new ModelOceny(nowaOcena);
            listaOcen.set(position, nowaOcenaM);
        });
    }

    @Override
    public int getItemCount() {
        return listaOcen.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        RadioGroup radioGroup;
        RadioButton radio2, radio3, radio4, radio5;
        TextView nazwaPrzedmiotuTv;

        public ViewHolder(View itemView) {
            super(itemView);
            radioGroup = itemView.findViewById(R.id.grupa_oceny);
            radio2 = itemView.findViewById(R.id.ocena2Button);
            radio3 = itemView.findViewById(R.id.ocena3Button);
            radio4 = itemView.findViewById(R.id.ocena4Button);
            radio5 = itemView.findViewById(R.id.ocena5Button);
            nazwaPrzedmiotuTv = itemView.findViewById(R.id.nazwa_oceny_tv);
        }
    }
}

