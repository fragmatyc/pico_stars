#include <snes.h>
#include "spell_manager.h"
#include "object_manager.h"
#include "../model/spell.h"
#include "../model/sprite.h"
#include "../model/unit.h"
#include "../model/player.h"

void castThrownSpell(struct sprite_t *casterSprite, struct unit_t *casterUnit, struct spell_t *spell) {

    s8 xOffset = 0;
    s8 yOffset = 0;
    if (casterUnit->direction == PLAYER_DIR_UP) {
        // Implement directional sprites
        yOffset = -12;
    } else if (casterUnit->direction == PLAYER_DIR_RIGHT) {
        spell->sprite->flipX = 0;
        xOffset = 16;
        if (spell->sprite->size == OBJ_LARGE) {
            yOffset = -8;
        }
    } else if (casterUnit->direction == PLAYER_DIR_DOWN) {
        yOffset = 12;
    } else if (casterUnit->direction == PLAYER_DIR_LEFT) {
        spell->sprite->flipX = 1;
        if (spell->sprite->size == OBJ_SMALL) {
            xOffset = -16;
        } else {
            xOffset = -32;
            yOffset = -8;
        }
    }

    spell->sprite->x = casterSprite->x + xOffset;
    spell->sprite->y = casterSprite->y + yOffset;
    spell->sprite->flipY = 0;
    spell->castDirection = casterUnit->direction;
    spell->travelDistance = 0;
}


void castFallOnTargetSpell(struct sprite_t *casterSprite, struct unit_t *casterUnit, struct spell_t *spell) {
    // Temporary code before target locking
    s8 xOffset = 0;
    if (casterSprite->flipX == 0) {
        xOffset = 64;
    } else {
        xOffset = -64;
    }

    spell->sprite->flipX = 0;
    spell->sprite->flipY = 0;
    spell->sprite->x = casterSprite->x + xOffset;
    spell->sprite->y = 0;
    spell->travelDistance = 0;
    spell->maxTravelDistance = casterSprite->y;
}

void castSpell(u8 casterObjId, struct spell_t *spell, struct object_manager_t *objManager) {
    if (spell == NULL) {
        return;
    }

    struct sprite_t *casterSprite = getObjectSprite(casterObjId, objManager);
    struct unit_t *casterUnit = getObjectUnit(casterObjId, objManager);

    switch(spell->type) {
        case SPELL_TYPE_THROWN_SKILLSHOT:
        case SPELL_TYPE_THROWN_EXPLOSION:
        case SPELL_TYPE_STATIC_CLOSE_ZONE:
            castThrownSpell(casterSprite, casterUnit, spell);
            break;
        case SPELL_TYPE_FALL_ON_TARGET_EXPLOSION:
            castFallOnTargetSpell(casterSprite, casterUnit, spell);
            break;
    }

    spell->sprite->visible = 1;
    spell->sprite->frameIdx = 0;
    if (spell->repeatCount > 0 && spell->repeatCounter == 0) {
        spell->repeatCounter = spell->repeatCount;
        spell->repeatTimer = 0;
    }
}
