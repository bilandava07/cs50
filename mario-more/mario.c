#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for input
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while ( h < 1 || h > 8);

    // build the pyramids

    int ind = h;
    for ( int i = 0; i < h; i++)
    {
        ind--;
        for ( int j = 0; j < ind; j++)
        {
            printf(".");
        }
        printf("\n");
    }
    printf("\n");



}