#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

#define LIST_SIZE 2

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL;

    for(int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        node *n = malloc(sizeof(node));
        n->phrase = phrase;
        n->next = NULL;

        list = n;

    }
}
