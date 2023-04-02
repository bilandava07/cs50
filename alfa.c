#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    bool lower = false;
    do
    {
        string word = get_string("Word: ");

        int lenght = strlen(word);
        for (int i = 0; i < lenght; i++)
        {
            if (word[i] > 97 || word[i] < 122)
            {
                lower = true;
            }
        }
    }
    while (lower == false);
    printf("lower indeed \n");
}
