#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "vec_math_serial.h"

void time_math_ops() {
  clock_t start, end;
  double cpu_time_used;
  int len = 10000000;
  int *src1 = malloc(len * sizeof(int));
  int *src2 = malloc(len * sizeof(int));
  int *dst = malloc(len * sizeof(int));
  for (unsigned int i = 0; i < len; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_iadd_serial(dst, src1, src2, len);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial iadd: %f\n", cpu_time_used);
}

int main() {
    time_math_ops();
    return 0;
}
