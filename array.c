#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n
    do
    {
        n = get_int("Size: ");

    }
    while (n < 1);

    int array[n];
    array[0] = 1;

    for (i = 1; i < n; i++)
    {
        array[i] = array[i-1] * 2;
    }
}