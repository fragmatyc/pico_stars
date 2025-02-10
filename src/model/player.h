#ifndef PLAYER_H
#define PLAYER_H

#include <snes.h>
#include "spell.h"
#include "sprite.h"
#include "unit.h"

#define PLAYER_DIR_UP 0
#define PLAYER_DIR_RIGHT 1
#define PLAYER_DIR_DOWN 2
#define PLAYER_DIR_LEFT 3

struct player_t {
    u8 objectId;
    u8 padId;

    struct sprite_t *sprite;
    struct unit_t *unit;

    struct spell_t *xSpell;
    struct spell_t *ySpell;
    struct spell_t *aSpell;
    struct spell_t *bSpell;
    struct spell_t *lSpell;
    struct spell_t *rSpell;
};

#endif