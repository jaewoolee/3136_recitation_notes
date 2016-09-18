// A linked list example program written by Jae Woo Lee and edited by Louis Croce in Recitation 10/27/14.
// To compile & link: gcc -g -Wall linked-list-2.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct Node {
    double data;
    struct Node *next;
};

void print(const char *msg, struct Node *list)
{
    // node points to same node as list
    struct Node *current = list;

    // prints each char msg points to until it reaches a '\0'
    printf("%s: ", msg);
    // traversing linked list
    while (current) { // STEP A of List Traversal.  same as while (current != NULL) {
    	// print data contents of node
        printf("-> %g ", current->data);  // current -> data is same as (*current).data
	current = current->next; // STEB B of List Traversal.  abstraction for current = (*current).next;
    }
    printf("\n");
}

/*
 * Create a node that holds the given data x,
 * and insert the node right after predecessor.
 *
 * If predecessor == NULL, return a new list containing the new node.
 *
 * Returns NULL if malloc for the node fails.
 */
struct Node *insert(struct Node *predecessor, double x)
{
    // create space on heap for new node
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    // check if malloc returned NULL (if malloc failed)
    if (node == NULL)
    	// not enough memory on the heap for the new node
	return NULL;

    // set node's data to x
    node->data = x;	// same as (*node).data = x;

    if (predecessor == NULL) {
        // no predecessor passed in; return a new list.
        node->next = NULL;
        return node;	// optional because we return node at the end
    } else {
        // insert the new node between predecessor and predecessor->next.
        node->next = predecessor->next;
        predecessor->next = node;
    }

    return node;
}

/*
 * Returns the first node containing x in the given list.
 * Returns NULL if no node contains x.
 */
struct Node *find(struct Node *list, double x)
{
    while (list) { // STEP A of List Traversal
        if (list->data == x) { // same as (*list).data == x
            return list;
        }
	list = list->next;  // STEP B of List Traversal
    }
    return NULL;
}

/*
 * Removes the 1st node containing x from the list, *listPtr.
 * Returns 1 if a node is removed, 0 otherwise.
 *
 * Note that a pointer to a list (rather than a list) is passed in
 * so that the caller's list can be modified if the head node gets 
 * removed.
 */
int remove_node(struct Node **listPtr, double x)
{
    // check for NULL pointer or empty list, 
    // in which cases we simply return 0;
    if (listPtr && *listPtr) {
        // currentNode is the node we are looking at.
        struct Node *currentNode = *listPtr;

        if (currentNode->data == x) {

            // The data matches x; let's remove the currentNode.
            // We modify the caller's list by changing *listPtr.
            // Note that "currentNode = currentNode->next" won't work
            // because currentNode is just a local variable.
            *listPtr = currentNode->next;

            // deallocate the currentNode and return 1.
            free(currentNode);
            return 1;

        } else {

            // The data does not match. Recursively call remove_node()
            // again with the list starting from the 2nd element.
            return remove_node(&currentNode->next, x);
        }
    }

    return 0;
}

int main()
{
    int i;
    double a[] = { 0.0, 1.0, 2.0, 3.0 };
    int n = sizeof(a) / sizeof(a[0]);

    // An initially empty list.
    struct Node *list = NULL;

    // Insert the first node.
    list = insert(NULL, a[0]);

    // Then we use insert() to successively append to the list.
    struct Node *node = list;
    for (i = 1; i < n; i++) {
        node = insert(node, a[i]);
    }
    print("original list", list);

    // test find() function
    assert(find(list, 0.0) == list);
    assert(find(list, 1.0) == list->next);
    assert(find(list, 2.0) == list->next->next);
    assert(find(list, 3.0) == list->next->next->next);
    assert(find(list, 2.1) == NULL);

    // insert 2.1 right after 2.0
    node = find(list, 2.0);
    node = insert(node, 2.1);
    assert(node->next->data == 3.0);
    print("inserted 2.1", list);

    // remove in this order: 2.1, 0.0, 3.0, 1.0, 2.0
    i = remove_node(&list, 2.1); print("removed 2.1", list); assert(i==1);
    i = remove_node(&list, 0.0); print("removed 0.0", list); assert(i==1);
    i = remove_node(&list, 3.0); print("removed 3.0", list); assert(i==1);
    i = remove_node(&list, 1.0); print("removed 1.0", list); assert(i==1);
    i = remove_node(&list, 2.0); print("removed 2.0", list); assert(i==1);
    assert(list == NULL);

    // Something to think about:
    //
    // Could we have implemented remove_node() so that you can pass 
    // the result of find(), i.e., remove_node(find(2.0)) for example?
    //
    // If not, how can we modify our list structure to make it work?

    return 0;
}
