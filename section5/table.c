#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

node *table[26];

int hash(string phrase);

int main(void)
{
    

}


int hash(string phrase)
{
    return toupper(phrase[0] - 'A');
    // A = 65
    // A - A = 0
    // B - A = 1
    // Z - A = 25
}
