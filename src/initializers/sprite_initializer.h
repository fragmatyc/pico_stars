#ifndef SPRITE_INITIALIZER_H
#define SPRITE_INITIALIZER_H
#include <snes.h>
#include "../model/unit.h"
#include "../model/sprite.h"
#include "../model/player.h"

void loadHumanGfx(struct player_t *player);
void loadMageGfx(struct player_t *player);

void loadCommonGfx(u16 healthBarPalette, u16 playerstatusesPalette);
void initHealthBar(struct sprite_t *unitSprite, struct unit_t *unit);

#endif