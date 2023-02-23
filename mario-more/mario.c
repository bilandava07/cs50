#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: \n");
    }
    while ( h < 1 || h > 8);


}