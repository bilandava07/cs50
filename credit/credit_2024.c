#include <stdio.h>
#include <cs50.h>

int main (void)
{
    sumcheck = False;
    int counter;
    long number = get_long number("Number: ");

    int right_most;
    int other;
    while (number != 0)
    {
        right_most += (number % 10);
        number = number / 10;

        tmp_other = number % 10;
        number = number / 10;
        tmp_other *= 2;

        if (tmp_other > 9)          // (10-18)
        {
            other += (tmp_other % 10);
            tmp_other = tmp_other / 10;
            other += tmp_other;
        }
        else                        // (0-9)
        {
            other += tmp_other;
        }

    }
    sum = rigth_most + other;

    if ((sum % 10) = 0)
    {
        
    }

}
