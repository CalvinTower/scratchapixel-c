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

double Vector3_float_length(Vector3_float const *in)
{
  return sqrt((in->x * in->x) + (in->y * in->y) + (in->z * in->z));
}

Vector3_float *Vector3_float_normalize(Vector3_float const *in)
{
  double magnitude = Vector3_float_length(in);
  if(magnitude == 0) {
    return NULL;
  }
  /* Create a temporary variable for the inverted magnitude of the
     incoming vector; multiplication is faster, and should be favored
     for such a commonly used function */
  double inverted_magnitude = 1 / magnitude;

  /* I'm not sure if multiplying by a double will leave it promoted
     to a double when it gets passed to the funciton, so I'm giving
     it an explicit cast for safety */
  Vector3_float *out = Vector3_float_init((float) in->x * inverted_magnitude,
                                          (float) in->y * inverted_magnitude,
                                          (float) in->z * inverted_magnitude);
  if(out == NULL) {
    return NULL;
  }
  return out;
}

float Vector3_float_dot(Vector3_float const *a, Vector3_float const *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
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

double Vector3_double_length(Vector3_double const *in)
{
  return sqrt((in->x * in->x) + (in->y * in->y) + (in->z * in->z));
}

Vector3_double *Vector3_double_normalize(Vector3_double const *in)
{
  double magnitude = Vector3_double_length(in);
  if(magnitude == 0) {
    return NULL;
  }
  /* "Maybe this is premature optimization", I hear you say. "Creating
     a temporary variable to use multiplication instead of division
     obfuscates your code and makes it less readable" Yeah sure, but
     the instructional material has me do it explicitly, so I'm going
     for it. */
  double inverted_magnitude = 1 / magnitude;

  Vector3_double *out = Vector3_double_init(in->x * inverted_magnitude,
                                            in->y * inverted_magnitude,
                                            in->z * inverted_magnitude);
  if(out == NULL) {
    return NULL;
  }
  return out;
}

double Vector3_double_dot(Vector3_double const *a, Vector3_double const *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
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

double Vector3_int_length(Vector3_int const *in)
{
  return sqrt((in->x * in->x) + (in->y * in->y) + (in->z * in->z));
}

/* DANGER This function returns a Vector3_float *, not a Vector3_int *
   It returns the float version because in terms of amount of
   precision in a data type, float is closer to int than double. */
Vector3_float *Vector3_int_normalize(Vector3_int const *in)
{
  double magnitude = Vector3_int_length(in);
  if(magnitude == 0) {
    return NULL;
  }
  /* Again we create the temporary variable */
  double inverted_magnitude = (1 / Vector3_int_length(in));

  /* And again the explcit casts */
  Vector3_float *out = Vector3_float_init((float) in->x * inverted_magnitude,
                                          (float) in->y * inverted_magnitude,
                                          (float) in->z * inverted_magnitude);
  if(out == NULL) {
    return NULL;
  }
  return out;
}

int Vector3_int_dot(Vector3_int const *a, Vector3_int const *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}
