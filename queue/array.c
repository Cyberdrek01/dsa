#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1, rear = -1;
void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    while(1){
        printf("\nEnter 1:Enqueue 2:Dequeue 3:Display: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4: exit(0);
            default:printf("Invalid choice");
            break;
        }

    }

}

void enqueue(){
    int x;
    printf("\nEnter the data: ");
    scanf("%d",&x);
    if(rear==N-1){
        printf("Queue is full\n");
    }
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }

}

void dequeue(){
    if(front==-1 &&rear==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("%d id dequeue",queue[front]);
        front++;

    }
}

void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("Queue empty");

    }
    else{
        for(i=front;i<rear+1;i++){
            printf("%d ",queue[i]);
        }
    }
}