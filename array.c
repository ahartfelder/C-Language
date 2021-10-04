#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX], qty, op, i, num, pos;


void pause();
void menu();
void ins();
void insPos();
void rem();
void print();
void del();
int isEmpty();
int isFull();
int isInvalidIns();
void posIns();
int isInvalidRem();
void posRem();

int main ()
{
    do {
        system("cls");
        menu();
        switch(op)
        {
        case 1:
            ins();
            break;
        case 2:
            insPos();
            break;
        case 3:
            rem();
            break;
        case 4:
            print();
            break;
        case 5:
            del();
            break;
        case 6:
            printf("Program has been terminated!!!\n");
            return 0;
        default:
            printf("[ERROR] Invalid Option! Try again!\n\n");
        }
        pause();
    } while(1);
}

void pause()
{
    printf("Press ENTER to continue!!!");
    fflush(stdin);
    getchar();
    fflush(stdin);
}

void menu()
{
    printf(" === ARRAY - MENU ===\n\n");
    printf("1 - Insert Number\n");
    printf("2 - Insert Number at Position\n");
    printf("3 - Remove Number\n");
    printf("4 - Print Array\n");
    printf("5 - Delete Array\n");
    printf("6 - Exit\n\n");
    printf("Choose an option: ");
    scanf("%d", &op);
    printf("\n");
}

void ins()
{
    if(isFull())
        return;
        printf("How many numbers to be inserted? ");
        scanf("%d", &num);
        if(num>MAX-qty){
            printf("[ERROR] More numbers than available slots!\n\n");
            return;
        }
        for(i=qty;i<qty+num;i++){
            printf("Insert a number: ");
            scanf("%d", &arr[i]);
            printf("\nNumber %d has been inserted at position %d.\n\n", arr[i], i+1);
        }
        qty += num;
}

void insPos()
{
    if(isFull())
        return;
    if(isEmpty())
        return;
    posIns();
    for(i=qty;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    printf("Insert a number: ");
    scanf("%d", &arr[pos-1]);
    printf("\nNumber %d has been inserted at position %d.\n\n", arr[pos-1], pos);
    qty++;
}

void rem()
{
    if(isEmpty())
        return;
    posRem();
    printf("\nNumber %d at position %d has been deleted.\n\n", arr[pos-1], pos);
    for(i=pos;i<qty;i++)
        arr[i-1]=arr[i];
    qty--;
}

void print()
{
    if(isEmpty())
        return;
    for(i=0;i<qty;i++)
        printf("%d\t", arr[i]);
    printf("\n\n");
}

void del()
{
    if(isEmpty())
        return;
    printf("Array has been deleted.\n\n");
    qty=0;
}

int isEmpty()
{
    if(!qty){
        printf("Array is empty!\n\n");
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if(qty==MAX){
        printf("Array is full!\n\n");
        return 1;
    }
    else
        return 0;
}

int isInvalidIns()
{
    if(pos<1||pos>qty+1){
        printf("\n[ERROR] Invalid Position!\n\n");
        return 1;
    } else
        return 0;
}

void posIns()
{
    do{
        printf("Insert position: ");
        scanf("%d", &pos);
    }while(isInvalidIns());
}

int isInvalidRem()
{
    if(pos<1||pos>qty){
        printf("\n[ERROR] Invalid Position!\n\n");
        return 1;
    } else
        return 0;
}

void posRem()
{
    do{
        printf("Insert position: ");
        scanf("%d", &pos);
    }while(isInvalidRem());
}
