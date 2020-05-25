#include <cstdlib>
#include <cstdio>
#include <omp.h>
#include <time.h>

void count_nucleotides(size_t nts, const char *dna, unsigned long total[4])
{

  unsigned long countsA = 0UL;
  unsigned long countsC = 0UL;
  unsigned long countsG = 0UL;
  unsigned long countsT = 0UL;
#pragma omp parallel for reduction(+: countsA, countsC, countsG, countsT)
  for (size_t i = 0; i < nts; ++i)
  {
    if (dna[i] == 'A')
      ++countsA;
    if (dna[i] == 'C')
      ++countsC;
    if (dna[i] == 'G')
      ++countsG;
    if (dna[i] == 'T')
      ++countsT;
  }
  total[0] = countsA;
  total[1] = countsC;
  total[2] = countsG;
  total[3] = countsT;
}

void initialize_buffer(size_t nts, char *dna)
{
  srand(time(NULL));
  char alphabet[4] = {'A', 'C', 'G', 'T'};
  for (size_t i = 0; i < nts; ++i)
  {
    dna[i] = alphabet[rand() % 4];
  }
}

int main(int argc, char **argv)
{
  const unsigned long nts = 1UL << 25;
  char *dna = (char *)malloc(sizeof(char) * nts);
  initialize_buffer(nts, dna);
  unsigned long counts[4] = {0UL, 0UL, 0UL, 0UL};

  const double t0 = omp_get_wtime();
  count_nucleotides(nts, dna, counts);
  const double t1 = omp_get_wtime();

  printf("Time: %f\n", t1 - t0);
  printf("A: %lu\nC: %lu\nG: %lu\nT: %lu\n", counts[0], counts[1], counts[2], counts[3]);
}
