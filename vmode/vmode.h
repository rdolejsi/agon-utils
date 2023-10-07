#ifndef AGON_UTILS_VMODE_H
#define AGON_UTILS_VMODE_H

/*
 * The video mode definition.
 *
 * This is directly based on the VDP 1.04 firmware
 * as available at https://github.com/breakintoprogram/agon-docs/wiki/VDP#screen-modes.
 */
struct video_mode_spec {
    uint8_t mode;
    uint16_t x_size;
    uint16_t y_size;
    uint8_t color;
    uint8_t refresh;
};

const struct video_mode_spec video_modes[] = {
        {0,   640,  480, 16, 60},
        {1,   640,  480, 4,  60},
        {2,   640,  480, 2,  60},
        {3,   640,  240, 64, 60},
        {4,   640,  240, 16, 60},
        {5,   640,  240, 4,  60},
        {6,   640,  240, 2,  60},
        {8,   320,  240, 64, 60},
        {9,   320,  240, 16, 60},
        {10,  320,  240, 4,  60},
        {11,  320,  240, 2,  60},
        {12,  320,  200, 64, 70},
        {13,  320,  200, 16, 70},
        {14,  320,  200, 4,  70},
        {15,  320,  200, 2,  70},
        {16,  800,  600, 4,  60},
        {17,  800,  600, 2,  60},
        {18,  1024, 768, 2,  60},
        {129, 640,  480, 4,  60},
        {130, 640,  480, 2,  60},
        {132, 640,  240, 16, 60},
        {133, 640,  240, 4,  60},
        {134, 640,  240, 2,  60},
        {136, 320,  240, 64, 60},
        {137, 320,  240, 16, 60},
        {138, 320,  240, 4,  60},
        {139, 320,  240, 2,  60},
        {140, 320,  200, 64, 70},
        {141, 320,  200, 16, 70},
        {142, 320,  200, 4,  70},
        {143, 320,  200, 2,  70}
};

const int video_modes_len = sizeof(video_modes) / sizeof(video_modes[0]);

#endif //AGON_UTILS_VMODE_H
