#include "header.h"

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    init_colors();

    matrix_rain(japanese_runeset(), static_colorset(2), 80);

    endwin();
}
