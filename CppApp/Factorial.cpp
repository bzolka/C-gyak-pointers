#include<stdio.h>

int Faktorialis(int n);


void Factorial_Recursive_Demo()
{
    int fact = Faktorialis(5);
}


int Faktorialis(int n)
{
    if (n >= 1)
        return n * Faktorialis(n - 1);
    else
        return 1;
}


