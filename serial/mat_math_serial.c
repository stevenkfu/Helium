void mat2x2_mult_int_serial(int *dst, int *src1, int *src2) {
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
