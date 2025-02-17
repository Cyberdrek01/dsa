#include<stdio.h>

int a[20], i, pos, size, num;

void create();
void display();
void insert();
void insertatbeginning();
void insertatend();
void insertatspecipos();
void delete();
void deleteatbeginning();
void deleteatend();
void deleteatspecipos();

int main() {
    int ch;
    while (1) {
        printf("\nEnter 1:Create 2:Display 3:Insert 4:Delete 5:Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete();break;
            case 5: return 0; // Exit condition
            default: printf("Invalid Choice!\n");
        }
    }
}

void create() {
    printf("Enter the size of array (max 20): ");
    scanf("%d", &size);
    if (size > 20 || size <= 0) {
        printf("Invalid size!\n");
        return;
    }
    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void display() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("The elements are: ");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert() {
    char in;
    printf("Enter a:Insert at the beginning b:Insert at specific position c:Insert at end: ");
    scanf(" %c", &in); // Space before %c to clear buffer
    switch (in) {
        case 'a': insertatbeginning(); break;
        case 'b': insertatspecipos(); break;
        case 'c': insertatend(); break;
        default: printf("Invalid choice!\n");
    }
}

void delete() {
    char in;
    printf("Enter a:Delete at the beginning b:Delete at specific position c:Delete at end: ");
    scanf(" %c", &in); // Space before %c to clear buffer
    switch (in) {
        case 'a': deleteatbeginning(); break;
        case 'b': deleteatspecipos(); break;
        case 'c': deleteatend(); break;
        default: printf("Invalid choice!\n");
    }
}

void insertatbeginning() {
    if (size >= 20) {
        printf("Array is full!\n");
        return;
    }
    printf("Enter the number you want to insert at the beginning: ");
    scanf("%d", &num);
    for (i = size - 1; i >= 0; i--) {
        a[i + 1] = a[i];
    }
    a[0] = num;
    size++;
}

void insertatspecipos() {
    if (size >= 20) {
        printf("Array is full!\n");
        return;
    }
    printf("Enter the position (1 to %d): ", size + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter the number you want to insert: ");
    scanf("%d", &num);
    for (i = size - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }
    a[pos - 1] = num;
    size++;
}

void insertatend() {
    if (size >= 20) {
        printf("Array is full!\n");
        return;
    }
    printf("Enter the number you want to insert at the end: ");
    scanf("%d", &num);
    a[size] = num;
    size++;
}

void deleteatbeginning(){
    if (size == 0) {
        printf("Underflow!");
    }
    else{
        for(i=0;i<size-1;i++){
            a[i]=a[i+1];
        }
        size--;
    }

}

void deleteatspecipos(){
    printf("Enter the position you want to delete: ");
    scanf("%d",&pos);
    if(size==0){
        printf("Underflow!");
    }
    else{
        for(i=pos-1;i<size-1;i++){
            a[i]=a[i+1];
        }
        size--;
    }
}

void deleteatend(){
    size--;
}