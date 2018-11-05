#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>               /* NAN */

/* All of these are square matrices. They all will have a dimension
   between 2 and 4 inclusive, such that 2 >= dimension >= 4. */

typedef struct Matrix_float {
  int dimension;
  float *entries;
} Matrix_float;

typedef struct Matrix_double {
  int dimension;
  float *entries;
} Matrix_double;

typedef struct Matrix_int {
  int dimension;
  int *entries;
} Matrix_int;

Matrix_float *Matrix_float_init(int dimension);
float Matrix_float_get_entry(Matrix_float const *in, int x, int y, int *error);
void Matrix_float_set_entry(Matrix_float *in, float value, int x, int y, int *error);
void Matrix_float_destroy(Matrix_float *in);

Matrix_double *Matrix_double_init(int dimension);
double Matrix_double_get_entry(Matrix_double const *in, int x, int y, int *error);
void Matrix_double_set_entry(Matrix_double *in, double value, int x, int y, int *error);
void Matrix_double_destroy(Matrix_double *in);

Matrix_int *Matrix_int_init(int dimension);
int Matrix_int_get_entry(Matrix_int const *in, int x, int y, int *error);
void Matrix_int_set_entry(Matrix_int *in, int value, int x, int y, int *error);
void Matrix_int_destroy(Matrix_int *in);

#endif
