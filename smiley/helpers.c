#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixel1 = image[2][0];
    pixel1.rgbtBlue = 255;

    image[3][0].rgbtBlue = 255;
}
