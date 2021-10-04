#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int aux, i, j, op, arr[MAX], n, qty, num;

void menu();
void print();
void insert();
void insertBeg();
void insertEnd();
void insertPos();
void ascend();
void descend();
void reverse();

int main()
{
    do{
        menu();
        switch(op)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertPos();
            break;
        case 4:
            ascend();
            break;
        case 5:
            descend();
            break;
        case 6:
            reverse();
            break;
        case 0:
            return 0;
        }
    }while(1);
}

void menu()
{
    system("clear||cls");
    printf(" === MENU ARRAY ===\n\n1 - Insert Beginning\n2 - Insert End\n3 - Insert Position\n"
           "4 - Ascending Order\n5 - Descending Order\n6 - Reverse\n0 - Sair\n\n");
    print();
    printf("Choose an option: ");
    scanf("%d", &op);
}

void print()
{
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

void insert()
{
    printf("Insert a number: ");
    scanf("%d", &num);
}

void insertBeg()
{
    if(!n){
        insert();
        arr[0] = num;
    } else {
        for(i=n-1;i>=0;i--)
            arr[i+1] = arr[i];
        insert();
        arr[0] = num;
    }
    n++;
}

void insertEnd()
{
    insert();
    arr[n] = num;
    n++;
}

void insertPos()
{
    int pos;
    printf("Insert position: ");
    scanf("%d", &pos);
    for(i=n-1;i>=pos-1;i--)
        arr[i+1] = arr[i];
    insert();
    arr[pos-1] = num;
    n++;
}

void ascend()
{
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr[j];
            }
        }
    }
}

void descend()
{
    for(i=n-1;i>0;i--){
        for(j=n-1;j>0-i;j--){
            if(arr[j]>arr[j-1]){
                aux = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = aux;
            }
        }
    }
}

void reverse()
{
    i = 0;
    for(j=n-1;j>=0;j--){
        if(i!=j){
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
        i++;
    }
}
