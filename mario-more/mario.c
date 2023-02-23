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
    // ind - indent; fc = first column;

    int ind = h;
    int fc = 0;
    for ( int i = 0; i < h; i++)
    {
        ind--;
        fc++;
        for ( int j = 0; j < ind; j++)
        {
            printf(" ");
        }
        for ( int j = 0; j < fc; j++)
        {
            printf("#");
        }
        printf("  ");
        for ( int j = 0; j < fc; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}