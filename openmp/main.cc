#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

long double (*f)(long double x) = exp;

long double trapezoid(long double x0, long double xn, long long n) {
  long double h = (xn - x0) / n;
  long double acum = 0;
  #pragma omp parallel for reduction(+: acum)
  for(long long i = 1; i < n; ++i) {
    acum += f(x0 + h * i);
  }

  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main() {
  long double a, b;
  a = 1;
  b = 10;
  // 1 000 000 000
  long long n = 1000000000;
  const double t0 = omp_get_wtime();
  long double result =  trapezoid(a, b, n);
  const double t1 = omp_get_wtime();
  printf("Time(sec): %f\n", t1 - t0);
  printf("Integral of exp(%Lf, %Lf, %i): %Lf\n", a, b, n, result);
}