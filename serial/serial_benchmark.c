#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec_math_serial.h"
#include "mat_math_serial.h"

#define LEN 10000000

void time_serial_add_int() {
  clock_t start, end;
  double cpu_time_used;
  int *src1 = malloc(LEN * sizeof(int));
  int *src2 = malloc(LEN * sizeof(int));
  int *dst = malloc(LEN * sizeof(int));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_add_int_serial(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) + (src2[i])) {
      printf("Error: serial int add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial int add: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_sub_int() {
  clock_t start, end;
  double cpu_time_used;
  int *src1 = malloc(LEN * sizeof(int));
  int *src2 = malloc(LEN * sizeof(int));
  int *dst = malloc(LEN * sizeof(int));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_sub_int_serial(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) - (src2[i])) {
      printf("Error: serial int sub failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial int sub: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_mul_int() {
  clock_t start, end;
  double cpu_time_used;
  int *src1 = malloc(LEN * sizeof(int));
  int *src2 = malloc(LEN * sizeof(int));
  int *dst = malloc(LEN * sizeof(int));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_mul_int_serial(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) * (src2[i])) {
      printf("Error: serial int mul failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial int mul: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_add_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src1 = malloc(LEN * sizeof(int));
  float *src2 = malloc(LEN * sizeof(int));
  float *dst = malloc(LEN * sizeof(int));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_add_float_serial(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) + (src2[i])) {
      printf("Error: serial float add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial float add: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_sub_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src1 = malloc(LEN * sizeof(int));
  float *src2 = malloc(LEN * sizeof(int));
  float *dst = malloc(LEN * sizeof(int));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_sub_float_serial(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) - (src2[i])) {
      printf("Error: serial float sub failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial float sub: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_mul_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src1 = malloc(LEN * sizeof(int));
  float *src2 = malloc(LEN * sizeof(int));
  float *dst = malloc(LEN * sizeof(int));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = i * 2;
    src2[i] = i - 5;
  }
  start = clock();
  vec_mul_float_serial(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) * (src2[i])) {
      printf("Error: serial float mul failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial float mul: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_div_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src1 = malloc(LEN * sizeof(int));
  float *src2 = malloc(LEN * sizeof(int));
  float *dst = malloc(LEN * sizeof(int));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = i * 2;
    src2[i] = i + 5;
  }
  start = clock();
  vec_div_float_serial(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) / (src2[i])) {
      printf("Error: serial int add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial float div: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_mat2x2_mult_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 2;
  int *src1 = malloc(len * len * sizeof(int*));
  int *src2 = malloc(len * len * sizeof(int*));
  int *dst = malloc(len * len * sizeof(int*));
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src1[j*2+k] = (j + 2) * (k - 5);
      src2[j*2+k] = (j + 3) * (k - 4);
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    mat2x2_mult_int_serial(dst, src1, src2);
  }
  if (dst[0*2+0] != 248 || dst[0*2+1] != 186 || dst[1*2+0] != 372 || dst[1*2+1] != 279) {
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
  int *src1 = malloc(len * len * sizeof(int*));
  int *src2 = malloc(len * len * sizeof(int*));
  int *dst = malloc(len * len * sizeof(int*));
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src1[j*4+k] = (j + 2) * (k - 5);
      src2[j*4+k] = (j + 3) * (k - 4);
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    mat4x4_mult_int_serial(dst, src1, src2);
  }
  end = clock();
  if (dst[0*4+0] != 464 || dst[0*4+1] != 348 || dst[0*4+2] != 232 || dst[0*4+3] != 116 ||
      dst[1*4+0] != 696 || dst[1*4+1] != 522 || dst[1*4+2] != 348 || dst[1*4+3] != 174 ||
      dst[2*4+0] != 928 || dst[2*4+1] != 696 || dst[2*4+2] != 464 || dst[2*4+3] != 232 ||
      dst[3*4+0] != 1160 || dst[3*4+1] != 870 || dst[3*4+2] != 580 || dst[3*4+3] != 290) {
    printf("Matrix multiply 4x4 ints returned incorrect result\n");
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat4x4 int mult: %f\n", cpu_time_used);
}

void time_serial_mat2x2_trans_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 2;
  int *src = malloc(len * len * sizeof(int*));
  int *dst = malloc(len * len * sizeof(int*));
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src[j*2+k] = j+k;
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    mat2x2_trans_int_serial(dst, src);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat2x2 int trans: %f\n", cpu_time_used);
}

void time_serial_mat4x4_trans_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 4;
  int *src = malloc(len * len * sizeof(int*));
  int *dst = malloc(len * len * sizeof(int*));
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src[j*4+k] = j+k;
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    mat4x4_trans_int_serial(dst, src);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat4x4 int trans: %f\n", cpu_time_used);
}

int main() {
    time_serial_add_int();
    time_serial_sub_int();
    time_serial_mul_int();
    time_serial_add_float();
    time_serial_sub_float();
    time_serial_mul_float();
    time_serial_div_float();
    time_serial_mat2x2_mult_int();
    time_serial_mat4x4_mult_int();
    time_serial_mat2x2_trans_int();
    time_serial_mat4x4_trans_int();
    return 0;
}
