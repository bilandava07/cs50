#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("How tall should the pyramides be? ");
    }
    while(height < 1 || height > 8);

    int blanks = height - 1;
    int hashes = 1;

    // loop for the amount of rows
    for (int i = 0; i < height; i++)
    {
        for (int y = blanks; y != 0; y--)
        {
            printf(" ");
        }
        for (int z = hashes; z != 0; z--)
        {
            printf("#");
        }

        printf("  ");

        for (int z = hashes; z != 0; z--)
        {
            printf("#");
        }

        blanks--;
        hashes++;
        printf("\n");

    }
}
