#ifndef MY_LIB_H
#define MY_LIB_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "splash_screen.h"
#include "win_screen.h"
#include "game_over.h"
#include "mario_left.h"
#include "mario_right.h"
#include "mario_buttcheek.h"
#include "kong_array.h"
#include "barrel_one.h"
#include "barrel_two.h"
#include "barrel_three.h"
#include "barrel_four.h"

#include "hardware.h"

#define SCREENHEIGHT 149
#define SCREENWIDTH 240

#define BG2_ENABLE (1 << 10)
#define COLOR(r, g, b) ((r) | (g) << 5 | (b) << 10)
#define RED COLOR(31, 0, 0)
#define GREEN COLOR(0, 31, 0)
#define BLUE COLOR(0, 0, 31)
#define YELLOW COLOR(31, 31, 0)
#define WHITE COLOR(31, 31, 31)
#define OFFSET(r, c, rowlen) ((r)*(rowlen)+(c))
#define BLACK COLOR(0, 0, 0)
#define BROWN COLOR(165, 42, 42)
#define GRAY COLOR (26, 26, 26)

extern const unsigned char fontdata_6x8[12288];

// Buttons

#define BUTTON_A		(1<<0)
#define BUTTON_B		(1<<1)
#define BUTTON_SELECT	(1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT		(1<<5)
#define BUTTON_UP		(1<<6)
#define BUTTON_DOWN		(1<<7)
#define BUTTON_R		(1<<8)
#define BUTTON_L		(1<<9)

#define KEY_DOWN_NOW(key) (~(BUTTONS) & key)

typedef struct
{
	const volatile void *src;
	volatile void *dst;
	unsigned int cnt;

} DMA_CONTROLLER;

struct MARIO
{
	int row;
	int col;
	int prev_row;
	int prev_col;
	int width;
	int height;
	int is_left;
};

struct BARREL
{
	int row;
	int col;
	int width;
	int height;
	int orientation;
};

struct LADDER
{
	int row;
	int col;
	int width;
	int height;
};

struct DONKEY_KONG
{
	int row;
	int col;
	int width;
	int height;
};

// Prototypes
void setPixel(int row, int col, unsigned short color);
void drawRect(int row, int col, int height, int width, unsigned short color);
void delay(int n);
void waitForVblank(void);
void drawChar(int row, int col, char ch, unsigned short color);
void drawString(int row, int col, char str[], unsigned short color);
void drawHorizontal(int col, int width, int row, unsigned int color);
void drawRect2(int row, int col, int height, int width, unsigned short color);
void drawFullscreenImage(const unsigned short *image);
void drawImage3(int row, int col, int height, int width, const unsigned short *image);
void drawLadder(int row, int col, int height, int width, unsigned int color);
void background(int height, int width, unsigned short color);
void drawVertical(int row, int col, int height, int width, unsigned int color);
int hitBarrel(int row_one, int col_one, int height_one, int width_one, int row_two, int col_two, int height_two, int width_two);

enum
{
	START,
	GAME,
	LOSE,
	WIN,
	PAUSE
};

extern int state;
extern int score;
extern char buffer[ 41 ];

extern struct MARIO mario;
extern struct DONKEY_KONG donkey_kong;
extern struct LADDER ladder_one;
extern struct LADDER ladder_two;
extern struct BARREL barrel_level_one;
extern struct BARREL barrel_level_two;
extern struct BARREL barrel_level_three;

extern uint16_t bgcolor;
extern bool up;
extern bool paused;

#endif /* MY_LIB_H */
