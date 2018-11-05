#include "Vector.h"
#include <math.h>
#include <stdlib.h>

/*
================================================================================
 Vec3_float functions
================================================================================
*/

Vec3_float *Vec3_float_init(float x, float y, float z)
{
  Vec3_float *res = malloc(sizeof(Vec3_float));
  if(res == NULL) {
    return NULL;
  }
  res->x = x;
  res->y = y;
  res->z = z;

  return res;
}

double Vec3_float_length(Vec3_float const *in)
{
  return sqrt((in->x * in->x) + (in->y * in->y) + (in->z * in->z));
}

Vec3_float *Vec3_float_normalize(Vec3_float const *in)
{
  double magnitude = Vec3_float_length(in);
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
  Vec3_float *out = Vec3_float_init((float) in->x * inverted_magnitude,
                                          (float) in->y * inverted_magnitude,
                                          (float) in->z * inverted_magnitude);
  if(out == NULL) {
    return NULL;
  }
  return out;
}

float Vec3_float_dot(Vec3_float const *a, Vec3_float const *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

/*
================================================================================
Vec3_double functions
================================================================================
*/

Vec3_double *Vec3_double_init(double x, double y, double z)
{
  Vec3_double *res = malloc(sizeof(Vec3_double));
  if(res == NULL) {
    return NULL;
  }
  res->x = x;
  res->y = y;
  res->z = z;

  return res;
}

double Vec3_double_length(Vec3_double const *in)
{
  return sqrt((in->x * in->x) + (in->y * in->y) + (in->z * in->z));
}

Vec3_double *Vec3_double_normalize(Vec3_double const *in)
{
  double magnitude = Vec3_double_length(in);
  if(magnitude == 0) {
    return NULL;
  }
  /* "Maybe this is premature optimization", I hear you say. "Creating
     a temporary variable to use multiplication instead of division
     obfuscates your code and makes it less readable" Yeah sure, but
     the instructional material has me do it explicitly, so I'm going
     for it. */
  double inverted_magnitude = 1 / magnitude;

  Vec3_double *out = Vec3_double_init(in->x * inverted_magnitude,
                                            in->y * inverted_magnitude,
                                            in->z * inverted_magnitude);
  if(out == NULL) {
    return NULL;
  }
  return out;
}

double Vec3_double_dot(Vec3_double const *a, Vec3_double const *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

/*
================================================================================
Vec3_int functions
================================================================================
*/

Vec3_int *Vec3_int_init(int x, int y, int z)
{
  Vec3_int *res = malloc(sizeof(Vec3_int));
  if(res == NULL) {
    return NULL;
  }
  res->x = x;
  res->y = y;
  res->z = z;

  return res;
}

double Vec3_int_length(Vec3_int const *in)
{
  return sqrt((in->x * in->x) + (in->y * in->y) + (in->z * in->z));
}

/* DANGER This function returns a Vec3_float *, not a Vec3_int *
   It returns the float version because in terms of amount of
   precision in a data type, float is closer to int than double. */
Vec3_float *Vec3_int_normalize(Vec3_int const *in)
{
  double magnitude = Vec3_int_length(in);
  if(magnitude == 0) {
    return NULL;
  }
  /* Again we create the temporary variable */
  double inverted_magnitude = (1 / Vec3_int_length(in));

  /* And again the explcit casts */
  Vec3_float *out = Vec3_float_init((float) in->x * inverted_magnitude,
                                          (float) in->y * inverted_magnitude,
                                          (float) in->z * inverted_magnitude);
  if(out == NULL) {
    return NULL;
  }
  return out;
}

int Vec3_int_dot(Vec3_int const *a, Vec3_int const *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}
