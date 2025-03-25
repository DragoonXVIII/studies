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
    private OnItemClickListener listener;

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
        holder.bind(phoneList.get(position), listener);
    }

    @Override
    public int getItemCount() {
        return phoneList.size();
    }

    public void updateList(List<Phone> newPhones) {
        phoneList = newPhones;
        notifyDataSetChanged();
    }

    public void removeItem(int position) {
        phoneList.remove(position);
        notifyItemRemoved(position);
    }

    static class PhoneViewHolder extends RecyclerView.ViewHolder {
        TextView tvManufacturer, tvModel;

        PhoneViewHolder(View itemView) {
            super(itemView);
            tvManufacturer = itemView.findViewById(R.id.tvManufacturer);
            tvModel = itemView.findViewById(R.id.tvModel);
        }

        void bind(Phone phone, OnItemClickListener listener) {
            tvManufacturer.setText(phone.getManufacturer());
            tvModel.setText(phone.getModel());

            itemView.setOnClickListener(v -> listener.onItemClick(phone));
        }
    }
}
