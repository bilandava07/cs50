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
        return 1;
    }

    // Open the memory card file for reading

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open the file!\n");
        return 2;
    }

    // Create buffer

    BYTE *buffer = malloc(BLOCK_SIZE);
    if (buffer == NULL)
    {
        return 3;
    }


    int jpeg_counter = 0;
    char filename[8];

    FILE *img;

    // Read from the card file
    fseek(card, 0, SEEK_END);
    long fileSize = ftell(card);
    fseek(card, 0, SEEK_SET);
    printf("File size: %ld bytes\n", fileSize);

    long position = ftell(card);
    printf("File pointer position before fread: %ld\n", position);

    size_t bytesRead = fread(buffer, 1, BLOCK_SIZE, card);
    printf("Bytes read: %zu\n", bytesRead);

    while (fread(buffer, BLOCK_SIZE, 1, card) == 1)
    {
        // If start of new jpg
        if ((buffer[0] == 0xff) & (buffer[1] == 0xd8))
        {
            printf("found\n");
        }
        if ((buffer[0] == 0xff) & (buffer[1] == 0xd8) & (buffer[2] == 0xff) & ((buffer[3] & 0xf0) & 0xe0))
        {
            // If it is the first JPEG found
            if (jpeg_counter == 0)
            {
                sprintf(filename, "%03i.jpg", jpeg_counter);
                img = fopen(filename, "w");
                if (img == NULL)
                {
                return 3;
                }
                fwrite(buffer, 1, BLOCK_SIZE, img);
                jpeg_counter++;

            }

            // Then next JPEG have been found
            else
            {
                // Close previous JPEG
                fclose(img);

                // Open a new JPEG and start writing to it
                sprintf(filename, "%03i.jpg", jpeg_counter);
                img = fopen(filename, "w");
                if (img == NULL)
                {
                return 3;
                }

                fwrite(buffer, 1, BLOCK_SIZE, img);
                jpeg_counter++;
            }
        }
        // If not start of a new JPEG
        else
        {
            // If already found a JPEG
            if (jpeg_counter > 0)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }
    }
    fclose(img);
    free(buffer);

}
