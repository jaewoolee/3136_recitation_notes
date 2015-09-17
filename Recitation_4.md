## Lab 2 ##

(a) Writing selection sort code and create a Makefile for the relevant code.

In a nutshell, your selection sort should do the following.

```
Given an array you will loop through each element. 
Find the minimum element seen past the element you are at in the loop.
Replace the element you are at in the loop with the minimum found.
```

Be sure to look back at Jae's code if you are stuck. For the Makefile, I highly encourage you to use the example one used by Jae (refer to recitation #2 for Makefile explanations).

(b) Write merge() function for mergesort().

```c
/*
 * Merge-sort an array a, which contains n elements.
 */
void merge_sort(char a[], int n)
{
    // BASIS: if a has only 1 element, there is nothing to do.
    if (n <= 1) {
        return;
    }

    // INDUCTION: merge_sort the 1st half and merge_sort the 2nd half 
    // so that we have 2 half-size sorted arrays, and then merge them 
    // into a single sorted list.

    int m = n / 2;

    // merge_sort the 1st m elements of a
    merge_sort(a, m);

    // merge_sort the remaining n - m elements of the array "a + m",
    // which is a way to take a sub-array of "a" where a[m] is the new 
    // 0th element (i.e., (a+m)[0] is the same as a[m]).
    merge_sort(a + m, n - m);

    // allocated a temporary array into which the merge function will 
    // put the merged array.
    char temp[n];

    // merge a (for which we are looking at only the 1st m elements)
    // and a+m (which has n-m elements from (a+m)[0] to (a+m)[n-m-1],
    //          which are really the same as a[m] to a[n-1])
    // into the temp array.
    merge(a, m, a + m, n - m, temp);

    // copy the temp array back into a.
    int i;
    for (i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
```
A mergesort() function has 3 sections

    a base case (an array of 1 or 0 elements is already sorted)
    a split step (split unsorted array into two unsorted arrays)
    call mergesort() on both unsorted sub arrays step
    a merge() step (merges the now sorted sub arrays into one array)
    (in our example, we have a 5th step, setting the values of array a to the values of the sorted array temp)

You will only be coding up the merge() step which is in fact not recursive. The basis for merge() is explained below in my own pseudocode. *Note merge() is such a common function that you can find pseudocode for it everywhere online. (but the below should be sufficient)

```c
define function merge (array1, array2) {
    array1_index = 0
    array2_index = 0
    return_array = array of size (array1.size + array2.size)

    for i from (0, return_array.size) {
        if array1_index >= array1.size {
            return_array[i] = array2[array2_index++]
            continue on with loop
        }
        if array2_index >= array2.size {
            return_array[i] = array1[array2_index++]
            continue on with loop
        }
        return_array[i] = lesser of array1[array1_index] and array2[array2_index]
        increment index of lesser of array1[array1_index] and array2[array2_index]
    }

    return return_array
}
```
    
Merge() is actually exactly what you would reasonably do if you were given two sorted decks and asked to combine it into one sorted deck.

(c) Add a print stack trace to mergesort_main.c

The main trick to this part is understanding where to put each distinct print statement and how to keep track of indentation. It is a lot easier if you use Jae's already included print_array() function to print the array, and you may decide to use multiple printf statements to get a single line to print out.
