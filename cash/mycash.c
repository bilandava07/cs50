#include <cs50.h>
#include <stdio.h>

int coins = 0;
int cents;

int main(void)
{
    do
    {
        cents = get_int("Change owed: ");
    }
    while ( cents < 0);
// calculate quarters
    while ( cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }

    while ( cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }

    while ( cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }

    while ( cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    printf("%i \n", coins);


}