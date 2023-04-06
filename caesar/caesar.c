#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_digits (string key);

int main(int argc, string argv[])
{
    if ( argc != 2)
    {
        printf("Usage: ./ caesar key \n");
        return 1;
    }
    if ( only_digits(argv[1]) == false)
    {
        printf(" function exit \n");
        return 1;
    }
    printf("Succes \n");
}

bool only_digits (string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}