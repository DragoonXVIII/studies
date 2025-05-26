package pl.jm.lab4;

import android.os.Parcel;
import android.os.Parcelable;

// parcable bo nie da sie przez intenty normalnie przekazywac danych
public class PostepInfo implements Parcelable {

    public int mPobranychBajtow;
    public int mRozmiar;
    public String mStatus; // "TRWA", "ZAKONCZONE", "BLAD"

    public PostepInfo(int pobrane, int rozmiar, String status) {
        mPobranychBajtow = pobrane;
        mRozmiar = rozmiar;
        mStatus = status;
    }

    //taki konstruktor pozwala zeby uzyc i odtworzyc dane w parcel
    protected PostepInfo(Parcel in) {
        mPobranychBajtow = in.readInt();
        mRozmiar = in.readInt();
        mStatus = in.readString();
    }

    //creator to wymagana androida zeby sam mogl sb tworzyc obiekty postepinfo
    public static final Creator<PostepInfo> CREATOR = new Creator<PostepInfo>() {
        @Override
        public PostepInfo createFromParcel(Parcel in) {
            return new PostepInfo(in);
        }

        @Override
        public PostepInfo[] newArray(int size) {
            return new PostepInfo[size];
        }
    };

    //zapisuje dane do parcel
    @Override
    public void writeToParcel(Parcel parcel, int flags) {
        parcel.writeInt(mPobranychBajtow);
        parcel.writeInt(mRozmiar);
        parcel.writeString(mStatus);
    }

    // teoretycznie sie nie przyda ale na wszelki wypadek do jakicbs dziwnych plikow
    @Override
    public int describeContents() {
        return 0;
    }
}
