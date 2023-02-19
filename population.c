#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask the user for a starting number of llamas
    int n = get_int("How many llamas are there? ");
    // ask the user for a goal number of llamas
    int e = get_int("How many llamas should be there? ");

    do

    n = n + n/3;

    n = n - n/4;
    
    while ( n < e )
    printf("The population is going to reach the desired number of llamas in %i years \n, n );


}
