#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector3_float {
  float x, y, z;
} Vector3_float;

typedef struct Vector3_double {
  double x, y, z;
} Vector3_double;

typedef struct Vector3_int {
  int x, y, z;
} Vector3_int;

Vector3_float *Vector3_float_init(float x, float y, float z);
double Vector3_float_length(Vector3_float *in);
Vector3_float *Vector3_float_normalize(Vector3_float const *in);

Vector3_double *Vector3_double_init(double x, double y, double z);
double Vector3_double_length(Vector3_double *in);
Vector3_float *Vector3_double_normalize(Vector3_double const *in);

Vector3_int *Vector3_int_init(int x, int y, int z);
double Vector3_int_length(Vector3_int *in);
