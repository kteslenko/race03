#include "header.h"

int main(int argc, char *argv[]) {
	if (argc != 2 && (argv[1][0] != '-' && argv[1][1] != 's')) {
		mx_printerr("usage: ./matrix_rain [-s]\n");
		exit(-1);
	}
		
    srand(time(NULL));
    initscr();
    curs_set(0);
    init_colors();
    
	mx_intro();
	setlocale(LC_ALL, "");
    matrix_rain(japanese_runeset(), static_colorset(2), 80);

    endwin();
}
