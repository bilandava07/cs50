#include <cs50.h>
#include <stdio.h>

        int p1;int p2; int p3; int p4; int p5; int p6; int p7; int p8;
        int d1; int d2; int d3; int d4;int d5;int d6; int d7; int d8;
        int d11 = 0; int d12 = 0; int d21 = 0; int d22 = 0; int d31 = 0; int d32 = 0;int d41 = 0;int d42 = 0;int d51 = 0;int d52 = 0;int d61 = 0;int d62 = 0;int d71 = 0;int d72 = 0;int d81 = 0;int d82 = 0;

int main(void)
{
    //promt for input
        long card;
        card = get_long("Number: ");
        const long cardconst = card;

    if ( card < 1000000000000 || card > 9999999999999999) // number is not a creditcard
    {
        printf("INVALID \n");
    }
    else // calculate the checksum
    {
        p1 = card % 10;
        card = card / 10;
        d1 = card % 10;

        card = card / 10;
        p2 = card % 10;
        card = card / 10;
        d2 = card % 10;

        card = card / 10;
        p3 = card % 10;
        card = card / 10;
        d3 = card % 10;

        card = card / 10;
        p4 = card % 10;
        card = card / 10;
        d4 = card % 10;

        card = card / 10;
        p5 = card % 10;
        card = card / 10;
        d5 = card % 10;

        card = card / 10;
        p6 = card % 10;
        card = card / 10;
        d6 = card % 10;

        card = card / 10;
        p7 = card % 10;
        card = card / 10;
        d7 = card % 10;

        card = card / 10;
        p8 = card % 10;
        card = card / 10;
        d8 = card % 10;

        //printf("%i %i %i %i %i %i %i %i \n", d1,d2,d3,d4,d5,d6,d7,d8 );


         d1 *=2; d2 *=2; d3 *=2; d4 *=2; d5 *=2; d6 *=2; d7 *=2; d8 *=2;

        //printf(" %i %i %i %i %i %i %i %i \n", d1,d2,d3,d4,d5,d6,d7,d8 );

        if ( d1 > 9)
        {

            d11 = d1 % 10 ;
            d12 = d1 / 10;
            //printf("%i %i \n", d11, d12 );
        }
        else
        {
            d11 = d1;
        }

        if ( d2 > 9)
        {

            d21 = d2 % 10 ;
            d22 = d2 / 10;
            //printf("%i %i \n", d21, d22 );
        }
        else
        {
            d21 = d2;
        }
        if ( d3 > 9)
        {
            d31 = d3 % 10 ;
            d32 = d3 / 10;
            //printf("%i %i \n", d31, d32 );
        }
        else
        {
            d31 = d3;
        }
        if ( d4 > 9)
        {

            d41 = d4 % 10 ;
            d42 = d4 / 10;
            //printf("%i %i \n", d41, d42 );
        }
        else
        {
            d41 = d4;
        }
        if ( d5 > 9)
        {

            d51 = d5 % 10 ;
            d52 = d5 / 10;
            //printf("%i %i \n", d51, d52 );
        }
        else
        {
            d51 = d5;
        }
        if ( d6 > 9)
        {

            d61 = d6 % 10 ;
            d62 = d6 / 10;
            //printf("%i %i \n", d61, d62 );
        }
        else
        {
            d61 = d6;
        }
        if ( d7 > 9)
        {

            d71 = d7 % 10 ;
            d72 = d7 / 10;
            //printf("%i %i \n", d71, d72 );
        }
        else
        {
            d71 = d7;
        }
        if ( d8 > 9)
        {

            d81 = d8 % 10 ;
            d82 = d8 / 10;
            //printf("%i %i \n", d81, d82 );
        }
        else
        {
            d81 = d8;
        }

        int sum_d;
        sum_d = d11 + d12 + d21 + d22 + d31 + d32 + d41 + d42 + d51 + d52 + d61 + d62 + d71 + d72 + d81 + d82;
        //printf (" sum_d: %i \n", sum_d);

        //printf("%i %i %i %i %i %i %i %i \n", p1,p2,p3,p4,p5,p6,p7,p8 );

        int sum_p;
        sum_p = p1+p2+p3+p4+p5+p6+p7+p8;
        //printf (" sum_p: %i \n", sum_p);

        int sum;
        sum = sum_d + sum_p;
        //printf (" sum: %i \n", sum);

        int checksum;
        checksum = sum % 10;

        printf("checksum: %i \n", checksum);2

        if ( checksum == 0)
        {
            long cardcheck = cardconst;

            if ( cardcheck < 1000000000000000 && cardcheck > 99999999999999)
            {
                int cardcheck_ax = cardcheck / 10000000000000;
                if ( cardcheck_ax == 34 || cardcheck_ax == 37 )
                {
                    printf("AMERICAN EXPRESS \n");
                }
            }

            else if ( cardcheck < 10000000000000000 && cardcheck > 999999999999999)
            {
                int cardcheck_m = cardcheck / 100000000000000;
                if ( cardcheck_m == 51 || cardcheck_m == 52 ||cardcheck_m == 53 || cardcheck_m == 54 ||cardcheck_m == 55 )
                {
                    printf("MASTERCARD \n");
                }
                int cardcheck_v2 = cardcheck / 1000000000000000;

                //printf ("%i \n", cardcheck_v2);
                if (cardcheck_v2 == 4)
                {
                    printf("VISA \n");
                }

            }
            else if (cardcheck < 10000000000000 && cardcheck > 999999999999)
            {
                int cardcheck_v1 = cardcheck / 1000000000000;
                if (cardcheck_v1 == 4)
                {
                    printf("VISA \n");
                }
            }
            else
            {
                printf("INVALID1 \n");
            }

        }
        else
            {
                printf("INVALID2 \n");
            }

    }
}
