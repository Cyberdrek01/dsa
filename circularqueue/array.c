#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define queue size

int queue[SIZE]; 
int front = -1, rear = -1;

// Function prototypes
void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to enqueue (insert) an element
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) { // Queue is full
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    if (front == -1) { // First element to be inserted
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE; // Move rear forward circularly
    }

    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

// Function to dequeue (remove) an element
void dequeue() {
    if (front == -1) { // Queue is empty
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    int value = queue[front];

    if (front == rear) { // Last element being removed
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE; // Move front forward circularly
    }

    printf("%d dequeued from the queue.\n", value);
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE; // Move forward circularly
    }
    printf("\n");
}
