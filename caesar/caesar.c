#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits (string key);
char rotate (int key, char char1);

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

    string ptext = get_string("plaintext: ");

    string ctext =  NULL;

    for (int i = 0; i < strlen(ptext); i++)
    {
        ctext[i] = rotate(key_int, ptext[i]);
    }

    printf("cyphertext: %s \n", ctext);
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

char rotate (int key, char char1)
{
    if (!isalpha(char1))
    {
        return char1;
    }

    if (isupper(char1))
    {
        int converted = char1 - 65;

        int cypher = ( converted + key ) % 26;

        cypher += 65;

        return cypher;

    }

    if(islower(char1))
    {
        int converted_lower = char1 - 97;

        int cypher = ( converted_lower + key) % 26;

        cypher += 97;

        return cypher;
    }
    return 1;
}