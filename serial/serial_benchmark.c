#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "vec_math_serial.h"

void time_math_ops() {
  clock_t start, end;
  double cpu_time_used;
  int len = 5;
  int *src1 = malloc(10 * sizeof(int));
  int *src2 = malloc(10 * sizeof(int));
  int *dst = malloc(10 * sizeof(int));
  for (unsigned int i = 0; i < 10; i++) {
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
