#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cs50.h>


int main (void)

{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;

    //count everything in one loop instead of going through the same string 3 times with different functions (my inital approach)
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    //add 1 to words, as there is no blank space at the end of the string
    words++;

    float avrg_l = (float) letters / (float) words * 100;
    float avrg_s = (float) sentences / (float) words * 100;

    int grade = round(0.0588 * avrg_l - 0.296 * avrg_s - 15.8);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


