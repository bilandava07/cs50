#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for bill before input float
    do
    {
        float bill = get_float("Bill before taxes and tip: ");
    }
    while ( bill < 0 );

    // ask for sale tax percent
    do
    {
        float tax = get_float("Sale Tax Percent: ");
    }
    while ( tax < 0 );

    // ask for tip percent
    do
    {
        int tip = get_int("Tip percent: ");
    }
    while ( tip < 0 );

}