#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m = ;
    // ask the user for a starting number of llamas
    int n = get_int("How many llamas are there? ");
    // ask the user for a goal number of llamas
    int e = get_int("How many llamas should be there? ");
    while ( m < e )
    {
        m = n/3 + n;
        m = m - n/4;
    }
    printf("The population is going to reach the desired number of llamas in %i years \n", m );
}
