#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m;
    int years = 0;
    int start;
    do
    {
        start = get_int("Start size? ");
    }
    while ( start < 9 );
    int end;
    do
    {
        end = get_int("End size? ");

    }
    while ( start > end );

    do
    {
        start = start + start/3 - start/4;
        years = years + 1;
    }
    while ( start < end );
    printf("Years: %i \n", years );
}
