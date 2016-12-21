
#ifndef __CONIO_H
#define __CONIO_H

//
// http://linux-sxs.org/programming/kbhit.html
//
//

#include <termios.h>
#include <unistd.h>   // read()
#include <stdlib.h>  // ssytem()

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard();

void close_keyboard();

int kbhit();

int readch();

int getch();

void gotoxy(int x,int y);

void clrscr(void);

void flushall();

void clreol();

#endif
