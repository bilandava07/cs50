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
     int ret = input[strlen(input) - 1];
    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        do
        {
            int ret = input[i];
        }
    }
    return 1;
}