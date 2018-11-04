#include "Vector.h"
#include <math.h>
#include <stdlib.h>

/*
================================================================================
 Vector3_float functions
================================================================================
*/

Vector3_float *Vector3_float_init(float x, float y, float z)
{
  Vector3_float *res = malloc(sizeof(Vector3_float));
  if(res == NULL) {
    return NULL;
  }
  res->x = x;
  res->y = y;
  res->z = z;

  return res;
}

double *Vector3_float_length(Vector3_float *in)
{
  return sqrt((in->x * in->x) + (in-y * in->y) + (in->z * in->z));
}

/*
================================================================================
Vector3_double functions
================================================================================
*/

Vector3_double *Vector3_double_init(double x, double y, double z)
{
  Vector3_double *res = malloc(sizeof(Vector3_double));
  if(res == NULL) {
    return NULL;
  }
  res->x = x;
  res->y = y;
  res->z = z;

  return res;
}

double *Vector3_double_length(Vector3_double *in)
{
  return sqrt((in->x * in->x) + (in-y * in->y) + (in->z * in->z));
}

/*
================================================================================
Vector3_int functions
================================================================================
*/

Vector3_int *Vector3_int_init(int x, int y, int z)
{
  Vector3_int *res = malloc(sizeof(Vector3_int));
  if(res == NULL) {
    return NULL;
  }
  res->x = x;
  res->y = y;
  res->z = z;

  return res;
}

double *Vector3_int_length(Vector3_int *in)
{
  return sqrt((in->x * in->x) + (in-y * in->y) + (in->z * in->z));
}
