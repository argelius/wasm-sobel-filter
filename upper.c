#include <string.h>

void upper(char *dst, char *src) {
  int i;
  int l = strlen(src);

  for (i = 0; i < l; i++) {
    char c = src[i];

    if (c >= 'a' && c <= 'z') {
      dst[i] = c - ('a' - 'A');
    } else {
      dst[i] = c;
    }
  }

  dst[l] = '\0';
}

