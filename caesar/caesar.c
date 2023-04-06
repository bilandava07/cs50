#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
        printf("Usage: ./ caesar key \n");
        return 1;
    }
    printf("Succes \n");

    int key_int = atoi(argv[1]);
    printf("%i \n", key_int);

    string plaintext = get_string("plaintext: ");
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