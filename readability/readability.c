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

    float avrg_l = (float) letters / (float) words;
    float avrg_s = (float) words / (float) sentences;

    int grade = round(0.0588 * avrg_l - 0.296 * avrg_s - 15.8);

    printf("Grade %i", grade);

}


