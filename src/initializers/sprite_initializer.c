#include <snes.h>
#include "sprite_initializer.h"
#include "../model/player.h"

extern char grenadesprite, grenadesprite_end, grenadespritepal;
extern char shotgunsprite, shotgunsprite_end, shotgunspritepal;
extern char humansprite, humansprite_end, humanspritepal;
extern char explosionsprite, explosionsprite_end, explosionspritepal;
extern char missilesprite, missilesprite_end, missilespritepal;
extern char healthbarsprite, healthbarsprite_end, healthbarspritepal;

void loadHumanGfx(u16 humanPalette, u16 ySpellPalette, u16 ySpellExplosionPalette, u16 xSpellPalette, u16 bSpellPalette) {
    oamInitGfxSet(&humansprite, (&humansprite_end - &humansprite), &humanspritepal, 16, humanPalette, 0x0000, OBJ_SIZE16_L32);
    oamInitGfxSet(&grenadesprite, (&grenadesprite_end - &grenadesprite), &grenadespritepal, 16, ySpellPalette, 0x0180, OBJ_SIZE16_L32);

    // Might reuse
    oamInitGfxSet(&explosionsprite, (&explosionsprite_end - &explosionsprite), &explosionspritepal, 32, ySpellExplosionPalette, 0x0300, OBJ_SIZE16_L32);
    oamInitGfxSet(&shotgunsprite, (&shotgunsprite_end - &shotgunsprite), &shotgunspritepal, 32, xSpellPalette, 0x0B00, OBJ_SIZE16_L32);
    oamInitGfxSet(&missilesprite, (&missilesprite_end - &missilesprite), &missilespritepal, 16, bSpellPalette, 0x1100, OBJ_SIZE16_L32);
}

void loadCommonGfx(u16 healthBarPalette) {
    oamInitGfxSet(&healthbarsprite, (&healthbarsprite_end - &healthbarsprite), &healthbarspritepal, 16, healthBarPalette, 0x1400, OBJ_SIZE16_L32);
}

void initHealthBar(struct sprite_t *unitSprite, struct unit_t *unit) {
    unit->healthBarSprite->visible = 1;
    unit->healthBarSprite->frameIdx = 0;
    unit->healthBarSprite->flipX = 0;
    unit->healthBarSprite->flipY = 0;
    unit->healthBarSprite->frameOffset = 320;
    unit->healthBarSprite->initialized = 1;
    unit->healthBarSprite->priority = 3;
    unit->healthBarSprite->size = OBJ_SMALL;
    unit->healthBarSprite->palette = 6;
    unit->healthBarSprite->totalNbAnimFrame = 8;
}