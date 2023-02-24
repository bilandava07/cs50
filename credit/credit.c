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


        int d11 = 0; int d12 = 0; int d21 = 0; int d22 = 0; int d31 = 0; int d32 = 0;int d41 = 0;int d42 = 0;int d51 = 0;int d52 = 0;int d61 = 0;int d62 = 0;int d71 = 0;int d71 = 0;int d81 = 0;int d82 = 0;


        if ( d1 > 9)
        {

            d11 = d1 % 10 ;
            d12 = d1 / 10;
            printf("%i %i \n", d11, d12 );
        }

        if ( d2 > 9)
        {

            d21 = d2 % 10 ;
            d22 = d2 / 10;
            printf("%i %i \n", d21, d22 );
        }

        if ( d3 > 9)
        {

            d31 = d3 % 10 ;
            d32 = d3 / 10;
            printf("%i %i \n", d31, d32 );
        }
    }
}