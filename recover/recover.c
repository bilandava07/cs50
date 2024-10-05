#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
    }

    // Open the memory card file for reading

    FILE *card = fopen(argv[1], "r");
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


    int jpg_counter = 0;
    char *filename[7];

    // Read from the card file
    while (fread(buffer, sizeof(BLOCK_SIZE), 1, card) == 1)
    {
        // if start of new jpg
        if ((buffer[0] == 0xff) & (buffer[1] == 0xd8) & (buffer[2] == 0xff) & ((buffer[3] & 0xf0) & 0xe0))
        {
            // If it is the first jpg found
            if (jpg_counter == 0)
            {
                sprintf(filename, "%03i.jpg", jpg_counter);

            }
            else
            {


            }
        }
    }

}
