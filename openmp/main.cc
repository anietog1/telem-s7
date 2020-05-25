#include <cstdlib>
#include <cstdio>
#include <omp.h>
#include <time.h>

void count_nucleotides(size_t nts, const char *dna, unsigned long total[4])
{
  unsigned long counts[4] = {0UL, 0UL, 0UL, 0UL};
#pragma omp for
  for (size_t i = 0; i < nts; ++i)
  {
    if (dna[i] == 'A')
      ++counts[0];
    if (dna[i] == 'C')
      ++counts[1];
    if (dna[i] == 'G')
      ++counts[2];
    if (dna[i] == 'T')
      ++counts[3];
  }

#pragma omp critical
  {
    total[0] += counts[0];
    total[1] += counts[1];
    total[2] += counts[2];
    total[3] += counts[3];
  }
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
