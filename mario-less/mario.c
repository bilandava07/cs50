#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for the height input int ( h = height )from 1 to 8 inclusively
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while ( h < 1 || h > 8 );
    // printing out (loops)
    int rows -= h;
    for ( int i = 0; i < h; i++)
    {
        rows--;
        for ( int j = 0; j > rows; j++)
        {
            printf(" ");
        }
        printf("#\n");
    }
}
