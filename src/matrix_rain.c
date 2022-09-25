#include "header.h"

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    init_colors();

    matrix_rain(japanese_runeset(), 80);

    endwin();
}
