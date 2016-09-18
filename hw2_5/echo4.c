/*
 * Louis Croce
 * LJC2154
 * 3136
 * HW 2.5
 *
 * echo4.c
 * Modify the echo program to print the arguments
 * in dictionary order.
 */

#include <stdio.h>
#include <string.h>

/*
 * Sorts char* array a of size n
 * using selectionsort iteratively
 */
void selectionSort(char **a, int n)
{
  int i, j, small;
  char *temp;

  for (i = 0; i < n-1; i ++) {
    // find minimum
    small = i;
    for (j = i+1; j < n; j++) {
      // strcmp from string.h, look up what it does!
      if (strcmp(a[j], a[small]) < 0) {
        small = j;
      }
    }
    // swap
    temp = a[small];
    a[small] = a[i];
    a[i] = temp;
  }
}

int main(int argc, char **argv)
{
  selectionSort(argv, argc);
  
  // i will be index of argv array
  int i;
  for (i = 1; i < argc; i++) {
    // print ith argument of argv array (argv[i] is a char *)
    printf("%s\n", argv[i]);
  }

  return 0; 
}
