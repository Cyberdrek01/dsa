#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *left, *right;
} node;

// Queue structure for BFS
typedef struct queue {
    node* data;
    struct queue* next;
} queue;

// Function prototypes
node* insert(node* root, int data);
void bfs(node* root);
void enqueue(node* data);
node* dequeue();
int isQueueEmpty();

// Global queue pointers
queue* front = NULL, *rear = NULL;

int main() {
    int n, i, item;
    node *root = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &item);
        root = insert(root, item);
    }

    printf("\nBFS (Level Order Traversal): ");
    bfs(root);
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

// BFS (Level Order Traversal)
void bfs(node* root) {
    if (root == NULL) return;

    enqueue(root);
    while (!isQueueEmpty()) {
        node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left) enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }
}

// Queue Operations for BFS
void enqueue(node* data) {
    queue* newNode = (queue*)malloc(sizeof(queue));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

node* dequeue() {
    if (front == NULL) return NULL;
    queue* temp = front;
    node* data = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return data;
}

int isQueueEmpty() {
    return front == NULL;
}
