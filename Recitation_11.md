# Recitation 11 #

## Templates and the Standard Template Library (STL) ##

### What's a template? ###
Function templates are special functions that can operate with generic types.

This allows us to create a function template whose functionality can be adapted to 
more than one type or class without repeating the entire code for each type.

### Sample function template: Merge Sort ###
Remember how we wrote mergesort for a char array in lab 1?  What if we could write it for ANY kind of array?
```c
template <typename T>
void merge_sort(T a[], int n)
{
  /* 
   * BASIS: if a has only 1 element, there is nothing to do.
   */
  if (n <= 1)
    return;
  
  
  /*
   * INDUCTION: merge_sort the 1st half and merge_sort the 2nd half
   * so that we have 2 half-size sorted arrays, and then merge them
   * into a single sorted array
   */
  int m = n / 2;
  
  /*
   * merge_sort the 1st m elements of a
   */
  merge_sort(a, m);
  
  /*
   * merge_sort the remaining n - m elements of the array "a + m",
   * which is a way to take a sub-array of "a" where a[m] is the new 
   * 0th element (i.e., (a+m)[0] is the same as a[m]).
   */
  merge_sort(a + m, n - m);

  /*
   * allocated a temporary array into which the merge function will
   * put the merged array.
   */
  T temp[n];

  /*
   * merge a (for which we are looking at only the 1st m elements)
   * and a+m (which has n-m elements from (a+m)[0] to (a+m)[n-m-1],
   *          which are really the same as a[m] to a[n-1])
   * into the temp array.
   */
  merge(a, m, a + m, n - m, temp);
  
  /*
   * copy the temp array back into a
   */
  for (int i = 0; i < n; i++)
    a[i] = temp[i];
}

template <typename T>
void merge(T a1[], int n1, T a2[], int n2, T output[])
{
  int i1 = 0;
  int i2 = 0;
  int j = 0;
  
  /*
   * go through the elements of a1 and a2,
   * copying the smaller one into the output array
   * until we reach the end of either a1 or a2.
   */
  while (i1 < n1 && i2 < n2) {
    /*
     * note that we take a1 if the two elements are the same.
     */
    if (a1[i1] <= a2[i2]) {
      output[j++] = a1[i1++];
    } else {
      output[j++] = a2[i2++];
    }
  }
  
  /*
   * copy over the remaining elements of a1, if any.
   */
  while (i1 < n1)
    output[j++] = a1[i1++];
  
  /*
   * copy over the remaining elements of a2, if any.
   */
  while (i2 < n2) 
    output[j++] = a2[i2++];
}
```

### Some things to remember with templates ###

  * Always need "template <typename T>" before function declaration/definition.
  * The function will only work with classes and types for which all functions/operators used in the function are defined.

### Difference between templates and void * ###

  * Templates enable generic programming for all types while void * enables a typless programming.
  * With templates, the programming is type-safe, so the compiler will catch type mismatches (things to remember #2).
  * With void *, the programming is not type-safe, so seg-faults catch type mismatches :(.
  * Templates enable value semantics, but with void * you are forced to use pointer semantics.

### STL Containers ###
The C++ Standard Template Library comes with built-in classes that contain data defined by templates.

These classes are based on different data structures and are called containers.

There are 3 different types of containers: sequence containers, container adapters, and associative containers.

We will focus on the 3 sequence containers: vector, deque, and list.

Good thing about these container fellas: they "contain" objects of type T "by value".  Don't have to do too much garbage collecting.  Elements of container are destroyed when container is destroyed. (so you can just delete the container and don't have to iterate through to delete all the elements).

### vector ###
  * an array
  * Provides efficient random access (operator[]) and adding/removing elements from the end of the vector (push_back()/pop_back()).
  * Supports item additions & removals at positions other than the end of the vector (insert()/remove()), but they are inefficient because other items need to be moved.

  Here an example of using a vector
  ```c
  #include <vector>
  #include <string>
  #include <iostream>
  using namespace std;

  int main(int argc, char **argv) {

    vector<string> str_vector;
    str_vector.push_back("hello");
    str_vector.insert(str_vector.begin(), "world");

    // print out contents now
    for (unsigned i = 0; i < str_vector.size(); i++) {
      cout << str_vector[i] << endl;
    }

    return 0;
  }
  ```

### deque ###
  * short for double-ended queue, pronounced "deck"
  * similar to vector, but unlike vector, deque supports efficient
    addition & removal of elements from the beginning of the deque
    (push_front()/pop_front()).
  * slower and/or wastes more memory than vector

### list ###
  * doubly linked list
  * efficient insertion & removal of elements anywhere in the list
  * no random access

### Iterators ###
  The sequential containers have iterators to keep track of elements.
  * "iterator" and "const_iterator" is a "type member" (i.e., a
    typedef defined inside a class)
  * An iterator behaves like a pointer: ++it, *it.  Sometimes it’s
    actully a pointer (vector<T>::iterator is just a typedef of T*),
    but more often it’s not.  (Think about what a list<T>::iterator
    would have to do when you increment it.)
  * Dereferencing an iterator gives you a T&, and dereferencing a
    const_iterator gives you a const T&.
  * v.begin() returns an iterator that points to the first element in
    the vector.
  * v.end() returns an iterator that points to ONE PAST THE LAST
    ELEMENT, not the last element.  It is used as a marker for the end
    of the container, and it cannot be dereferenced.
  * Note that we use "!=" rather than "<" in the for loop.  This is
    recommended (especially if you’re writing template code) because
    not all iterators define operator<().  (list iterator does not,
    for example.)
  * Note that we use ++it rather than it++.  This is recommended
    because when the iterator is a class object rather than a native
    pointer, it’s usually less costly to call ++it than it++.

    Below is some sample code on using an iterator to print the contents of a vector<string> v.

    ```c
    typename vector<string>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
      cout << *it << " ";
    }
    ```
