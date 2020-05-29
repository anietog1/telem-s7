#include <bits/stdc++.h>
#include <cmath>
#include <omp.h>
#include <mpi.h>
using namespace std;

long double (*f)(long double x) = exp;

long double trapezoid(double x0, double xn, long long n)
{
  long double h = (xn - x0) / n;
  long double acum = 0.0;
#pragma omp parallel for reduction(+ \
                                   : acum)
  for (long long i = 0; i < n; ++i)
  {
    acum += f(x0 + h * i);
  }
  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main(int argc, char **argv)
{
  int n, p, i, j, ierr, num;
  float result, a, b;
  float my_a, my_b, my_range;

  int myid, source, dest, tag;
  MPI_Status status;
  float my_result;

  a = 0.;      /* lower limit of integration */
  b = 10;      /* upper limit of integration */
  n = 1000000; /* number of increment within each process */

  dest = 0;  /* define the process that computes the final result */
  tag = 123; /* set the tag to identify this particular job */

  /* Starts MPI processes ... */
  const double t0 = omp_get_wtime();
  MPI_Init(&argc, &argv);               /* starts MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, &myid); /* get current process id */
  MPI_Comm_size(MPI_COMM_WORLD, &p);    /* get number of processes */

  num = n / p; /* number of intervals calculated by each process*/
  my_range = (b - a) / p;
  my_a = a + myid * my_range;
  my_b = my_a + my_range;
  my_result = trapezoid(my_a, my_b, num);
  if (myid == 0)
  {
    result = my_result;
    for (i = 1; i < p; i++)
    {
      source = i; /* MPI process number range is [0,p-1] */
      MPI_Recv(&my_result, 1, MPI_REAL, source, tag,
               MPI_COMM_WORLD, &status);
      result += my_result;
    }
    printf("The result =%f\n", result);
    const double t1 = omp_get_wtime();
    printf("Time(sec): %f\n", t1 - t0);
  }
  else
  {
    MPI_Send(&my_result, 1, MPI_REAL, dest, tag, MPI_COMM_WORLD); // send my_result to intended dest.
  }
  MPI_Finalize(); /* let MPI finish up ... */
}
