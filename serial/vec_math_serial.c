// Add two integer vectors and return the result 

void vec_iadd_serial(int *dst, int *src1, int *src2, int len) {
  for (unsigned int i = 0; i < len; i++) {
    dst[i] = src1[i] + src2[i];
  }
}
