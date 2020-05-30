#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
typedef double double_type;

double_type (*f)(double_type x) = exp;

double_type trapezoid(double_type x0, double_type xn, long long n) {
  double_type h = (xn - x0) / n;
  double_type acum = 0;

  for(long long i = 1; i < n; ++i) {
    acum += f(x0 + h * i);
  }

  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main() {
  double_type a, b;
  a = 1;
  b = 25;
  // 1 000 000 000
  long long n = 1000000000;
  const double t0 = omp_get_wtime();
  double_type result =  trapezoid(a, b, n);
  const double t1 = omp_get_wtime();
  printf("Time(sec): %f\n", t1 - t0);
  printf("Integral of exp(%Lf, %Lf, %i): %Lf\n", a, b, n, result);
}