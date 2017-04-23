// Add two integer vectors and return the result 
#include "vec_math_vector.h"

void vec_add_int_vector(int *dst, int *src1, int *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i += 4) {
    int32x4_t vec1;
    int32x4_t vec2;
    int32x4_t res;
    vec1 = vld1q_s32(src1+i);
    vec2 = vld1q_s32(src2+i);
    res = vaddq_s32(vec1, vec2);
    vst1q_s32(dst+i, res);
  }
}

void vec_sub_int_vector(int *dst, int *src1, int *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i++) {
    dst[i] = src1[i] - src2[i];
  }
}

void vec_mul_int_vector(int *dst, int *src1, int *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i++) {
    dst[i] = src1[i] * src2[i];
  }
}

void vec_div_int_vector(int *dst, int *src1, int *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i++) {
    dst[i] = src1[i] / src2[i];
  }
}
void vec_add_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for(i = 0; i < len; i++) {
    dst[i] = src1[i] + src2[i];
  }
}

void vec_mul_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for(i = 0; i < len; i++) {
    dst[i] = src1[i] * src2[i];
  }
}

void vec_div_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for(i = 0; i < len; i++) {
    dst[i] = src1[i] / src2[i];
  }
}

void vec_sub_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for(i = 0; i < len; i++) {
    dst[i] = src1[i] - src2[i];
  }
}
