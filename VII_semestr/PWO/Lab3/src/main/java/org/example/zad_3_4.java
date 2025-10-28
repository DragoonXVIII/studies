package org.example;

public class zad_3_4 {};

public interface MediaProcessor{

    void playFile(File f);

}

public interface MediaSaver {
    String fileDestination;
    Boolean fileSaved;
    void savePicture(File f);
    void saveVideoFile(File f);
    void saveMusicFile(File f);
}

public interface MediaLoader{
    Mp3 loadMusicFile(File f);
    Mpeg loadVideoFile(File f);
    Jpeg loadPicture(File f);
}

public interface MediaConverter extends MediaProcessor{
    Mp3 convertToMp3(Wave wave);
    Avi convertToAvi(Mpeg mpeg);
    Mp3 extractFromAvi(Avi avi);
    Mp3 extractFromMpeg(Mpeg mpeg);
}

public interface MediaPostProcessor extends MediaProcessor{
    Mp3 filterMusic(Mp3 mp3);
    Mpeg filterVideo(Mpeg mpeg);
    void cutFile(File f, double start, double end);
}

public interface MediaShare extends MediaPostProcessor {
    void attachFileToEnmail(File f);
    void sendEmail(Message m);
    Message[] readEmails(String server, String login, String pwd);
}

public interface MetaProcessor extends MediaProcessor
{
    void addAuthor(MediaFile mf);
    Jpeg addAuthorToPicture(Jpeg jpeg);
}