#include "../common/definition.h"
#include <cmath>
#include <mpi.h>

#define MY_ROOT 0

double trapezoid(double x0, long start, long end, double h) {
  double acum = 0;

#pragma omp parallel for simd simdlen(8) reduction(+: acum)
  for(long i = start; i < end; ++i) {
    acum += f(x0 + h * i);
  }

  double total = 0;
  MPI_Reduce(&acum, &total, 1, MPI_DOUBLE, MPI_SUM, MY_ROOT, MPI_COMM_WORLD);
  return total;
}

int main(int argc, char **argv) {
  double my_result, result, h;

  double a = LOWER_LIMIT; /* lower limit of integration */
  double b = UPPER_LIMIT; /* upper limit of integration */

  long n = N; /* number of steps */
  long u_num, l_num;

  int p;
  int myid;
  int dest = MY_ROOT;  /* define the process that computes the final result */

  /* Starts MPI processes ... */
  MPI_Init(&argc, &argv);               /* starts MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, &myid); /* get current process id */
  MPI_Comm_size(MPI_COMM_WORLD, &p);    /* get number of processes */

  l_num = (n / p) * myid;
  u_num = (n / p) * myid + (n / p);
  h = (b - a) / n;

  if(l_num == 0) {
    l_num = 1;
  }

  MPI_Barrier(MPI_COMM_WORLD);

  const double t0 = omp_get_wtime();
  my_result = trapezoid(a, l_num, u_num, h);

  if(myid == dest) {
    result = (h / 2) * (f(a) + 2 * my_result + f(b));
    const double t1 = omp_get_wtime();
    printf("Time(sec): %f\n", t1 - t0);
    print_result(a, b, n, result);
  }

  MPI_Finalize(); /* let MPI finish up ... */
}
