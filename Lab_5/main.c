#include <stdio.h>

int factorial(int n)
{

    if (n > 1 )
        return (n *factorial(n-1));
    else
        return(1);
}

int main()
{
    int n;
    printf("Please enter an integer: ");
    scanf("%d",&n);
    printf("Factorial(%d) = %d\n", n, factorial(n));
    return 0;
}
