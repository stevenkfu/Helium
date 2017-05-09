// Add two integer vectors and return the result 
#include "vec_math_vector.h"

void vec_add_int_vector(int *dst, int *src1, int *src2, int len) {
  int i;
  for (i = 0; i < len-4; i += 4) {
    int32x4_t vec1;
    int32x4_t vec2;
    int32x4_t res;
    vec1 = vld1q_s32(src1+i);
    vec2 = vld1q_s32(src2+i);
    res = vaddq_s32(vec1, vec2);
    vst1q_s32(dst+i, res);
  }
  for(; i < len; i++){
        dst[i] = src1[i] + src2[i];
  }
}

void vec_sub_int_vector(int *dst, int *src1, int *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i += 4) {
    int32x4_t vec1;
    int32x4_t vec2;
    int32x4_t res;
    vec1 = vld1q_s32(src1+i);
    vec2 = vld1q_s32(src2+i);
    res = vsubq_s32(vec1, vec2);
    vst1q_s32(dst+i, res);
  }
}

void vec_mul_int_vector(int *dst, int *src1, int *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i += 4) {
    int32x4_t vec1;
    int32x4_t vec2;
    int32x4_t res;
    vec1 = vld1q_s32(src1+i);
    vec2 = vld1q_s32(src2+i);
    res = vmulq_s32(vec1, vec2);
    vst1q_s32(dst+i, res);
  }
}

void vec_div_int_vector(int *dst, int *src1, int *src2, int len) {
//Do some weird reciprocal shit
return;
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

void vec_add_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i += 4) {
    float32x4_t vec1;
    float32x4_t vec2;
    float32x4_t res;
    vec1 = vld1q_f32(src1+i);
    vec2 = vld1q_f32(src2+i);
    res = vaddq_f32(vec1, vec2);
    vst1q_f32(dst+i, res);
  }
}

void vec_mul_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i += 4) {
    float32x4_t vec1;
    float32x4_t vec2;
    float32x4_t res;
    vec1 = vld1q_f32(src1+i);
    vec2 = vld1q_f32(src2+i);
    res = vmulq_f32(vec1, vec2);
    vst1q_f32(dst+i, res);
  }
}

void vec_div_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i += 4) {
    float32x4_t vec1;
    float32x4_t vec2;
    float32x4_t res;
    vec1 = vld1q_f32(src1+i);
    vec2 = vld1q_f32(src2+i);
    // get an initial estimate of 1/b.
    float32x4_t reciprocal = vrecpeq_f32(vec2);
    
    // use a couple Newton-Raphson steps to refine the estimate.  Depending on your
    // application's accuracy requirements, you may be able to get away with only
    // one refinement (instead of the two used here).  Be sure to test!
    reciprocal = vmulq_f32(vrecpsq_f32(vec2, reciprocal), reciprocal);
    
    // and finally, compute a/b = a*(1/b)
    res = vmulq_f32(vec1,reciprocal);
    vst1q_f32(dst+i, res);
  }
}

void vec_sub_float_vector(float *dst, float *src1, float *src2, int len) {
  unsigned int i;
  for (i = 0; i < len; i += 4) {
    float32x4_t vec1;
    float32x4_t vec2;
    float32x4_t res;
    vec1 = vld1q_f32(src1+i);
    vec2 = vld1q_f32(src2+i);
    res = vsubq_f32(vec1, vec2);
    vst1q_f32(dst+i, res);
  }
}
