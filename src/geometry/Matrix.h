#ifndef MATRIX_H
#define MATRIX_H

/* All of these are square matrices. They all will have a dimension
   between 2 and 4 inclusive, such that 2 >= dimension >= 4. */

typedef struct Matrix_float {
  int dimension;
  float *entries;
} Matrix_float;

typedef struct Matrix_double {
  int dimension;
  double *entries;
} Matrix_double;

typedef struct Matrix_int {
  int dimension;
  int *entries;
} Matrix_int;

Matrix_float *Matrix_float_init(int dimension);
int Matrix_float_get_dimension(Matrix_float const *in);
float Matrix_float_get_entry(Matrix_float const *in, int x, int y, int *error);
void Matrix_float_set_entry(Matrix_float *in, float value, int x, int y, int *error);
Matrix_float *Matrix_float_multiply(Matrix_float const *a, Matrix_float const *b);
Matrix_float *Matrix_float_transpose(Matrix_float const *in);
void Matrix_float_destroy(Matrix_float *in);

Matrix_double *Matrix_double_init(int dimension);
int Matrix_double_get_dimension(Matrix_double const *in);
double Matrix_double_get_entry(Matrix_double const *in, int x, int y, int *error);
void Matrix_double_set_entry(Matrix_double *in, double value, int x, int y, int *error);
Matrix_double *Matrix_double_multiply(Matrix_double const *a, Matrix_double const *b);
Matrix_double *Matrix_double_transpose(Matrix_double const *in);
void Matrix_double_destroy(Matrix_double *in);

Matrix_int *Matrix_int_init(int dimension);
int Matrix_int_get_dimension(Matrix_int const *in);
int Matrix_int_get_entry(Matrix_int const *in, int x, int y, int *error);
void Matrix_int_set_entry(Matrix_int *in, int value, int x, int y, int *error);
Matrix_int *Matrix_int_multiply(Matrix_int const *a, Matrix_int const *b);
Matrix_int *Matrix_int_transpose(Matrix_int const *in);
void Matrix_int_destroy(Matrix_int *in);

#endif
