package com.lg;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class ImageUtil {
    public static byte[] loadImageAsBytes(String filePath) throws IOException {
        return Files.readAllBytes(Path.of(filePath));
    }
}
