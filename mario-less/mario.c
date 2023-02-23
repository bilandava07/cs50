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
    // printing out ( nesting loops )
    int rows =  h;
    int col = 0;
    for ( int i = 0; i < h; i++)
    {
        rows--;
        col++;
        for ( int j = 0; j < rows; j++)
        {
            printf(" ");
        }
        for ( int k = 0; k < col; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
