#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec_math_vector.h"

void time_vector_add_int() {
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
  vec_add_int_vector(dst, src1, src2, len);
  end = clock();
  for (i = 0; i < len; i++) {
    if (dst[i] != (src1[i]) + (src2[i])) {
      printf("Error: vector int add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector int add: %f\n", cpu_time_used);
}

void time_vector_sub_int() {
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
  vec_sub_int_vector(dst, src1, src2, len);
  end = clock();
  for (i = 0; i < len; i++) {
    if (dst[i] != (src1[i]) - (src2[i])) {
      printf("Error: vector int sub failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector int subtract: %f\n", cpu_time_used);
}

void time_vector_mul_int() {
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
  vec_mul_int_vector(dst, src1, src2, len);
  end = clock();
  for (i = 0; i < len; i++) {
    if (dst[i] != (src1[i]) * (src2[i])) {
      printf("Error: vector int mul failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector int mul: %f\n", cpu_time_used);
}

int main() {
    time_vector_add_int();
    time_vector_sub_int();
    time_vector_mul_int();
    return 0;
}
