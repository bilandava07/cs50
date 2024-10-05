#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover [name of the forensic image]\n");
    }

    // Open the memory card file for reading

    FILE *card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open the file!\n");
        return 2;
    }

    // Create buffer

    BYTE *buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);
    if (buffer == NULL)
    {
        return 3;
    }

    // Read from the card file

    while (fread(buffer, sizeof(BLOCK_SIZE), 1, card) == 1)
    {
        
    }

}
