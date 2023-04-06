#include <cs50.h>
#include <stdio.h>

bool only_digits (string key);

int main(int argc, string argv[])
{
    if ( argc != 2)
    {
        printf("Usage: ./ caesar key \n");
        return 1;
    }
    bool check = only_digits(argv[1]);
    if ( check == false)
    {
        printf("Usage: ./ caesar key \n");
        return 1;
    }
}

bool only_digits (string key)
{
    int start = 49;
    for (int i = 0; i < 9; i++)
    {
        if ( key == start)
        {
            return true;
            break
        }
        start++;
    }
    return false;
}