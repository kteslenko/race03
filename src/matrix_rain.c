#include "header.h"

static t_runeset* select_runeset(const char* name) {
    if (mx_strcmp(name, "ascii") == 0) {
        return ascii_runeset();
    }
    if (mx_strcmp(name, "japan") == 0) {
        return japanese_runeset();
    }
    if (mx_strcmp(name, "math") == 0) {
        return mathematical_runeset();
    }
    return NULL;
}

static t_colorset* select_colorset(const char* name) {
    int c;
    
    if (mx_strcmp(name, "random") == 0) {
        return random_colorset();
    }
    if (mx_atoi(name, &c) == 0
        && c >= 1
        && c <= 7) {
        return static_colorset(c);
    }
    return NULL;
}

static void usage() {
    mx_printerr("usage: ./matrix_rain [-h] [-s] [-r runeset] [-c colorset]\n"
                "\trunesets: ascii, japan, math\n"
                "\tcolorsets: 1-7, random\n");
	exit(-1);
}

bool is_exit(bool screensaver) {
    char ch = getch();

    return (screensaver && ch != ERR)
            || (!screensaver && ch == 'q');
}

int main(int argc, char *argv[]) {
    bool screensaver = false;
    t_runeset *runeset = NULL;
    t_colorset *colorset = NULL;

    if (argc > 6) {
        usage();
    }

    for (int i = 1; i < argc; i++)
    {
        if (mx_strcmp(argv[i], "-h") == 0) {
            usage();
        }
        else if (mx_strcmp(argv[i], "-s") == 0) {
            screensaver = true;
        }
        else if (mx_strcmp(argv[i], "-r") == 0) {
            if (argc == i + 1) {
                mx_printerr("runeset expected after -r\n");
                exit(-1);
            }
            i++;
            runeset = select_runeset(argv[i]);
            if (runeset == NULL) {
                mx_printerr("invalid runeset\n");
                exit(-1);
            }
        }
        else if (mx_strcmp(argv[i], "-c") == 0) {
            if (argc == i + 1) {
                mx_printerr("colorset expected after -c\n");
                exit(-1);
            }
            i++;
            colorset = select_colorset(argv[i]);
            if (colorset == NULL) {
                mx_printerr("invalid colorset\n");
                exit(-1);
            }
        }
        else {
            mx_printerr("invalid argument: ");
            mx_printerr(argv[i]);
            mx_printerr("\n");
            exit(-1);
        }
    }
    
    if (runeset == NULL) {
        runeset = ascii_runeset();
    }
    if (colorset == NULL) {
        colorset = static_colorset(2);
    }
    srand(time(NULL));
	setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(0);
    init_colors();
    
	if (mx_intro(colorset, screensaver)) {
        matrix_rain(runeset, colorset, 80, screensaver);
    }

    endwin();
}
