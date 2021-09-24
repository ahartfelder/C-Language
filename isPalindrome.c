#include <stdio.h>

int main()
{
    int q, res=0, rem, n;
    printf("Insert a number to check if it's a palindrome: ");
    scanf("%d", &n);
    q = n;

    while(q){
        rem = q%10;
        res = res*10 + rem;
        q = q/10;
    }
    if(res==n)
        printf("It's a palindrome!\n");
    else
        printf("It's NOT a palindrome.\n");

    return 0;
}
