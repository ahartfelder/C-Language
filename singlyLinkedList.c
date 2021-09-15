#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void menu(int *op)
{
        system("cls");
        printf(" === MAIN MENU ===\n\n1 - Insert Number\n2 - List Numbers\n3 - Reverse List\n");
        printf("4 - Delete Number\n5 - Delete All Numbers\n6 - Exit\n\nChoose an option: ");
        scanf("%d", op);
        printf("\n");
}

void print(Node *head)
{
    Node *ptr = head;
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

Node* first(Node *head)
{
    system("cls");
    printf(" === MENU - INSERT NEW NUMBER ===\n\n");
    printf("Insert a number: ");
    scanf("%d", &head->data);
    head->next = NULL;
    return head;
}

void addEnd(Node *head)
{
    Node *temp = malloc(sizeof(Node));
    Node *ptr = head;
    system("cls");
    printf(" === MENU - INSERT NEW NUMBER ===\n\n");
    printf("Insert a number: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void addPos(Node **head, int count)
{
    Node *temp = malloc(sizeof(Node));
    Node *curr = *head;
    int pos;
    do{
        system("cls");
        printf(" === MENU - INSERT NEW NUMBER ===\n\n");
        printf("Current List:\n\n");
        print(*head);
        printf("\n\nChoose position to add a number: ");
        scanf("%d", &pos);
        if((pos>count+1)||(pos<1)){
            printf("\n[ERROR] Invalid position number! Try again.\n\n");
            pos = 0;
            system("pause");
        }
    } while(!pos);
    printf("\nInsert a number at position %d: ", pos);
    scanf("%d", &temp->data);
    if(pos==1){
        temp->next = *head;
        *head = temp;
    } else {
        pos--;
        while(pos!=1){
            curr = curr->next;
            pos--;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void delPos(Node **head, int count)
{
    Node *prev = *head;
    Node *curr = *head;
    int pos;
    do{
        system("cls");
        printf(" === MENU - DELETE NUMBER ===\n\n");
        printf("Current List:\n\n");
        print(*head);
        printf("\n\nChoose position to delete a number: ");
        scanf("%d", &pos);
        if((pos>count)||(pos<1)){
            printf("\n[ERROR] Invalid position number! Try again.\n\n");
            pos = 0;
            system("pause");
        }
    } while(!pos);
    if(pos==1){
        *head = curr->next;
        free(curr);
        curr = NULL;
    } else {
        while(pos!=1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        free(curr);
        curr = NULL;
    }
}

Node* delAll(Node *head)
{
    Node *curr = head;
    while(curr->next!=NULL){
        head = head->next;
        free(curr);
        curr = head;
    }
    free(head);
    head = NULL;
    return head;
}

Node* rev(Node *head)
{
    Node *curr = NULL;
    Node *prev = NULL;
    while(head!=NULL){
        curr = head->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    head = prev;
    return head;
}

int main()
{
    int op, count = 0;
    Node *ptr, *head = NULL;
    do {
        menu(&op);
        switch(op){
            case 1:
                do {
                    if(head==NULL){
                        head = malloc(sizeof(Node));
                        head = first(head);
                        printf("\nUpdated List:\n\n"),
                        print(head);
                        printf("\n\nDo you want to add a new number? [1] YES / [0] NO ");
                        scanf("%d", &op);
                        count++;
                    }
                    if(op){
                        addPos(&head, count);
                        count++;
                        printf("\nUpdated List:\n\n");
                        print(head);
                        printf("\n\nDo you want to add a new number? [1] YES / [0] NO ");
                        scanf("%d", &op);
                    }
                }while(op);
                break;
            case 2:
                if(head==NULL){
                    printf("List is Empty!");
                } else {
                    printf("Current List with %d number(s):\n\n", count);
                    print(head);
                }
                printf("\n\n");
                system("pause");
                break;
            case 3:
                system("cls");
                printf(" === MENU - REVERSE LIST ===\n\n");
                if(head==NULL){
                    printf("List is Empty!");
                } else if(head->next!=NULL){
                    printf("Previous List:\n\n");
                    print(head);
                    head = rev(head);
                    printf("\n\nUpdated List:\n\n");
                    print(head);
                } else {
                    printf("Single number. Reverse not required.");
                    printf("\n\nUpdated List:\n\n");
                    print(head);
                }
                printf("\n\n");
                system("pause");
                break;
            case 4:
                if(head==NULL){
                    printf("List is already Empty!");
                    printf("\n\n");
                    system("pause");
                } else if(head->next==NULL){
                    free(head);
                    head = NULL;
                    count = 0;
                    printf("The only number has been deleted. List is Empty!");
                    printf("\n\n");
                    system("pause");
                } else {
                    do{
                        delPos(&head, count);
                        count--;
                        printf("\nUpdated List:\n\n");
                        print(head);
                        printf("\n\nDo you want to delete a new number? [1] YES / [0] NO ");
                        scanf("%d", &op);
                        if((head->next==NULL) && (op)) {
                            free(head);
                            count = 0;
                            head = NULL;
                            printf("\nLast number has been deleted. List is empty!");
                            printf("\n\n");
                            system("pause");
                            op = 0;
                        }
                    }while(op);
                }
                break;
            case 5:
                if(head==NULL){
                    printf("List is already Empty!");
                } else if(head->next==NULL){
                    free(head);
                    head = NULL;
                    printf("The only number has been deleted. List is Empty!");
                } else {
                    head = delAll(head);
                    printf("All numbers have been deleted. List is Empty!");
                }
                count = 0;
                printf("\n\n");
                system("pause");
                break;
            case 6:
                printf("Program has been finished! Thank you!!!\n");
                exit(0);
            default:
                printf("[ERROR] Invalid Option! Try again.");
            }
        op = 0;
    } while(!op);
}
