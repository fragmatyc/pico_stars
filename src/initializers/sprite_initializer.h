#ifndef SPRITE_INITIALIZER_H
#define SPRITE_INITIALIZER_H
#include <snes.h>
#include "../model/unit.h"
#include "../model/sprite.h"

void loadHumanGfx(u16 humanPalette, u16 ySpellPalette, u16 ySpellExplosionPalette, u16 xSpellPalette, u16 bSpellPalette);
void loadCommonGfx(u16 healthBarPalette);

void initHealthBar(struct sprite_t *unitSprite, struct unit_t *unit);

#endif