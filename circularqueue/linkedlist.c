#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

struct node*front=NULL;
struct node*rear=NULL;

void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    
    while(1){
        printf("Enter 1:Enqueue 2:Dequeue 3:Display 4:Exit: ");
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
    node*new=(node*)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d",&new->data);
    new->next=NULL;
    if(front==NULL){
        front=rear=new;
        rear->next=front;

    }
    else{
        rear->next=new;
        rear=new;
        rear->next=front;
    }
}

void dequeue(){
    if(front==NULL){
        printf("Queue empty");
    }
    else{
        node*temp=front;
        printf("%d dequeued",temp->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void display(){
    if(front==NULL){
        printf("Queue empty");
    }
    node*temp=front;
    printf("Queue contains: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=front);
    printf("\n");
}