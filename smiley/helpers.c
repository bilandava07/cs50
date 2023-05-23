#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixel1 = image[2][0];
    pixel1.rgbtBlue = 255;

    image[2][0].rgbtBlue = 255;
    image[3][0].rgbtBlue = 255;
    image[4][0].rgbtBlue = 255;
    image[5][0].rgbtBlue = 255;

    image[2][7].rgbtBlue = 255;
    image[3][7].rgbtBlue = 255;
    image[4][7].rgbtBlue = 255;
    image[5][7].rgbtBlue = 255;

    image[7][2].rgbtBlue = 255;
    image[7][3].rgbtBlue = 255;
    image[7][4].rgbtBlue = 255;
    image[7][5].rgbtBlue = 255;

    image[0][2].rgbtBlue = 255;
    image[0][3].rgbtBlue = 255;
    image[0][4].rgbtBlue = 255;
    image[0][5].rgbtBlue = 255;

    image[2][0].rgbtBlue = 255;
    image[3][0].rgbtBlue = 255;
    image[4][0].rgbtBlue = 255;
    image[5][0].rgbtBlue = 255;

    image[1][1].rgbtBlue = 255;

    image[1][6].rgbtBlue = 255;

    image[6][1].rgbtBlue = 255;

    image[6][6].rgbtBlue = 255;

    image[2][2].rgbtBlue = 255;

    image[2][5].rgbtBlue = 255;

    image[4][2].rgbtBlue = 255;

    image[4][5].rgbtBlue = 255;

    image[5][3].rgbtBlue = 255;

    image[5][4].rgbtBlue = 255;







}
