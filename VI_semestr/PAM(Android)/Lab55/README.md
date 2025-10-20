# Android Drawing App with Orientation Preservation

This is an Android drawing application that allows users to draw on a canvas with different colors and save their drawings. The app includes advanced orientation handling to preserve drawings when the device is rotated.

## Features

- **Multi-color drawing**: Red, Blue, Green, Yellow color options
- **Clear screen functionality**
- **Save drawings to device gallery**
- **Orientation preservation**: Drawings are preserved and properly rotated when device orientation changes
- **Touch-based drawing**: Smooth drawing with touch gestures

## Project Structure

### Main Components

1. **MainActivity.java** - Main activity handling UI interactions and state management
2. **DrawingSurface.java** - Custom SurfaceView for drawing operations
3. **activity_main.xml** - UI layout with drawing surface and color buttons

## Key Methods and Fixes Applied

### 1. Orientation State Preservation (MainActivity.java)

#### Problem
When the device orientation changed, Android would recreate the activity, causing all drawings to disappear.

#### Solution: State Saving and Restoration

```java
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
```

**What it does:**
- Captures the current drawing as a bitmap
- Compresses it to PNG format
- Converts to byte array for storage in Bundle
- Saves the byte array with key "drawing"

#### State Restoration in onCreate()

```java
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
```

**What it does:**
- Retrieves saved byte array from Bundle
- Converts back to Bitmap
- Uses `post()` to ensure surface is ready before restoration
- Includes fallback with delay if surface dimensions aren't ready

### 2. Smart Bitmap Rotation (DrawingSurface.java)

#### Problem
Original approach was stretching/scaling drawings when orientation changed, which distorted the original artwork.

#### Solution: Intelligent Rotation Detection and Application

```java
public void setBitmap(Bitmap bitmap) {
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
        }
    }
}
```

**Key Features:**
- **Aspect Ratio Detection**: Compares bitmap and surface aspect ratios to detect orientation mismatch
- **Smart Rotation**: Only rotates when necessary (portrait ↔ landscape change)
- **90-degree Rotation**: Uses Matrix transformation for precise 90° rotation
- **Centering**: Places rotated drawing in center of new canvas
- **Memory Management**: Properly recycles temporary bitmaps to prevent memory leaks

### 3. Drawing Operations (DrawingSurface.java)

#### Touch Event Handling
```java
@Override
public boolean onTouchEvent(MotionEvent event) {
    performClick(); // Accessibility requirement
    
    switch (event.getAction()) {
        case MotionEvent.ACTION_DOWN:
            // Start new path and draw initial dot
            this.mSciezka = new Path();
            this.mSciezka.moveTo(event.getX(), event.getY());
            this.mBitmapCanvas.drawCircle(event.getX(), event.getY(), 5, mFarba);
            break;
            
        case MotionEvent.ACTION_MOVE:
            // Continue drawing path
            if(this.mSciezka != null) {
                this.mSciezka.lineTo(event.getX(), event.getY());
                this.mBitmapCanvas.drawPath(mSciezka, mFarba);
            }
            break;
            
        case MotionEvent.ACTION_UP:
            // End with a dot
            this.mBitmapCanvas.drawCircle(event.getX(), event.getY(), 5, mFarba);
            break;
    }
    invalidate(); // Trigger screen refresh
    return true;
}
```

#### Canvas Management
```java
public void clearScreen() {
    // Create bitmap matching surface size
    this.mBitmap = Bitmap.createBitmap(getWidth(), getHeight(), Bitmap.Config.ARGB_8888);
    this.mBitmapCanvas = new Canvas(mBitmap);
    // Fill with white background
    this.mBitmapCanvas.drawARGB(255, 255, 255, 255);
    invalidate();
}
```

### 4. Image Saving (MainActivity.java)

The app includes functionality to save drawings to the device's media gallery:

```java
private void saveImage() {
    // Create MediaStore entry
    ContentValues imageDetails = new ContentValues();
    String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
    String fileName = "IMG_" + timeStamp + ".png";
    imageDetails.put(MediaStore.Images.Media.DISPLAY_NAME, fileName);
    
    // Save bitmap to gallery
    Uri imageUri = resolver.insert(imageCollection, imageDetails);
    // ... file writing logic
}
```

## Technical Improvements Made

### 1. **Timing Issues Fixed**
- Used `post()` and `postDelayed()` to ensure surface is ready before bitmap operations
- Added dimension checking before applying saved state

### 2. **Memory Management**
- Proper bitmap recycling to prevent memory leaks
- Efficient bitmap compression for state saving

### 3. **Orientation Handling**
- **Before**: Drawings would disappear on rotation
- **After**: Drawings are preserved and intelligently rotated

### 4. **Quality Preservation**
- **Before**: Scaling would distort drawings
- **After**: Rotation maintains original quality and proportions

## How Orientation Preservation Works

1. **Save Phase** (when rotating):
   - `onSaveInstanceState()` captures current drawing
   - Converts bitmap to compressed byte array
   - Stores in Bundle for activity recreation

2. **Restore Phase** (after rotation):
   - `onCreate()` checks for saved state
   - Converts byte array back to bitmap
   - Waits for surface to be ready with proper dimensions

3. **Smart Rotation** (in setBitmap):
   - Detects if orientation changed by comparing aspect ratios
   - Rotates bitmap 90° if needed using Matrix transformation
   - Centers rotated drawing on new canvas size
   - Preserves original quality and proportions

## Usage

1. **Drawing**: Touch and drag to draw on the canvas
2. **Color Selection**: Tap color buttons (Red, Blue, Green, Yellow)
3. **Clear**: Tap clear button to erase all drawings
4. **Save**: Use menu option to save drawing to gallery
5. **Rotation**: Rotate device - drawings will be preserved and properly oriented

## Files Modified

- `MainActivity.java`: Added state saving/restoration logic
- `DrawingSurface.java`: Enhanced with smart rotation and improved bitmap handling
- Added proper imports for Matrix and Rect classes

This implementation ensures a seamless drawing experience regardless of device orientation changes.
