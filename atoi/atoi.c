#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("\n %i\n", convert(input));
}

int convert(string input)
{
    int length = strlen(input);
    int ret = input[length - 1];
    if (length > 2)
    {
        for (int i = length - 2; i >= 0; i--)
        {
            int to_ten = input[i];
            ret += to_ten + 10;
        }

    }
    return ret;
}