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
        printf(" function exit \n");
        return 1;
    }
    printf("Succes \n");
}

bool only_digits (string key)
{
    int start = 49;
    for (int i = 0; i < 8; i++)
    {
        if ( key[0] == start)
        {
            return true;
        }
        start++;
    }
    return false;
}