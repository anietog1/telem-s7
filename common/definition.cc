#include "definition.h"
double_type f(const double_type x)
{
    return exp(x);
}

void print_result(double_type a, double_type b, n_type n, double_type result)
{
    printf("Integral of exp(%f, %f, %i): %f\n", a, b, n, result);
}