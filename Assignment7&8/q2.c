#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//int **memory;

int bottom_up_dp(int n, int *s, int *v, int C)
{
    //write your code here
    int memory[n+1][C+1];
    int temp = 0;
    for(int items = 0; items <= n; items++)
    {
        for(int capacity = 0; capacity <= C; capacity++)
        {

            if(items == 0 || capacity == 0)
            {
                memory[items][capacity] = 0;
            }
            else if(s[items] <= capacity)
            {
                temp = memory[items-1][capacity-s[items]] + v[items];
                memory[items][capacity] = memory[items-1][capacity];
                if(temp > memory[items][capacity])
                    memory[items][capacity] = temp;

            }
            else
            {
                memory[items][capacity] = memory[items-1][capacity];
            }
        }
    }
    return memory[n][C];
}


int main ()
{
    int n = 4,C = 5;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
//    scanf("%d",&n);
    printf("Enter the capacity C:\n");
//    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));

//    memory = (int **)malloc(sizeof(int *) * (n+1));
//    for(i=0;i<=n;i++)
//        memory[i] = (int *)malloc(sizeof(int) * (C+1));
//
//    for(i=0;i<=n;i++)
//        for(j=0;j<=C;j++)
//            memory[i][j] = 0;
//
//    memory = (int *)malloc(sizeof(int) * (n+1));
//    for (i=0; i<=n; i++)
//    {
//        memory[i] = (int *) malloc(sizeof(int) * (C+1));
//        for(j = 0;j <= C; j++)
//        {
//            memory[i][j] = (int ) malloc(sizeof(int));
//            memory[i][j] = 0;
//
//        }
//    }

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
//    for (i=1;i<=n;i++)
//        scanf("%d",&s[i]);
    s[1] = 2;
    s[2] = 1;
    s[3] = 3;
    s[4] = 2;
    printf("Enter the values of items (as a list, separate by spacing:\n");
//    for (i=1;i<=n;i++)
//        scanf("%d",&v[i]);
    v[1] = 12;
    v[2] = 10;
    v[3] = 20;
    v[4] = 15;

    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));

}
