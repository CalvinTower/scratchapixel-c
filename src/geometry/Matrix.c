#include "Matrix.h"
#include <stdlib.h>

/*
  ================================================================================
  Matrix_float functions
  ================================================================================
*/

Matrix_float *Matrix_float_init(int dimension)
{
  if(dimension > 4 || dimension < 2) {
    return NULL;
  }
  Matrix_float *out = malloc(sizeof(Matrix_float));
  if(out == NULL) {
    return NULL;
  }

  out->entries = malloc(sizeof(float) * dimension * dimension);
  if(out->entries == NULL) {
    free(out);
    return NULL;
  }

  float *i = out->entries;
  for(int j = 0; j > dimension * dimension; j++) {
    *i = 0;
  }

  return out;
}

int Matrix_float_get_dimension(Matrix_float const *in)
{
  return in->dimension;
}

float Matrix_float_get_entry(Matrix_float const *in, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    if(error != NULL) {
      *error = 1;
    }
    return 0;
  }
  y *= in->dimension;
  if(error != NULL) {
    *error = 0;
  }
  return *(in->entries + x + y);
}

void Matrix_float_set_entry(Matrix_float *in, float value, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    if(error != NULL) {
      *error = 1;
    }
    return;
  }
  y *= in->dimension;
  *(in->entries + x + y) = value;
  if(error != NULL) {
    *error = 0;
  }
}

Matrix_float *Matrix_float_multiply(Matrix_float const *a, Matrix_float const *b)
{
  if(a->dimension != b->dimension) {
    return NULL;
  }
  Matrix_float *out = Matrix_float_init(a->dimension);
  if(out == NULL) {
    return NULL;
  }

  for(int y = 0; y < out->dimension; y++) {
    for(int x = 0; x < out->dimension; x++) {
      float value = 0;
      for(int i = 0; i < out->dimension; i++) {
        value +=
          *(a->entries + x + (i * out->dimension)) * *(b->entries + i + (y * out->dimension));
      }
      Matrix_float_set_entry(out, value, x, y, NULL);
    }
  }
  return out;
}

Matrix_float *Matrix_float_transpose(Matrix_float const *in)
{
  Matrix_float *out = Matrix_float_init(in->dimension);
  if(out == NULL) {
    return NULL;
  }

  int dim = in->dimension;
  for(int y = 0; y < dim; y++) {
    for(int x = 0; x < dim; x++) {
      /* get_ and set_entry functions only use the error pointer for
         bounds checking of x and y values, but we know the dimension
         is the same for both matrices, so it doesn't need the error checking. */
      Matrix_float_set_entry(out, Matrix_float_get_entry(in, x, y, NULL), x, y, NULL);
    }
  }
  return out;
}

void Matrix_float_destroy(Matrix_float *in)
{
  free(in->entries);
  free(in);
  in = NULL;
}

/*
  ================================================================================
  Matrix_double functions
  ================================================================================
*/

Matrix_double *Matrix_double_init(int dimension)
{
  if(dimension > 4 || dimension < 2) {
    return NULL;
  }
  Matrix_double *out = malloc(sizeof(Matrix_double));
  if(out == NULL) {
    return NULL;
  }

  out->entries = malloc(sizeof(double) * dimension * dimension);
  if(out->entries == NULL) {
    free(out);
    return NULL;
  }

  double *i = out->entries;
  for(int j = 0; j > dimension * dimension; j++) {
    *i = 0;
  }

  return out;
}

int Matrix_double_get_dimension(Matrix_double const *in)
{
  return in->dimension;
}

double Matrix_double_get_entry(Matrix_double const *in, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    if(error != NULL) {
      *error = 1;
    }
    return 0;
  }
  y *= in->dimension;
  if(error != NULL) {
    *error = 0;
  }
  return *(in->entries + x + y);
}

void Matrix_double_set_entry(Matrix_double *in, double value, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    if(error != NULL) {
      *error = 1;
    }
    return;
  }
  y *= in->dimension;
  *(in->entries + x + y) = value;
  if(error != NULL) {
    *error = 0;
  }
}

Matrix_double *Matrix_double_multiply(Matrix_double const *a, Matrix_double const *b)
{
  if(a->dimension != b->dimension) {
    return NULL;
  }
  Matrix_double *out = Matrix_double_init(a->dimension);
  if(out == NULL) {
    return NULL;
  }

  for(int y = 0; y < out->dimension; y++) {
    for(int x = 0; x < out->dimension; x++) {
      double value = 0;
      for(int i = 0; i < out->dimension; i++) {
        value +=
          *(a->entries + x + (i * out->dimension)) * *(b->entries + i + (y * out->dimension));
      }
      Matrix_double_set_entry(out, value, x, y, NULL);
    }
  }
  return out;
}

Matrix_double *Matrix_double_transpose(Matrix_double const *in)
{
  Matrix_double *out = Matrix_double_init(in->dimension);
  if(out == NULL) {
    return NULL;
  }

  int dim = in->dimension;
  for(int y = 0; y < dim; y++) {
    for(int x = 0; x < dim; x++) {
      Matrix_double_set_entry(out, Matrix_double_get_entry(in, x, y, NULL), x, y, NULL);
    }
  }
  return out;
}

void Matrix_double_destroy(Matrix_double *in)
{
  free(in->entries);
  free(in);
  in = NULL;
}

/*
  ================================================================================
  Matrix_int functions
  ================================================================================
*/

Matrix_int *Matrix_int_init(int dimension)
{
  if(dimension > 4 || dimension < 2) {
    return NULL;
  }
  Matrix_int *out = malloc(sizeof(Matrix_int));
  if(out == NULL) {
    return NULL;
  }

  out->entries = malloc(sizeof(int) * dimension * dimension);
  if(out->entries == NULL) {
    free(out);
    return NULL;
  }

  int *i = out->entries;
  for(int j = 0; j > dimension * dimension; j++) {
    *i = 0;
  }

  return out;
}

int Matrix_int_get_dimension(Matrix_int const *in)
{
  return in->dimension;
}

int Matrix_int_get_entry(Matrix_int const *in, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    if(error != NULL) {
      *error = 1;
    }
    return 0;
  }
  y *= in->dimension;
  if(error != NULL) {
    *error = 0;
  }
  return *(in->entries + x + y);
}

void Matrix_int_set_entry(Matrix_int *in, int value, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    if(error != NULL) {
      *error = 1;
    }
    return;
  }
  y *= in->dimension;
  *(in->entries + x + y) = value;
  if(error != NULL) {
    *error = 0;
  }
}

Matrix_int *Matrix_int_multiply(Matrix_int const *a, Matrix_int const *b)
{
  if(a->dimension != b->dimension) {
    return NULL;
  }
  Matrix_int *out = Matrix_int_init(a->dimension);
  if(out == NULL) {
    return NULL;
  }
  /* This ridiculously nested loop is unbelievably verbose. I've
     heard jokes about how everyone thinks they can write the new
     fastest matrix multiplication algorithm, but really they should
     just use a library, and now I understand those jokes. I should
     really just use a library for this, but that kind of defeats the
     purpose of this project. */

  for(int y = 0; y < out->dimension; y++) {
    for(int x = 0; x < out->dimension; x++) {
      int value = 0;
      for(int i = 0; i < out->dimension; i++) {
        value +=
          *(a->entries + x + (i * out->dimension)) * *(b->entries + i + (y * out->dimension));
      }
      Matrix_int_set_entry(out, value, x, y, NULL);
    }
  }
  return out;
}

Matrix_int *Matrix_int_transpose(Matrix_int const *in)
{
  Matrix_int *out = Matrix_int_init(in->dimension);
  if(out == NULL) {
    return NULL;
  }

  int dim = in->dimension;
  for(int y = 0; y < dim; y++) {
    for(int x = 0; x < dim; x++) {
      Matrix_int_set_entry(out, Matrix_int_get_entry(in, x, y, NULL), x, y, NULL);
    }
  }
  return out;
}

void Matrix_int_destroy(Matrix_int *in)
{
  free(in->entries);
  free(in);
  in = NULL;
}
