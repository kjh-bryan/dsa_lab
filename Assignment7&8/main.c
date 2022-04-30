#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int *memory;

int top_down_dp(int n)
{
    //write your code here
    if(memory[n] > -1)
        return memory[n];

    if(n == 0)
    {
        memory[n] = 0;
        return memory[n];
    }

    if(n == 1)
     {
        memory[n] = 1;
        return memory[n];
    }
    if(n == 2)
    {
        memory[n] = 2;
        return memory[n];
    }

    memory[n] = top_down_dp(n-1) + (2 * top_down_dp(n-2)) - (3 * top_down_dp(n-3));


    return memory[n];
}



int main ()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    memory = malloc(sizeof(int) * (n+1));
    for (i=0; i<=n; i++)
        memory[i] = -1;

    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));

}
