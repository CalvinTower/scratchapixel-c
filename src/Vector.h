#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vec3_float {
  float x, y, z;
} Vec3_float;

typedef struct Vec3_double {
  double x, y, z;
} Vec3_double;

typedef struct Vec3_int {
  int x, y, z;
} Vec3_int;

Vec3_float *Vec3_float_init(float x, float y, float z);
double Vec3_float_length(Vec3_float const *in);
Vec3_float *Vec3_float_add(Vec3_float const *a, Vec3_float const *b);
Vec3_float *Vec3_float_subtract(Vec3_float const *a, Vec3_float const *b);
Vec3_float *Vec3_float_multiply(Vec3_float const *in, float scale);
Vec3_float *Vec3_float_normalize(Vec3_float const *in);
float Vec3_float_dot(Vec3_float const *a, Vec3_float const *b);
Vec3_float *Vec3_float_cross(Vec3_float const *a, Vec3_float const *b);
void Vec3_float_destroy(Vec3_float *in);

Vec3_double *Vec3_double_init(double x, double y, double z);
double Vec3_double_length(Vec3_double const *in);
Vec3_double *Vec3_double_add(Vec3_double const *a, Vec3_double const *b);
Vec3_double *Vec3_double_subtract(Vec3_double const *a, Vec3_double const *b);
Vec3_double *Vec3_double_multiply(Vec3_double const *in, double scale);
Vec3_double *Vec3_double_normalize(Vec3_double const *in);
double Vec3_double_dot(Vec3_double const *a, Vec3_double const *b);
Vec3_double *Vec3_double_cross(Vec3_double const *a, Vec3_double const *b);
void Vec3_double_destroy(Vec3_double *in);

Vec3_int *Vec3_int_init(int x, int y, int z);
double Vec3_int_length(Vec3_int const *in);
Vec3_int *Vec3_int_add(Vec3_int const *a, Vec3_int const *b);
Vec3_int *Vec3_int_subtract(Vec3_int const *a, Vec3_int const *b);
Vec3_int *Vec3_int_multiply(Vec3_int const *in, int scale);
/* Note that this one will create a Vec3_float from a Vec3_int input */
Vec3_float *Vec3_int_normalize(Vec3_int const *in);
int Vec3_int_dot(Vec3_int const *a, Vec3_int const *b);
Vec3_int *Vec3_int_cross(Vec3_int const *a, Vec3_int const *b);
void Vec3_int_destroy(Vec3_int *in);

#endif
