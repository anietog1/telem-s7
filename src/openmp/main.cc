#include "../common/definition.h"

double trapezoid(double x0, double xn, long long n) {
  double h = (xn - x0) / n;
  double acum = 0;

#pragma omp parallel for simd simdlen(8) reduction(+: acum)
  for(long long i = 1; i < n; ++i) {
    acum += f(x0 + h * i);
  }

  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main() {
  double a, b;
  a = LOWER_LIMIT;
  b = UPPER_LIMIT;
  long long n = N;
  const double t0 = omp_get_wtime();
  double result = trapezoid(a, b, n);
  const double t1 = omp_get_wtime();
  printf("Time(sec): %f\n", t1 - t0);
  print_result(a, b, n, result);
}
