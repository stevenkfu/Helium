#include "lodepng.h"
#include "mat_math_serial.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void decodeOneStep(const char* filename)
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
  float_conv_serial(output_gaus, gray, height, width, filter_gaussian, 7, 7);
  float_conv_serial(output_log, gray, height, width, filter_log, 7, 7);
  float_conv_serial(output_gaus_v, gray, height, width, filter_gaussian_v, 7, 7);
  float_conv_serial(output_gaus_h, gray, height, width, filter_gaussian_h, 7, 7);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time elapsed for 4 filters: %f\n", cpu_time_used);

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
  
  error = lodepng_encode32_file("Lenna_gaus.png", img_gaus, width, height);
  error = lodepng_encode32_file("Lenna_log.png", img_log, width, height);
  error = lodepng_encode32_file("Lenna_gaus_v.png", img_gaus_v, width, height);
  error = lodepng_encode32_file("Lenna_gaus_h.png", img_gaus_h, width, height);
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

  free(image);
  free(gray);
  free(img_gaus);
  free(img_log);
  free(img_gaus_v);
  free(img_gaus_h);
}

int main() {
 decodeOneStep("Lenna.png");
}
