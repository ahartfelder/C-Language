#include <stdio.h>

int main()
{
    int seen[10]={0}, N, rem;

    printf("Insert a number: ");
    scanf("%d", &N);

    while(N>0){
        rem = N%10;
        if(seen[rem]==1)
            break;
        seen[rem]=1;
        N = N/10;
    }
    printf("\nAre there any repeated digit? ");
    if(N>0){
        printf("YES");
    } else {
        printf("NO");
    }
    printf("\n");
    return 0;
}
