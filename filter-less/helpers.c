#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
                float avrg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
                int rounded_avrg = (int) round(avrg);
                image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rounded_avrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float sepiaRed = (image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtBlue * 0.189);

            float sepiaGreen  = (image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtBlue * 0.168);

            float sepiaBlue = (image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtBlue * 0.131);

            if ((int) round(sepiaRed) > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = (int) round(sepiaRed);
            }


            if ((int) round(sepiaGreen) > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = (int) round(sepiaGreen);
            }

            if ((int) round(sepiaBlue ) > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = (int) round(sepiaBlue);
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int iter = width / 2;
    for(int i = 0; i < height; i++)
    {
        int left = 0;
        int right = width - 1;
        RGBTRIPLE ph;

        for(int j = 0; j < iter; j++)
        {
            ph.rgbtRed = image[i][left].rgbtRed;
            ph.rgbtGreen = image[i][left].rgbtGreen;
            ph.rgbtBlue = image[i][left].rgbtBlue;

            image[i][left].rgbtRed = image[i][right].rgbtRed;
            image[i][left].rgbtGreen = image[i][right].rgbtGreen;
            image[i][left].rgbtBlue = image[i][right].rgbtBlue;

            image[i][right].rgbtRed = ph.rgbtRed;
            image[i][right].rgbtGreen = ph.rgbtGreen;
            image[i][right].rgbtBlue = ph.rgbtBlue;

            left++;
            right--;
        }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create the copy of the 2D array "image"
    RGBTRIPLE copy[height][width];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }


    return;
}
