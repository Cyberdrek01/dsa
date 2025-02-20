#include<stdio.h>
#include<stdlib.h>

#define N 5
int stack[N];
int top = -1;

void display();
void push();
void pop();

void main(){
    int ch;
    while(1){
    printf("\nEnter 1:Push 2:Pop 3:Display 4:Exit : ");
    scanf("%d",&ch);
    switch(ch){
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: display();
        break;
        case 4: exit(0);
    }
    printf("\n-------------------------------------------------------------------------------\n");
}
}



void push(){
    int x;
    printf("Enter the data to be inserted: ");
    scanf("%d",&x);
    if(top==N-1){
        printf("\nStack Overflow!");
    }
    else{
        top++;
        stack[top]=x;
    }
}


void pop(){
    if(top==-1){
        printf("Underflow!");
    }
    else{
        printf("%d is popped ",stack[top]);
        top=top-1;
    }
}

void display(){
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}