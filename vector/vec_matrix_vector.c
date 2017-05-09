#include "vec_matrix_vector.h"
#include "arm_neon.h"
#include <stdio.h>

void int_matrix_mul_2x2(int* prod, int* m1, int* m2){
    
    int i;
    int32x2x2_t vec1;
    int32x2x2_t vec2;
    int32x2x2_t result;
    vec1 = vld2_s32(m1);
    vec2 = vld2_s32(m2);
    for(i = 0; i < 2; i++){
        int j;
        result.val[i] = vdup_n_s32(0);
            result.val[i] = vmla_lane_s32(result.val[i], vec1.val[0], vec2.val[i], 0);
            result.val[i] = vmla_lane_s32(result.val[i], vec1.val[1], vec2.val[i], 1);
    }
    vst2_s32(prod, result);
    return;
}

void int_matrix_mul_4x4(int* prod, int* m1, int* m2){
    
    int i;
    int32x4x4_t vec1;
    int32x4x4_t vec2;
    int32x2_t vec2_part;
    int32x4x4_t result;
    vec1 = vld4q_s32(m1);
    vec2 = vld4q_s32(m2);
    for(i = 0; i < 4; i++){
        int j;
        result.val[i] = vdupq_n_s32(0);
            vec2_part = vget_low_s32(vec2.val[i]);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[0], vec2_part, 0);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[1], vec2_part, 1);
            vec2_part = vget_high_s32(vec2.val[i]);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[2], vec2_part, 0);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[3], vec2_part, 1);
    }
    vst4q_s32(prod, result);
    return;
}

void mat4x4_trans_int_vector(int* trans, int* m){
    int i;
    int32x4x4_t vec;
    vec = vld4q_s32(m);
    for(i = 0; i < 4; i++){
        vst1q_s32(trans+4*i, vec.val[i]);
    }
    return;
}

void vector_matrix_det_4x4(int* determinant, int* m){
    //first find 3x3 determinants 
    int32x4_t sub_3x3;
    int32x4_t firstRow = vld1q_s32(m);
    int32x4_t secondRow = vld1q_s32(m+4);
    //find first 3x3 determinant
    int32x4_t temp, temp2;
    int a,b,c,d,e,f;
    a = m[8] * m[13] - m[9] * m[12];
    b = m[8] * m[14] - m[10] * m[12];
    c = m[8] * m[15] - m[11] * m[12];
    d = m[9] * m[14] - m[10] * m[13];
    e = m[9] * m[15] - m[11] * m[13];
    f = m[10] * m[15] - m[11] * m[14];
    temp[0] = 0;
    temp[1] = f;
    temp[2] = e;
    temp[3] = d;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[0] = temp2[1] - temp2[2] + temp2[3];
    temp[0] = f;
    temp[2] = c;
    temp[3] = b;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[1] = temp2[0] - temp2[2] + temp2[3];
    temp[0] = e;
    temp[1] = c;
    temp[3] = a;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[2] = temp2[0] - temp2[1] + temp2[3];
    temp[0] = d;
    temp[1] = b;
    temp[2] = a;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[3] = temp2[0] - temp2[1] + temp2[2];
    //multiply 3x3 determinants by first row
    temp = vmulq_s32(sub_3x3, firstRow);
    *determinant = temp[0] - temp[1] + temp[2] - temp[3];
    return;
}

void int_dotprod(int* prod, int* v1, int* v2, int len){
    int sum = 0;
    int i;
    int32x4_t vec1, vec2, res;
    int32x2_t accum = vdup_n_s32(0);
    vec1 = vld1q_s32(v1);
    vec2 = vld1q_s32(v2);
    for(i = 4; i < len; i += 4){
        res = vmulq_s32(vec1, vec2);
        accum = vpadd_s32(accum, vpadd_s32(vget_low_s32(res),vget_high_s32(res)));
        vec1 = vld1q_s32(v1 + i);
        vec2 = vld1q_s32(v2 + i);
    }
    res = vmulq_s32(vec1, vec2);
    int prev = i;
    for(i = 0; i < len + 4 - prev; i++)
        sum += res[i];
    sum += accum[0] + accum[1];
    *prod = sum;
}
 
// Credits to http://stackoverflow.com/a/28027063
void matmxn_trans_int_serial_cache(int *dst, int *src, int rows, int cols, int rb, int re, int cb, int ce) {
  int r = re - rb;
  int c = ce - cb;
  int i, j;
  if (r <= 16 && c <= 16) {
    for (i = rb; i < re; i++) {
      for (j = cb; j < ce; j++) {
        dst[j * rows + i] = src[i * cols + j];
      }
    }
  }
  else if (r >= c) {
    matmxn_trans_int_serial_cache(dst, src, rows, cols, rb, rb + (r / 2), cb, ce);
    matmxn_trans_int_serial_cache(dst, src, rows, cols, rb + (r / 2), re, cb, ce);
  }
  else {
    matmxn_trans_int_serial_cache(dst, src, rows, cols, rb, re, cb, cb + (c / 2));
    matmxn_trans_int_serial_cache(dst, src, rows, cols, rb, re, cb + (c / 2), ce);
  }
}

void int_matrix_mul(int* prod, int* m1, int* m2, int m, int n, int o){
    int* m2_transpose = malloc(sizeof(int) * n * o);
    matmxn_trans_int_serial_cache(m2_transpose, m2, n,o,0,n,0,o);
    int i;
    for(i = 0; i < m * o; i++){
        int_dotprod(prod + i, m1 + (i / o * n), m2_transpose + (i % o * n), n);
    }
    free (m2_transpose);
}
/*
#define M 800
#define N 1200
#define O 1200

int main(){//({5,1,25,2},{61,5,12,3},{15,52,32,5},{17,8246,44,2})
    //int m[M * N];
    int* m = malloc(sizeof(int) * M * N);
    //int n[N * O];
    int* n = malloc(sizeof(int) * N * O);
    int i, j;
    for(i = 0; i < M * N; i++){
        m[i] = i;
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < O; j++){
            n[i] = 0;
            if(i == j) n[O * i + j] = 1;
        }
    }
    int prod[M*O];
    int_matrix_mul(prod, m, n, M, N, O);
    for(i = 0; i < M; i++){
        for(j = 0; j < O; j++){
            printf("%d ", prod[O * i + j]);
        }
        printf("\n");
    }
    free(m);
    free(n);
    return 0;
}
*/
