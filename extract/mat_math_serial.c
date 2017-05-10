#include <stdlib.h>
#include "vec_math_serial.h"
#include <stdio.h>

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
void matmxn_trans_int_serial_cache1(int *dst, int *src, int rows, int cols, int rb, int re, int cb, int ce) {
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
    matmxn_trans_int_serial_cache1(dst, src, rows, cols, rb, rb + (r / 2), cb, ce);
    matmxn_trans_int_serial_cache1(dst, src, rows, cols, rb + (r / 2), re, cb, ce);
  }
  else {
    matmxn_trans_int_serial_cache1(dst, src, rows, cols, rb, re, cb, cb + (c / 2));
    matmxn_trans_int_serial_cache1(dst, src, rows, cols, rb, re, cb + (c / 2), ce);
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

void mat_mult_int_serial(int *dst, int *src1, int *src2, int s1r, int s1c, int s2r, int s2c) {
  int i, j, k, l, m, n;
  int blocksize = 2048;
  for (i = 0; i < s2r; i += blocksize) {
    for (j = 0; j < s2c; j += blocksize) {
      for (k = 0; k < s1r; k++) {
        for (m = j; m < s2c && m < j + blocksize; m++) {
          int sum = 0;
          for (n = i; n < s1c && m < i + blocksize; n++) {
            sum += src1[k*s1c+n] * src2[n*s2c+m];
          }
          dst[k*s2c+m] = sum;
        }
      }
    }
  }
}

void int_dotprod_serial(int *prod, int *v1, int *v2, int len) {
  int sum = 0;
  int i;
  for (i = 0; i < len; i++) {
    sum += v1[i] * v2[i];
  }
  *prod = sum;
}

void int_matrix_mul_helper_serial(int* prod, int* m1, int* m2, int m_orig, int n_orig, int o_orig,
                    int m1_rb, int m1_re, int m1_cb, int m1_ce,
                    int m2_rb, int m2_re, int m2_cb, int m2_ce){
    int m = m1_re - m1_rb;
    int n = m2_re - m2_rb;
    int o = m2_ce - m2_cb;
    int i,j;
    if(m * n + n * o < 256000){
        for(i = 0; i < m; i++){
            for(j = 0; j < o; j++){ 
                int_dotprod_serial(prod + (i * o_orig) + j, m1 + ((i + m1_rb) * n_orig + m1_cb), m2 + ((j + m2_cb) * n_orig + m2_rb), n);
            }
        }
        return;
    }
    else if(n > m && n > o){
        //cut n in half
        //allocate temporary array to hold product of the two to sum them together
        int* temp = malloc(sizeof(int) * m * o);
        int_matrix_mul_helper_serial(prod, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_re, m1_cb, m1_cb + n/2, 
                       m2_rb, m2_rb + n/2, m2_cb, m2_ce);
        int_matrix_mul_helper_serial(temp, m1, m2, m, n_orig, o,
                       m1_rb, m1_re, m1_cb + n/2, m1_ce,
                       m2_rb + n/2, m2_re, m2_cb, m2_ce);
        //sum together
        for(i = 0; i < m; i++){
           vec_add_int_serial(prod + i * o_orig, prod + i * o_orig, temp + i * o, o);
        }
        free(temp);
        return;
    }
    else if(m > o){
        //split m1 horizontally (cut m in half)
        int_matrix_mul_helper_serial(prod, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_rb + m/2, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb, m2_ce);
        int_matrix_mul_helper_serial(prod + (m/2 * o_orig), m1, m2, m_orig, n_orig, o_orig,
                       m1_rb + m/2, m1_re, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb, m2_ce);
        return;
    }
    else{
        //split m2 vertically (cut o in half)
        int_matrix_mul_helper_serial(prod, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_re, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb, m2_cb + o/2);
        int_matrix_mul_helper_serial(prod + o/2, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_re, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb + o/2, m2_ce);
        return;
    }
}

void mat_mult_int_serial_trans(int *dst, int *src1, int *src2, int s1r, int s1c, int s2r, int s2c) {
  int *src2_trans = malloc(s2c*s2r*sizeof(int*));
  matmxn_trans_int_serial_cache1(src2_trans, src2, s2r, s2c, 0, s2r, 0, s2c);
  int_matrix_mul_helper_serial(dst, src1, src2_trans, s1r, s1c, s2c, 0, s1r, 0, s1c, 0, s2r, 0, s2c);
  /*
  int i, j, k;
  for (i = 0; i < s1r; i++) {
    for (j = 0; j < s2c; j++) {
      int sum = 0;
      for (k = 0; k < s2r; k++) {
        sum += src1[i*s1c+k] * src2_trans[j*s2r+k];
      }
      dst[i*s2c+j] = sum;
    }
  }
  */
}

void mat_mult_int_serial_naive(int *dst, int *src1, int *src2, int s1r, int s1c, int s2r, int s2c) {
  int i, j, k;
  for (i = 0; i < s1r; i++) {
    for (j = 0; j < s2c; j++) {
      int sum = 0;
      for (k = 0; k < s1c; k++) {
        sum += src1[i*s1c+k] * src2[k*s2c+j];
      }
      dst[i*s2c+j] = sum;
    }
  }
}

void int_conv_serial(int* dst, int* src, int w, int h, int* filter, int f_w, int f_h) {
  int i, j, k, l;
  int m, n;
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      int total = 0;
      for (k = -f_h/2; k < f_h/2+1; k++) {
        for (l = -f_w/2; l < f_w/2+1; l++) {
          m = i + k;
          n = j + l;
          if (m >= 0 && m < h && n >= 0 && n < w) {
            total += src[m*w+n] * filter[(k+f_h/2)*f_w+(l+f_w/2)];
          }
        }
      }
      dst[i*w+j] = total;
    }
  }
}

void float_conv_serial(float* dst, float* src, int w, int h, float* filter, int f_w, int f_h) {
  int i, j, k, l;
  int m, n;
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      float total = 0;
      for (k = -f_h/2; k < f_h/2+1; k++) {
        for (l = -f_w/2; l < f_w/2+1; l++) {
          m = i + k;
          n = j + l;
          if (m >= 0 && m < h && n >= 0 && n < w) {
            total += src[m*w+n] * filter[(k+f_h/2)*f_w+(l+f_w/2)];
          }
        }
      }
      dst[i*w+j] = total;
    }
  }
}
