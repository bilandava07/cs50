#include "helpers.h"
#include <math.h>


int lesser (int a, int b);


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

            image[i][y].rgbtRed = lesser(red, 255);
            image[i][y].rgbtGreen = lesser(green, 255);
            image[i][y].rgbtBlue = lesser(blue, 255);
        }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n;
    int tmp_blue;
    int tmp_green;
    int tmp_red;

    if (width % 2 == 0)
        n = (width / 2) - 1;
    else
        n = width / 2

    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < n; y++)
        {
            tmp_blue = image[i][y].blue;
            tmp_green = iamge[i][y].green;
            tmp_red = image[i][y].red;

            image[i][y].blue = image[i][width-(y+1)].blue;
            image[i][y].green = image[i][width-(y+1)].green;
            image[i][y].red = image[i][width-(y+1)].red;

            image[i][width-(y+1)].blue = tmp_blue;
            image[i][width-(y+1)].green = tmp_green;
            image[i][width-(y+1)].red = tmp_red;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}


// returns lesser out of two integers
int lesser (int a, int b)
{
    if (a < b)
        return a;
    else if (b < a)
        return b;
    else
        return b;

}
