#include <snes.h>
#include "titlescreen.h"

extern char titlescreen_tileset, titlescreen_tileset_end, titlescreenpal;
extern char titlescreen, titlescreendef, titlescreenatt;

void initTitleScreen() {
    bgInitTileSet(0, &titlescreen_tileset, &titlescreenpal, 0, (&titlescreen_tileset_end - &titlescreen_tileset), 16 * 2, BG_16COLORS, 0x2000);
    bgSetMapPtr(0, 0x6800, SC_64x32);
    mapLoad((u8 *)&titlescreen, (u8 *)&titlescreendef, (u8 *)&titlescreenatt);

    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);

    setScreenOn();

    u16 startPressed = 0;
    while(startPressed == 0) {
        u16 pad0 = padsCurrent(0);
        if (pad0) {
            startPressed = pad0 & KEY_START;
        }
        mapUpdate();
        WaitForVBlank();
        mapVblank();
    }

    return;
}