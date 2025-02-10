#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <snes.h>
#include "../model/player.h"
#include "../model/sprite.h"

struct object_manager_t {
    u8 currentObjectId;
    u16 currentOamId;
    struct player_t *players[2];
    struct sprite_t *spellSprites[2][6];
    struct spell_t *spells[2][6];
};

void initObjectManager(struct object_manager_t *objManager);
void registerPlayer(u8 teamId, struct player_t *player, struct object_manager_t *objManager);
struct sprite_t *getObjectSprite(u8 objectId, struct object_manager_t *objManager);
struct unit_t *getObjectUnit(u8 objectId, struct object_manager_t *objManager);

#endif