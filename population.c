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
        
    }
    while ( m < end );
    printf("Years: %i \n", years );
}
