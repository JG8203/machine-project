// give a number which is divisible by 3 and 4 and 15 and is part of the fibonacci sequence
#include <stdio.h>
#include <math.h>

int isFibonacci(int n)
{
    int a = 0, b = 1, c = 1;
    while (c < n)
    {
        a = b;
        b = c;
        c = a + b;
    }
    if (c == n)
        return 1;
    else
        return 0;
}

int isFizzBuzz(int n)
{
    if (n % 15 == 0)
        return 1;
    else
        return 0;
}

int isDivisibleByFour(int n)
{
    if (n % 4 == 0)
        return 1;
    else
        return 0;
}

int main(){
    int n = 1;
    while (1)
    {
        if (isDivisibleByFour(n) && isFibonacci(n))
        {
            printf("%d", n);
            getchar();
        }
        n++;
    }
    return 0;
}