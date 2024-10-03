#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < width; y++)
        {
            avg = (image[i][y].rgbtBlue + image[i][y].rgbtGreen + image[i][y].rgbtRed) / 3;

            image[i][y].rgbtBlue = avg;
            image[i][y].rgbtGreen = avg;
            image[i][y].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < width; y++)
        {
            int red = round(.393 * image[i][y].rgbtRed + .769 * image[i][y].rgbtGreen + .189 * image[i][y].rgbtBlue);
            int green = round(.349 * image[i][y].rgbtRed + .686 * image[i][y].rgbtGreen + .168 * image[i][y].rgbtBlue);
            int blue = round(.272 * image[i][y].rgbtRed + .534 * image[i][y].rgbtGreen + .131 * image[i][y].rgbtBlue);

            if (red > 255)
                image[i][y].rgbtRed = 255
            else
                image[i][y].rgbtRed = red;

            if (green > 255)
                image[i][y].rgbtGreen = 255;
            else
                image[i][y].rgbtGreen = green;

            if (blue > 255)
                image[i][y].rgbtBlue = 255;
            else
                image[i][y].rgbtBlue = blue;
        }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
