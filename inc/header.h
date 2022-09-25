#pragma once

#define _XOPEN_SOURCE_EXTENDED

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <curses.h>

typedef struct s_matrix {
    wchar_t **buf;
    int cols;
    int rows;
}              t_matrix;

typedef struct s_runeset {
    wchar_t *runes;
    int size;
}              t_runeset;

void matrix_rain(t_runeset *runeset, int timeout);

t_runeset *ascii_runeset();
t_runeset *japanese_runeset();
t_runeset *mathematical_runeset();
wchar_t get_rune(t_runeset *runeset);

void init_colors();
