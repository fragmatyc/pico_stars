#include <snes.h>
#include "minion_initializer.h"
#include "../model/minion.h"
#include "../model/unit.h"
#include "../model/sprite.h"

void initSlimeUnit(struct minion_t *minion) {
    struct unit_t *unit = minion->unit;
}

void initSlimeSprite(struct minion_t *minion) {
    struct sprite_t *sprite = minion->sprite;
}

void initSlimeSpells(struct minion_t *minion) {
    struct spell_t *spell1 = minion->spells[SPELL_1];

    struct spell_t *spell2 = minion->spells[SPELL_2];

    struct spell_t *spell3 = minion->spells[SPELL_3];

    struct spell_t *spell4 = minion->spells[SPELL_4];
}

void initSlime(struct minion_t *minion) {
    initSlimeUnit(minion);
    initSlimeSprite(minion);
    initSlimeSpells(minion);
}