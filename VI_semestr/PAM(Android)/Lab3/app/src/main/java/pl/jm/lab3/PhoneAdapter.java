package pl.jm.lab3;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class PhoneAdapter extends RecyclerView.Adapter<PhoneAdapter.PhoneViewHolder> {
    private List<Phone> phones = new ArrayList<>();
    private final OnItemClickListener listener;

    public interface OnItemClickListener {
        void onItemClick(Phone phone);
    }

    public PhoneAdapter(OnItemClickListener listener) {
        this.listener = listener;
    }

    public void setPhones(List<Phone> phones) {
        this.phones = phones;
        notifyDataSetChanged();
    }

    public Phone getPhoneAt(int position) {
        return phones.get(position);
    }

    @NonNull
    @Override
    public PhoneViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.item_phone, parent, false);
        return new PhoneViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(@NonNull PhoneViewHolder holder, int position) {
        Phone phone = phones.get(position);
        holder.manufacturerTextView.setText(phone.getManufacturer());
        holder.modelTextView.setText(phone.getModel());
        holder.itemView.setOnClickListener(v -> listener.onItemClick(phone));
    }

    @Override
    public int getItemCount() {
        return phones.size();
    }

    static class PhoneViewHolder extends RecyclerView.ViewHolder {
        TextView manufacturerTextView, modelTextView;

        public PhoneViewHolder(@NonNull View itemView) {
            super(itemView);
            manufacturerTextView = itemView.findViewById(R.id.manufacturerTextView);
            modelTextView = itemView.findViewById(R.id.modelTextView);
        }
    }
}
