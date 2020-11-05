#include <stdio.h>
#include "my-lib.h"

int state;
int score = 0;
char buffer[ 41 ];

struct MARIO mario;
struct DONKEY_KONG donkey_kong;
struct LADDER ladder_one;
struct LADDER ladder_two;
struct BARREL barrel_level_one;
struct BARREL barrel_level_two;
struct BARREL barrel_level_three;

uint16_t bgcolor = BLACK;
bool up = false;
bool paused = false;

void init( void )
{
    hardware_video_init( &bgcolor );

    snprintf(buffer, sizeof(buffer), "Score: %d", score);
    drawString( 150, 5, buffer, RED);

    // Initialise mario
    mario.row = SCREENWIDTH - 15;
    mario.col = SCREENHEIGHT - 36;
    mario.width = 15;
    mario.height = 16;
    mario.is_left = 1;

    // Initialise donkey_kong
    donkey_kong.row = 5;
    donkey_kong.col = 5;
    donkey_kong.width = 32;
    donkey_kong.height = 43;

    // Initialise ladder_one
    ladder_one.col = 40;
    ladder_one.row = SCREENWIDTH - 10;
    ladder_one.width = LADDER_WIDTH;
    ladder_one.height = 50;

    // Initialise ladder_two
    ladder_two.col = 90;
    ladder_two.row = 30;
    ladder_two.width = LADDER_WIDTH;
    ladder_two.height = 50;

    // Initialise barrel_one
    barrel_level_one.col = 40 - 10;
    barrel_level_one.row = SCREENWIDTH - 190;
    barrel_level_one.width = 10;
    barrel_level_one.height = 12;
    barrel_level_one.orientation = 0;

    // Initialise barrel_two
    barrel_level_two.col = 90 - 10;
    barrel_level_two.row = 30;
    barrel_level_two.width = 10;
    barrel_level_two.height = 12;
    barrel_level_two.orientation = 0;

    // Initialise barrel_three
    barrel_level_three.col = 140 - 10;
    barrel_level_three.row = 30;
    barrel_level_three.width = 10;
    barrel_level_three.height = 12;
    barrel_level_three.orientation = 0;

    drawFullscreenImage( splash_screen );
    snprintf(buffer, sizeof(buffer),  "Press 'Enter'." );
    drawString( 100, 80, buffer, WHITE );
    state = START;
    score = 0;
}

int main(void)
{
    init();

    while( 1 )
    {
        switch( state )
        {
        case START:
            if( KEY_DOWN_NOW( BUTTON_START ) )
            {
                state = GAME;
            }
            break;

        case GAME:
            if( KEY_DOWN_NOW( BUTTON_B ))
            {
                state = PAUSE;
            }
            if( KEY_DOWN_NOW( BUTTON_LEFT ))
            {
                if( mario.row > 1 )
                {
                    mario.row -= 2;
                    mario.is_left = 1;
                }
            }
            if( KEY_DOWN_NOW( BUTTON_RIGHT ))
            {
                if( mario.row < SCREENWIDTH - (mario.width + 1) )
                {
                    mario.row += 2;
                    mario.is_left = 0;
                }
            }
            if( KEY_DOWN_NOW( BUTTON_UP ))
            {
                if( mario.col > 0 )
                {
                    if( mario.row > ( ladder_two.row - LADDER_WIDTH ) && mario.row < ladder_two.row &&
                        mario.col > ( ladder_two.col - mario.height ) && mario.col < 125 )
                    {
                        mario.col--;
                        mario.is_left = 2;
                    }
                    else if( mario.row > ( ladder_one.row - LADDER_WIDTH ) && mario.row < ladder_one.row &&
                             mario.col > ( ladder_one.col - mario.height ) && mario.col < 75 )
                    {
                        mario.col--;
                        mario.is_left = 2;
                    }
                }
            }
            if( KEY_DOWN_NOW( BUTTON_DOWN ))
            {
                if( mario.col > 0 )
                {
                    if( mario.row > ( ladder_two.row - LADDER_WIDTH ) && mario.col < ladder_two.col &&
                        mario.col < 125 )
                    {
                        mario.col++;
                        mario.is_left = 2;
                    }
                    else if( mario.row > ( ladder_one.row - LADDER_WIDTH ) && mario.col < ladder_one.col &&
                             mario.col < 75 )
                    {
                        mario.col++;
                        mario.is_left = 2;
                    }
                }
            }

            if( !( mario.row > ( ladder_two.row - LADDER_WIDTH ) && mario.row < ladder_two.row ) &&
                    mario.col > ladder_two.height + mario.height + 8 )
            {
                if(( mario.col + mario.height < 140 ) && ( up == false ))
                {
                    mario.col += 2;

                    if( mario.col + mario.height > 140 )
                    {
                        up = false;
                        mario.col = 140;
                    }
                }
                else if(( mario.col + mario.height == 140) || up == true )
                {
                    if( KEY_DOWN_NOW( BUTTON_A ) )
                    {
                        if( mario.col > 140 - 48 )
                        {
                            up = true;
                        }
                    }

                    if( mario.col < 140 - 40 )
                    {
                        up = false;
                    }
                }
                if( up == true && mario.col > 0 )
                {
                    mario.col -= 2;
                }
            }
            else if( !(mario.row > ladder_one.row - 35 && mario.row < ladder_one.row ) &&
                     mario.col > mario.height + 8 )
            {
                if((( mario.col + mario.height ) < 90 ) && ( up == false ))
                {
                    mario.col += 2;

                    if( mario.col + mario.height > 90 )
                    {
                        up = false;
                        mario.col = 90;
                    }
                }
                else if(( mario.col + mario.height == 90 ) || ( up == true ))
                {
                    if( KEY_DOWN_NOW( BUTTON_A ) )
                    {
                        if( mario.row > 90 - 48 )
                        {
                            up = true;
                        }
                    }
                    if( mario.col < 90 - 40 )
                    {
                        up = false;
                    }
                }
                if( up == true && mario.col >= 2 )
                {
                    mario.col -= 2;
                }
            }
            else
            {
                if(( mario.col + mario.height < 40 ) && ( up == false ))
                {
                    mario.col += 2;

                    if( mario.col > 40 )
                    {
                        up = false;
                        mario.col = 40;
                    }
                }
                else if(( mario.col + mario.height == 40) || ( up == true ))
                {
                    if( KEY_DOWN_NOW( BUTTON_A ))
                    {
                        if( mario.col > 20 )
                        {
                            up = true;
                        }
                    }

                    if( mario.col <= 0 )
                    {
                        up = false;
                    }
                }

                if( up == true && mario.col > 0 )
                {
                    mario.col -= 2;
                }
            }

            //Draw background and floors
            background( SCREENHEIGHT, SCREENWIDTH, BLACK );
            drawHorizontal( 0, 40, SCREENWIDTH, RED );
            drawHorizontal( 0, 90, SCREENWIDTH, RED );
            drawHorizontal( 0, 140, SCREENWIDTH, RED );

            // Update barrel_one
            if( barrel_level_one.row > SCREENWIDTH - ( barrel_level_one.height + 1 ) )
            {
                barrel_level_one.row = SCREENWIDTH - 190;
            }
            else
            {
                barrel_level_one.row += 1;
            }
            if( barrel_level_one.orientation == 0 )
            {
                drawImage3( barrel_level_one.row, barrel_level_one.col,
                            barrel_level_one.width, barrel_level_one.height,
                            barrel_one );
                barrel_level_one.orientation = 1;
            }
            else if( barrel_level_one.orientation == 1 )
            {
                drawImage3( barrel_level_one.row, barrel_level_one.col,
                            barrel_level_one.width, barrel_level_one.height,
                            barrel_two );
                barrel_level_one.orientation = 2;
            }
            else if( barrel_level_one.orientation == 2 )
            {
                drawImage3( barrel_level_one.row, barrel_level_one.col,
                            barrel_level_one.width, barrel_level_one.height,
                            barrel_three );
                barrel_level_one.orientation = 3;
            }
            else
            {
                drawImage3( barrel_level_one.row, barrel_level_one.col,
                            barrel_level_one.width, barrel_level_one.height,
                            barrel_four );
                barrel_level_one.orientation = 0;
            }

            // Update barrel_two
            if( barrel_level_two.row < 4 )
            {
                barrel_level_two.row = SCREENWIDTH - ( barrel_level_two.height + 1 );
            }
            else
            {
                barrel_level_two.row -= 1;
            }

            if( barrel_level_two.orientation == 0 )
            {
                drawImage3( barrel_level_two.row, barrel_level_two.col,
                            barrel_level_two.width, barrel_level_two.height,
                            barrel_one );
                barrel_level_two.orientation = 1;
            }
            else if( barrel_level_two.orientation == 1 )
            {
                drawImage3( barrel_level_two.row, barrel_level_two.col,
                            barrel_level_two.width, barrel_level_two.height,
                            barrel_two );
                barrel_level_two.orientation = 2;
            }
            else if( barrel_level_two.orientation == 2 )
            {
                drawImage3( barrel_level_two.row, barrel_level_two.col,
                            barrel_level_two.width, barrel_level_two.height,
                            barrel_three );
                barrel_level_two.orientation = 3;
            }
            else
            {
                drawImage3( barrel_level_two.row, barrel_level_two.col,
                            barrel_level_two.width, barrel_level_two.height,
                            barrel_four );
                barrel_level_two.orientation = 0;
            }

            if( barrel_level_three.row > SCREENWIDTH - ( barrel_level_three.height + 1 ) )
            {
                barrel_level_three.row = 1;
            }
            else
            {
                barrel_level_three.row += 1;
            }

            if( barrel_level_three.orientation == 0 )
            {
                drawImage3( barrel_level_three.row, barrel_level_three.col,
                            barrel_level_three.width, barrel_level_three.height,
                            barrel_one );
                barrel_level_three.orientation = 1;
            }
            else if( barrel_level_three.orientation == 1 )
            {
                drawImage3( barrel_level_three.row, barrel_level_three.col,
                            barrel_level_three.width, barrel_level_three.height,
                            barrel_two );
                barrel_level_three.orientation = 2;
            }
            else if( barrel_level_three.orientation == 2 )
            {
                drawImage3( barrel_level_three.row, barrel_level_three.col,
                        barrel_level_three.width, barrel_level_three.height,
                        barrel_three );
                barrel_level_three.orientation = 3;
            }
            else
            {
                drawImage3( barrel_level_three.row, barrel_level_three.col,
                            barrel_level_three.width, barrel_level_three.height,
                            barrel_four );
                barrel_level_three.orientation = 0;
            }

            //Draw Donkey Kong
            drawImage3( donkey_kong.row, donkey_kong.col, donkey_kong.width, donkey_kong.height, kong_array );

            //Update Mario
            if( mario.is_left == 0 )
            {
                drawImage3( mario.row, mario.col, mario.width, mario.height, mario_right );
            }
            else if( mario.is_left == 1 )
            {
                drawImage3( mario.row, mario.col, mario.width, mario.height, mario_left );
            }
            else
            {
                drawImage3( mario.row, mario.col, mario.width, mario.height, mario_buttcheek );
            }

            // Update Ladder
            drawLadder( ladder_one.row, ladder_one.col, ladder_one.height, ladder_one.width, BLUE );
            drawLadder( ladder_two.row, ladder_two.col, ladder_two.height, ladder_two.width, BLUE );

            // Update Score barrel_three
            if( mario.col < 124 && mario.col > 100 && ( mario.row == barrel_level_three.row - 2 ))
            {
                score++;
            }
            else if( mario.col < 124 && mario.col > 100 && ( mario.row == barrel_level_three.row - 1 ))
            {
                score++;
            }
            else if( mario.col < 124 && mario.col > 100 && ( mario.row == barrel_level_three.row ))
            {
                score++;
            }
            else if( mario.col < 124 && mario.col > 100 && ( mario.row == barrel_level_three.row + 1 ))
            {
                score++;
            }
            else if( mario.col < 124 && mario.col > 100 && ( mario.row == barrel_level_three.row + 2 ))
            {
                score++;
            }
            // Update Score barrel_two
            else if( mario.col < 90 && mario.col > 40 && ( mario.row == barrel_level_two.row - 2 ))
            {
                score++;
            }
            else if( mario.col < 90 && mario.col > 40 && ( mario.row == barrel_level_two.row - 1 ))
            {
                score++;
            }
            else if( mario.col < 90 && mario.col > 40 && ( mario.row == barrel_level_two.row ))
            {
                score++;
            }
            else if( mario.col < 90 && mario.col > 40 && ( mario.row == barrel_level_two.row + 1 ))
            {
                score++;
            }
            else if( mario.col < 90 && mario.col > 40 && ( mario.row == barrel_level_two.row + 2 ))
            {
                score++;
            }
            // Update Score barrel_one
            else if( mario.col < 40 && ( mario.row == barrel_level_one.row - 2 ))
            {
                score++;
            }
            else if( mario.col < 40 && ( mario.row == barrel_level_one.row - 1 ))
            {
                score++;
            }
            else if( mario.col < 40 && ( mario.row == barrel_level_one.row ))
            {
                score++;
            }
            else if( mario.col < 40 && ( mario.row == barrel_level_one.row + 1 ))
            {
                score++;
            }
            else if( mario.col < 40 && ( mario.row == barrel_level_one.row + 2 ))
            {
                score++;
            }
            snprintf( buffer, sizeof( buffer ), "Score: %d", score);
            drawString(150, 5, buffer, GREEN);

            if(( mario.col < donkey_kong.col + donkey_kong.width ) && mario.row < 40 )
            {
                state = WIN;
            }

            if( hitBarrel( mario.row, mario.col, mario.height, mario.width,
                           barrel_level_one.row, barrel_level_one.col,
                           barrel_level_one.height, barrel_level_one.width ) ||
                hitBarrel( mario.row, mario.col, mario.height, mario.width,
                           barrel_level_two.row, barrel_level_two.col,
                           barrel_level_two.height, barrel_level_two.width ) ||
                hitBarrel( mario.row, mario.col, mario.height, mario.width,
                           barrel_level_three.row, barrel_level_three.col,
                           barrel_level_three.height, barrel_level_three.width ))
            {
                state = LOSE;
            }
            break;

        case WIN:
            drawFullscreenImage( win_screen );
            snprintf(buffer, sizeof(buffer),  "Score: %d", score );
            drawString( 150, 175, buffer, GREEN );
            break;

        case LOSE:
            drawFullscreenImage( game_over );
            snprintf(buffer, sizeof(buffer),  "Score: %d", score );
            drawString( 150, 175, buffer, GREEN );
            break;

        case PAUSE:
            //background(160, 240, BLACK);
            snprintf(buffer, sizeof(buffer),  "PAUSED" );
            drawString( 80, 105, buffer, WHITE );
            snprintf(buffer, sizeof(buffer),  "Press 'Enter'." );
            drawString( 100, 80, buffer, WHITE );
            if( KEY_DOWN_NOW( BUTTON_START ))
            {
                state = GAME;
            }
        }

        waitForVblank();
        if( KEY_DOWN_NOW( BUTTON_SELECT ) )
        {
            init();
        }
    }
}

void setPixel(int row, int col, unsigned short color)
{
    videoBuffer[ OFFSET( row, col, 240 )] = color; //pixel location = col + row * 240
}

void drawLadder(int row, int col, int height, int width, unsigned int color)
{
    //Draw ladder sides
    drawVertical( row, col, height, 1, color );
    drawVertical( row - width, col, height, 1, color );

    //Draw rungs
    drawHorizontal( row - width, col,     LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 5, LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 10, LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 15, LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 20, LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 25, LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 30, LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 35, LADDER_WIDTH, color );
    drawHorizontal( row - width, col + 40, LADDER_WIDTH, color );
}

int hitBarrel(int row_one, int col_one, int height_one, int width_one, int row_two, int col_two,
        int height_two, int width_two)
{

    return row_one < row_two + height_two - 1 && row_two < row_one + height_one - 1
            && col_one < col_two + width_two - 1 && col_two < col_one + width_one - 1;
}

void drawChar(int row, int col, char ch, unsigned short color)
{
    for( int r = 0; r < 8; r++ )
    {
        for( int c = 0; c < 6; c++ )
        {
            if( fontdata_6x8[OFFSET(r, c, 6) + ch * 48] == 1 )
            {
                setPixel( r + row, c + col, color );
            }
        }
    }
}

void drawString(int row, int col, char str[], unsigned short color)
{
    while( *str )
    {
        drawChar( row, col, *str++, color );
        col += 6;
    }
}
