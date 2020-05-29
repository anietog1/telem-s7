#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

double (*f)(double x) = exp;

double trapezoid(double x0, double xn, long long n)
{
  double h = (xn - x0) / n;
  double acum = 0;

  for (long long i = 1; i < n; ++i)
  {
    acum += f(x0 + h * i);
  }

  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main()
{
  double a, b;
  a = 1;
  b = 10;
  // 1000 000 000 000 000
  long long n = 1000000000000000;

  auto start = std::chrono::system_clock::now();
  double result = trapezoid(a, b, n);
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end - start;

  printf("Time(sec): %f\n", elapsed_seconds.count());
  printf("Integral of exp(%f, %f, %lli): %f\n", a, b, n, result);
}