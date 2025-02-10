#include <snes.h>
#include "object_manager.h"
#include "../model/player.h"
#include "../model/sprite.h"

u16 nextOamId(struct object_manager_t *objManager) {
    u16 oamId = objManager->currentOamId;
    objManager->currentOamId += 4;
    return oamId;
}

u8 nextObjectId(struct object_manager_t *objManager) {
    u8 objId = objManager->currentObjectId;
    objManager->currentObjectId++;
    return objId;
}

void registerSpell(u8 teamId, u8 spellIdx, struct spell_t *spell, struct object_manager_t *objManager) {
    spell->sprite->oamId = nextOamId(objManager);
    spell->objectId = nextObjectId(objManager);

    objManager->spells[teamId][spellIdx] = spell;
    objManager->spellSprites[teamId][spellIdx] = spell->sprite;
}

void registerPlayer(u8 teamId, struct player_t *player, struct object_manager_t *objManager) {
    player->objectId = nextObjectId(objManager);
    player->sprite->oamId = nextOamId(objManager);

    player->unit->healthBarSprite->oamId = nextOamId(objManager);
    player->unit->teamId = teamId;
    objManager->players[teamId] = player;

    registerSpell(teamId, 0, player->xSpell, objManager);
    registerSpell(teamId, 1, player->ySpell, objManager);
    registerSpell(teamId, 2, player->aSpell, objManager);
    registerSpell(teamId, 3, player->bSpell, objManager);
    registerSpell(teamId, 4, player->lSpell, objManager);
    registerSpell(teamId, 5, player->rSpell, objManager);
}

struct sprite_t *getObjectSprite(u8 objectId, struct object_manager_t *objManager) {
    u8 teamIdx;
    for (teamIdx = 0; teamIdx < 2; teamIdx++) {
        struct player_t *player = objManager->players[teamIdx];
        if (player->objectId == objectId) {
            return player->sprite;
        }
    }

    return NULL;
}

struct unit_t *getObjectUnit(u8 objectId, struct object_manager_t *objManager) {
    u8 teamIdx;
    for (teamIdx = 0; teamIdx < 2; teamIdx++) {
        struct player_t *player = objManager->players[teamIdx];
        if (player->objectId == objectId) {
            return player->unit;
        }
    }

    return NULL;
}

void initObjectManager(struct object_manager_t *objManager) {
    objManager->currentOamId = 0;
    objManager->currentObjectId = 0;
    objManager->players[0] = NULL;
    objManager->players[1] = NULL;
}