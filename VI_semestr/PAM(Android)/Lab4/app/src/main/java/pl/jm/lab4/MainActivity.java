package pl.jm.lab4;

import android.Manifest;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import pl.jm.lab4.databinding.ActivityMainBinding;

import java.net.HttpURLConnection;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    // do bindingu zamiast by id
    private ActivityMainBinding binding;

    // do aktualizowania ui przez powiadomienia ktore odbiera z download service
    private BroadcastReceiver postepReceiver;

    // do zapamietywania ostatniego stanu
    private PostepInfo lastPostepInfo;

    // bool do anulowania ponownego rejestrowania broadcast receivera bo inaczje blad wywala
    private boolean isReceiverRegistered = false;

    // do śledzenia info o pliku
    private boolean fileInfoFetched = false;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Inicjalizacja odbiornika
        postepReceiver = new BroadcastReceiver() {
            @Override
            public void onReceive(android.content.Context context, Intent intent) {
                PostepInfo info = intent.getParcelableExtra("info");
                if (info != null) {
                    lastPostepInfo = info;
                    runOnUiThread(() -> {
                        binding.bytesDownloadedTextView.setText(info.mPobranychBajtow + " / " + info.mRozmiar + " B");
                        binding.downloadProgressBar.setMax(info.mRozmiar);
                        binding.downloadProgressBar.setProgress(info.mPobranychBajtow);
                    });
                }
            }
        };

        //testowo zeby zobaczyc czy fixnie opozninone pobieranie powiadomienie
        // spoiler: dziala xDDD
        if (!isReceiverRegistered) {
            registerReceiver(postepReceiver, new IntentFilter("pl.jm.lab4.POSTEP"), Context.RECEIVER_NOT_EXPORTED);
            isReceiverRegistered = true;
        }

        // Uprawnienia
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            if (checkSelfPermission(Manifest.permission.POST_NOTIFICATIONS) != PackageManager.PERMISSION_GRANTED) {
                requestPermissions(new String[]{Manifest.permission.POST_NOTIFICATIONS}, 2);
            }
        }
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.Q) {
            if (checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, 1);
            }
        }

        // start -przycisk pobierania nieaktywny
        binding.downloadButton.setEnabled(false);

        // zmiana url - zmiana przycisku
        binding.urlEditText.addTextChangedListener(new android.text.TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                fileInfoFetched = false;
                binding.downloadButton.setEnabled(false);
            }
            @Override
            public void afterTextChanged(android.text.Editable s) {}
        });

        binding.fetchInfoButton.setOnClickListener(v -> {
            String url = binding.urlEditText.getText().toString();
            new FetchFileInfoTask().execute(url);
        });

        binding.downloadButton.setOnClickListener(v -> {
            String url = binding.urlEditText.getText().toString();
            startDownloadService(url);
            // blokada przyciksu po zaczeciu pobierania zeby nie duplikowac procesu pobierania
            fileInfoFetched = false;
            binding.downloadButton.setEnabled(false);
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (!isReceiverRegistered) {
            registerReceiver(postepReceiver, new IntentFilter("pl.jm.lab4.POSTEP"), Context.RECEIVER_NOT_EXPORTED);
            isReceiverRegistered = true;
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (isReceiverRegistered) {
            unregisterReceiver(postepReceiver);
            isReceiverRegistered = false;
        }
    }

    // zacznij pobieranie = w tle wywolanie downloadservice
    private void startDownloadService(String url) {
        lastPostepInfo = null;
        binding.bytesDownloadedTextView.setText("0 / 0 B");
        binding.downloadProgressBar.setProgress(0);
        binding.downloadProgressBar.setMax(0);

        Intent intent = new Intent(this, DownloadService.class);
        intent.putExtra(DownloadService.EXTRA_URL, url);
        ContextCompat.startForegroundService(this, intent);
    }

    /*@Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == 1 && grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
            String url = binding.urlEditText.getText().toString();
            startDownloadService(url);
        } else {
            Toast.makeText(this, "Brak uprawnień do zapisu pliku!", Toast.LENGTH_SHORT).show();
        }
    }*/

    // zapisanie info przy obrocie itp
    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);

        // Zapisz dane z widoków
        outState.putString("fileSize", binding.fileSizeTextView.getText().toString());
        outState.putString("fileType", binding.fileTypeTextView.getText().toString());
        outState.putString("bytesDownloaded", binding.bytesDownloadedTextView.getText().toString());
        outState.putInt("progress", binding.downloadProgressBar.getProgress());
        outState.putInt("maxProgress", binding.downloadProgressBar.getMax());
        outState.putBoolean("fileInfoFetched", fileInfoFetched);
    }

    // przywrocenie info po obrocie itp
    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);

        // Przywrocenie danych z zapisanych stanów
        String fileSize = savedInstanceState.getString("fileSize");
        String fileType = savedInstanceState.getString("fileType");
        String bytesDownloaded = savedInstanceState.getString("bytesDownloaded");
        int progress = savedInstanceState.getInt("progress");
        int maxProgress = savedInstanceState.getInt("maxProgress");

        binding.fileSizeTextView.setText(fileSize);
        binding.fileTypeTextView.setText(fileType);
        binding.bytesDownloadedTextView.setText(bytesDownloaded);

        binding.downloadProgressBar.setMax(maxProgress);
        binding.downloadProgressBar.setProgress(progress);

        binding.downloadProgressBar.setVisibility(View.VISIBLE);

        lastPostepInfo = savedInstanceState.getParcelable("postepInfo");
        if (lastPostepInfo != null) {
            binding.bytesDownloadedTextView.setText(lastPostepInfo.mPobranychBajtow + " / " + lastPostepInfo.mRozmiar + " B");
            binding.downloadProgressBar.setMax(lastPostepInfo.mRozmiar);
            binding.downloadProgressBar.setProgress(lastPostepInfo.mPobranychBajtow);
        }

        fileInfoFetched = savedInstanceState.getBoolean("fileInfoFetched", false);
        binding.downloadButton.setEnabled(fileInfoFetched);
    }

    // klasa przestarzala ale dziala do asynchronicznwgo pobierania info o pliku
    private class FetchFileInfoTask extends AsyncTask<String, Void, FileInfo> {
        @Override
        protected FileInfo doInBackground(String... urls) {
            try {
                URL url = new URL(urls[0]);
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                connection.setRequestMethod("HEAD");
                connection.connect();

                int length = connection.getContentLength();
                String type = connection.getContentType();
                return new FileInfo(length, type);
            } catch (Exception e) {
                e.printStackTrace();
                return new FileInfo(-1, "Błąd");
            }
        }

        @Override
        protected void onPostExecute(FileInfo fileInfo) {
            if (fileInfo.size >= 0) {
                binding.fileSizeTextView.setText(fileInfo.size + " B");
                binding.fileTypeTextView.setText(fileInfo.type);
                fileInfoFetched = true;
                binding.downloadButton.setEnabled(true);
            } else {
                binding.fileSizeTextView.setText("Błąd");
                binding.fileTypeTextView.setText("Błąd");
                fileInfoFetched = false;
                binding.downloadButton.setEnabled(false);
            }
        }
    }

    // klasa pomocnicza co trzyma info o pliku
    private static class FileInfo {
        int size;
        String type;

        FileInfo(int size, String type) {
            this.size = size;
            this.type = type;
        }
    }
}