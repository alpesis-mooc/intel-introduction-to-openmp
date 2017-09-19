int main(void)
{
  #pragma omp parallel
  {
    double tmp, B;
    B = DOIT();
    tmp = big_ugly(B);

  #pragma omp atomic
    X += tmp;
  }
}
