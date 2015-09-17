/*
 * ncat.c
 * Written by Jae Woo Lee, edited by Louis Croce in Recitation on 10/27/14
 * ncat <file_name>
 *
 * - reads a file line-by-line, 
 * printing them out with line numbers
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

  if (argc != 2) {
    fprintf(stderr, "%s\n", "usage: ncat <file_name>");
    return 1;
  }
  
  char *filename = argv[1];
  
  // open's up the file filename as a FILE *, a data type used for reading/writing files
  FILE *fp = fopen(filename, "r");
  
  // check if fopen returned NULL
  if (fp == NULL) {
    // no file of name filename
    perror(filename);
    return 1;
  }
  
  // array to store chars from a given line
  char buf[100];
  
  // keep track of line number because we want to print it!
  int lineno = 1;
  
  // read file until either 100 bytes are read or a new line character/EOF character is read
  while (fgets(buf, sizeof(buf), fp) != NULL) {
  
    // leave spacing as if the integer is 4 digits, but only fill in the right most digits as needed
    printf("%4d ", lineno++);
    
    if (fputs(buf, stdout) == EOF) { // like printf
      perror("can’t write to stdout");
      exit(1);
    }
 }

 // check for error during reading file
 if (ferror(fp)) { // checks if error flag of FILE * was set (?)
   perror(filename);
   exit(1);
 }

 // we will not read from FILE *fp anymore
 fclose(fp);

 return 0;
}
