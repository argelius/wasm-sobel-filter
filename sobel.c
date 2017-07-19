/*
Compile with emcc with:
emcc -o change.js change.c  -lm -O3 -s WASM=1 -s EXPORTED_FUNCTIONS="['_change']" -s BINARYEN_IMPRECISE=1
*/
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int getPixel(unsigned char *data, int i, int j, int width) {
  return data[i * 4 * width + 4 * j];
}

void sobel(unsigned char *dst, unsigned char *src, int width, int height) {
  int pixelX, pixelY, mag;

  for (int i = 1; i < height - 1; i = i + 1) {
    for (int j = 1; j < width - 1; j = j + 1) {
      pixelX = (-1 * getPixel(src, i - 1, j - 1, width)) +
        (1 * getPixel(src, i - 1, j + 1, width)) +
        (-2 * getPixel(src, i, j - 1, width)) +
        (2 * getPixel(src, i, j + 1, width)) +
        (-1 * getPixel(src, i + 1, j - 1, width)) +
        (1 * getPixel(src, i + 1, j + 1, width));

      pixelY = (-1 * getPixel(src, i - 1, j - 1, width)) +
        (-2 * getPixel(src, i - 1, j, width)) +
        (-1 * getPixel(src, i - 1, j + 1, width)) +
        (1 * getPixel(src, i + 1, j - 1, width)) +
        (2 * getPixel(src, i + 1, j, width)) +
        (1 * getPixel(src, i + 1, j + 1, width));

      mag = ceil(sqrt(pixelX * pixelX + pixelY * pixelY));

      if (mag > 255) {
        mag = 255;
      }

      dst[i * 4 * width + 4 * j] = mag;
      dst[i * 4 * width + 4 * j + 1] = mag;
      dst[i * 4 * width + 4 * j + 2] = mag;
      dst[i * 4 * width + 4 * j + 3] = 255;
    }
  }
}
