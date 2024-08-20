#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int str_length;

int count_letters(string text_f);
int count_words(string text_f);
int count_sent(string text_f);

int main(void)
{
    string text = get_string("Text: ");

    str_length = strlen(text);

    int num_letters = count_letters(text);

    int num_words = count_words(text);

    int num_sent = count_sent(text);

    float avrg_l = (float)num_letters / (float)num_words * 100;

    float avrg_s = (float)num_sent / (float)num_words * 100;

    float grade = 0.0588 * avrg_l - 0.296 * avrg_s - 15.8;

    if ((int) round(grade) >= 16)
    {
        printf("Grade 16+ \n");
        return 0;
    }
    else if ((int) round(grade) < 1)
    {
        printf("Before Grade 1 \n");

    }
    else
    {
        printf("Grades: %i \n", (int) round(grade));
    }
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

