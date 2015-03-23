#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void f(int N)
{
  int n, i, j;
  double *I = malloc(N*N*sizeof(double));

  for(n = 0; n < N*N; ++n)
  {
    I[n] = n;
  }

  for(j = 0; j < N; ++j)
  {
    for(i = 0; i < N; ++i)
    {
      I[N*i+j] += 100;
    }
  }

  printf("I[N*N] = %g\n", I[N*N]);

  I[N*N] = 1.0;

  printf("I[N*N] = %g\n", I[N*N]);

  double *I2 = malloc(N*N*sizeof(double));

  printf("I2[0] = %g\n", I2[0]);

  free(I);
  free(I);
}

int main(int argc, char* argv[])
{
  int N;

  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s N\n", argv[0]);
    return -1;
  }

  N = MAX(atoi(argv[1]), 1);

  printf("N = %d\n", N);

  f(N);

  return 0;
}
