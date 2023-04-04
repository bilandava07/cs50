// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);
int str_len;

int main(void)
{
    string password;
    do
    {
        password = get_string("Enter your password: ");
        str_len = strlen(password);

        if (!valid(password))
        {
            printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol without any spaces.\n");

        }
    }
    while (!valid(password));


    printf("Your password is valid!\n");
}

bool valid(string password)
{
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;


    for (int i = 0; i < str_len; i++)
    {
        if (isupper(password[i]))
        {
            upper = true;
        }
        if (islower(password[i]))
        {
            lower = true;
        }
        if (isdigit(password[i]))
        {
            number = true;
        }
        if (ispunct(password[i]))
        {
            symbol = true;
        }
        if (isspace(password[i]))
        {
            return false;
        }
    }
    if ( upper == true && lower == true && number == true && symbol == true )
    {
        return true;
    }
    return 0;
}
