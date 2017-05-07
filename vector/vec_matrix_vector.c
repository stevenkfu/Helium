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

void mat4x4_trans_int_vector(int* trans, int* m){
    int i;
    int32x4x4_t vec;
    vec = vld4q_s32(m);
    for(i = 0; i < 4; i++){
        vst1q_s32(trans+4*i, vec.val[i]);
    }
    return;
}

void mat4x4_determinant_int_vector(int* determinant, int* m){
    //first find 3x3 determinants 
    int32x4_t sub_3x3;
    int32x4_t firstRow = vld1q_s32(m);
    int32x4_t secondRow = vld1q_s32(m+4);
    //find first 3x3 determinant
    int32x4_t temp, temp2;
    int a,b,c,d,e,f;
    a = m[8] * m[13] - m[9] * m[12];
    b = m[8] * m[14] - m[10] * m[12];
    c = m[8] * m[15] - m[11] * m[12];
    d = m[9] * m[14] - m[10] * m[13];
    e = m[9] * m[15] - m[11] * m[13];
    f = m[10] * m[15] - m[11] * m[14];
    temp[0] = 0;
    temp[1] = f;
    temp[2] = e;
    temp[3] = d;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[0] = temp2[1] - temp2[2] + temp2[3];
    temp[0] = f;
    temp[2] = c;
    temp[3] = b;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[1] = temp2[0] - temp2[2] + temp2[3];
    temp[0] = e;
    temp[1] = c;
    temp[3] = a;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[2] = temp2[0] - temp2[1] + temp2[3];
    temp[0] = d;
    temp[1] = b;
    temp[2] = a;
    temp2 = vmulq_s32(temp, secondRow);
    sub_3x3[3] = temp2[0] - temp2[1] + temp2[2];
    //multiply 3x3 determinants by first row
    temp = vmulq_s32(sub_3x3, firstRow);
    *determinant = temp[0] - temp[1] + temp[2] - temp[3];
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
*/
int main(){//({5,1,25,2},{61,5,12,3},{15,52,32,5},{17,8246,44,2})
    int m[16];
    m[0] = 5;
    m[1] = 1;
    m[2] = 25;
    m[3] = 2;
    m[4] = 61;
    m[5] = 5;
    m[6] = 12;
    m[7] = 3;
    m[8] = 15;
    m[9] = 52;
    m[10] = 32;
    m[11] = 5;
    m[12] = 16;
    m[13] = 8246;
    m[14] = 44;
    m[15] = 2;
    int determinant;
    mat4x4_determinant_int_vector(&determinant, m);
    printf("%d\n", determinant);
    return 0;
}
