#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

double (*f)(double x) = exp;

double trapezoid(double x0, double xn, int n) {
  double h = (xn - x0) / n;
  double acum = 0;

  for(int i = 1; i < n; ++i) {
    acum += f(x0 + h * i);
  }

  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main() {
  double a, b;
  a = 1;
  b = 10;
  int n = 100000000;
  const double t0 = omp_get_wtime();
  double result =  trapezoid(a, b, n);
  const double t1 = omp_get_wtime();
  printf("Time(sec): %f\n", t1 - t0);
  printf("Integral of exp(%f, %f, %i): %f\n", a, b, n, result);
}