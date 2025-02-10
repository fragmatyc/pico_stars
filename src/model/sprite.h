#ifndef SPRITE_H
#define SPRITE_H

#include <snes.h>

struct sprite_t {
    u8 initialized;
    u16 oamId;
    u8 objectId;

    u16 x;
    u8 flipX;
    u16 y;
    u8 flipY;

    u16 frameCounter;
    u16 framesPerFrame;
    u16 frameOffset;
    u16 frameOffsetOrig;
    u8 frameIdx;
    u8 totalNbAnimFrame;
    u8 totalNbAnimFrameOrig;
    u8 dmgAnimationTimer;

    u8 palette;
    u8 paletteOrig;
    u8 priority;
    u8 visible;
    u8 size;
    u8 sizeOrig;
};

#endif