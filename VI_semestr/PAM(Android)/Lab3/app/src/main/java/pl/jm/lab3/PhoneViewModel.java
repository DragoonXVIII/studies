package pl.jm.lab3;

import android.app.Application;

import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;

import java.util.List;

public class PhoneViewModel extends AndroidViewModel {

    private PhoneRepository mRepository;
    private LiveData<List<Phone>> mAllPhones;

    public PhoneViewModel(Application application) {
        super(application);
        mRepository = new PhoneRepository(application);
        mAllPhones = mRepository.getAllPhones();
        // dodanie sample daty
        mRepository.addSampleData();
    }

    LiveData<List<Phone>> getAllPhones() {
        return mAllPhones;
    }

    public void deleteAll() {
        mRepository.deleteAll();
    }

}

