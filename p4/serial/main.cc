#include "../common/definition.h"

double_type trapezoid(double_type x0, double_type xn, n_type n) {
  double_type h = (xn - x0) / n;
  double_type acum = 0;

  for(n_type i = 1; i < n; ++i) {
    acum += fs(x0 + h * i);
  }

  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main() {
  double_type a, b;
  a = LOWER_LIMIT;
  b = UPPER_LIMIT;
  n_type n = N;
  const double t0 = omp_get_wtime();
  double_type result =  trapezoid(a, b, n);
  const double t1 = omp_get_wtime();
  printf("Time(sec): %f\n", t1 - t0);
  print_result(a,b, n, result);
}