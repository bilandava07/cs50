#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //promt for input
        long card;
        card = get_long("Number: ");
    if ( card < 1000000000000 || card > 9999999999999999) // number is not a creditcard
    {
        printf("INVALID \n");
    }
    else // calculate the checksum
    {
        int mod = 100;
        int d1;
        int d2;
        int d3;
        int d4;
        int d5;
        int d6;
        int d7;
        int d8;

        d1 = card % mod;
        mod = mod *2;
        d2 = card % mod;

        printf(" %i %i \n", d1, d2);

    }
}