package pl.jm.lab4;

import android.os.Parcel;
import android.os.Parcelable;

public class PostepInfo implements Parcelable {

    public int mPobranychBajtow;
    public int mRozmiar;
    public String mStatus; // "TRWA", "ZAKONCZONE", "BLAD"

    public PostepInfo(int pobrane, int rozmiar, String status) {
        mPobranychBajtow = pobrane;
        mRozmiar = rozmiar;
        mStatus = status;
    }

    protected PostepInfo(Parcel in) {
        mPobranychBajtow = in.readInt();
        mRozmiar = in.readInt();
        mStatus = in.readString();
    }

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

    @Override
    public void writeToParcel(Parcel parcel, int flags) {
        parcel.writeInt(mPobranychBajtow);
        parcel.writeInt(mRozmiar);
        parcel.writeString(mStatus);
    }

    @Override
    public int describeContents() {
        return 0;
    }
}
