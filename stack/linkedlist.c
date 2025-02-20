#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

typedef struct node{
    int data;
    struct node *next;
}node;

node*top=NULL;

void main(){
    int ch;
    while(1){
        printf("Enter 1: Push 2:Pop 3:Display 4:Exit : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
}

void push(){
    int x;
    printf("Enter the data: ");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("%d pushed into stack\n", x);
}

void pop(){
    if (top == NULL) {
        printf("Stack empty\n");
        return;
    }

    struct node *temp = top;
    printf("Popped element is %d\n", top->data);
    top = top->next;
    free(temp);
}

void display(){
    if (top == NULL) {
        printf("Stack empty\n");
        return;
    }

    node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}