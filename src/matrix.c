#include "header.h"

static wchar_t **realloc_buf(wchar_t **buf, int cols, int rows) {
    int new_rows;
    int new_cols;
    wchar_t **new_buf;

    getmaxyx(stdscr, new_rows, new_cols);
    new_buf = malloc(sizeof(wchar_t*) * new_cols);
    for (int i = 0; i < new_cols; i++) {
        new_buf[i] = malloc(sizeof(wchar_t) * new_rows);
        for (int j = 0; j < new_rows; j++) {
            if (buf != NULL && i < cols && j < rows) {
                new_buf[i][j] = buf[i][j];
                continue;
            }
            new_buf[i][j] = ' ';
        }
    }

    if (buf != NULL) {
        for (int i = 0; i < cols; i++) {
            free(buf[i]);
        }
        free(buf);
    }

    return new_buf;
}

static void handle_resize(t_matrix *matrix) {
    int temp_cols;
    int temp_rows;

    getmaxyx(stdscr, temp_rows, temp_cols);
    temp_cols /= 2;
    temp_rows += 1;
    if (temp_cols == matrix->cols
        && temp_rows == matrix->rows) {
        return;
    }

    matrix->buf = realloc_buf(matrix->buf, matrix->cols, matrix->rows);
    matrix->cols = temp_cols;
    matrix->rows = temp_rows;
}

static void print_matrix(t_matrix *matrix, t_runeset *runeset) {
    bool first = true;

    for (int i = 0; i < matrix->cols; i++) {
        for (int j = matrix->rows - 1; j >= 0; j--) {
            if (matrix->buf[i][j] == ' ') {
                first = true;
                mvprintw(j, i * 2, "%lc", matrix->buf[i][j]);
                continue;
            }
            if (first) {
                attroff(COLOR_PAIR(2));
                attron(COLOR_PAIR(1));
            }
            else {
                attroff(COLOR_PAIR(1));
                attron(COLOR_PAIR(2));
            }
            matrix->buf[i][j] = get_rune(runeset);
            mvprintw(j, i * 2, "%lc", matrix->buf[i][j]);
            first = false;
        }
        first = true;
    }
}

static bool probability(int percent) {
    return rand() % 100 < percent;
}

static void move_down(t_matrix *matrix) {
    for (int i = 0; i < matrix->cols; i++) {
        for (int j = matrix->rows - 1; j >= 0; j--) {
            if (j > 0) {
                matrix->buf[i][j] = matrix->buf[i][j - 1];
            }
            else {
                matrix->buf[i][j] = ' ';
            }
        }
    }
}

static t_matrix *new_matrix() {
    t_matrix *matrix = malloc(sizeof(t_matrix));

    matrix->buf = NULL;
    matrix->cols = 0;
    matrix->rows = 0;

    return matrix;
}

static void del_matrix(t_matrix *matrix) {
    if (matrix == NULL) {
        return;
    }
    if (matrix->buf != NULL) {
        for (int i = 0; i < matrix->cols; i++) {
            free(matrix->buf[i]);
        }
        free(matrix->buf);
    }
    free(matrix);
}

static void fill_first_row(t_matrix *matrix, t_runeset *runeset) {
    for (int i = 0; i < matrix->cols; i++) {
        if (matrix->buf[i][1] == ' ') {
            if (probability(2)) {
                matrix->buf[i][0] = get_rune(runeset);
            }
        }
        else {
            if (probability(7)) {
                matrix->buf[i][0] = ' ';
            }
            else {
                matrix->buf[i][0] = get_rune(runeset);
            }
        }
    }
}

void matrix_rain(t_runeset *runeset, int timeout) {
    t_matrix *matrix = new_matrix();

    while (true) {
        handle_resize(matrix);
        move_down(matrix);
        fill_first_row(matrix, runeset);
        clear();
        print_matrix(matrix, runeset);
        refresh();
        timeout(timeout);
        if (getch() == 'q') {
            break;
        }
    }

    del_matrix(matrix);
}