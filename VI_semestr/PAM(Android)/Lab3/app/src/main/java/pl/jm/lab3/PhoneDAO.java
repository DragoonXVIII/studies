package pl.jm.lab3;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.lifecycle.LiveData;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface PhoneDAO {
    @Insert
    void insert(Phone phone);

    @Query("SELECT * FROM phones LIMIT 1")
    Phone[] getAnyPhone();

    @Query("SELECT * FROM phones ORDER BY manufacturer ASC")
    LiveData<List<Phone>> getAllPhones();
    
    @Query("DELETE FROM phones")
    void deleteAllPhones();

    @Delete
    void deletePhone(Phone phone);

    @Update
    void updatePhone(Phone phone);




}

