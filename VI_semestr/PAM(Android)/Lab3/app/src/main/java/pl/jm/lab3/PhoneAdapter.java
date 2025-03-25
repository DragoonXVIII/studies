package pl.jm.lab3;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import java.util.List;

public class PhoneAdapter extends RecyclerView.Adapter<PhoneAdapter.PhoneViewHolder> {
    private List<Phone> phoneList;
    private final OnItemClickListener listener;

    public interface OnItemClickListener {
        void onItemClick(Phone phone);
    }

    public PhoneAdapter(List<Phone> phoneList, OnItemClickListener listener) {
        this.phoneList = phoneList;
        this.listener = listener;
    }

    @NonNull
    @Override
    public PhoneViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.row_phone, parent, false);
        return new PhoneViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull PhoneViewHolder holder, int position) {
        Phone phone = phoneList.get(position);
        holder.manufacturerTextView.setText(phone.getManufacturer());
        holder.modelTextView.setText(phone.getModel());

        holder.itemView.setOnClickListener(v -> listener.onItemClick(phone));
    }

    @Override
    public int getItemCount() {
        return phoneList.size();
    }

    public void updateList(List<Phone> newPhones) {
        this.phoneList = newPhones;
        notifyDataSetChanged();
    }

    public Phone getItem(int position) {
        return phoneList.get(position);
    }

    public static class PhoneViewHolder extends RecyclerView.ViewHolder {
        TextView manufacturerTextView, modelTextView;

        public PhoneViewHolder(@NonNull View itemView) {
            super(itemView);
            manufacturerTextView = itemView.findViewById(R.id.tvManufacturer);
            modelTextView = itemView.findViewById(R.id.tvModel);
        }
    }
}
