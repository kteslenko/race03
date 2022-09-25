#include "../inc/header.h"

void mx_intro() {
	initscr();
	
	char str1[] = "Wake up, Neo..";
	char str2[] = "The Matrix has you..";
	char str3[] = "Follow the white rabbit";
	char str4[] = "Knock, knock, Neo";
	refresh();
	
	for (int a = 0; a < mx_strlen(str1); a++) {
		mvaddch(5, a + 4, str1[a] | COLOR_PAIR(2));
		refresh();
		usleep(150000);
	}
	usleep(100000);
	clear();
	refresh();
	
	for (int b = 0; b < mx_strlen(str2); b++) {
		mvaddch(5, b + 4, str2[b] | COLOR_PAIR(2));
		refresh();
		usleep(150000);
	}
	usleep(100000);
	clear();
	refresh();
	
	for (int c = 0; c < mx_strlen(str3); c++) {
		mvaddch(5, c + 4, str3[c] | COLOR_PAIR(2));
		refresh();
		usleep(150000);
	}
	usleep(100000);
	clear();
	refresh();
	
	for (int d = 0; d < mx_strlen(str4); d++) {
		mvaddch(5, d + 4, str4[d] | COLOR_PAIR(2));
		refresh();
		usleep(150000);
	}
	usleep(100000);
	clear();
	refresh();
}
