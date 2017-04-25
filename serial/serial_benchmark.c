#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec_math_serial.h"
#include "mat_math_serial.h"

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

void time_serial_mat2x2_mult_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 2;
  int **src1 = malloc(len * sizeof(int*));
  int **src2 = malloc(len * sizeof(int*));
  int **dst = malloc(len * sizeof(int*));
  unsigned int i;
  for (i = 0; i < len; i++) {
    src1[i] = (int *) malloc(len * sizeof(int));
    src2[i] = (int *) malloc(len * sizeof(int));
    dst[i] = (int *) malloc(len * sizeof(int));
  }
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src1[j][k] = (j + 2) * (k - 5);
      src2[j][k] = (j + 3) * (k - 4);
    }
  }
  start = clock();
  for (i = 0; i < 10000000; i++) {
    mat2x2_mult_int_serial(dst, src1, src2);
  }
  if (dst[0][0] != 248 || dst[0][1] != 186 || dst[1][0] != 372 || dst[1][1] != 279) {
    printf("Matrix multiply 2x2 ints returned incorrect result\n");
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat2x2 int mult: %f\n", cpu_time_used);
}

void time_serial_mat4x4_mult_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 4;
  int **src1 = malloc(len * sizeof(int*));
  int **src2 = malloc(len * sizeof(int*));
  int **dst = malloc(len * sizeof(int*));
  unsigned int i;
  for (i = 0; i < len; i++) {
    src1[i] = (int *) malloc(len * sizeof(int));
    src2[i] = (int *) malloc(len * sizeof(int));
    dst[i] = (int *) malloc(len * sizeof(int));
  }
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src1[j][k] = (j + 2) * (k - 5);
      src2[j][k] = (j + 3) * (k - 4);
    }
  }
  start = clock();
  for (i = 0; i < 10000000; i++) {
    mat4x4_mult_int_serial(dst, src1, src2);
  }
  end = clock();
  if (dst[0][0] != 464 || dst[0][1] != 348 || dst[0][2] != 232 || dst[0][3] != 116 ||
      dst[1][0] != 696 || dst[1][1] != 522 || dst[1][2] != 348 || dst[1][3] != 174 ||
      dst[2][0] != 928 || dst[2][1] != 696 || dst[2][2] != 464 || dst[2][3] != 232 ||
      dst[3][0] != 1160 || dst[3][1] != 870 || dst[3][2] != 580 || dst[3][3] != 290) {
    printf("Matrix multiply 4x4 ints returned incorrect result\n");
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat4x4 int mult: %f\n", cpu_time_used);
}

int main() {
    time_serial_add_int();
    time_serial_div_float();
    time_serial_mat2x2_mult_int();
    time_serial_mat4x4_mult_int();
    return 0;
}
