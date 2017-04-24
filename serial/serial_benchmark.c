#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec_math_serial.h"

void time_serial_add_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 10000000;
  int *src1 = malloc(len * sizeof(int));
  int *src2 = malloc(len * sizeof(int));
  int *dst = malloc(len * sizeof(int));
  unsigned int i;
  for (i = 0; i < len; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_add_int_serial(dst, src1, src2, len);
  end = clock();
  for (i = 0; i < len; i++) {
    if (dst[i] != (src1[i]) + (src2[i])) {
      printf("Error: serial int add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial int add: %f\n", cpu_time_used);
}

void time_serial_div_float() {
  clock_t start, end;
  double cpu_time_used;
  int len = 10000000;
  float *src1 = malloc(len * sizeof(int));
  float *src2 = malloc(len * sizeof(int));
  float *dst = malloc(len * sizeof(int));
  unsigned int i;
  for (i = 0; i < len; i++) {
    src1[i] = i * 2;
    src2[i] = i + 5;
  }
  start = clock();
  vec_div_float_serial(dst, src1, src2, len);
  end = clock();
  for (i = 0; i < len; i++) {
    if (dst[i] != (src1[i]) / (src2[i])) {
      printf("Error: serial int add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial int add: %f\n", cpu_time_used);
}

int main() {
    time_serial_add_int();
    time_serial_div_float();
    return 0;
}
