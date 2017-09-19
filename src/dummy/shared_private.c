int main()
{
  #pragma omp parallel shared(A, B, C) private(id)
  {
    id = omp_get_thread_num();
    A[id] = big_cal(id);
  #pragma omp barrier
  #pragma omp for
    for (i = 0; i < N; ++i) {C[i] = big_cal3(i, A);}
  #pragma omp for nowait
    for (i = 0; i < N; ++i) { B[i] = big_cal2(C, i); }
    A[id] = big_cal4(id);
  }
}
