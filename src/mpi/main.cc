#include "../common/definition.h"
#include <cmath>
#include <mpi.h>

double trapezoid(double x0, long long start, long long end, double h) {
  double acum = 0;

#pragma omp parallel for simd simdlen(8) reduction(+: acum)
  for(long long i = start; i < end; ++i) {
    acum += f(x0 + h * i);
  }

  double total = 0;
  MPI_Allreduce(&acum, &total, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  return total;
}

int main(int argc, char **argv) {
  double my_result, result, h;

  double a = LOWER_LIMIT; /* lower limit of integration */
  double b = UPPER_LIMIT; /* upper limit of integration */

  long long n = N; /* number of steps */
  long long u_num, l_num;

  int p, i;
  int myid, source, dest, tag;

  MPI_Status status;

  dest = 0;  /* define the process that computes the final result */
  tag = 123; /* set the tag to identify this particular job */

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
  if(myid == 0) {
    result = (h / 2) * (f(a) + 2 * my_result + f(b));
    const double t1 = omp_get_wtime();
    printf("Time(sec): %f\n", t1 - t0);
    print_result(a, b, n, result);
  }

  MPI_Finalize(); /* let MPI finish up ... */
}
