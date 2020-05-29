#include <bits/stdc++.h>
#include <cmath>
#include <omp.h>
#include <mpi.h>
using namespace std;

const int nTrials = 10;
const int skipTrials = 3;

double Stats(double & x, double & dx) {
  x  /= (double)(nTrials - skipTrials);
  dx  = sqrt(dx/double(nTrials - skipTrials) - x*x);
}

long double (*f)(long double x) = exp;

long double trapezoid(long double x0, long double xn, long long n) {
  long double h = (xn - x0) / n;
  long double partial_acum = 0;
  #pragma omp parallel for reduction(+: acum)
  for(long long i = 1; i < n; ++i) {
    partial_acum += f(x0 + h * i);
  }
  long double acum = 0.0;
  MPI_Allreduce(&acum_partial, &acum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  return (h / 2) * (f(x0) + 2 * acum + f(xn));
}

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);

  int rank, nRanks;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &nRanks);

  long double a, b;
  a = 1;
  b = 10;
  // 1 000 000 000 000
  long long n = 1000000000000;

  if (rank == 0)
  {
    printf("\n\033[1mNumerical integration with n=%d\033[0m\n", n);
    printf("\033[1m%5s %15s %15s\033[0m\n", "Step", "Time, ms", "GSteps/s");
    fflush(stdout);
  }

  for (int iTrial = 1; iTrial <= nTrials; iTrial++)
  {

    const double a = double(iTrial - 1);
    const double b = double(iTrial + 1);

    MPI_Barrier(MPI_COMM_WORLD);

    const double t0 = omp_get_wtime();
    const long double result = trapezoid(a, b, n, rank, nRanks);
    const double t1 = omp_get_wtime();

    const double ts = t1 - t0;                 // time in seconds
    const double tms = ts * 1.0e3;             // time in milliseconds
    const double fpps = double(n) * 1e-9 / ts; // performance in steps/s

    if (iTrial > skipTrials)
    { // Collect statistics
      t += tms;
      dt += tms * tms;
      f += fpps;
      df += fpps * fpps;
    }

    if (rank == 0)
      // Output performance
      printf("%5d %15.3f %15.3f %s\n",
             iTrial, tms, fpps, (iTrial <= skipTrials ? "*" : ""));
    fflush(stdout);
  }


  if (rank == 0)
  {
    printf("-----------------------------------------------------\n");
    printf("\033[1m%s\033[0m\n%8s   \033[42m%8.1f+-%.1f\033[0m   \033[42m%8.1f+-%.1f\033[0m\n",
           "Average performance:", "", t, dt, f, df);
    printf("-----------------------------------------------------\n");
    printf("* - warm-up, not included in average\n\n");
    printf("Integral of exp(%Lf, %Lf, %i): %Lf\n", a, b, n, result);
  }

  MPI_Finalize();
}