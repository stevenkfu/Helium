// Add two integer vectors and return the result 
#include "arm_neon.h"

void vec_add_int_vector(int *dst, int *src1, int *src2, int len);
void vec_sub_int_vector(int *dst, int *src1, int *src2, int len);
void vec_mul_int_vector(int *dst, int *src1, int *src2, int len);
void vec_div_int_vector(int *dst, int *src1, int *src2, int len);

void vec_add_float_vector(float *dst, float *src1, float *src2, int len);
void vec_mul_float_vector(float *dst, float *src1, float *src2, int len);
void vec_div_float_vector(float *dst, float *src1, float *src2, int len);
void vec_sub_float_vector(float *dst, float *src1, float *src2, int len);
