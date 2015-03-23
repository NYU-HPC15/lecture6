#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <mpi.h>

#define MAX_COMMAND_LEN 2048


int main(int argc, char* argv[])
{
  char command[MAX_COMMAND_LEN];
  int N = 1024;
  double a = 2.9;
  double *data = malloc(N * sizeof(double));
  int rank;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

#if 1
  snprintf(command, MAX_COMMAND_LEN, "tmux new-window -t %d 'gdb -tui %s %d'",
      rank+1, argv[0], getpid());
  printf("command: %s\n", command);
  system(command);
  sleep(5);
#endif

  printf("rank %d: data = %p\n", rank, data);

  MPI_Finalize();

  return 0;
}
