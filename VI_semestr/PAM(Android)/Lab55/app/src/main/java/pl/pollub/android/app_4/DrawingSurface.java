package pl.pollub.android.app_4;

import static android.graphics.Color.BLUE;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import androidx.annotation.NonNull;

public class DrawingSurface extends SurfaceView implements SurfaceHolder.Callback {
    private static final String TAG = DrawingSurface.class.getSimpleName();
    // pozwala kontrolować i monitorować powierzchnię
    private SurfaceHolder mHolder;
    private Bitmap mBitmap = null;
    private Canvas mBitmapCanvas = null;
    private Paint mFarba;
    private Path mSciezka = null;



    public DrawingSurface(Context context, AttributeSet attrs) {
        super(context, attrs);
        // Pojemnik powierzchni - pozwala kontrolować i monitorować powierzchnię
        mHolder = getHolder();
        mHolder.addCallback(this);
        this.mFarba = new Paint(BLUE);
        // ustawienie szerokości linii
        mFarba.setStrokeWidth(2);
// styl rysowania – wypełnianie figur
        mFarba.setStyle(Paint.Style.FILL);
// styl rysowania – rysowanie tylko konturu
        mFarba.setStyle(Paint.Style.STROKE);
        // włączenie (podwójna negacja) rysowania za pomocą metody onDraw
        setWillNotDraw(false);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        //trzeba implementować razem
        performClick();
        //rozpoznanie akcji (dotknięcie, przesunięcie, zabranie palca) i rysowanie na
        //bitmapie
        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                //rysowanie...
                this.mSciezka = new Path();
                this.mSciezka.moveTo(event.getX(), event.getY());
                this.mBitmapCanvas.drawCircle(event.getX(), event.getY(), 5, mFarba);
                break;
            case MotionEvent.ACTION_MOVE:
                //rysowanie...
                if(this.mSciezka != null) {
                    // szerokość linii
                    this.mSciezka.lineTo(event.getX(), event.getY());
                    this.mBitmapCanvas.drawPath(mSciezka, mFarba);
                }
                break;
            case MotionEvent.ACTION_UP:
                //rysowanie...
                this.mBitmapCanvas.drawCircle(event.getX(), event.getY(), 5, mFarba);
                break;
        }
        //unieważnienie zawartości komponentu
        invalidate();
        return true;
    }
    @Override
    protected void onDraw(@NonNull Canvas canvas) {
        super.onDraw(canvas);
        //narysowanie bitmapy na komponencie
        canvas.drawBitmap(this.mBitmap, 0, 0, null);
    }
    //żeby lint nie wyświetlał ostrzeżeń - onTouchEvent i performClick trzeba
    //implementować razem
    public boolean performClick() {
        return super.performClick();
    }
    //robocza bitmapa na której tworzymy rysunek gdy użytkownik dotknie ekranu

    //implementacja interfejsu SurfaceHolder.Callback
    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        if (this.mBitmap == null) {
            this.clearScreen();
        } else {
            invalidate();
        }
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        if (this.mBitmap == null) {
            this.clearScreen();
        }
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
    }
    public void clearScreen() {
        //utworzenie bitmapy o rozmiarze takim samym jak powierzchnia
        //utworzenie kanwy na której będzie rysowany obraz
        this.mBitmap = Bitmap.createBitmap(getWidth(), getHeight(), Bitmap.Config.ARGB_8888);
        this.mBitmapCanvas = new Canvas(mBitmap);
        // zmalowanie na biało
        this.mBitmapCanvas.drawARGB(255, 255, 255, 255);

        //czyszczenie powierzchni
        //...
        //unieważnienie zawartości komponentu
        invalidate();
    }
    public void setPaintColor(int color) {
        mFarba.setColor(color);
    }

    public Bitmap getBitmap() {
        return mBitmap;
    }    public void setBitmap(Bitmap bitmap) {
        if (bitmap != null) {
            // sprawdzenie wys szer
            int currentWidth = getWidth();
            int currentHeight = getHeight();
            
            if (currentWidth > 0 && currentHeight > 0) {
                // sprawdzenie czy orient sie zmienil przez porownianie ratio  szer do wys png'a i ekranu
                boolean bitmapIsPortrait = bitmap.getHeight() > bitmap.getWidth();
                boolean surfaceIsPortrait = currentHeight > currentWidth;
                boolean needsRotation = bitmapIsPortrait != surfaceIsPortrait;
                
                Bitmap finalBitmap;
                if (needsRotation) {
                    // przekrecenie obrazka o 90 stopni
                    android.graphics.Matrix matrix = new android.graphics.Matrix();
                    matrix.postRotate(90);
                    finalBitmap = Bitmap.createBitmap(bitmap, 0, 0, 
                            bitmap.getWidth(), bitmap.getHeight(), matrix, true);
                } else {
                    finalBitmap = bitmap;
                }
                
                // nowa bitmapa z odpowiednimi rozmiarami
                this.mBitmap = Bitmap.createBitmap(currentWidth, currentHeight, Bitmap.Config.ARGB_8888);
                this.mBitmapCanvas = new Canvas(this.mBitmap);
                
                // fill na bialo
                this.mBitmapCanvas.drawARGB(255, 255, 255, 255);
                
                // wycentrowanie i rysowanie finalBitmap
                float left = (currentWidth - finalBitmap.getWidth()) / 2f;
                float top = (currentHeight - finalBitmap.getHeight()) / 2f;
                this.mBitmapCanvas.drawBitmap(finalBitmap, left, top, null);
                
                // cleanup
                if (finalBitmap != bitmap) {
                    finalBitmap.recycle();
                }
                
                invalidate();
            } else {
                // kopia bitmapy bez zmian jakby cos sie zepsulo podczas ladownaia i wymuszap onowne wczytanier
                this.mBitmap = bitmap.copy(Bitmap.Config.ARGB_8888, true);
                this.mBitmapCanvas = new Canvas(this.mBitmap);
                invalidate();
            }
        }
    }

}
