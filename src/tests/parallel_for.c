#include <omp.h>
#include <stdio.h>

#include "timer.h"

#define N 50000

void plus(void)
{
  int A[N];

  int i;
  for (i = 0; i < N; ++i)
  {
    A[i] = 2 * i;
  }
}


void plus_omp(void)
{
  int A[N];

  int i;
  #pragma omp parallel for
  for (i = 0; i < N; ++i)
    A[i] = 2 * i;
}


void main(void)
{
  double tic;

  tic = timer();
  plus();
  printf("time elapsed: %f\n", timer() - tic);

  tic = timer();
  plus_omp();
  printf("(omp) time elapsed: %f\n", timer() - tic);

}
