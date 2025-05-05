package pl.jm.lab4;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Intent;
import android.os.Build;
import android.os.IBinder;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.core.app.NotificationCompat;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class DownloadService extends Service {

    public static final String CHANNEL_ID = "DownloadChannel";
    public static final String EXTRA_URL = "file_url";
    private NotificationManager notificationManager;
    private NotificationCompat.Builder notificationBuilder;
    private int notificationId = 1;

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.d("DownloadService", "onStartCommand wywołany");
        createNotificationChannel();
        notificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);

        Intent notificationIntent = new Intent(this, MainActivity.class);
        PendingIntent pendingIntent = PendingIntent.getActivity(
                this, 0, notificationIntent, PendingIntent.FLAG_IMMUTABLE);

        // Tworzenie powiadomienia tylko raz
        notificationBuilder = new NotificationCompat.Builder(this, CHANNEL_ID)
                .setContentTitle("Pobieranie pliku")
                .setContentText("Trwa pobieranie...")
                .setSmallIcon(android.R.drawable.stat_sys_download)
                .setContentIntent(pendingIntent)
                .setPriority(NotificationCompat.PRIORITY_HIGH)
                .setOngoing(true)
                .setOnlyAlertOnce(true)
                .setProgress(100, 0, false);

        // Start jako foreground service
        startForeground(notificationId, notificationBuilder.build());

        String fileUrl = intent.getStringExtra(EXTRA_URL);
        new Thread(() -> downloadFile(fileUrl)).start();

        return START_NOT_STICKY;
    }

    private void sendProgress(int downloaded, int total, String status) {
        Intent intent = new Intent("pl.jm.lab4.POSTEP");
        intent.putExtra("info", new PostepInfo(downloaded, total, status)); // ← NAZWA EXTRA
        sendBroadcast(intent);
    }



    private void downloadFile(String fileUrl) {
        try {
            URL url = new URL(fileUrl);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.connect();

            int fileLength = conn.getContentLength();
            String fileName = fileUrl.substring(fileUrl.lastIndexOf('/') + 1);

            File file = new File(getExternalFilesDir(null), fileName);
            InputStream in = conn.getInputStream();
            FileOutputStream out = new FileOutputStream(file);

            byte[] buffer = new byte[4096];
            int bytesRead;
            int total = 0;
            int lastProgress = 0;

            while ((bytesRead = in.read(buffer)) != -1) {
                out.write(buffer, 0, bytesRead);
                total += bytesRead;

                int progress = (int) ((total * 100L) / fileLength);
                if (progress - lastProgress >= 5 || progress == 100) {
                    lastProgress = progress;

                        sendProgress(total, fileLength, "TRWA");


                    notificationBuilder.setProgress(100, progress, false);
                    notificationManager.notify(notificationId, notificationBuilder.build());
                }

                Log.d("DownloadService", "Pobrano: " + total + " / " + fileLength);
            }

            out.close();
            in.close();

            // Finalne powiadomienie po zakończeniu
            notificationBuilder.setProgress(0, 0, false)
                    .setContentText("Pobieranie zakończone.")
                    .setSmallIcon(android.R.drawable.stat_sys_download_done)
                    .setOngoing(false);
            notificationManager.notify(notificationId, notificationBuilder.build());
            sendProgress(fileLength, fileLength, "ZAKONCZONE");
            stopSelf();

        } catch (Exception e) {
            Log.e("DownloadService", "Błąd pobierania", e);
            notificationBuilder.setContentText("Błąd pobierania.")
                    .setProgress(0, 0, false)
                    .setOngoing(false);
            notificationManager.notify(notificationId, notificationBuilder.build());

        }
    }

    private void createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            NotificationChannel serviceChannel = new NotificationChannel(
                    CHANNEL_ID,
                    "Kanał pobierania",
                    NotificationManager.IMPORTANCE_HIGH
            );
            serviceChannel.setDescription("Powiadomienia o pobieraniu pliku");
            NotificationManager manager = getSystemService(NotificationManager.class);
            manager.createNotificationChannel(serviceChannel);
        }
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
}
