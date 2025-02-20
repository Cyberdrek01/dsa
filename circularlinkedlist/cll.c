#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert();
void insertatbeginning();
void insertafteranynode();
void insertatend();
void delete();
void deleteatbeginning();
void deleteafteranynode();
void deleteatend();


typedef struct node{
    int data;
    struct node*next;
}node;

node*head=NULL;
node*tail=NULL;

void main(){
    int ch;
    while(1){
    printf("\nEnter 1:Create 2:Display 3:Insert 4:Delete 5:End : ");
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
        case 5: exit(0);
    }
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    }
}

void create(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the data: ");
    int i=0;
    while(i<n){
        node*new;
        new=(node*)malloc(sizeof(node));
        scanf("%d",&new->data);
        if(head==NULL){
            head=tail=new;
            tail->next=head;
        }
        else{
            tail->next=new;
            tail=new;
            tail->next=head;
        }
        i++;
    }
   
}

void display(){
    node*temp;
    temp=head;
    printf("Linked list: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

void insert(){
    int ch;
    printf("Enter 1:Insert at beginning 2:Insert after any node 3:Insert at end: ");
    scanf("%d",&ch);
    switch(ch){
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
    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d",&new->data);
    if(head==NULL){
        head=tail=new;
        tail->next=head;
    }else{
        new->next=head;
        head=new;
        tail->next=new;
    }
}

void insertafteranynode(){
    node*new;
    int p;
    printf("Enter the node after which you want to insert: ");
    scanf("%d",&p);
    node*temp;
    temp=head;
    do {
        if (temp->data == p) {
            break;
        }
        temp = temp->next;
    } while (temp != head);
    new = (node *)malloc(sizeof(node));  
    printf("Enter the data to be inserted: ");
    scanf("%d", &new->data);
    new->next = temp->next;
    temp->next = new;

}

void insertatend(){
    node*new;
    new=(node*)malloc(sizeof(node));
    printf("Enter the data you want to insert at the end: ");
    scanf("%d",&new->data);
    if(head==NULL){
        head=tail=new;
        tail->next=head;
        
    }
    new->next=head;
    tail->next=new;
    tail=new;
}


void delete(){
    int ch;
    printf("Enter 1:Delete at beginning 2:Delete after any node 3:Delete at end: ");
    scanf("%d",&ch);
    switch(ch){
        case 1: deleteatbeginning();
        break;
        case 2: deleteafteranynode();
        break;
        case 3: deleteatend();
        break;
    }
}

void deleteatbeginning(){
    node*p;
    p=head;
    if(head==NULL){
        printf("No data to be deleted");
    }
    else{
        head=head->next;
        free(p);
        tail->next=head;
    }

}

void deleteafteranynode(){
    int p;
    printf("Enter the node: ");
    scanf("%d",&p);
    node*temp;
    temp=head;
    while (temp->next != head)
    {
        if (temp->data == p)
        {
            break;
        }
        temp = temp->next;
    }
    node *q;
    q = temp->next;
    temp->next = q->next;
    free(q);
}
void deleteatend(){
    if (head == NULL) { 
        printf("No data to be deleted\n");
        return;
    }

    if (head->next == head) {  
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    node* temp = head;
    
    while (temp->next->next != head) {
        temp = temp->next;
    }

    node* last = temp->next;  
    temp->next = head;        
    free(last);               
    tail = temp;              
}