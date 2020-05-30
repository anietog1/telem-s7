#include <bits/stdc++.h>
#include <omp.h>
// 1 000 000 000 000
#define N 1000000000000
#define LOWER_LIMIT 1
#define UPPER_LIMIT 10
typedef double double_type;
typedef long long n_type;

using namespace std;

#pragma omp declare simd
double_type f(const double_type x);

void print_result(double_type a, double_type b, n_type n, double_type result);