#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for bill before input float
    float bill;
    do
    {
        bill = get_float("Bill before taxes and tip: ");
    }
    while ( bill < 0 );

    // ask for sale tax percent
    float tax;
    do
    {
         tax = get_float("Sale Tax Percent: ");
    }
    while ( tax < 0 );

    // ask for tip percent
    int tip;
    do
    {
        tip = get_int("Tip percent: ");
    }
    while ( tip < 0 );

    //math
    float bill_tax;
    float end;

    bill_tax = bill + (bill * (tax/100));

    end = bill_tax + (bill_tax * ((float) tip/100));

    //end = end / 2;

    printf("%f \n", end);

}