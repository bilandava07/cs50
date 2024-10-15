// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

void destroy_list(node *head);

// TODO: Choose number of buckets in hash table
const unsigned int N = 999;

// Hash table
node *table[N];

// global variable to keep track of the words added

int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // force to lower case
    int index;
    char word_copy[LENGTH + 1];

    int counter = 0;
    while (word[counter] != '\0')
    {
        word_copy[counter] = tolower(word[counter]);
        counter++;
    }
    word_copy[counter] = '\0';

    index = hash(word_copy);

    if (table[index] == NULL)
    {
        return false;
    }

    // ptr to traverse through the list is set to the head of the list
    node *ptr = table[index];

    while (true)
    {
        // if found
        if (strcmp(ptr->word, word_copy) == 0)
        {
            return true;
        }
        // if end of the list
        if (ptr->next == NULL)
        {
            return false;
        }
        // go to the next node
        ptr = ptr->next;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int index = 0;

    int sum = 0;
    int counter = 0;
    while (word[counter] != '\0')
    {
        if (word[counter] == '\'')
        {
            sum += '\'';
        }
        else
        {
            sum += (word[counter]);
        }
        counter++;
    }
    
    if (sum > 999)
    {
        do
        {
            sum -= 1000;
        }
        while (sum > 999);
    }

    index = sum;

    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // create a buffer for new node
    node *new_node;
    // preset the whole hash table to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // open the file and check the pointer
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open the file!");
        return false;
    }

    // create a buffer to store a word
    char word[LENGTH + 1];
    // create a buffer for the index returned by the hash function
    int index;
    // read one word at a time until reached the EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not allocate space for a new node!");
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        index = hash(word);

        // if the linked list is empty, set the head of the list to be pointing to the new_node
        if (table[index] == NULL)
        {
            table[index] = new_node;
        }
        // the list is not empty -> insert the new_node at the beginning of the linked list
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        destroy_list(table[i]);
    }

    return true;
}

void destroy_list(node *head)
{
    if (head == NULL)
    {
        return;
    }

    destroy_list(head->next);
    free(head);
}
