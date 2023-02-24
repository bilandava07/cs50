#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //promt for input
        long card;
        card = get_long("Number: ");
    if ( card < 1000000000000 || card > 9999999999999999)
    {
        printf("INVALID \n");
    }
    else
    {
        //calculate the checksum
        int mod = 0;
        for ( int i = 0; i > 16; i++)
        {
            card = 

        }
    }

}