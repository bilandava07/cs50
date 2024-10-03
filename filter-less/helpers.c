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
            avg = round((image[i][y].rgbtBlue + image[i][y].rgbtGreen + image[i][y].rgbtRed) / 3.0);

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

    n = width / 2;

    for (int i = 0; i < height; i++)
    {
        for (int y = 0; y < n; y++)
        {
            tmp_blue = image[i][y].rgbtBlue;
            tmp_green = image[i][y].rgbtGreen;
            tmp_red = image[i][y].rgbtRed;

            image[i][y].rgbtBlue = image[i][width-(y+1)].rgbtBlue;
            image[i][y].rgbtGreen = image[i][width-(y+1)].rgbtGreen;
            image[i][y].rgbtRed = image[i][width-(y+1)].rgbtRed;

            image[i][width-(y+1)].rgbtBlue = tmp_blue;
            image[i][width-(y+1)].rgbtGreen = tmp_green;
            image[i][width-(y+1)].rgbtRed = tmp_red;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }





    int inner_block = 3;
    int sum_inner;
    int avg;

    // the inner block (3x3)
    for (int i = 1; i < height - 1; i++)
    {
        for (int y = 1; y < width - 1; y++)
        {
            avg = avg_block(3,3, i, end, copy);
            set_all(i, y, avg, image);
        }
    }

    // corners (2x2)
    //top left


    set_all(0, 0, avg_block(), image)



    image[height-1][0]
    image[0][width-1]
    image[height-1][width]



    // edges (3x2)




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

// sets Red, Green and Blue to the provided value
void set_all(int a, int b, value, RGBTRIPLE image[height][width])
{
    image[a][b].rgbtBlue = value;
    image[a][b].rgbtGreen = value;
    image[a][b].rgbtRed = value;
}


// returns average of the block of variable size
int avg_block(int block_height, int block_width, int start, int end, RGBTRIPLE copy[height][width])
{
    int sum = 0;
    for(int z = start; z < block_height; z++)
    {
        for(int c = end; c < block_width; c++)
        {
            sum += copy[z][c];
        }
    }
    return round(sum / (block_height * block_width));
}
