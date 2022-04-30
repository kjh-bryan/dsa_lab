#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;
void print_pos(int rlength, int first_cut[]){
    if (rlength==0)
        return;
    int pos = first_cut[rlength];
    printf("%d ", pos);
    print_pos(rlength-pos,first_cut);
}

int cr_bottom_up_dp_print(int *p, int n)
{

    int i,j;
    r[0] = 0;

    int first_cut[n+1];
    for (i=0;i<=n;i++)
        first_cut[i] = 0;

    for (j=1;j<=n;j++)
    {
        int pos_temp = 0;
        for (i=1;i<=j;i++)
        {
            int temp = p[i] + r[j-i];
            if (temp > r[j]){
                pos_temp = i;
                r[j] = temp;
            }
        }
        first_cut[j] = pos_temp;
    }

    printf("Length of each piece is:\n");
    print_pos(n,first_cut);
    printf("\n");
    return r[n];
}
//int cr_bottom_up_dp_print(int *p, int n)
//{
//    r[0] = p[0];
//    r[1] = p[1];
//    int max = 0;
//    int l1 = 0, l2 = 0;
//    for(int j = 1; j <= n; j++)
//    {
//        for(int i = 1;i <= j; i++)
//        {
//            int temp = p[i] + r[j-i];
//            //printf("Length %d and Length %d\n", i, j-i);
//            if(r[j] < temp)
//            {
//                r[j] = temp;
//                //printf("Maximum Revenue : %d\n",temp);
//                if(max < temp)
//                    max = temp;
//                    l1 = i;
//                    l2 = j-i;
//            }
//            else
//            {
//                //printf("Maximum Revenue : %d\n",r[j]);
//                if(max < r[j])
//                    max = r[j];
//                    l1 = i;
//                    l2 = j-i;
//            }
//
//        }
//
//
//    }
//
//    printf("Length %d and Length %d\n",l1,l2);
//    printf("Maximum Revenue : %d\n",max);
//    return r[n];
//}


void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list

    int price_list[10] = {0,1,4,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;

//    n = sizeof(price_list) / sizeof(int) - 1;
n= 4;
    p = price_list;


    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));


    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;

    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}
