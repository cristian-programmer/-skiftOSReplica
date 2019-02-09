#pragma once

#include <skift/generic.h>
#include <skift/list.h>
#include <skift/lock.h>

#define CONSOLE_MAX_ATTR 8
#define CONSOLE_CELL_HEIGHT 16
#define CONSOLE_CELL_WIDTH 8

typedef enum 
{
    CCOLOR_DEFAULT_BACKGROUND,
    CCOLOR_DEFAULT_FORGROUND,

    CCOLOR_BLACK,
    CCOLOR_RED,
    CCOLOR_GREEN,
    CCOLOR_YELLOW,
    CCOLOR_BLUE,
    CCOLOR_MAGNETA,
    CCOLOR_CYAN,
    CCOLOR_LIGHT_GREY,

    CCOLOR_DARK_GREY,
    CCOLOR_LIGHT_RED,
    CCOLOR_LIGHT_GREEN,
    CCOLOR_LIGHT_YELLOW,
    CCOLOR_LIGHT_BLUE,
    CCOLOR_LIGHT_MAGNETA,
    CCOLOR_LIGHT_CYAN,
    CCOLOR_WHITE,
} console_color_t;

typedef enum 
{
    CSTATE_ESC,
    CSTATE_BACKET,
    CSTATE_ATTR,
    CSTATE_ENDVAL,
} console_state_t;

typedef struct
{
    char c;

    console_color_t fg;
    console_color_t bg;
} console_cell_t;

typedef struct
{
    console_cell_t *screen;

    uint cx;
    uint cy;
    uint w;
    uint h;

    console_state_t state;
    uint attr_stack[CONSOLE_MAX_ATTR];

    console_color_t fg;
    console_color_t bg;

} console_t;
 
 void console_setup();
 void console_print(const char *s);
 void console_getchar(char c);




