int main()
{
      int *array;
    int n = 5;
    array[0] = 1;
    array[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        array[i] = (i * array[i-1]) + ((i-1) * array[i-2]);
    }
    printf(" Array : %d\n",array[n]);

//    printf("Array ; %d\n", f(5));
    return 0;
}


int f(int n)
{
    if(n==0 || n == 1)
        return 1;

    int m = (n * f(n-1)) + ((n-1) * f(n-2));

    return m;
}
