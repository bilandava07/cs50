#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int str_length;

int count_letters(string text_f);
int count_words(string text_f);
int count_sent(string text_f);

int main(void)
{
    string text = get_string("Text: ");

    str_length = strlen(text);
    printf("The string is %i charachters long \n", str_length);

    int num_letters = count_letters(text);
    printf ("The text contains %i letters \n", num_letters);

    int num_words = count_words(text);
    printf ("The text contains %i words \n", num_words);

    int num_sent = count_sent(text);
    printf("The text contains %i sentences \n", num_sent);

    int avrg_l = num_letters / num_words * 100;
    int avrg_s = num_sent / num_words * 100;

    int grade = 0.0588 * avrg_l - 0.296 * avrg_s - 15.8;

    printf("Grades: %i \n", grade);

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
    int spaces = 0;
    int words;
    for (int i = 0; i < str_length; i++)
    {
        if (isspace(text_f[i]))
        {
            spaces++;
        }
    }
    words = spaces + 1;
    return words;
}

int count_sent(string text_f)
{
    int sent = 0;

    for (int i = 0; i < str_length; i++)
    {
        if (text_f[i] == '!' || text_f[i] == '.' || text_f[i] == '?')
            {
                sent++;
            }
    }
    return sent;
}

