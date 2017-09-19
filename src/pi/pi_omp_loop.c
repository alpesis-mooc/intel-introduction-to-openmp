#include <omp.h>
#include <stdio.h>

#include "timer.h"

static long num_steps = 100000;
double step;

void pi(void)
{
  int i;
  double x, pi, sum = 0.0;
  step = 1.0/(double)num_steps;

  #pragma omp parallel
  {
    double x;
    #pragma omp for reduction(+:sum)
      for (i = 0; i < num_steps; ++i)
      {
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
      }
  }
  pi = step * sum;
}


void main(void)
{
  double tic = timer();
  pi();
  printf("time elapsed: %f\n", timer() - tic);
}
