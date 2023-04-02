#include <stdio.h>
#include <cs50.h>
#include <stirng.h>

int main(void)
{
    bool lower = true;
    do
    {
        string word = get_string("Word: ");

        int lenght = strlen(word);
        for (int i = 0; i < lenght; i++)
        {
            if (word[i] < 97 || > 122)
            {
                lower = false;
            }

        }
    while ( lower = false)
}