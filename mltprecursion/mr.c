#include <std.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int n = get_int("n: \n");
    printf(" It takes %i steps \n", collatz(n));

}

int collatz(int n)
{
    if n == 1
        return 0;
    else if n 

}