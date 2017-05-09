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

void time_serial_sum_int() {
  clock_t start, end;
  double cpu_time_used;
  int *src = malloc(LEN * sizeof(int));
  int sum;
  unsigned int i;
  for (i = 0; i < LEN; i++) {
    src[i] = i * 2;
  }
  start = clock();
  vec_sum_int_serial(&sum, src, LEN);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial sum add: %f\n", cpu_time_used);
  free(src);
}

void time_serial_add_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src1 = malloc(LEN * sizeof(float));
  float *src2 = malloc(LEN * sizeof(float));
  float *dst = malloc(LEN * sizeof(float));
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
  float *src1 = malloc(LEN * sizeof(float));
  float *src2 = malloc(LEN * sizeof(float));
  float *dst = malloc(LEN * sizeof(float));
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
  float *src1 = malloc(LEN * sizeof(float));
  float *src2 = malloc(LEN * sizeof(float));
  float *dst = malloc(LEN * sizeof(float));
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
  float *src1 = malloc(LEN * sizeof(float));
  float *src2 = malloc(LEN * sizeof(float));
  float *dst = malloc(LEN * sizeof(float));
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
  free(src1);
  free(src2);
  free(dst);
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
  free(src1);
  free(src2);
  free(dst);
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
  free(src);
  free(dst);
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
      src[j*4+k] = 2*j+3*k;
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    mat4x4_trans_int_serial(dst, src);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat4x4 int trans: %f\n", cpu_time_used);
  free(src);
  free(dst);
}

void time_serial_mat2x2_det_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 2;
  int *src = malloc(len * len * sizeof(int*));
  int det = 0;
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src[j*2+k] = 2*j+3*k;
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    int_matrix_det_2x2(&det, src);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat2x2 int det: %f\n", cpu_time_used);
  free(src);
}

void time_serial_mat2x2_inv_float() {
  clock_t start, end;
  double cpu_time_used;
  float *src = malloc(LEN * sizeof(float));
  float *dst = malloc(LEN * sizeof(float));
  unsigned int j;
  unsigned int k;
  unsigned int i;
  int len = 2;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src[j*2+k] = 2*j+3*k;
    }
  }
  start = clock();
  for (i = 0; i < LEN; i++) {
    mat2x2_inv_float_serial(dst, src);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat2x2 inv: %f\n", cpu_time_used);
  free(src);
  free(dst);
}

void time_serial_mat4x4_det_int() {
  clock_t start, end;
  double cpu_time_used;
  int len = 4;
  int *src = malloc(len * len * sizeof(int*));
  int det;
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < len; j++) {
    for (k = 0; k < len; k++) {
      src[j*4+k] = j*4+k + 1;
    }
  }
  src[0] = 10;
  src[1] = 9;
  src[2] = 10;
  src[8] = 10;
  start = clock();
  for (i = 0; i < LEN; i++) {
    int_matrix_det_4x4(&det, src);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat4x4 int det: %f\n", cpu_time_used);
  free(src);
}

void time_serial_matmxn_trans_int_cache() {
  clock_t start, end;
  double cpu_time_used;
  int rows = 2000;
  int cols = 1400;
  int *src = malloc(rows * cols * sizeof(int*));
  int *dst = malloc(cols * rows * sizeof(int*));
  unsigned int j;
  unsigned int k;
  for (j = 0; j < rows; j++) {
    for (k = 0; k < cols; k++) {
      src[j*cols+k] = 2*j+3*k;
    }
  }
  /*
  printf("before\n");
  for (j = 0; j < rows; j++) {
    for (k = 0; k < cols; k++) {
      printf("%d ", src[j*cols+k]);
    }
    printf("\n");
  }
  */
  start = clock();
  matmxn_trans_int_serial_cache(dst, src, rows, cols, 0, rows, 0, cols);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial matmxn int trans cache: %f\n", cpu_time_used);
  /*
  for (j = 0; j < cols; j++) {
    for (k = 0; k < rows; k++) {
      printf("%d ", dst[j*rows+k]);
    }
    printf("\n");
  }
  */
  for (j = 0; j < cols; j++) {
    for (k = 0; k < rows; k++) {
      if (dst[j*rows+k] != src[k*cols+j]) {
        printf("********ERROR*********\n");
      }
    }
  }
  free(src);
  free(dst);
}

void time_serial_matmxn_trans_int() {
  clock_t start, end;
  double cpu_time_used;
  int rows = 2000;
  int cols = 1600;
  int *src = malloc(rows * cols * sizeof(int*));
  int *dst = malloc(cols * rows * sizeof(int*));
  unsigned int j;
  unsigned int k;
  for (j = 0; j < rows; j++) {
    for (k = 0; k < cols; k++) {
      src[j*cols+k] = 2*j+3*k;
    }
  }
  /*
  printf("before\n");
  for (j = 0; j < rows; j++) {
    for (k = 0; k < cols; k++) {
      printf("%d ", src[j*cols+k]);
    }
    printf("\n");
  }
  */
  start = clock();
  matmxn_trans_int_serial(dst, src, cols, rows);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial matmxn int trans: %f\n", cpu_time_used);
  /*
  for (j = 0; j < cols; j++) {
    for (k = 0; k < rows; k++) {
      printf("%d ", dst[j*rows + k]);
    }
    printf("\n");
  }
  */
  for (j = 0; j < cols; j++) {
    for (k = 0; k < rows; k++) {
      if (dst[j*rows+k] != src[k*cols+j]) {
        printf("********ERROR*********\n");
      }
    }
  }
  free(src);
  free(dst);
}

void time_serial_mat_mult_int() {
  clock_t start, end;
  double cpu_time_used;
  int s1r = 800;
  int s1c = 1200;
  int s2r = s1c;
  int s2c = 600;
  int *src1 = malloc(s1r * s1c * sizeof(int*));
  int *src2 = malloc(s2r * s2c * sizeof(int*));
  int *dst = malloc(s1r * s2c * sizeof(int*));
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < s1r; j++) {
    for (k = 0; k < s1c; k++) {
      src1[j*s1c+k] = 2*j+6*k;
    }
  }
  for (j = 0; j < s2r; j++) {
    for (k = 0; k < s2c; k++) {
      src2[j*s2c+k] = 3*j-2*k;
    }
  }
  start = clock();
  mat_mult_int_serial(dst, src1, src2, s1r, s1c, s2r, s2c);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat int mult: %f\n", cpu_time_used);
  /*
  for (j = 0; j < s1r; j++) {
    for (k = 0; k < s2c; k++) {
      printf("%d ", dst[j*s2c + k]);
    }
    printf("\n");
  }
  */
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_mat_mult_int_trans() {
  clock_t start, end;
  double cpu_time_used;
  int s1r = 5000;
  int s1c = 5000;
  int s2r = s1c;
  int s2c = 5000;
  int *src1 = malloc(s1r * s1c * sizeof(int*));
  int *src2 = malloc(s2r * s2c * sizeof(int*));
  int *dst = malloc(s1r * s2c * sizeof(int*));
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < s1r; j++) {
    for (k = 0; k < s1c; k++) {
      src1[j*s1c+k] = 2*j+6*k;
    }
  }
  for (j = 0; j < s2r; j++) {
    for (k = 0; k < s2c; k++) {
      src2[j*s2c+k] = 3*j-2*k;
    }
  }
  start = clock();
  mat_mult_int_serial_trans(dst, src1, src2, s1r, s1c, s2r, s2c);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat int mult trans: %f\n", cpu_time_used);
  /*
  for (j = 0; j < s1r; j++) {
    for (k = 0; k < s2c; k++) {
      printf("%d ", dst[j*s2c + k]);
    }
    printf("\n");
  }
  */
  free(src1);
  free(src2);
  free(dst);
}

void time_serial_mat_mult_int_naive() {
  clock_t start, end;
  double cpu_time_used;
  int s1r = 11;
  int s1c = 8;
  int s2r = s1c;
  int s2c = 9;
  int *src1 = malloc(s1r * s1c * sizeof(int*));
  int *src2 = malloc(s2r * s2c * sizeof(int*));
  int *dst = malloc(s1r * s2c * sizeof(int*));
  unsigned int i;
  unsigned int j;
  unsigned int k;
  for (j = 0; j < s1r; j++) {
    for (k = 0; k < s1c; k++) {
      src1[j*s1c+k] = 2*j+6*k;
    }
  }
  for (j = 0; j < s2r; j++) {
    for (k = 0; k < s2c; k++) {
      src2[j*s2c+k] = 3*j-2*k;
    }
  }
  start = clock();
  mat_mult_int_serial_trans(dst, src1, src2, s1r, s1c, s2r, s2c);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for serial mat int mult naive: %f\n", cpu_time_used);
  free(src1);
  free(src2);
  free(dst);
}

#define M 100
#define N 100
#define O 10
#define P 10

void test_int_conv_serial() {
  clock_t start, end;
  double cpu_time_used;
    int m[M*N];
    int filter[O * P];
    int i;
    for(i = 0; i < M * N; i++){
        m[i] = i;
    }
    for(i = 0; i < O * P; i++){
        filter[i] = i;
    }
    int output[M * N];

    start = clock();
    int_conv_serial(output, m, N, M, filter,O,P);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time elapsed for conv: %f\n", cpu_time_used);
    /*
    for(i = 0; i < M*N;i++){
        printf("%d ", output[i]);
        if(i % N == N - 1) printf("\n");
    }
    */
}

int main() {
    /*
    time_serial_add_int();
    time_serial_sub_int();
    time_serial_mul_int();
    time_serial_sum_int();
    time_serial_add_float();
    time_serial_sub_float();
    time_serial_mul_float();
    time_serial_div_float();
    time_serial_mat2x2_mult_int();
    time_serial_mat4x4_mult_int();
    time_serial_mat2x2_trans_int();
    time_serial_mat4x4_trans_int();
    time_serial_mat2x2_det_int();
    time_serial_mat2x2_inv_float();
    time_serial_mat4x4_det_int();
    time_serial_matmxn_trans_int_cache();
    time_serial_matmxn_trans_int();
    */
    //time_serial_mat_mult_int();
    //time_serial_mat_mult_int_trans();
    //time_serial_mat_mult_int_naive();
    test_int_conv_serial();
    return 0;
}
