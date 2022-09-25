#include "header.h"

void init_colors() {
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
}

static void set_color(int color) {
	for (int i = 1; i <= 7; i++) {
		attroff(COLOR_PAIR(i));
	}
	attron(COLOR_PAIR(color));
}

static void random_head_color(t_colorset* colorset) {
	set_color(colorset->colors[0]);
}

static void random_tail_color(t_colorset* colorset) {
	set_color(colorset->colors[rand() % (colorset->count - 1) + 1]);
}

t_colorset *random_colorset() {
	static int colors[] = {1, 2, 3, 4, 5, 6, 7};
	static t_colorset colorset = {
		colors,
		7,
		random_head_color,
		random_tail_color,
	};

	return &colorset;
}

static void static_head_color(t_colorset* colorset) {
	set_color(colorset->colors[0]);
}

static void static_tail_color(t_colorset* colorset) {
	set_color(colorset->colors[1]);
}

t_colorset *static_colorset(int color) {
	static int colors[] = {1, 2};
	static t_colorset colorset = {
		colors,
		2,
		static_head_color,
		static_tail_color,
	};

	colors[1] = color;
	return &colorset;
}
