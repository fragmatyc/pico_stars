#ifndef MINION_H
#define MINION_H

#include <snes.h>
#include "spell.h"

#define SPELL_1 0
#define SPELL_2 1
#define SPELL_3 2
#define SPELL_4 3

struct minion_t {
    u8 objectId;

    struct sprite_t *sprite;
    struct unit_t *unit;

    struct spell_t *spells[4];
};

#endif