#include "arm_neon.h"
#include <stdlib.h>

void int_matrix_mul_2x2(int* prod, int* m1, int* m2);
void int_matrix_mul_4x4(int* prod, int* m1, int* m2);
void mat4x4_trans_int_vector(int* trans, int* m);
void vector_matrix_det_4x4(int* det, int*m);
void int_dotprod(int* prod, int* v1, int* v2, int len);
