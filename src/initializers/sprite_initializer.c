#include <snes.h>
#include "sprite_initializer.h"
#include "../model/player.h"

extern char healthbarsprite, healthbarsprite_end, healthbarspritepal;
extern char explosionsprite, explosionsprite_end, explosionspritepal;
extern char playerstatusessprite, playerstatusessprite_end, playerstatusesspritepal;

extern char humansprite, humansprite_end, humanspritepal;
extern char grenadesprite, grenadesprite_end, grenadespritepal;
extern char shotgunsprite, shotgunsprite_end, shotgunspritepal;
extern char missilesprite, missilesprite_end, missilespritepal;

extern char magesprite, magesprite_end, magespritepal;
extern char iceballsprite, iceballsprite_end, iceballspritepal;
extern char playerstatusessprite, playerstatusessprite_end, playerstatusesspritepal;

#define SIZE_OF_16x16_FRAME 128;
#define SIZE_OF_32x32_FRAME 512;

/*
    VRAM MANAGEMENT
    0x0000 Player 1
    0x1000 Player 2
    0x2000 Common
    0x4000 Map Tileset
    0x6800 Map Data
*/
#define PLAYER_VRAM_SPACE 0x1000
#define PLAYER_FRAME_OFFSET_SPACE 256
#define PLAYER_SPRITE_OFFSET 0x0000
#define PLAYER_A_SPELL_OFFSET 0x0200
#define PLAYER_B_SPELL_OFFSET 0x0380
#define PLAYER_X_SPELL_OFFSET 0x0900
#define PLAYER_Y_SPELL_OFFSET 0x0000

u16 getPaletteSize(struct sprite_t *sprite) {
    if (sprite->size == OBJ_LARGE) {
        return 32;
    }
    return 16;
}

u16 incrementOffset(u16 offset, struct sprite_t *sprite) {
    if (sprite->size == OBJ_SMALL) {
        offset += sprite->totalNbAnimFrame * SIZE_OF_16x16_FRAME;
    } else {
        offset += sprite->totalNbAnimFrame * SIZE_OF_32x32_FRAME;
    }
    return offset;
}

void loadHumanGfx(struct player_t *player) {
    u16 offset = player->unit->teamId * PLAYER_VRAM_SPACE;
    u16 frameOffset = player->unit->teamId * PLAYER_FRAME_OFFSET_SPACE;

    struct sprite_t *sprite = player->sprite;
    sprite->palette = 1;
    oamInitGfxSet(
        &humansprite, (&humansprite_end - &humansprite), 
        &humanspritepal, 16, sprite->palette, 
        offset + PLAYER_SPRITE_OFFSET, OBJ_SIZE16_L32);
    sprite->frameOffset = frameOffset + 0;

    sprite = player->aSpell->sprite;
    sprite->palette = 2;
    oamInitGfxSet(
        &grenadesprite, (&grenadesprite_end - &grenadesprite), 
        &grenadespritepal, 16, sprite->palette, 
        offset + PLAYER_A_SPELL_OFFSET, OBJ_SIZE16_L32);
    sprite->frameOffset = 32;
    
    sprite = player->bSpell->sprite;
    sprite->palette = 3;
    oamInitGfxSet(
        &shotgunsprite, (&shotgunsprite_end - &shotgunsprite), 
        &shotgunspritepal, 32, sprite->palette, 
        offset + PLAYER_B_SPELL_OFFSET, OBJ_SIZE16_L32);
    sprite->frameOffset = 56; 

    sprite = player->xSpell->sprite;
    sprite->palette = 4;
    oamInitGfxSet(
        &missilesprite, (&missilesprite_end - &missilesprite), 
        &missilespritepal, 16, sprite->palette, 
        offset + PLAYER_X_SPELL_OFFSET, OBJ_SIZE16_L32);
    sprite->frameOffset = 144;
    
}


void loadMageGfx(struct player_t *player) {
    u16 offset = player->unit->teamId * PLAYER_VRAM_SPACE;
    struct sprite_t *sprite;

    sprite = player->sprite;

    oamInitGfxSet(&magesprite, (&magesprite_end - &magesprite), &magespritepal, 16, 1, 0x0000, OBJ_SIZE16_L32);
    oamInitGfxSet(&iceballsprite, (&iceballsprite_end - &iceballsprite), &iceballspritepal, 16, 2, 0x0180, OBJ_SIZE16_L32);
}

void loadCommonGfx(u16 healthBarPalette, u16 playerstatusesPalette) {
    //oamInitGfxSet(&explosionsprite, (&explosionsprite_end - &explosionsprite), &explosionspritepal, 32, 5, 0x2000, OBJ_SIZE16_L32);

    //oamInitGfxSet(&healthbarsprite, (&healthbarsprite_end - &healthbarsprite), &healthbarspritepal, 16, 9, 0x3000, OBJ_SIZE16_L32);
    //oamInitGfxSet(&playerstatusessprite, (&playerstatusessprite_end - &playerstatusessprite), &playerstatusesspritepal, 16, 10, 0x3400, OBJ_SIZE16_L32);
    //oamInitGfxSet(&explosionsprite, (&explosionsprite_end - &explosionsprite), &explosionspritepal, 32, 11, 0x3000, OBJ_SIZE16_L32);

}

void initHealthBar(struct sprite_t *unitSprite, struct unit_t *unit) {
    unit->healthBarSprite->visible = 1;
    unit->healthBarSprite->frameIdx = 0;
    unit->healthBarSprite->flipX = 0;
    unit->healthBarSprite->flipY = 0;
    unit->healthBarSprite->frameOffset = 768;
    unit->healthBarSprite->initialized = 1;
    unit->healthBarSprite->priority = 3;
    unit->healthBarSprite->size = OBJ_SMALL;
    unit->healthBarSprite->palette = 9;
    unit->healthBarSprite->totalNbAnimFrame = 8;
}