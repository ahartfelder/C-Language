#include <stdio.h>
#include <stdlib.h>

int op, pos, count=0;

typedef struct node
{
    struct node *prev;
    struct node *next;
    int data;
} Node;

void pause()
{
    printf("Press ENTER to continue!!! ");
    fflush(stdin);
    getchar();
    fflush(stdin);
}

void position(int qty)
{
    do{
        printf("Insert at Position: ");
        scanf("%d", &pos);
    }while(pos<1||pos>qty);
}

void print(Node *head);
void menu(Node *head);
void first(Node **head);
void insertEnd(Node *head);
void insertBeg(Node **head);
void insertPos(Node **head);

int main()
{
    Node *head = NULL;
    do{
        menu(head);
        switch(op)
        {
        case 1:
            if(head==NULL){
                head = malloc(sizeof(Node));
                first(&head);
            } else
                insertEnd(head);
            break;
        case 2:
            if(head==NULL){
                head = malloc(sizeof(Node));
                first(&head);
            } else
                insertBeg(&head);
            break;
        case 3:
            if(head==NULL){
                head = malloc(sizeof(Node));
                first(&head);
            } else
                insertPos(&head);
            break;
        case 0:
            printf("Program has been terminated!\n");
            exit(0);
        default:
            printf("[ERROR] Invalid Option! Try again!\n\n");
        }
        printf("\n");
        pause();
        op = 0;
    }while(!op);
}

void print(Node *head)
{
    Node *ptr = head;
    if(!count)
        printf(" ===   EMPTY LIST   ===\n\n");
    else if(count==1)
        printf(" ===   LIST WITH 1 NUMBER   ===\n\n");
    else
        printf(" ===   LIST WITH %d NUMBERS   ===\n\n", count);
    while(ptr!=NULL){
        printf(" %d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void menu(Node *head)
{
    system("cls");
    printf(" ===   MENU - DOUBLY LINKED LIST   ===\n\n1 - Insert at the End\n2 - Insert at the Beginning\n3 - Insert Before Position\n"
           "0 - Exit\n\n");
    print(head);
    printf("Choose an option: ");
    scanf("%d", &op);
    printf("\n");
}

void first(Node **head)
{
    printf("Insert a number: ");
    scanf("%d", &(*head)->data);
    (*head)->prev = NULL;
    (*head)->next = NULL;
    count = 1;
}

void insertEnd(Node *head)
{
    Node *ptr = head;
    Node *temp = malloc(sizeof(Node));
    printf("Insert a number: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    count++;
}

void insertBeg(Node **head)
{
    Node *temp = malloc(sizeof(Node));
    printf("Insert a number: ");
    scanf("%d", &temp->data);
    temp->next = *head;
    temp->prev = NULL;
    (*head)->prev = temp;
    *head = temp;
    count++;
}

void insertPos(Node **head)
{
    Node *temp1, *temp2;
    temp1 = temp2 = *head;
    Node *temp = malloc(sizeof(Node));
    position(count+1);
    printf("\nInsert a number: ");
    scanf("%d", &temp->data);
    if(pos==1){
        temp->next = *head;
        temp->prev = NULL;
        (*head)->prev = temp;
        *head = temp;
    } else {
        while(pos!=1){
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr;
        temp->prev = ptr->prev;
        temp->prev->next = temp;
        ptr->prev = temp;
    }
    count++;
}

void insertAfter(Node *head)
{
    Node *ptr1 = head, *ptr2=NULL;
    Node *temp = malloc(sizeof(Node));
    position(count+1);
    printf("\nInsert a number: ");
    scanf("%d", &temp->data);
    while(pos!=1){
        ptr1 = ptr1->next;
        pos--;
    }
    ptr2 = ptr1->next;
    ptr1 = temp;
    ptr2 = temp;
    temp->prev = ptr1;
    temp->next = ptr2;
}
