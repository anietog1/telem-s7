#pragma once

#include <bits/stdc++.h>
#include <omp.h>

// 4 000 000 000
#define N 4000000000L

#define LOWER_LIMIT 0
#define UPPER_LIMIT 10

#pragma omp declare simd simdlen(8)
double f(const double x);

double fs(const double x);

void print_result(double a, double b, long long n, double result);
