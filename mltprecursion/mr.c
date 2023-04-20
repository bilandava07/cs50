#include <stdio.h>
#include <cs50.h>

int collatz(int n);
int steps = 0;

int main(void)
{
    int n = get_int("n: ");
    printf("It takes %i steps \n", collatz(n));

}

int collatz(int n)
{
    if (n == 1)
        return 0;

    else if(n % 2 == 0)
    {
        collatz(n/2);
        steps++;
    }
    else
    {
        collatz(n*3 + 1);
        steps++;
    }
    return steps;
}