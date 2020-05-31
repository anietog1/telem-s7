#include "definition.h"

#pragma omp declare simd simdlen(8)
double f(const double x) {
  return exp(x);
}

double fs(const double x) {
  return exp(x);
}

void print_result(double a, double b, long long n, double result) {
  printf("Integral of exp(%f, %f, %lu): %f\n", a, b, n, result);
}
