#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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


    int jpeg_counter = 0;
    char filename[8];

    FILE *img;

    // Read from the card file
    while (fread(buffer, 1, sizeof(BLOCK_SIZE), card) == 1)
    {
        // If start of new jpg
        if ((buffer[0] == 0xff) & (buffer[1] == 0xd8) & (buffer[2] == 0xff) & ((buffer[3] & 0xf0) & 0xe0))
        {
            // If it is the first JPEG found
            if (jpeg_counter == 0)
            {
                sprintf(filename, "%03i.jpg", jpeg_counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, sizeof(BLOCK_SIZE), img);
            }

            // Then next JPEG have been found
            else
            {
                // Close previous JPEG
                fclose(img);
                jpeg_counter++;

                // Open a new JPEG and start writing to it
                sprintf(filename, "%03i.jpg", jpeg_counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, sizeof(BLOCK_SIZE), img);
            }
        }
        // If not start of a new JPEG
        else
        {
            // If already found a JPEG
            if (jpeg_counter > 0)
            {
                fwrite(buffer, 1, sizeof(BLOCK_SIZE), img);
            }
        }
    }
    fclose(img);
    free(buffer);

}
