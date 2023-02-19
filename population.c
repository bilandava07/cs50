#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m;
    int years = 0;
    // ask the user for a starting number of llamas
    int start;
    do
    {
        start = get_int("How many llamas are there? ");
    }
    while ( n < 9 );
    int end;
    do
    {
        end = get_int("How many llamas are there? ");

    }
    while ( start > end )
    // ask the user for a goal number of llamas
    int e = get_int("How many llamas should be there? ");
    do
    {
        m = n/3 + n;
        m = m - n/4;
        years = years + 1;
    }
    while ( m < e );
    printf("The population is going to reach the desired number of llamas in %i years \n", years );
}
