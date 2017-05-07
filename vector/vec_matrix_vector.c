#include "vec_matrix_vector.h"
#include "arm_neon.h"
#include <stdio.h>

void int_matrix_mul_2x2(int* prod, int* m1, int* m2){
    
    int i;
    int32x2x2_t vec1;
    int32x2x2_t vec2;
    int32x2x2_t result;
    vec1 = vld2_s32(m1);
    vec2 = vld2_s32(m2);
    for(i = 0; i < 2; i++){
        int j;
        result.val[i] = vdup_n_s32(0);
            result.val[i] = vmla_lane_s32(result.val[i], vec1.val[0], vec2.val[i], 0);
            result.val[i] = vmla_lane_s32(result.val[i], vec1.val[1], vec2.val[i], 1);
    }
    vst2_s32(prod, result);
    return;
}

void int_matrix_mul_4x4(int* prod, int* m1, int* m2){
    
    int i;
    int32x4x4_t vec1;
    int32x4x4_t vec2;
    int32x2_t vec2_part;
    int32x4x4_t result;
    vec1 = vld4q_s32(m1);
    vec2 = vld4q_s32(m2);
    for(i = 0; i < 4; i++){
        int j;
        result.val[i] = vdupq_n_s32(0);
            vec2_part = vget_low_s32(vec2.val[i]);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[0], vec2_part, 0);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[1], vec2_part, 1);
            vec2_part = vget_high_s32(vec2.val[i]);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[2], vec2_part, 0);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[3], vec2_part, 1);
    }
    vst4q_s32(prod, result);
    return;
}
/*
void int_matrix_mul_4x4_v2(int* prod, int* m1, int* m2){
    
    int i;
    int32x4x4_t vec1;
    int32x4x4_t vec2;
    int32x2_t vec2_part;
    int32x4x4_t result;
    vec1 = vld4q_s32(m1);
    vec2 = vld4q_s32(m2);
    for(i = 0; i < 4; i++){
        int j;
        result.val[i] = vdupq_n_s32(0);
            vec2_part = vget_low_s32(vec2.val[i]);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[0], vec2_part, 0);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[1], vec2_part, 1);
            vec2_part = vget_high_s32(vec2.val[i]);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[2], vec2_part, 0);
            result.val[i] = vmlaq_lane_s32(result.val[i], vec1.val[3], vec2_part, 1);
    }
    vst4q_s32(prod, result);
    return;
}

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
    int m3[4];
    int m4[4];
    int result2[4];
    for(i = 0; i < 4; i++){
        m3[i] = i+4;
        m4[i] = 2 * i + 2;
    }
    int_matrix_mul_2x2(result2, m3, m4);
    for(i = 0; i < 4; i++){
        printf("%d ", result2[i]);
        if(i % 2 == 1) printf("\n");
    }
    int32x4_t test = vld1q_s32(m1);
    int sum = vqadd_s32(test,test);
    printf("%d\n", sum);
    return 0;
}
*/
