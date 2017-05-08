#include <stdlib.h>

void mat2x2_mult_int_serial(int *dst, int *src1, int *src2) {
  dst[0] = src1[0]*src2[0] + src1[1]*src2[2];
  dst[1] = src1[0]*src2[1] + src1[1]*src2[3];
  dst[2] = src1[2]*src2[0] + src1[3]*src2[2];
  dst[3] = src1[2]*src2[1] + src1[3]*src2[3];
}

void mat2x2_mult_float_serial(float *dst, float *src1, float *src2) {
  dst[0] = src1[0]*src2[0] + src1[1]*src2[2];
  dst[1] = src1[0]*src2[1] + src1[1]*src2[3];
  dst[2] = src1[2]*src2[0] + src1[3]*src2[2];
  dst[3] = src1[2]*src2[1] + src1[3]*src2[3];
}

void mat4x4_mult_int_serial(int *dst, int *src1, int*src2) {
  dst[0] = src1[0]*src2[0]+src1[1]*src2[4]+src1[2]*src2[8]+src1[3]*src2[12];
  dst[1] = src1[0]*src2[1]+src1[1]*src2[5]+src1[2]*src2[9]+src1[3]*src2[13];
  dst[2] = src1[0]*src2[2]+src1[1]*src2[6]+src1[2]*src2[10]+src1[3]*src2[14];
  dst[3] = src1[0]*src2[3]+src1[1]*src2[7]+src1[2]*src2[11]+src1[3]*src2[15];
  dst[4] = src1[4]*src2[0]+src1[5]*src2[4]+src1[6]*src2[8]+src1[7]*src2[12];
  dst[5] = src1[4]*src2[1]+src1[5]*src2[5]+src1[6]*src2[9]+src1[7]*src2[13];
  dst[6] = src1[4]*src2[2]+src1[5]*src2[6]+src1[6]*src2[10]+src1[7]*src2[14];
  dst[7] = src1[4]*src2[3]+src1[5]*src2[7]+src1[6]*src2[11]+src1[7]*src2[15];
  dst[8] = src1[8]*src2[0]+src1[9]*src2[4]+src1[10]*src2[8]+src1[11]*src2[12];
  dst[9] = src1[8]*src2[1]+src1[9]*src2[5]+src1[10]*src2[9]+src1[11]*src2[13];
  dst[10] = src1[8]*src2[2]+src1[9]*src2[6]+src1[10]*src2[10]+src1[11]*src2[14];
  dst[11] = src1[8]*src2[3]+src1[9]*src2[7]+src1[10]*src2[11]+src1[11]*src2[15];
  dst[12] = src1[12]*src2[0]+src1[13]*src2[4]+src1[14]*src2[8]+src1[15]*src2[12];
  dst[13] = src1[12]*src2[1]+src1[13]*src2[5]+src1[14]*src2[9]+src1[15]*src2[13];
  dst[14] = src1[12]*src2[2]+src1[13]*src2[6]+src1[14]*src2[10]+src1[15]*src2[14];
  dst[15] = src1[12]*src2[3]+src1[13]*src2[7]+src1[14]*src2[11]+src1[15]*src2[15];
}

void mat2x2_trans_int_serial(int *dst, int *src) {
  dst[0] = src[0];
  dst[1] = src[2];
  dst[2] = src[1];
  dst[3] = src[3];
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

//don't use, slower than above
void matmxn_trans_int_serial(int *dst, int *src, int rows, int cols) {
  int i, j, k, l;
  int blocksize = 256;
  for (i = 0; i < rows; i += blocksize) {
    for (j = 0; j < cols; j += blocksize) {
      for (k = i; k < rows && k < i + blocksize; k++) {
        for (l = j; l < cols && l < j + blocksize; l++) {
          dst[k * cols + l] = src[l * rows + k];
        }
      }
    }
  }
}
