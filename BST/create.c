#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *left, *right;
} node;

// Function prototypes
node* insert(node* root, int data);

void postorder(node*root);

int main() {
    int n, i, item;
    node *root = NULL; // Initialize root to NULL

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &item);
        root = insert(root, item); // Insert elements into BST
    }

    printf("Inorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

// Function to insert a node into BST
node* insert(node* root, int data) {
    if (root == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}



void postorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        postorder(root->left);
        postorder(root->right);
    }
}