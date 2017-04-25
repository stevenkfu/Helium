#include "vec_matrix_vector.h"
#include "arm_neon.h"
#include <stdio.h>

void int_matrix_mul_4x4(int* prod, int* m1, int* m2){
    
    int i;
    int32x4x4_t vec1;
    int32x2_t vec2_part;
    int32x4x4_t result;
    vec1 = vld4q_s32(m1);
    for(i = 0; i < 4; i++){
        int j;
        result.val[i] = vdupq_n_s32(0);
            vec2_part = vld1_s32(m2+i);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[0], vec2_part, 0);
            vec2_part = vld1_s32(m2+i+4);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[1], vec2_part, 0);
            vec2_part = vld1_s32(m2+i+8);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[2], vec2_part, 0);
            vec2_part = vld1_s32(m2+i+12);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[3], vec2_part, 0);
    }
    vst4q_s32(prod, result);
    return;
/*
    int32x4_t result = vmlaq_lane_s32(vec1.val[1], vec1.val[0],temp_vec, 1);
    for(i = 0; i < 4; i++){
        printf("%d\n", y[i]);
    }
    for(i = 0; i < 4; i++){
        printf("%d + 5 * %d = %d\n", vec1.val[1][i], vec1.val[0][i],result[i]);
    }
    return 0;
*/
}
/*
int main(){
    int m1[16];
    int m2[16];
    int result[16];
    int i;
    for(i = 0; i < 16; i++){
        m1[i] = i+2;
        m2[i] = 2 * i;
    }
    int_matrix_mul_4x4(result, m1, m2);
    for(i = 0; i < 16; i++){
        printf("%d ", result[i]);
        if(i % 4 == 3) printf("\n");
    }
    return 0;
}
*/
