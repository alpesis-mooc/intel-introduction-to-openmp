int main(void)
{
  #pragma omp parallel
  {
    #pragma omp for
      for (I = 0; I < N; I++)
      {
        NEAT_STUFF(I);
      }
  }
}
