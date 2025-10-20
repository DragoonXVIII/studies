package pl.pollub.android.app_4;

import static android.content.ContentValues.TAG;

import android.content.ContentResolver;
import android.content.ContentValues;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.ParcelFileDescriptor;
import android.provider.MediaStore;
import android.util.Log;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.io.ByteArrayOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

import pl.pollub.android.app_4.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        EdgeToEdge.enable(this);
        setContentView(binding.getRoot());
        
        // Restore drawing after the view is ready
        if (savedInstanceState != null) {
            byte[] bytes = savedInstanceState.getByteArray("drawing");
            if (bytes != null) {
                Bitmap restored = BitmapFactory.decodeByteArray(bytes, 0, bytes.length);
                // Use post to ensure the surface is ready and has proper dimensions before setting bitmap
                binding.drawingSurface.post(() -> {
                    // Double check that surface has dimensions
                    if (binding.drawingSurface.getWidth() > 0 && binding.drawingSurface.getHeight() > 0) {
                        binding.drawingSurface.setBitmap(restored);
                    } else {
                        // If dimensions not ready, wait a bit more
                        binding.drawingSurface.postDelayed(() -> {
                            binding.drawingSurface.setBitmap(restored);
                        }, 100);
                    }
                });
            }
        }

        this.binding.btnRed.setOnClickListener(v -> binding.drawingSurface.setPaintColor(Color.RED));
        this.binding.btnBlue.setOnClickListener(v -> binding.drawingSurface.setPaintColor(Color.BLUE));
        this.binding.btnGreen.setOnClickListener(v -> binding.drawingSurface.setPaintColor(Color.GREEN));
        this.binding.btnYellow.setOnClickListener(v -> binding.drawingSurface.setPaintColor(Color.YELLOW));
        this.binding.btnClear.setOnClickListener(v -> binding.drawingSurface.clearScreen());

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;

        });
    }

    private void saveImage() {
        Log.d(TAG, "save image");
        //Informacje o obrazku będziemy zapisywać do bazy MediaStore
        ContentResolver resolver = getApplicationContext().getContentResolver();
        //Odczytanie URI do kolekcji obrazów (zależy od wersji Androida)
        Uri imageCollection;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
            imageCollection = MediaStore.Images.Media
                    .getContentUri(MediaStore.VOLUME_EXTERNAL_PRIMARY);
        } else {
            imageCollection = MediaStore.Images.Media.EXTERNAL_CONTENT_URI;
        }
        //Utworzenie rekordu opisującego zapisywany obraz
        ContentValues imageDetails = new ContentValues();
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String fileName = "IMG_" + timeStamp + ".png";
        imageDetails.put(MediaStore.Images.Media.DISPLAY_NAME, fileName);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
            //w nowszych wersjach Androida możemy oznaczyć plik jako zapisywany (tzn. że
            //zapisywanie trwa)
            imageDetails.put(MediaStore.Images.Media.IS_PENDING, 1);
        }
        //zapisanie rekordu w kolekcji obrazów
        Uri imageUri = resolver.insert(imageCollection, imageDetails);
        //zapisanie bitmapy do pliku, używamy deskryptora utworzonego na podstawie URI do
        //pliku
        try (ParcelFileDescriptor pfd =
                     resolver.openFileDescriptor(imageUri, "w", null);
             FileOutputStream fos = new FileOutputStream(pfd.getFileDescriptor())) {
            this.binding.drawingSurface.getBitmap()
                    .compress(Bitmap.CompressFormat.PNG, 100, fos);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
            imageDetails.clear();
            imageDetails.put(MediaStore.Images.Media.IS_PENDING, 0);
            resolver.update(imageUri, imageDetails, null, null);
        }
    }
    @Override
    public boolean onCreateOptionsMenu(android.view.Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(android.view.MenuItem item) {
        if (item.getItemId() == R.id.action_save) {
            saveImage();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        Bitmap bitmap = binding.drawingSurface.getBitmap();
        if (bitmap != null) {
            ByteArrayOutputStream stream = new ByteArrayOutputStream();
            bitmap.compress(Bitmap.CompressFormat.PNG, 100, stream);
            byte[] bytes = stream.toByteArray();
            outState.putByteArray("drawing", bytes);
        }
    }
    
}
