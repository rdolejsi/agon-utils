/*
 * Switches or lists Agon Light video modes.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <mos_api.h>
#include <agon/vdp_vdu.h>

#include "vmode.h"

extern void exit();

static void list_modes() {
    printf("Listing video modes (VDP 1.04+):\n");
    for (unsigned int idx = 0; idx < video_modes_len; idx += 1) {
        struct video_mode_spec mode = video_modes[idx];
        printf("%3i: %4ix%3i, %2i colors, %2iHz\n", mode.mode, mode.x_size, mode.y_size, mode.color, mode.refresh);
    }
}

static void get_mode() {
    uint16_t width = getsysvar_scrwidth();
    uint16_t height = getsysvar_scrheight();
    uint8_t columns = getsysvar_scrCols();
    uint8_t rows = getsysvar_scrRows();
    uint8_t colors = getsysvar_scrColours();

    printf("Current video mode %dx%d (%dx%d chars), %d colors\n", width, height, columns, rows, colors);
}

static void set_mode(int mode) {
    printf("Setting video mode %d\n", mode);
    vdp_mode(mode);
    printf("Switched to video mode %d\n", mode);
    get_mode();
}

static void str_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

static void assert_no_params(int argc, char *cmd) {
    if (argc != 2) {
        printf("error: %s command has no extra parameters\n", cmd);
        exit(1);
    }
}

static bool is_number(char *text) {
    int idx = 0;
    int length = strlen(text);
    while (idx < length) {
        char ch = text[idx++];
        if (ch < '0' || ch > '9') {
            return false;
        }
    }
    return true;
}

static void assert_number(char *text) {
    if (!is_number(text)) {
        printf("error: parameter '%s' is not a number\n", text);
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("vmode - video mode selection/list; @github/rdolejsi/agon-utils\n");
        printf("syntax:\n");
        printf("  l[ist]         .. lists video modes (VDP 1.04+)\n");
        printf("  g[et]          .. gets video mode details\n");
        printf("  [set] <number> .. switches video mode\n");
        exit(1);
    }

    char *cmd = argv[1];
    str_lower(cmd);
    if (!strcmp(cmd, "list") || !strcmp(cmd, "l")) {
        assert_no_params(argc, "list");
        list_modes();
    } else if (!strcmp(cmd, "get") || !strcmp(cmd, "g")) {
        assert_no_params(argc, "get");
        get_mode();
    } else if (!strcmp(cmd, "set") || !strcmp(cmd, "s")) {
        assert_number(argv[2]);
        unsigned int mode;
        sscanf(argv[2], "%d", &mode);
        set_mode(mode);
    } else if (is_number(cmd) && argc == 2) {
        assert_no_params(argc, "set");
        unsigned int mode;
        sscanf(cmd, "%d", &mode);
        set_mode(mode);
    } else {
        printf("error: invalid command '%s'\n", cmd);
        exit(1);
    }
    exit(0);
}
