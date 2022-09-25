#include "header.h"

t_runeset *ascii_runeset() {
    static wchar_t runes[94];
    static t_runeset runeset = {runes, 94};

    for (int i = 0; i < 95; i++) {
        runes[i] = 33 + i;
    }

    return &runeset;
}

t_runeset *japanese_runeset() {
    static wchar_t runes[42];
    static t_runeset runeset = {runes, 42};

    for (int i = 0; i < 42; i++) {
        runes[i] = 12450 + i * 2;
    }

    return &runeset;
}

t_runeset *mathematical_runeset() {
    static wchar_t runes[256];
    static t_runeset runeset = {runes, 42};

    for (int i = 0; i < 256; i++) {
        runes[i] = 8704 + i;
    }

    return &runeset;
}

wchar_t get_rune(t_runeset *runeset) {
    int idx = rand() % runeset->size;
    return runeset->runes[idx];
}
