#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define a linked list node that can hold a character pointer */
// TODO Define the structure for the linked list node
// NOTE: Name the structure: node
// NOTE: Name the member variable for the character pointer: value
struct node {
    char *value;
    struct node *next;
};

/* Function declarations */
struct node *addnode(struct node *the_node, char *value);
struct node *deletelastnode(struct node *the_node);
struct node *getlastnode(struct node *the_node);
void printlistiterative(struct node *the_node);
void printlistrecursive(struct node *the_node);

/* Use the functions to create and manipulate
   a linked list of character array values. */
int main() {
	struct node *root = NULL;

	root = addnode(root, "Alpha");
	root = addnode(root, "Beta");
	root = addnode(root, "Gamma");
	root = addnode(root, "Delta");

	printf("Print the list using recursion:\n");
	printlistrecursive(root);
	printf("\nPrint the list using iteration:\n");
	printlistiterative(root);

	printf("\nPrint the last node's value: %s\n", getlastnode(root)->value);

	printf("\nRepeatedly delete the last node and");
	printf("\nreprint the list until all nodes have been removed\n");
	while (root) {
		root = deletelastnode(root);
		printlistiterative(root);
        printf("\n");
	}

	return 0;
}


// addnode - add a node to the end of the linked list
// TODO Place the code for the function here
// NOTE: The return value must be the ROOT node
struct node *addnode(struct node *the_node, char *value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = strdup(value);
    new_node->next = NULL;

    if (the_node == NULL) {
        return new_node;
    }

    struct node *current = the_node;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return the_node;
}

// deletelastnode - delete the last node from the linked list
// TODO Place the code for the function here
// NOTE: The return value must be the ROOT node
struct node *deletelastnode(struct node *the_node) {
    if (the_node == NULL || the_node->next == NULL) {
        free(the_node);
        return NULL;
    }

    struct node *current = the_node;
    struct node *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    free(current);
    if (previous != NULL) {
        previous->next = NULL;
        return the_node;
    } else {
        return NULL;
    }
}

// getlastnode - get the last node from the linked list
// TODO Place the code for the function here
// NOTE: The return value must be the LAST node
struct node *getlastnode(struct node *the_node) {
    if (the_node == NULL) {
        return NULL;
    }

    struct node *current = the_node;
    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

// printlistrecursive - print out the list values using recursion
// TODO Place the code for the function here
void printlistrecursive(struct node *the_node)
{
	if (the_node == NULL)
	{
		return;
	}

	printf("%s ", the_node->value);
	printlistrecursive(the_node->next);
}

// printlistiterative - print out the list values using iteration
// TODO Place the code for the function here
void printlistiterative(struct node *the_node) {
    while (the_node != NULL) {
        printf("%s ", the_node->value);
        the_node = the_node->next;
    }
}

