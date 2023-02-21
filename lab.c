#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //starting number
    int n;
    do
    {
        n = get_int("Starting number? ");
    }
    while ( n < 9 );

    //ending number
    int e;
    do
    {
        e = get_int("Ending number? ");

    }
    while ( n > e );

    //the math
    while ( n < e)
    {
        n = n + n/3 - n/4
    }

}
