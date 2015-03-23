# lecture6

Examples used in HPC'15 class on March 23, 2015.
Remember to add the -g flag to the compile line, to enable
referencing back to the source code.


broken_valgrind.c:
simple example of out-of-bounds error valgrind does not detect
since the variable is allocated on the stack

broken.c:
contans several bugs valgrind can help find

debug_mpi.c:
parallel example to debug with valgrind

mpi_demo.c:
long list of bugs valgrind detects