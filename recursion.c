#include <stdio.h>

int m = 1;
int direct(int);     // Direct = Call the same function again.
void indirect();     // Indirect = Call another function, then call back the first function directly or indirectly.
void odd();
void even();
void tail(int);      // Tail = Recursive Call is the LAST thing done by the function. There's no need to keep record of the previous state.
void nonTail(int);   // Non-Tail = Recursive Call is NOT the last thing done by the function. There's smth left to evaluate.

// Advantages: It's more ELEGANT and requires relatively LESS lines of codes.
// Disadvantages: It requires MORE space (in stack) then iterative programs.

int main ()
{
    int op, n = 5;
    printf(" === RECURSION ===\n\n1 - Direct\n2 - Indirect\n"
           "3 - Tail\n4 - Non-Tail\n\nChoose an option: ");
    scanf("%d", &op);
    printf("\n");
    switch(op)
    {
    case 1:
        printf("%d", direct(n));
        break;
    case 2:
        indirect();
        break;
    case 3:
        tail(n);
        break;
    case 4:
        nonTail(n);
        break;
    }
    printf("\n");
}

int direct(int n)
{
    if(n==0)
        return 1;
    else
        return n * direct(n-1);
}

void indirect()
{
    odd();
}

void odd()
{
    if(m<11){
        printf("%d ", m+1);
        m++;
        even();
    }
}

void even()
{
    if(m<11){
        printf("%d ", m-1);
        m++;
        odd();
    }
}

void tail(int n)
{
    if(n==0)
        return;
    else
        printf("%d ", n);
    return tail(n-1);
}

void nonTail(int n)
{
    if(n==0)
        return;
    nonTail(n-1);
    printf("%d ", n);
}
