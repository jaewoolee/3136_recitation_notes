# Recitation 5: Pointers on Pointers on Pointers #

## What's a pointer anyway? ##

A pointer is a data type whose value is an address in memory.  The value "points" to another value stored in that memory location.

Here is an example of a declaration of a pointer c which points to a char.
```c
    char *c;
```
The * in the declaration lets us know that we are working with a pointer.
The data type before the * indicates the data type or structure that the pointer points to.

We also use a * when accessing the data that the pointer points to.  If the contents of pointer c has been assigned, we can do something like this:
```c
    char b;
    b = *c;
```
Here, b would take on the value on what ever was pointed to by the char pointer c.

To access the address of a variable, we use an &.
```c
    int x = 5;
    int *y;
    y = &x;
```    
This tells y to point to the address of the int x.

### I still don't get it ###

Legendary Professor Alfred Aho once compared data types to people and pointers to where they live. Hopefully the analogy will make pointers easier to understand for you as well!

Imagine that I have a person named Joe who is represented by an int. Let's say his value is 13.

```c
    int person = 13;
```

He lives somewhere (in this case in your computer) and you can ask him for his address in the computer (just like you could ask a person his home address) and store it somewhere. *Note we use & to ask a variable for its address.

```c
    int *persons_address = &person;
```

It's been a while and I want to vist Joe again and see how he's doing. Good thing I have his address.

```c
    printf("%d", *persons_address);
```

*Note that here we use * to travel to a pointers address and get the contents. It's kind of like traveling to Joe's house and asking for him.
    
And that's pointers in a nutshell.

### Pointer Example ###

Walk through the following program, keeping track of what the variables represent, what pointers point to what, and what's happening at each step.  Although this will compile, we will have warnings and some possible run-time errors.
```c
#include <stdio.h>

int main()
{
    int i,j;
    int *x;
    int *y;
    char a,b;
    char *k;

    i = 7;
    j = 97;
    x = i;  // hint: think about what this is saying
    y = &j;
    a = 'a';
    *k = a; // hint: may lead to seg fault
    b = *k;
    a = 'c';
    a = (char)j;

    if (a == b)
    {
        printf("a and b are equal!\n");
    }

    printf("i equals %d\n", i);
    printf("j equals %d\n", j);
    printf("the value stored in y equals %d\n", *y);
    printf("a equals %c\n", a);
    printf("b equals %c\n", b);
    printf("the value stored in k equals %c\n", *k);
    printf("the value of x equals %d\n", x);
    printf("the value stored in x equals %d\n", *x);

    return 0;
}
```

## NULL Pointer ##
A NULL pointer holds the memory address 0.

It cannot be dereferenced.

It can be initialized with `NULL` or `0` as done in the below example.
```c
  char *c = NULL;
  int *p = 0;
  if (p)  // same as "if (p != 0)" or "if (p != NULL)"
    printf("p is not a NULL pointer.\n");
  if (!p) // same as "if (p == 0)" or "if (p == NULL)"
    printf("p is a NULL pointer.\n");
```

## Simulating call-by-reference ##
When you pass a parameter into a function by value, any changes made to the parameter inside the body of the function do not affect the parameter outside the scope of the function.

To address this, C++ has a "call-by-reference" where the changes made to a parameter hold after the function's execution.

C does not allow for call-by-reference, but it can simulate it by passing values by pointers.
By passing by pointers, the address of the value is passed into the function and thus the actual value can be changed.

See how this is done in the following program which features pass-by-value and pass-by-pointer double functions.
```c
#include <stdio.h>

/* A function that doubles an integer where a is the value of the actual integer */
void doubleItV(int a);
/* A function that doubles an integer where a is the pointer to an integer */
void doubleItP(int *a);

int main(int argc, char **argv)
{
  int a = 2;
  printf("The value of a is originally %d.\n", a); // a is 2
  
  doubleItV(a);
  printf("The value of a after passing by value to the double function is %d.\n", a); // should still be 2
  
  doubleItP(&a); //passing the address of a to the function
  printf("The value of a after passing by pointer (address) to the double function is %d.\n", a); // should be 4
  
  return 0;
}

/* A function that doubles an integer where a is the value of the actual integer */
void doubleItV(int a)
{
  a = 2 * a;
}

/* A function that doubles an integer where a is the pointer to an integer */
void doubleItP(int *a)
{
  *a = *a * 2;
}
```

## sizeof() and pointers ##
`sizeof()` is a built-in function in c that returns the size of a given variable or type in bytes as a long unsigned integer.

The size of a `char` is 1 byte.
The size of an `int` is 4 bytes.
The size of a pointer is 8 bytes.
The size of an array is equal to the array size times the size of the data inside of it.
If you are taking the sizeof() of a dereferenced pointer, the size is the size of the type after dereferencing.

```c
#include <stdio.h>

int main(int argc, char **argv)
{
  int x;
  char *c;
  int a[20];
  
  printf("%lu\n", sizeof(x));        // should be 4.  note the %lu for long unsigned int
  printf("%lu\n", sizeof(c));        // should be 8
  printf("%lu\n", sizeof(a));        // should be 80 (4 * 20)
  printf("%lu\n", sizeof(*c));       // should be 1
  printf("%lu\n", sizeof(a[1]));     // should be 4
  
  return 0;
}
```

## Arrays and Pointers ##
An array is pretty much a glorified pointer.  You can do very similar things with both of them.

In the following example, we move pointers around the array to access elements.

```c
#include <stdio.h>

int main(int argc, char **argv)
{
  int a[] = {23, 5, 4, 20, 39, 88, 6, 25, 92, 1};
  int *p = a;

  printf("%d is the same as %d\n", *p, a[0]);
  printf("%d is the same as %d\n", *(p + 4), a[4]);
  printf("%d is the same as %d is the same as %d\n", *(p + 6), a[6], *(a + 6));
  printf("%d is the same as %d is the same as %d is the same as %d\n", *(p + 9), a[9], *(a + 9), *(9 + a));

  /* you can also increment a pointer with p++! */
  int i;
  for (i = 0; i < 10; i++)
    printf("element number %d: %d\n", i, *p++);
  /* but you can't do this with an array :( */

  /* observe that now p points to one past the last element of the array */
  printf("last element: %d\nwhat p points to (not defined by us): %d\n", *(p - 1), *p);

  return 0;
}
```

### char * (strings in C) ###
As you have heard by now, C does not come with a string data type like java, python, and c++.

Instead, strings are represented as an array of chars.

You can set a char pointer or char array to a string literal, or characters surrounded by ""'s like "boat".  It is important to note that you cannot manipulate string literals like you can a normal array of characters.

C comes with a <string.h> library of functions for string literal manipulation. You can find more details here: http://www.cs.cf.ac.uk/Dave/C/node19.html

Because there is no string data type, there is no == operator for string literals.  Below is the strncmp function.  It is used to evaluate whether the first n characters of 2 strings are the same.
It returns 0 if the first n characters of the strings are the same (or if the first string has less than n characters and they all match up).  It returns -1 or 1 otherwise depending on the first character mismatch.
```c
int strncmp(const char *s1, const char *s2, int n)
{
	int i;
	for (i = 0; n > 0; i++)
  		if (*(s1 + i) != *(s2 + i))				// dereference pointers
  		{
  			if (*(unsigned char *)(s1 + i) < *(unsigned char *)(s2 + i)) //the cast is to get rid of warnings
  				return -1;
  			else
  				return 1;
  		}
		else if (*s1 == '\0')
	    	return 0;
  	return 0;
}
```

## Malloc ##
Sometimes you want a bit more than a local variable, but less than a static variable.  
Sometimes, you want a dynamic AND persistant array.  Who you gonna call? -> Heap allocation.
How you gonna call it? -> with malloc().
A variable allocated on the heap will stay there until free() is called.  Wow!
Example:
```c
#include <stdio.h> // look!  a new library for malloc and free!
#include <stdlib.h>

int *allocateIntArray()
{
  int *p = (int *)malloc(3 * sizeof(int));
  return p;
}

void callNumber(int *p, int n)
{
  printf("Calling ");
  int i;
  for (i = 0; i < 3; i++)
  {
    printf("%d", *(p + i));
  }
  printf("\n");
}

void freeIntArray(int *p)
{
  free(p);
}

int main(int argc, char **argv)
{
  int *emergency = allocateIntArray();
  *(emergency) = 9;
  *(emergency + 1) = 1;
  *(emergency + 2) = 1;
  callNumber(emergency, 3);
  freeIntArray(emergency);
  return 0;
}
```
### Memory Leaks ###
When you run valgrind on your programs, you will have memory errors if you allocated memory on the heap that wasn't freed.
Don't forget to free()!  Memory errors will lose you points on labs!
