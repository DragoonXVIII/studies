package pl.jm.lab3;

import static pl.jm.lab3.PhoneRoomDatabase.databaseWriteExecutor;
import android.app.Application;
import androidx.lifecycle.LiveData;
import java.util.List;
import android.util.Log;

public class PhoneRepository {

    private PhoneDAO mPhoneDao;
    private LiveData<List<Phone>> mAllPhones;

    PhoneRepository(Application application) {
        PhoneRoomDatabase db = PhoneRoomDatabase.getDatabase(application);
        mPhoneDao = db.phoneDao();
        mAllPhones = mPhoneDao.getAllPhones();
    }

    LiveData<List<Phone>> getAllPhones() {
        return mAllPhones;
    }

    void deleteAll() {
        databaseWriteExecutor.execute(() -> {
            mPhoneDao.deleteAllPhones();
        });
    }

    // zad 3.3
    void deletePhone(Phone phone) {
        databaseWriteExecutor.execute(() -> {
            mPhoneDao.deletePhone(phone);
        });
    }

    //zad3.2
    void insertPhone(Phone phone) {
        databaseWriteExecutor.execute(() -> {
            mPhoneDao.insert(phone);
        });
    }

    //zad 3.3
    public void updatePhone(Phone phone) {
        databaseWriteExecutor.execute(()->{
            mPhoneDao.updatePhone(phone);
        });
    }

    public void addSampleData() {
        databaseWriteExecutor.execute(() -> {
            mPhoneDao.deleteAllPhones();
            if (mPhoneDao.getAnyPhone().length == 0) {  //jak pusta to dodaj
                Log.d("PhoneRepository", "Baza jest pusta. Dodaję przykładowe telefony...");

                mPhoneDao.insert(new Phone("Samsung", "Galaxy S23", "Android 13", "https://www.samsung.com"));
                mPhoneDao.insert(new Phone("Google", "Pixel 7", "Android 13", "https://store.google.com"));
                mPhoneDao.insert(new Phone("OnePlus", "10 Pro", "Android 12", "https://www.oneplus.com"));

                Log.d("PhoneRepository", "Dodano przykładowe telefony do bazy.");
            } else {
                Log.d("PhoneRepository", "Baza danych nie jest pusta – nie dodaję nowych telefonów.");
            }
        });
    }

}

