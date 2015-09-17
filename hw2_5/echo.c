/*
 * Louis Croce
 * LJC2154
 * 3136
 * HW 2.5
 *
 * echo.c
 * Type out the "echo" program in the lecture note and run it.
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	// i will be index of argv array
  int i;
  for (i = 1; i < argc; i++) {
  	// print ith argument of argv array (argv[i] is a char *)
  	printf("%s\n", argv[i]);
  }

  return 0; 
}
