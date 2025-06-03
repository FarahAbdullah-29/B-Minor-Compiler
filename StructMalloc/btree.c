#include <stdio.h>
#include <stdlib.h>

struct BinaryTree {
    int data;
    struct BinaryTree* left_child;
    struct BinaryTree* right_child;
};

/* Function declarations */
struct BinaryTree* createNode(int value);
struct BinaryTree* addNode(struct BinaryTree* root, int value);
void printInOrder(struct BinaryTree* root);

struct BinaryTree* createNode(int value) {
    struct BinaryTree* newNode = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    newNode->data = value;
    newNode->left_child = newNode->right_child = NULL;
    return newNode;
}

struct BinaryTree* addNode(struct BinaryTree* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left_child = addNode(root->left_child, value);
    } else if (value > root->data) {
        root->right_child = addNode(root->right_child, value);
    }

    return root;
}

void print(struct BinaryTree* root) {
    if (root != NULL) {
        print(root->left_child);
        printf("%d ", root->data);
        print(root->right_child);
    }
}

int main() {
    struct BinaryTree* root = NULL;

    root = addNode(root, 1);
    root = addNode(root, 8);
    root = addNode(root, 26);
    root = addNode(root, 7);
    root = addNode(root, 12);
    root = addNode(root, 20);
    root = addNode(root, 3);

    printf("In-order traversal: ");
    print(root);
    printf("\n");
}