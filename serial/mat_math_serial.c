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
 *det = m[0*4+3] * m[1*4+2] * m[2*4+1] * m[3*4+0] - m[0*4+2] * m[1*4+3] * m[2*4+1] * m[3*4+0] -
        m[0*4+3] * m[1*4+1] * m[2*4+2] * m[3*4+0] + m[0*4+1] * m[1*4+3] * m[2*4+2] * m[3*4+0] +
        m[0*4+2] * m[1*4+1] * m[2*4+3] * m[3*4+0] - m[0*4+1] * m[1*4+2] * m[2*4+3] * m[3*4+0] -
        m[0*4+3] * m[1*4+2] * m[2*4+0] * m[3*4+1] + m[0*4+2] * m[1*4+3] * m[2*4+0] * m[3*4+1] +
        m[0*4+3] * m[1*4+0] * m[2*4+2] * m[3*4+1] - m[0*4+0] * m[1*4+3] * m[2*4+2] * m[3*4+1] -
        m[0*4+2] * m[1*4+0] * m[2*4+3] * m[3*4+1] + m[0*4+0] * m[1*4+2] * m[2*4+3] * m[3*4+1] +
        m[0*4+3] * m[1*4+1] * m[2*4+0] * m[3*4+2] - m[0*4+1] * m[1*4+3] * m[2*4+0] * m[3*4+2] -
        m[0*4+3] * m[1*4+0] * m[2*4+1] * m[3*4+2] + m[0*4+0] * m[1*4+3] * m[2*4+1] * m[3*4+2] +
        m[0*4+1] * m[1*4+0] * m[2*4+3] * m[3*4+2] - m[0*4+0] * m[1*4+1] * m[2*4+3] * m[3*4+2] -
        m[0*4+2] * m[1*4+1] * m[2*4+0] * m[3*4+3] + m[0*4+1] * m[1*4+2] * m[2*4+0] * m[3*4+3] +
        m[0*4+2] * m[1*4+0] * m[2*4+1] * m[3*4+3] - m[0*4+0] * m[1*4+2] * m[2*4+1] * m[3*4+3] -
        m[0*4+1] * m[1*4+0] * m[2*4+2] * m[3*4+3] + m[0*4+0] * m[1*4+1] * m[2*4+2] * m[3*4+3];
}

void int_matrix_det_4x4_block(float *det, int *m) {
  int len = 4;
  float *m_a = malloc(len * len * sizeof(float*));
  float *m_b = malloc(len * len * sizeof(float*));
  float *m_c = malloc(len * len * sizeof(float*));
  float *m_d = malloc(len * len * sizeof(float*));
  m_a[0] = (float)(m[0*4+0]);
  m_a[1] = (float)(m[0*4+1]);
  m_a[2] = (float)(m[1*4+0]);
  m_a[3] = (float)(m[1*4+1]);
  m_b[0] = (float)(m[0*4+2]);
  m_b[1] = (float)(m[0*4+3]);
  m_b[2] = (float)(m[1*4+2]);
  m_b[3] = (float)(m[1*4+3]);
  m_c[0] = (float)(m[2*4+0]);
  m_c[1] = (float)(m[3*4+1]);
  m_c[2] = (float)(m[2*4+0]);
  m_c[3] = (float)(m[3*4+1]);
  m_d[0] = (float)(m[2*4+0]);
  m_d[1] = (float)(m[3*4+1]);
  m_d[2] = (float)(m[2*4+0]);
  m_c[3] = (float)(m[3*4+1]);
  float det_a = (m_a[0] * m_a[3]) - (m_a[1] * m_a[2]);
  float *inv_a = malloc(len * len * sizeof(float*));
  int res = mat2x2_inv_float_serial(inv_a, m_a);
  float *m_cainv = malloc(len * len * sizeof(float*));;
  mat2x2_mult_float_serial(m_cainv, m_c, inv_a);
  float *m_cainvb = malloc(len * len * sizeof(float*));;
  mat2x2_mult_float_serial(m_cainvb, m_cainv, m_b);
  float *m_dcainvb = malloc(len * len * sizeof(float*));;
  m_dcainvb[0] = m_d[0] - m_cainvb[0];
  m_dcainvb[1] = m_d[1] - m_cainvb[1];
  m_dcainvb[2] = m_d[2] - m_cainvb[2];
  m_dcainvb[3] = m_d[3] - m_cainvb[3];
  float det_dcainvb = (m_dcainvb[0] * m_dcainvb[3]) - (m_dcainvb[1] * m_dcainvb[2]);
  *det = det_a * det_dcainvb;
  
}
