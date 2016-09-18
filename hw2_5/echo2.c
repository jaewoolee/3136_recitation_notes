/*
 * Louis Croce
 * LJC2154
 * 3136
 * HW 2.5
 *
 * echo2.c
 * Modify the echo program to print out the command
 * line arguments in reverse order.
 */

#include <stdio.h>

int main(int argc, char **argv)
{
  // i will be index of argv array
  int i;
  for (i = argc-1; i > 0; i--) {
    // print ith argument of argv array (argv[i] is a char *)
    printf("%s\n", argv[i]);
  }

  return 0; 
}