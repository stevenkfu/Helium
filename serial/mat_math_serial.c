#include <stdlib.h>

void mat2x2_mult_int_serial(int *dst, int *src1, int *src2) {
  dst[0*2+0] = src1[0*2+0]*src2[0*2+0] + src1[0*2+1]*src2[1*2+0];
  dst[0*2+1] = src1[0*2+0]*src2[0*2+1] + src1[0*2+1]*src2[1*2+1];
  dst[1*2+0] = src1[1*2+0]*src2[0*2+0] + src1[1*2+1]*src2[1*2+0];
  dst[1*2+1] = src1[1*2+0]*src2[0*2+1] + src1[1*2+1]*src2[1*2+1];
}

void mat2x2_mult_float_serial(float *dst, float *src1, float *src2) {
  dst[0*2+0] = src1[0*2+0]*src2[0*2+0] + src1[0*2+1]*src2[1*2+0];
  dst[0*2+1] = src1[0*2+0]*src2[0*2+1] + src1[0*2+1]*src2[1*2+1];
  dst[1*2+0] = src1[1*2+0]*src2[0*2+0] + src1[1*2+1]*src2[1*2+0];
  dst[1*2+1] = src1[1*2+0]*src2[0*2+1] + src1[1*2+1]*src2[1*2+1];
}

void mat4x4_mult_int_serial(int *dst, int *src1, int*src2) {
  dst[0*4+0] = src1[0*4+0]*src2[0*4+0]+src1[0*4+1]*src2[1*4+0]+src1[0*4+2]*src2[2*4+0]+src1[0*4+3]*src2[3*4+0];
  dst[0*4+1] = src1[0*4+0]*src2[0*4+1]+src1[0*4+1]*src2[1*4+1]+src1[0*4+2]*src2[2*4+1]+src1[0*4+3]*src2[3*4+1];
  dst[0*4+2] = src1[0*4+0]*src2[0*4+2]+src1[0*4+1]*src2[1*4+2]+src1[0*4+2]*src2[2*4+2]+src1[0*4+3]*src2[3*4+2];
  dst[0*4+3] = src1[0*4+0]*src2[0*4+3]+src1[0*4+1]*src2[1*4+3]+src1[0*4+2]*src2[2*4+3]+src1[0*4+3]*src2[3*4+3];
  dst[1*4+0] = src1[1*4+0]*src2[0*4+0]+src1[1*4+1]*src2[1*4+0]+src1[1*4+2]*src2[2*4+0]+src1[1*4+3]*src2[3*4+0];
  dst[1*4+1] = src1[1*4+0]*src2[0*4+1]+src1[1*4+1]*src2[1*4+1]+src1[1*4+2]*src2[2*4+1]+src1[1*4+3]*src2[3*4+1];
  dst[1*4+2] = src1[1*4+0]*src2[0*4+2]+src1[1*4+1]*src2[1*4+2]+src1[1*4+2]*src2[2*4+2]+src1[1*4+3]*src2[3*4+2];
  dst[1*4+3] = src1[1*4+0]*src2[0*4+3]+src1[1*4+1]*src2[1*4+3]+src1[1*4+2]*src2[2*4+3]+src1[1*4+3]*src2[3*4+3];
  dst[2*4+0] = src1[2*4+0]*src2[0*4+0]+src1[2*4+1]*src2[1*4+0]+src1[2*4+2]*src2[2*4+0]+src1[2*4+3]*src2[3*4+0];
  dst[2*4+1] = src1[2*4+0]*src2[0*4+1]+src1[2*4+1]*src2[1*4+1]+src1[2*4+2]*src2[2*4+1]+src1[2*4+3]*src2[3*4+1];
  dst[2*4+2] = src1[2*4+0]*src2[0*4+2]+src1[2*4+1]*src2[1*4+2]+src1[2*4+2]*src2[2*4+2]+src1[2*4+3]*src2[3*4+2];
  dst[2*4+3] = src1[2*4+0]*src2[0*4+3]+src1[2*4+1]*src2[1*4+3]+src1[2*4+2]*src2[2*4+3]+src1[2*4+3]*src2[3*4+3];
  dst[3*4+0] = src1[3*4+0]*src2[0*4+0]+src1[3*4+1]*src2[1*4+0]+src1[3*4+2]*src2[2*4+0]+src1[3*4+3]*src2[3*4+0];
  dst[3*4+1] = src1[3*4+0]*src2[0*4+1]+src1[3*4+1]*src2[1*4+1]+src1[3*4+2]*src2[2*4+1]+src1[3*4+3]*src2[3*4+1];
  dst[3*4+2] = src1[3*4+0]*src2[0*4+2]+src1[3*4+1]*src2[1*4+2]+src1[3*4+2]*src2[2*4+2]+src1[3*4+3]*src2[3*4+2];
  dst[3*4+3] = src1[3*4+0]*src2[0*4+3]+src1[3*4+1]*src2[1*4+3]+src1[3*4+2]*src2[2*4+3]+src1[3*4+3]*src2[3*4+3];
}

void mat2x2_trans_int_serial(int *dst, int *src) {
  dst[0*2+0] = src[0*2+0];
  dst[0*2+1] = src[1*2+0];
  dst[1*2+0] = src[0*2+1];
  dst[1*2+1] = src[1*2+1];
}

void mat4x4_trans_int_serial(int *dst, int *src) {
  dst[0*4+0] = src[0*4+0];
  dst[0*4+1] = src[1*4+0];
  dst[0*4+2] = src[2*4+0];
  dst[0*4+3] = src[3*4+0];
  dst[1*4+0] = src[0*4+1];
  dst[1*4+1] = src[1*4+1];
  dst[1*4+2] = src[2*4+1];
  dst[1*4+3] = src[3*4+1];
  dst[2*4+0] = src[0*4+2];
  dst[2*4+1] = src[1*4+2];
  dst[2*4+2] = src[2*4+2];
  dst[2*4+3] = src[3*4+2];
  dst[3*4+0] = src[0*4+3];
  dst[3*4+1] = src[1*4+3];
  dst[3*4+2] = src[2*4+3];
  dst[3*4+3] = src[3*4+3];
}

void int_matrix_det_2x2(int* det, int* m) {
  *det = (m[0] * m[3]) - (m[1] * m[2]);
}

int mat2x2_inv_float_serial(float *dst, float *src) {
  float det = (src[0] * src[3]) - (src[1] * src[2]);
  if (det == 0.f) {
    return 0;
  }
  dst[0*2+0] = src[1*2+1] / det;
  dst[0*2+1] = -src[0*2+1] / det;
  dst[1*2+0] = -src[1*2+0] / det;
  dst[1*2+1] = src[0*2+0] / det;
  return 1;
}

void int_matrix_det_4x4(int *det, int *m) {
  int a,b,c,d,e,f;
  a = m[8] * m[13] - m[9] * m[12];
  b = m[8] * m[14] - m[10] * m[12];
  c = m[8] * m[15] - m[11] * m[12];
  d = m[9] * m[14] - m[10] * m[13];
  e = m[9] * m[15] - m[11] * m[13];
  f = m[10] * m[15] - m[11] * m[14];
  *det = m[0] * m[5] * f - m[0] * m[6] * e + m[0] * m[7] * d - m[1] * m[4] * f +
         m[1] * m[6] * c - m[1] * m[7] * b + m[2] * m[4] * e - m[2] * m[5] * c +
         m[2] * m[7] * a - m[3] * m[4] * d + m[3] * m[5] * b - m[3] * m[6] * a;
  return;
 *det = m[3] * m[6] * m[9] * m[12] - m[2] * m[7] * m[9] * m[12] -
        m[3] * m[5] * m[10] * m[12] + m[1] * m[7] * m[10] * m[12] +
        m[2] * m[5] * m[11] * m[12] - m[1] * m[6] * m[11] * m[12] -
        m[3] * m[6] * m[8] * m[13] + m[2] * m[7] * m[8] * m[13] +
        m[3] * m[4] * m[10] * m[13] - m[0] * m[7] * m[10] * m[13] -
        m[2] * m[4] * m[11] * m[13] + m[0] * m[6] * m[11] * m[13] +
        m[3] * m[5] * m[8] * m[14] - m[1] * m[7] * m[8] * m[14] -
        m[3] * m[4] * m[9] * m[14] + m[0] * m[7] * m[9] * m[14] +
        m[1] * m[4] * m[11] * m[14] - m[0] * m[5] * m[11] * m[14] -
        m[2] * m[5] * m[8] * m[15] + m[1] * m[6] * m[8] * m[15] +
        m[2] * m[4] * m[9] * m[15] - m[0] * m[6] * m[9] * m[15] -
        m[1] * m[4] * m[10] * m[15] + m[0] * m[5] * m[10] * m[15];
}
