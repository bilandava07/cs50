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

        card = card / 10;
        d1 = card % 10;

        card = card / 100;
        d2 = card % 10;

        card = card / 100;
        d3 = card % 10;

        card = card / 100;
        d4 = card % 10;

        card = card / 100;
        d5 = card % 10;

        card = card / 100;
        d6 = card % 10;

        card = card / 100;
        d7 = card % 10;

        card = card / 100;
        d8 = card % 10;

        printf("%i %i %i %i %i %i %i %i \n", d1,d2,d3,d4,d5,d6,d7,d8 );


         d1 *=2; d2 *=2; d3 *=2; d4 *=2; d5 *=2; d6 *=2; d7 *=2; d8 *=2;

        printf("%i %i %i %i %i %i %i %i \n", d1,d2,d3,d4,d5,d6,d7,d8 );

        if ( d6 > 9)
        {
            int d61 = d6 % 10 ;
            int d62 = d1 / 10;
        }
        printf("%i %i \n", d61, d62 );




    }
}