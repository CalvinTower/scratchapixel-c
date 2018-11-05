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

float Matrix_float_get_entry(Matrix_float *in, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    *error = 1;
    return 0;
  }
  y *= in->dimension;
  *error = 0;
  return *(in->entries + x + y);
}

void Matrix_float_set_entry(Matrix_float *in, float value, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    *error = 1;
    return 0;
  }
  y *= in->dimension;
  *(in->entries + x + y) = value;
  *error = 0;
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

double Matrix_double_get_entry(Matrix_double *in, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    *error = 1;
    return 0;
  }
  y *= in->dimension;
  *error = 0;
  return *(in->entries + x + y);
}

void Matrix_double_set_entry(Matrix_double *in, double value, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    *error = 1;
    return 0;
  }
  y *= in->dimension;
  *(in->entries + x + y) = value;
  *error = 0;
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

int Matrix_int_get_entry(Matrix_int *in, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    *error = 1;
    return 0;
  }
  y *= in->dimension;
  *error = 0;
  return *(in->entries + x + y);
}

void Matrix_int_set_entry(Matrix_int *in, int value, int x, int y, int *error)
{
  if(x > (in->dimension - 1) || y > (in->dimension - 1)) {
    *error = 1;
    return 0;
  }
  y *= in->dimension;
  *(in->entries + x + y) = value;
  *error = 0;
}

void Matrix_int_destroy(Matrix_int *in)
{
  free(in->entries);
  free(in);
  in = NULL;
}
