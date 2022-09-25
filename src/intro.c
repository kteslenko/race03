#include "header.h"

bool mx_intro(t_colorset *colorset, bool screensaver) {
	static const char *str[] = {
		"Wake up, Neo..",
		"The Matrix has you..",
		"Follow the white rabbit",
		"Knock, knock, Neo"
	};

	for (int i = 0; i < 4; i++) {
		clear();
		for (int j = 0; j < mx_strlen(str[i]); j++) {
			colorset->set_tail_color(colorset);
			mvaddch(5, j + 4, str[i][j]);
			refresh();
			timeout(100);
			if (is_exit(screensaver)) {
				return false;
			}
		}
		timeout(100);
		if (is_exit(screensaver)) {
			return false;
		}
	}
	return true;
}
