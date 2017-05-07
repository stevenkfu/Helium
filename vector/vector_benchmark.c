#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec_math_vector.h"
#include "vec_matrix_vector.h"

#define LEN 10000000

void time_vector_add_int() {
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
  vec_add_int_vector(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) + (src2[i])) {
      printf("Error: vector int add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector int add: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_vector_sub_int() {
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
  vec_sub_int_vector(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) - (src2[i])) {
      printf("Error: vector int sub failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector int subtract: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_vector_mul_int() {
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
  vec_mul_int_vector(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) * (src2[i])) {
      printf("Error: vector int mul failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector int mul: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_vector_add_float() {
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
  vec_add_float_vector(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) + (src2[i])) {
      printf("Error: vector float add failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector float add: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_vector_sub_float() {
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
  vec_sub_float_vector(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) - (src2[i])) {
      printf("Error: vector float sub failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector float subtract: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_vector_mul_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src1 = malloc(LEN * sizeof(float));
  float *src2 = malloc(LEN * sizeof(float));
  float *dst = malloc(LEN * sizeof(float));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = (float)i * 2;
    src2[i] = (float)i - 5;
  }
  start = clock();
  vec_mul_float_vector(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] != (src1[i]) * (src2[i])) {
      printf("Error: vector float mul failed at index %d\n", i);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector float mul: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_vector_div_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src1 = malloc(LEN * sizeof(float));
  float *src2 = malloc(LEN * sizeof(float));
  float *dst = malloc(LEN * sizeof(float));
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src1[i] = (float)i * 2;
    src2[i] = (float)i + 5;
  }
  start = clock();
  vec_div_float_vector(dst, src1, src2, LEN);
  end = clock();
  for (i = 0; i < LEN; i++) {
    if (dst[i] - (src1[i]) / (src2[i]) > 0.0001) {
      printf("Error: vector float div failed at index %d\n%f vs %f \n", i, dst[i], src1[i]/src2[i]);
    }
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector float div: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

void time_vector_mat4x4_mult_int() {
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
    int_matrix_mul_4x4(dst, src1, src2);
  }
  end = clock();
  if (dst[0*4+0] != 464 || dst[0*4+1] != 348 || dst[0*4+2] != 232 || dst[0*4+3] != 116 ||
      dst[1*4+0] != 696 || dst[1*4+1] != 522 || dst[1*4+2] != 348 || dst[1*4+3] != 174 ||
      dst[2*4+0] != 928 || dst[2*4+1] != 696 || dst[2*4+2] != 464 || dst[2*4+3] != 232 ||
      dst[3*4+0] != 1160 || dst[3*4+1] != 870 || dst[3*4+2] != 580 || dst[3*4+3] != 290) {
    printf("Matrix multiply 4x4 ints returned incorrect result\n");
  }
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for vector mat4x4 int mult: %f\n", cpu_time_used);
}

void time_vector_mat2x2_mult_int() {
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
    int_matrix_mul_2x2(dst, src1, src2);
  }
  if (dst[0*2+0] != 248 || dst[0*2+1] != 186 || dst[1*2+0] != 372 || dst[1*2+1] != 279) {
    printf("Matrix multiply 2x2 ints returned incorrect result\n");
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat2x2 int mult: %f\n", cpu_time_used);
}

void time_vector_mat4x4_trans_int() {
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
      src[j*4+k] = 4*j+k;
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    mat4x4_trans_int_vector(dst, src);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat4x4 int trans: %f\n", cpu_time_used);
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      printf("%d ",src[4*i+j]);
    }
    printf("\n");
  }
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      printf("%d ",dst[4*i+j]);
    }
    printf("\n");
  }
}

int main() {
    time_vector_add_int();
    time_vector_sub_int();
    time_vector_mul_int();
    time_vector_add_float();
    time_vector_sub_float();
    time_vector_mul_float();
    time_vector_mat2x2_mult_int();
    time_vector_mat4x4_mult_int();
    time_vector_mat4x4_trans_int();
    return 0;
}
