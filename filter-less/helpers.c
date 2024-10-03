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
    for (int c1 = 0; c1 < height; c1++)
    {
        for (int c2 = 0; c2 < width; c2++)
        {
            copy[c1][c2] = image[c1][c2];
        }
    }


    int block_height;
    int block_width;

    int sum_blue;
    int sum_green;
    int sum_red;

    int avg_blue;
    int avg_green;
    int avg_red;

    int start;
    int end;

    // the inner block (3x3) // middle pixels
    block_height = 3;
    block_width = 3;

    //2 outer loops iterate through the inner block
    for (int i = 1; i < height - 1; i++)
    {
        for (int y = 1; y < width - 1; y++)
        {
            //block loops
            sum_blue = 0;
            sum_green = 0;
            sum_red = 0;

            start = i - 1;
            end = y - 1;

            for (int z = start; z < start + block_height; z++)
            {
                {
                    for (int c = end; c < end + block_width; c++)
                    {
                        sum_blue += copy[z][c].rgbtBlue;
                        sum_green += copy[z][c].rgbtGreen;
                        sum_red += copy[z][c].rgbtRed;
                    }
                }
            }
            image[i][y].rgbtBlue = round(sum_blue / (block_height * block_width * 1.0));
            image[i][y].rgbtGreen = round(sum_green / (block_height * block_width * 1.0));
            image[i][y].rgbtRed = round(sum_red / (block_height * block_width * 1.0));
        }

    }
    // corner pixels 2x2 blocks

    int corner_arr [8] = {0,0,height-1,0,0,width-1,height-1,width-1};

    block_height = 2;
    block_width = 2;

    sum_blue = 0;
    sum_green = 0;
    sum_red = 0;

    for (int corner = 0; corner < 7; corner += 2)
    {

        start = corner;
        end = corner + 1;
        
        for (int z = start; z < start + block_height; z++)
        {
            {
                for (int c = end; c < end + block_width; c++)
                {
                    sum_blue += copy[z][c].rgbtBlue;
                    sum_green += copy[z][c].rgbtGreen;
                    sum_red += copy[z][c].rgbtRed;
                }
            }
        }
        image[0][0].rgbtBlue = round(sum_blue / (block_height * block_width * 1.0));
        image[][y].rgbtGreen = round(sum_green / (block_height * block_width * 1.0));
        image[i][y].rgbtRed = round(sum_red / (block_height * block_width * 1.0));
    }




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

