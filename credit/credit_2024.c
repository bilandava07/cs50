#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int counter = 0;
    long number = get_long("Number: ");

    int right_most = 0;
    int other = 0;
    while (number != 0)
    {
        right_most += (number % 10);
        number = number / 10;
        counter++;

        if (number !=0)
        {
            int tmp_other = number % 10;
            number = number / 10;
            counter++;
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

    }
    int sum = right_most + other;

    printf("sum = %i\n", sum);
    printf("The number is %i digits long.\n", counter);

}
