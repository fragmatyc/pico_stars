#include <snes.h>
#include "sprite_manager.h"
#include "object_manager.h"
#include "../model/player.h"

void displaySprite(struct sprite_t *sprite) {
    if (sprite->visible == 1 && sprite->initialized == 1) {
        u16 frameOffsetStep = 2;
        if (sprite->size == OBJ_LARGE) {
            frameOffsetStep = 4;
        }
        oamSet(sprite->oamId, sprite->x, sprite->y, sprite->priority, sprite->flipX, sprite->flipY, sprite->frameOffset + (sprite->frameIdx * frameOffsetStep), sprite->palette);
        oamSetEx(sprite->oamId, sprite->size, OBJ_SHOW);
        oamSetVisible(sprite->oamId, OBJ_SHOW);
    } else if (sprite->initialized == 1) {
       oamSetVisible(sprite->oamId, OBJ_HIDE);
    }
}

void handlePlayerHealthBarDisplay(struct player_t *player) {
    // (totalNbAnimFrame - 1) - (healthPoints * totalNbAnimFrame / maxHealthPoints);
    player->unit->healthBarSprite->frameIdx = (player->unit->healthBarSprite->totalNbAnimFrame - 1) * 
           (player->unit->maxHealthPoints - player->unit->healthPoints) / 
           player->unit->maxHealthPoints;

    if (player->unit->healthBarSprite->frameIdx < 0) 
        player->unit->healthBarSprite->frameIdx = 0;
    else if (player->unit->healthBarSprite->frameIdx >= player->unit->healthBarSprite->totalNbAnimFrame) 
        player->unit->healthBarSprite->frameIdx = player->unit->healthBarSprite->totalNbAnimFrame - 1;

    displaySprite(player->unit->healthBarSprite);
}

void handlePlayerSpritesDisplay(struct object_manager_t *objManager) {
    u8 playerIdx;
    for (playerIdx = 0; playerIdx < 2; playerIdx++) {
        struct player_t *player = objManager->players[playerIdx];
        if (player == NULL) {
            continue;
        }
        
        displaySprite(player->sprite);

        displaySprite(player->xSpell->sprite);
        displaySprite(player->ySpell->sprite);
        displaySprite(player->aSpell->sprite);
        displaySprite(player->bSpell->sprite);
        displaySprite(player->lSpell->sprite);
        displaySprite(player->rSpell->sprite);
        
        player->unit->healthBarSprite->x = player->sprite->x;
        player->unit->healthBarSprite->y = player->sprite->y - 16;

        handlePlayerHealthBarDisplay(player);
    }
}

void handleSpritesDisplay(struct object_manager_t *objManager) {
    handlePlayerSpritesDisplay(objManager);
}
