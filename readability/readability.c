#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int str_length;

int count_letters(string text_f);
int count_words(string text_f);

int main(void)
{
    string text = get_string("Text: ");

    str_length = strlen(text);
    printf("The string is %i charachters long \n", str_length);

    int num_letters = count_letters(text);

    printf ("The text contains %i letters \n", num_letters);






}

int count_letters(string text_f)
{
    int letters = 0;
    for (int i = 0; i < str_length; i++)
    {
        if (islower(text_f[i]))
        {
            letters++;
        }
        else if (isupper(text_f[i]))
        {
            letters++;
        }
    }
    return letters;

}

int count_words(string text_f)
{
    int words = 0;
    for (int i = 0; i < str_length; i++)
    {
        if
    }
}
