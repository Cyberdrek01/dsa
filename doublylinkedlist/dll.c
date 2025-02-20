#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next,*prev;
}node;

node*head=NULL;
node*tail=NULL;

void create();
void display();
void insert();
void delete();
void insertatbeginning();
void insertatend();
void insertafteranynode();
void deleteatbeginning();
void deleteatend();
void deleteafteranynode();

int main(){
    int ch;
    while(1){
    printf("\nEnter 1:Create 2:Display 3:Insert 4:Delete 5:Exit: ");
    scanf("%d",&ch);
    switch(ch){
        case 1: create();
        break;
        case 2: display();
        break;
        case 3: insert();
        break;
        case 4: delete();
        break;
        case 5: return 0;
        default: printf("Invalid choice");
    }
    printf("\n------------------------------------------------------------------------------------------------------------------\n");
}
}

void create(){
    int n;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    int i=0;
    printf("\nEnter the data: ");
    while(i<n){
        node*new;
        new=(node*)malloc(sizeof(node));
        new->next = NULL;
        new->prev = NULL;
        scanf("%d",&new->data);
        if(head==NULL){
            head=tail=new;
        }
        else{
            tail->next=new;
            new->prev=tail;
            tail=new;
            tail->next=NULL;
        }
        i++;
    }
}

void insert(){
    int c;
    printf("Enter1:To insert at beginning 2:To insert after any node 3:To insert at the end : ");
    scanf("%d",&c);
    switch(c){
        case 1: insertatbeginning();
        break;
        case 2: insertafteranynode();
        break;
        case 3: insertatend();
        break;
    }
}


void insertatbeginning(){
    node*new;
    new=(node*)malloc(sizeof(node));
    printf("Enter the data to insert at the beginning: ");
    scanf("%d",&new->data);
    if(head==NULL){
        head=tail=new;
    }
    else{
        new->next=head;
        head->prev=new;
        new->prev=NULL;
        head=new;
    }
}


void insertatend(){
    node*new;
    new=(node*)malloc(sizeof(node));
    printf("Enter the data to be inserted at the end: ");
    scanf("%d",&new->data);
    if(head==NULL){
        head=tail=new;
    }
    else{
        tail->next=new;
        new->prev=tail;
        tail=new;
        tail->next=NULL;
    }
}

void insertafteranynode(){
    node*new;
    node*temp;
    temp=head;
    int q;
    printf("Enter the data after which you want to insert: ");
    scanf("%d",&q);
    while (temp != NULL)
    {
        if (temp->data == q)
        {
            break;
        }
        else
            temp = temp->next;
    }
    new=(node*)malloc(sizeof(node));
    printf("Enter the data to be inserted: ");
     scanf("%d",&new->data);
    new->next=temp->next;
    temp->next->prev=new;
    temp->next=new;
    new->prev=temp;

}

void delete(){
    int h;
    printf("Enter1:To delete at beginning 2:To delete after any node 3:To delete at the end : ");
    scanf("%d",&h);
    switch(h){
        case 1: deleteatbeginning();
        break;
        case 2: deleteafteranynode();
        break;
        case 3: deleteatend();
        break;
    }
}

void deleteatbeginning(){
    if(head == NULL){
        printf("No data to be deleted\n");
        return;
    }
    node* p = head;
    head = head->next;
    if (head != NULL) { // Check if list is not empty after deletion
        head->prev = NULL;
    } else {
        tail = NULL; // If list is empty, update tail
    }
    free(p);
}

void deleteatend(){
    node*temp;
    if(head==NULL){
        printf("No data to be deleted");
    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    }
}

void deleteafteranynode(){
    int p;
    node*q;
    printf("Enter the node after which you want to delete: ");
    scanf("%d",&p);
    node*temp;
    temp=head;
    while(temp!=NULL){
        if(temp->data==p){
            break;
        }
        temp=temp->next;
        
    }
    q=temp->next;
    temp->next=q->next;
    q->next->prev=temp;
    free(q); 
}

void display(){
    node*temp;
    temp=head;
    printf("\nThe list is: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}