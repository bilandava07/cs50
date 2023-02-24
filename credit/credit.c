#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //promt for input
    do
    {
        long card;
        card = get_long("Number: ");
    }
    while ( card < 1000000000000 || card > 9999999999999999);

}