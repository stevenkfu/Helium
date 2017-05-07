void mat2x2_mult_int_serial(int *dst, int *src1, int *src2);
void mat2x2_mult_float_serial(float *dst, float *src1, float *src2);
void mat4x4_mult_int_serial(int *dst, int *src1, int *src2);
void mat2x2_trans_int_serial(int *dst, int *src);
void mat4x4_trans_int_serial(int *dst, int *src);
void int_matrix_det_2x2(int* det, int* m);
int mat2x2_inv_float_serial(float *dst, float *src);
void int_matrix_det_4x4(int *det, int *m);
void int_matrix_det_4x4_block(float *det, int *m);
