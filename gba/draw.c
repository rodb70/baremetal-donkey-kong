#include "my-lib.h"

void drawRect(int row, int col, int height, int width, unsigned short color)
{
    for( int r = 0; r < height; r++ )
    {
        DMA[3].src = &color;
        DMA[3].dst = &videoBuffer[OFFSET( row + r, col, 240 )];
        DMA[3].cnt = (width) | DMA_ON | DMA_DESTINATION_INCREMENT | DMA_SOURCE_FIXED;
    }
}


void background(int height, int width, unsigned short color)
{
    DMA[3].src = &color;
    DMA[3].dst = videoBuffer;
    DMA[3].cnt = (width * height) | DMA_ON | DMA_DESTINATION_INCREMENT | DMA_SOURCE_FIXED;
}

void drawFullscreenImage(const unsigned short *image)
{
    DMA[3].src = image;
    DMA[3].dst = videoBuffer;
    DMA[3].cnt = (240 * 160) | DMA_ON | DMA_DESTINATION_INCREMENT | DMA_SOURCE_INCREMENT;
}

void drawImage3(int row, int col, int height, int width, const unsigned short *image)
{
    for( int r = 0; r < height; r++ )
    {
        DMA[3].src = &image[OFFSET( r, 0, width )];
        DMA[3].dst = &videoBuffer[OFFSET( row + r, col, SCREENWIDTH )];
        DMA[3].cnt = (width) | DMA_ON | DMA_DESTINATION_INCREMENT | DMA_SOURCE_INCREMENT;
    }
}

void drawHorizontal(int row, int col, int width, unsigned int color)
{
    DMA[3].src = &color;
    DMA[3].dst = &videoBuffer[OFFSET( row, col, SCREENWIDTH )];
    DMA[3].cnt = (width) | DMA_ON | DMA_DESTINATION_INCREMENT | DMA_SOURCE_FIXED;
}

void drawVertical(int row, int col, int height, int width, unsigned int color)
{
    for( int r = 0; r < height; r++ )
    {
        DMA[3].src = &color;
        DMA[3].dst = &videoBuffer[OFFSET( row + r, col, SCREENWIDTH )];
        DMA[3].cnt = (width) | DMA_ON | DMA_DESTINATION_INCREMENT | DMA_SOURCE_FIXED;
    }
}




