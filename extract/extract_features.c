#include "lodepng.h"
#include "mat_math_serial.h"
#include "vec_matrix_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void float_dotprod_sequential(float *prod, float *v1, float *v2, int len) {
  float sum = 0;
  int i;
  for (i = 0; i < len; i++) {
    sum += v1[i] * v2[i];
  }
  *prod = sum;
}

void float_matrix_mul_helper_sequential(float* prod, float* m1, float* m2, int m_orig, int n_orig, int o_orig,
                    int m1_rb, int m1_re, int m1_cb, int m1_ce,
                    int m2_rb, int m2_re, int m2_cb, int m2_ce){
    int m = m1_re - m1_rb;
    int n = m2_re - m2_rb;
    int o = m2_ce - m2_cb;
    int i,j;
    if(m * n + n * o < 128000){
        for(i = 0; i < m; i++){
            for(j = 0; j < o; j++){ 
                float_dotprod_sequential(prod + (i * o_orig) + j, m1 + ((i + m1_rb) * n_orig + m1_cb), m2 + ((j + m2_cb) * n_orig + m2_rb), n);
            }
        }
        return;
    }
    else if(n > m && n > o){
        //cut n in half
        //allocate temporary array to hold product of the two to sum them together
        float* temp = (float*)malloc(sizeof(float) * m * o);
        float_matrix_mul_helper_sequential(prod, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_re, m1_cb, m1_cb + n/2, 
                       m2_rb, m2_rb + n/2, m2_cb, m2_ce);
        float_matrix_mul_helper_sequential(temp, m1, m2, m, n_orig, o,
                       m1_rb, m1_re, m1_cb + n/2, m1_ce,
                       m2_rb + n/2, m2_re, m2_cb, m2_ce);
        //sum together
        for(i = 0; i < m; i++){
           vec_add_float_serial(prod + i * o_orig, prod + i * o_orig, temp + i * o, o);
        }
        free(temp);
        return;
    }
    else if(m > o){
        //split m1 horizontally (cut m in half)
        float_matrix_mul_helper_sequential(prod, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_rb + m/2, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb, m2_ce);
        float_matrix_mul_helper_sequential(prod + (m/2 * o_orig), m1, m2, m_orig, n_orig, o_orig,
                       m1_rb + m/2, m1_re, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb, m2_ce);
        return;
    }
    else{
        //split m2 vertically (cut o in half)
        float_matrix_mul_helper_sequential(prod, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_re, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb, m2_cb + o/2);
        float_matrix_mul_helper_sequential(prod + o/2, m1, m2, m_orig, n_orig, o_orig,
                       m1_rb, m1_re, m1_cb, m1_ce,
                       m2_rb, m2_re, m2_cb + o/2, m2_ce);
        return;
    }
}

void mat_mult_float_serial_trans(float *dst, float *src1, float *src2, int s1r, int s1c, int s2r, int s2c) {
  float *src2_trans = (float*)malloc(s2c*s2r*sizeof(float));
  matmxn_trans_float_serial_cache(src2_trans, src2, s2r, s2c, 0, s2r, 0, s2c);
  float_matrix_mul_helper_sequential(dst, src1, src2_trans, s1r, s1c, s2c, 0, s1r, 0, s1c, 0, s2r, 0, s2c);
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

void run_float_conv_serial(float* dst, float* src_setup, int w, int h, float* filter, int f_w, int f_h){
    mat_mult_float_serial_trans(dst, src_setup, filter, w * h, f_w * f_h, f_w * f_h, 1);
}

void extractSerial(const char* filename)
{
  unsigned error;
  unsigned char* image;
  unsigned width, height;
  clock_t start, end;
  double cpu_time_used;

  error = lodepng_decode32_file(&image, &width, &height, filename);
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

  float *gray = malloc(sizeof(float) * width * height);
  int i,j;
  for (i = 0; i < height; i += 1) {
    for (j = 0; j < width * 4; j += 4) {
      //printf("%d %d %d %d\n", image[i*(width*4)+j], image[i*(width*4)+j+1], image[i*(width*4)+j+2], image[i*(width*4)+j+3]);
      gray[i*width+(j/4)] = 0.2989 * (float)(image[i*(width*4)+j]) + 0.5870 * (float)(image[i*(width*4)+j+1]) + 0.1140 * (float)(image[i*(width*4)+j+2]);
    }
    //printf("\n");
  }

  float filter_gaussian[49] = {.0000196519161240319,0.000239409349497270,0.00107295826497866,0.00176900911404382,0.00107295826497866,0.000239409349497270,.0000196519161240319,
      0.000239409349497270,0.00291660295438644,0.0130713075831894,0.0215509428482683,0.0130713075831894,0.00291660295438644,0.000239409349497270,
      0.00107295826497866,0.0130713075831894,0.0585815363306070,0.0965846250185641,0.0585815363306070,0.0130713075831894,0.00107295826497866,
      0.00176900911404382,0.0215509428482683,0.0965846250185641,0.159241125690702,0.0965846250185641,0.0215509428482683,0.00176900911404382,
      0.00107295826497866,0.0130713075831894,0.0585815363306070,0.0965846250185641,0.0585815363306070,0.0130713075831894,0.00107295826497866,
      0.000239409349497270,0.00291660295438644,0.0130713075831894,0.0215509428482683,0.0130713075831894,0.00291660295438644,0.000239409349497270,
      .0000196519161240319,0.000239409349497270,0.00107295826497866,0.00176900911404382,0.00107295826497866,0.000239409349497270,.0000196519161240319};
  float filter_log[49] = {0.000481288336109739,0.00280036052259520,0.00875052379795451,0.0125499214764320,0.00875052379795451,0.00280036052259520,0.000481288336109739,
      0.00280036052259520,0.0176664754044438,0.0393807804276934,0.0432687433746617,0.0393807804276934,0.0176664754044438,0.00280036052259520,
      0.00875052379795451,0.0393807804276934,0.000166857678125228,-0.0964177673404389,0.000166857678125228,0.0393807804276934,0.00875052379795451,
      0.0125499214764320,0.0432687433746617,-0.0964177673404389,-0.318315393703280,-0.0964177673404389,0.0432687433746617,0.0125499214764320,
      0.00875052379795451,0.0393807804276934,0.000166857678125228,-0.0964177673404389,0.000166857678125228,0.0393807804276934,0.00875052379795451,
      0.00280036052259520,0.0176664754044438,0.0393807804276934,0.0432687433746617,0.0393807804276934,0.0176664754044438,0.00280036052259520,
      0.000481288336109739,0.00280036052259520,0.00875052379795451,0.0125499214764320,0.00875052379795451,0.00280036052259520,0.000481288336109739};
  float filter_gaussian_v[49] = {0.000239409349497270,0.00105330634885463,0.00152959976454655,0,-0.00152959976454655,-0.00105330634885463,-0.000239409349497270,
      0.00291660295438644,0.0128318982336921,0.0186343398938818,0,-0.0186343398938818,-0.0128318982336921,-0.00291660295438644,
      0.0130713075831894,0.0575085780656284,0.0835133174353747,0,-0.0835133174353747,-0.0575085780656284,-0.0130713075831894,
      0.0215509428482683,0.0948156159045203,0.137690182842434,0,-0.137690182842434,-0.0948156159045203,-0.0215509428482683,
      0.0130713075831894,0.0575085780656284,0.0835133174353747,0,-0.0835133174353747,-0.0575085780656284,-0.0130713075831894,
      0.00291660295438644,0.0128318982336921,0.0186343398938818,0,-0.0186343398938818,-0.0128318982336921,-0.00291660295438644,
      0.000239409349497270,0.00105330634885463,0.00152959976454655,0,-0.00152959976454655,-0.00105330634885463,-0.000239409349497270};
  float filter_gaussian_h[49] = {0.000239409349497270,0.00291660295438644,0.0130713075831894,0.0215509428482683,0.0130713075831894,0.00291660295438644,0.000239409349497270,
      0.00105330634885463,0.0128318982336921,0.0575085780656284,0.0948156159045203,0.0575085780656284,0.0128318982336921,0.00105330634885463,
      0.00152959976454655,0.0186343398938818,0.0835133174353747,0.137690182842434,0.0835133174353747,0.0186343398938818,0.00152959976454655,
      0,0,0,0,0,0,0,
      -0.00152959976454655,-0.0186343398938818,-0.0835133174353747,-0.137690182842434,-0.0835133174353747,-0.0186343398938818,-0.00152959976454655,
      -0.00105330634885463,-0.0128318982336921,-0.0575085780656284,-0.0948156159045203,-0.0575085780656284,-0.0128318982336921,-0.00105330634885463,
      -0.000239409349497270,-0.00291660295438644,-0.0130713075831894,-0.0215509428482683,-0.0130713075831894,-0.00291660295438644,-0.000239409349497270};

  float output_gaus[width*height];
  float output_log[width*height];
  float output_gaus_v[width*height];
  float output_gaus_h[width*height];
  start = clock();
  for(i = 0; i < 1; i++){
    float_conv_serial(output_gaus, gray, height, width, filter_gaussian, 7, 7);
    //float_conv_serial(output_log, gray, height, width, filter_log, 7, 7);
    //float_conv_serial(output_gaus_v, gray, height, width, filter_gaussian_v, 7, 7);
    //float_conv_serial(output_gaus_h, gray, height, width, filter_gaussian_h, 7, 7);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for 4 filters serial: %f\n", cpu_time_used);

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_gaus[i*width+j] > 255.0) output_gaus[i*width+j] = 255.0;
      if (output_gaus[i*width+j] < 0.0) output_gaus[i*width+j] = 0.0;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_log[i*width+j] > 255.0) output_log[i*width+j] = 255.0;
      if (output_log[i*width+j] < 0.0) output_log[i*width+j] = 0.0;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_gaus_v[i*width+j] > 255.0) output_gaus_v[i*width+j] = 255.0;
      if (output_gaus_v[i*width+j] < 0.0) output_gaus_v[i*width+j] = 0.0;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_gaus_h[i*width+j] > 255.0) output_gaus_h[i*width+j] = 255.0;
      if (output_gaus_h[i*width+j] < 0.0) output_gaus_h[i*width+j] = 0.0;
    }
  }

  unsigned char* img_gaus = malloc(sizeof(char) * 4 * width * height);;
  unsigned char* img_log = malloc(sizeof(char) * 4 * width * height);;
  unsigned char* img_gaus_v = malloc(sizeof(char) * 4 * width * height);;
  unsigned char* img_gaus_h = malloc(sizeof(char) * 4 * width * height);;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_gaus[i*width+j];
      img_gaus[i*(width*4)+j*4] = color;
      img_gaus[i*(width*4)+j*4+1] = color;
      img_gaus[i*(width*4)+j*4+2] = color;
      img_gaus[i*(width*4)+j*4+3] = 255;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_log[i*width+j];
      img_log[i*(width*4)+j*4] = color;
      img_log[i*(width*4)+j*4+1] = color;
      img_log[i*(width*4)+j*4+2] = color;
      img_log[i*(width*4)+j*4+3] = 255;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_gaus_v[i*width+j];
      img_gaus_v[i*(width*4)+j*4] = color;
      img_gaus_v[i*(width*4)+j*4+1] = color;
      img_gaus_v[i*(width*4)+j*4+2] = color;
      img_gaus_v[i*(width*4)+j*4+3] = 255;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_gaus_h[i*width+j];
      img_gaus_h[i*(width*4)+j*4] = color;
      img_gaus_h[i*(width*4)+j*4+1] = color;
      img_gaus_h[i*(width*4)+j*4+2] = color;
      img_gaus_h[i*(width*4)+j*4+3] = 255;
    }
  }
  
  error = lodepng_encode32_file("Lenna_gaus_s.png", img_gaus, width, height);
  error = lodepng_encode32_file("Lenna_log_s.png", img_log, width, height);
  error = lodepng_encode32_file("Lenna_gaus_v_s.png", img_gaus_v, width, height);
  error = lodepng_encode32_file("Lenna_gaus_h_s.png", img_gaus_h, width, height);
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

  free(image);
  free(gray);
  free(img_gaus);
  free(img_log);
  free(img_gaus_v);
  free(img_gaus_h);
}

void extractVector(const char* filename)
{
  unsigned error;
  unsigned char* image;
  unsigned width, height;
  clock_t start, end;
  double cpu_time_used;

  error = lodepng_decode32_file(&image, &width, &height, filename);
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

  float *gray = malloc(sizeof(float) * width * height);
  int i,j;
  for (i = 0; i < height; i += 1) {
    for (j = 0; j < width * 4; j += 4) {
      //printf("%d %d %d %d\n", image[i*(width*4)+j], image[i*(width*4)+j+1], image[i*(width*4)+j+2], image[i*(width*4)+j+3]);
      gray[i*width+(j/4)] = 0.2989 * (float)(image[i*(width*4)+j]) + 0.5870 * (float)(image[i*(width*4)+j+1]) + 0.1140 * (float)(image[i*(width*4)+j+2]);
    }
    //printf("\n");
  }

  float filter_gaussian[49] = {.0000196519161240319,0.000239409349497270,0.00107295826497866,0.00176900911404382,0.00107295826497866,0.000239409349497270,.0000196519161240319,
      0.000239409349497270,0.00291660295438644,0.0130713075831894,0.0215509428482683,0.0130713075831894,0.00291660295438644,0.000239409349497270,
      0.00107295826497866,0.0130713075831894,0.0585815363306070,0.0965846250185641,0.0585815363306070,0.0130713075831894,0.00107295826497866,
      0.00176900911404382,0.0215509428482683,0.0965846250185641,0.159241125690702,0.0965846250185641,0.0215509428482683,0.00176900911404382,
      0.00107295826497866,0.0130713075831894,0.0585815363306070,0.0965846250185641,0.0585815363306070,0.0130713075831894,0.00107295826497866,
      0.000239409349497270,0.00291660295438644,0.0130713075831894,0.0215509428482683,0.0130713075831894,0.00291660295438644,0.000239409349497270,
      .0000196519161240319,0.000239409349497270,0.00107295826497866,0.00176900911404382,0.00107295826497866,0.000239409349497270,.0000196519161240319};
  float filter_log[49] = {0.000481288336109739,0.00280036052259520,0.00875052379795451,0.0125499214764320,0.00875052379795451,0.00280036052259520,0.000481288336109739,
      0.00280036052259520,0.0176664754044438,0.0393807804276934,0.0432687433746617,0.0393807804276934,0.0176664754044438,0.00280036052259520,
      0.00875052379795451,0.0393807804276934,0.000166857678125228,-0.0964177673404389,0.000166857678125228,0.0393807804276934,0.00875052379795451,
      0.0125499214764320,0.0432687433746617,-0.0964177673404389,-0.318315393703280,-0.0964177673404389,0.0432687433746617,0.0125499214764320,
      0.00875052379795451,0.0393807804276934,0.000166857678125228,-0.0964177673404389,0.000166857678125228,0.0393807804276934,0.00875052379795451,
      0.00280036052259520,0.0176664754044438,0.0393807804276934,0.0432687433746617,0.0393807804276934,0.0176664754044438,0.00280036052259520,
      0.000481288336109739,0.00280036052259520,0.00875052379795451,0.0125499214764320,0.00875052379795451,0.00280036052259520,0.000481288336109739};
  float filter_gaussian_v[49] = {0.000239409349497270,0.00105330634885463,0.00152959976454655,0,-0.00152959976454655,-0.00105330634885463,-0.000239409349497270,
      0.00291660295438644,0.0128318982336921,0.0186343398938818,0,-0.0186343398938818,-0.0128318982336921,-0.00291660295438644,
      0.0130713075831894,0.0575085780656284,0.0835133174353747,0,-0.0835133174353747,-0.0575085780656284,-0.0130713075831894,
      0.0215509428482683,0.0948156159045203,0.137690182842434,0,-0.137690182842434,-0.0948156159045203,-0.0215509428482683,
      0.0130713075831894,0.0575085780656284,0.0835133174353747,0,-0.0835133174353747,-0.0575085780656284,-0.0130713075831894,
      0.00291660295438644,0.0128318982336921,0.0186343398938818,0,-0.0186343398938818,-0.0128318982336921,-0.00291660295438644,
      0.000239409349497270,0.00105330634885463,0.00152959976454655,0,-0.00152959976454655,-0.00105330634885463,-0.000239409349497270};
  float filter_gaussian_h[49] = {0.000239409349497270,0.00291660295438644,0.0130713075831894,0.0215509428482683,0.0130713075831894,0.00291660295438644,0.000239409349497270,
      0.00105330634885463,0.0128318982336921,0.0575085780656284,0.0948156159045203,0.0575085780656284,0.0128318982336921,0.00105330634885463,
      0.00152959976454655,0.0186343398938818,0.0835133174353747,0.137690182842434,0.0835133174353747,0.0186343398938818,0.00152959976454655,
      0,0,0,0,0,0,0,
      -0.00152959976454655,-0.0186343398938818,-0.0835133174353747,-0.137690182842434,-0.0835133174353747,-0.0186343398938818,-0.00152959976454655,
      -0.00105330634885463,-0.0128318982336921,-0.0575085780656284,-0.0948156159045203,-0.0575085780656284,-0.0128318982336921,-0.00105330634885463,
      -0.000239409349497270,-0.00291660295438644,-0.0130713075831894,-0.0215509428482683,-0.0130713075831894,-0.00291660295438644,-0.000239409349497270};

  float output_gaus[width*height];
  float output_log[width*height];
  float output_gaus_v[width*height];
  float output_gaus_h[width*height];
  start = clock();
  float* temp = malloc(sizeof(float) * width * height * 49);
  float_conv_setup(temp, gray, height, width, 7,7);
  for(i = 0; i < 1; i++){
    run_float_conv(output_gaus, temp, height, width, filter_gaussian, 7, 7);
    //run_float_conv_serial(output_log, temp, height, width, filter_log, 7, 7);
    //run_float_conv_serial(output_gaus_v, temp, height, width, filter_gaussian_v, 7, 7);
    //run_float_conv_serial(output_gaus_h, temp, height, width, filter_gaussian_h, 7, 7);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for 4 filters vector: %f\n", cpu_time_used);

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_gaus[i*width+j] > 255.0) output_gaus[i*width+j] = 255.0;
      if (output_gaus[i*width+j] < 0.0) output_gaus[i*width+j] = 0.0;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_log[i*width+j] > 255.0) output_log[i*width+j] = 255.0;
      if (output_log[i*width+j] < 0.0) output_log[i*width+j] = 0.0;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_gaus_v[i*width+j] > 255.0) output_gaus_v[i*width+j] = 255.0;
      if (output_gaus_v[i*width+j] < 0.0) output_gaus_v[i*width+j] = 0.0;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (output_gaus_h[i*width+j] > 255.0) output_gaus_h[i*width+j] = 255.0;
      if (output_gaus_h[i*width+j] < 0.0) output_gaus_h[i*width+j] = 0.0;
    }
  }

  unsigned char* img_gaus = malloc(sizeof(char) * 4 * width * height);;
  unsigned char* img_log = malloc(sizeof(char) * 4 * width * height);;
  unsigned char* img_gaus_v = malloc(sizeof(char) * 4 * width * height);;
  unsigned char* img_gaus_h = malloc(sizeof(char) * 4 * width * height);;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_gaus[i*width+j];
      img_gaus[i*(width*4)+j*4] = color;
      img_gaus[i*(width*4)+j*4+1] = color;
      img_gaus[i*(width*4)+j*4+2] = color;
      img_gaus[i*(width*4)+j*4+3] = 255;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_log[i*width+j];
      img_log[i*(width*4)+j*4] = color;
      img_log[i*(width*4)+j*4+1] = color;
      img_log[i*(width*4)+j*4+2] = color;
      img_log[i*(width*4)+j*4+3] = 255;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_gaus_v[i*width+j];
      img_gaus_v[i*(width*4)+j*4] = color;
      img_gaus_v[i*(width*4)+j*4+1] = color;
      img_gaus_v[i*(width*4)+j*4+2] = color;
      img_gaus_v[i*(width*4)+j*4+3] = 255;
    }
  }
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color = output_gaus_h[i*width+j];
      img_gaus_h[i*(width*4)+j*4] = color;
      img_gaus_h[i*(width*4)+j*4+1] = color;
      img_gaus_h[i*(width*4)+j*4+2] = color;
      img_gaus_h[i*(width*4)+j*4+3] = 255;
    }
  }
  
  error = lodepng_encode32_file("Lenna_gaus_v.png", img_gaus, width, height);
  error = lodepng_encode32_file("Lenna_log_v.png", img_log, width, height);
  error = lodepng_encode32_file("Lenna_gaus_v_v.png", img_gaus_v, width, height);
  error = lodepng_encode32_file("Lenna_gaus_h_v.png", img_gaus_h, width, height);
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

  free(image);
  free(gray);
  free(img_gaus);
  free(img_log);
  free(img_gaus_v);
  free(img_gaus_h);
}

int main() {
 extractSerial("Lenna.png");
 extractVector("Lenna.png");
}
