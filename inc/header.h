#pragma once

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

typedef struct s_colorset {
    int *colors;
    int count;
    void (*set_head_color)(struct s_colorset *colorset);
    void (*set_tail_color)(struct s_colorset *colorset);
}              t_colorset;

int mx_strlen(const char *s);
void mx_printerr(const char *s);
void matrix_rain(t_runeset *runeset, t_colorset *colorset, int timeout);
void mx_intro();

t_runeset *ascii_runeset();
t_runeset *japanese_runeset();
t_runeset *mathematical_runeset();
wchar_t get_rune(t_runeset *runeset);

void init_colors();
t_colorset *random_colorset();
t_colorset *static_colorset(int color);
