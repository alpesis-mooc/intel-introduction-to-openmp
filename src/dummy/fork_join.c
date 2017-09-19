int main (void)
{
  double A[1000];
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    pooh(id, A);
  }
  printf("all done\n");

  #pragma omp parallel num_threads(4)
  {
    foobar();
  }
}
