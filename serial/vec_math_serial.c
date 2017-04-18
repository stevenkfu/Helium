// Add two integer vectors and return the result 

void vec_add_int_serial(int *dst, int *src1, int *src2, int len) {
  for (unsigned int i = 0; i < len; i++) {
    dst[i] = src1[i] + src2[i];
  }
}

void vec_sub_int_serial(int *dst, int *src1, int *src2, int len) {
  for (unsigned int i = 0; i < len; i++) {
    dst[i] = src1[i] - src2[i];
  }
}

void vec_mul_int_serial(int *dst, int *src1, int *src2, int len) {
  for (unsigned int i = 0; i < len; i++) {
    dst[i] = src1[i] * src2[i];
  }
}

void vec_div_int_serial(int *dst, int *src1, int *src2, int len) {
  for (unsigned int i = 0; i < len; i++) {
    dst[i] = src1[i] / src2[i];
  }
}
void vec_add_float_serial(float *dst, float *src1, float *src2, int len) {
    for(unsigned int i = 0; i < len; i++) {
        dst[i] = src1[i] + src2[i];
    }
}

void vec_mul_float_serial(float *dst, float *src1, float *src2, int len) {
    for(unsigned int i = 0; i < len; i++) {
        dst[i] = src1[i] * src2[i];
    }
}

void vec_div_float_serial(float *dst, float *src1, float *src2, int len) {
    for(unsigned int i = 0; i < len; i++) {
        dst[i] = src1[i] / src2[i];
    }
}

void vec_sub_float_serial(float *dst, float *src1, float *src2, int len) {
    for(unsigned int i = 0; i < len; i++) {
        dst[i] = src1[i] - src2[i];
    }
}
