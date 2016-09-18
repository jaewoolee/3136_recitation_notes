// A linked list example program from Jae's class touched up by Louis in Recitation 10/20/14
// To compile & link: gcc -g -Wall linked-list-1.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct Node {
    double data;
    struct Node *next;
};

/*
 * Create a node that holds the given data x,
 * add the node to the front of the given list (oldHead),
 * and returns the resulting list (newHead).
 *
 * Returns NULL if malloc for the node fails.
 */
struct Node *prepend(struct Node *oldHead, double x)
{
    // allocate memory on heap for a new Node
    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    // check if malloc returned NULL (not enough available memory on heap)
    if (newHead == NULL)
		return NULL;

    // set variables for the new node struct
    // same as (*newHead).data =x;
    newHead->data = x;
    newHead->next = oldHead;
    // newHead now points to the first Node in the list
    return newHead;
}

/*
 * Print the contents of the list that starts at head
 */
void print(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL) {
        printf("-> %g ", current->data);
		current = current->next;
    }
    printf("\n");
}

/*
 * Apply f(x) on each data item in the list and store its new value in its place. (not recursively)
 * Alternative to Jae's function below
 */
/*
void apply(struct Node *head, double (*f)(double))
{
    struct Node *current = head;
    // step 1 for "traversing" a linked list": check if current is a NULL pointer
    while (current != NULL) {
        current->data = f(current->data);
        // step 2, set current to point to the next node
	current = current->next;
    }
}
*/

/*
 * Apply f(x) on each data item in the list. (recursively)
 */
void apply(struct Node *list, double (*f)(double))
{
    // same as "if (list != NULL) {"
    if (list) {
        list->data = f(list->data);
        // using recursion as if it were a while loop to "traverse" the list (replaces step 2 above)
        apply(list->next, f);
    }
}

/*
 * Removes the first node (deallocating the memory for the node) 
 * and returns the rest of the list.  
 *
 * Returns NULL if list is NULL.
 */
struct Node *remove_front(struct Node *oldHead)
{
    struct Node *newHead = NULL;
    if (oldHead) {
        // second node in the list will be the new head (new first node)
	newHead = oldHead->next;
        free(oldHead);
    }
    return newHead;
}

/*
 * Deallocates all nodes.  Returns NULL.
 */
struct Node *remove_all_nodes(struct Node *head)
{
    while (head) {
        head = remove_front(head);
    }
    return head;  // head is NULL because of while condition
}

int main()
{
    double a[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    int n = sizeof(a) / sizeof(a[0]);

    // An initially empty list
    struct Node *list = NULL;

    int i;
    for (i = 0; i < n; i++) {
        list = prepend(list, a[i]);
    }

    // print the list, apply 2^x, and print the list again.
    print(list);
    apply(list, exp2);
    print(list);

    // remove first and print.
    list = remove_front(list);
    print(list);

    // remove first and print one more time.
    list = remove_front(list);
    print(list);

    // remove all nodes
    list = remove_all_nodes(list);
    assert(list == NULL);

    return 0;
}
