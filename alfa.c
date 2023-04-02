#include <stdio.h>
#include <cs50.h>
#include <stirng.h>

int main(void)
{
    string word = get_string("Word: ");

    int lenght = strlen(word);

    for (int i = 0; i < lenght; i++)
    {
        if ( word[i] < word[i++])
    }
}