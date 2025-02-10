#include <snes.h>
#include "player_manager.h"
#include "spell_manager.h"
#include "../model/player.h"
#include "../model/spell.h"
#include "../managers/object_manager.h"

bool isSpellInitializedAndCasting(struct spell_t *spell) {
    return spell->sprite->initialized && spell->castTimer > 0;
}

bool isCastingSpell(struct player_t *player) {
    return isSpellInitializedAndCasting(player->xSpell) ||
        isSpellInitializedAndCasting(player->ySpell) ||
        isSpellInitializedAndCasting(player->aSpell) ||
        isSpellInitializedAndCasting(player->bSpell) ||
        isSpellInitializedAndCasting(player->lSpell) ||
        isSpellInitializedAndCasting(player->rSpell);
}

void handlePlayerMovements(struct object_manager_t *objManager) {
    u8 playerIdx;
    for (playerIdx = 0; playerIdx < 2; playerIdx++) {
        struct player_t *player = objManager->players[playerIdx];
        if (player == NULL || player->sprite->visible == 0 || isCastingSpell(player)) {
            continue;
        }

        u16 pad = padsCurrent(player->padId);
        if (pad) {
            if (pad & KEY_UP) {
                player->sprite->frameCounter++;
                player->unit->moveFrameCountTimer++;
                player->unit->direction = PLAYER_DIR_UP;
                
                if (player->unit->moveFrameCountTimer >= player->unit->moveFrameCount) {
                    player->unit->moveFrameCountTimer = 0;
                    player->sprite->y -= player->unit->moveSpeed;
                }
            } else if (pad & KEY_RIGHT) {
                player->sprite->frameCounter++;
                player->sprite->flipX = 0;
                player->unit->moveFrameCountTimer ++;
                player->unit->direction = PLAYER_DIR_RIGHT;

                if (player->unit->moveFrameCountTimer >= player->unit->moveFrameCount) {
                    player->unit->moveFrameCountTimer = 0;
                    player->sprite->x += player->unit->moveSpeed;
                }
            } else if (pad & KEY_DOWN) {
                player->sprite->frameCounter++;
                player->unit->moveFrameCountTimer ++;
                player->unit->direction = PLAYER_DIR_DOWN;

                if (player->unit->moveFrameCountTimer >= player->unit->moveFrameCount) {
                    player->unit->moveFrameCountTimer = 0;
                    player->sprite->y += player->unit->moveSpeed;
                }
            } else if (pad & KEY_LEFT) {
                player->sprite->frameCounter++;
                player->sprite->flipX = 1;
                player->unit->moveFrameCountTimer ++;
                player->unit->direction = PLAYER_DIR_LEFT;

                if (player->unit->moveFrameCountTimer >= player->unit->moveFrameCount) {
                    player->unit->moveFrameCountTimer = 0;
                    player->sprite->x -= player->unit->moveSpeed;
                }
            } 

            if (player->sprite->frameCounter >= player->sprite->framesPerFrame) {
                player->sprite->frameCounter = 0;
                player->sprite->frameIdx++;
                if (player->sprite->frameIdx >= player->sprite->totalNbAnimFrame) {
                    player->sprite->frameIdx = 0;
                }
            }

            if (player->sprite->x < 0) player->sprite->x = 0;
            if (player->sprite->x > 255) player->sprite->x = 255;
            if (player->sprite->y < 0) player->sprite->y = 0;
            if (player->sprite->y > 239) player->sprite->y = 239;
        }
    }
}

void animateStaticZoneClose(struct spell_t *spell, bool animationLoopComplete) {
    if (animationLoopComplete) {
        spell->sprite->visible = 0;
    }
}

void animateExplosion(struct spell_t *spell, bool animationLoopComplete) {
    if (spell->travelDistance >= spell->maxTravelDistance && spell->sprite->frameOffset == 48 && animationLoopComplete) {
        spell->sprite->visible = 0; 
        spell->sprite->frameIdx = 0;
        spell->sprite->frameOffset = spell->sprite->frameOffsetOrig;
        spell->sprite->size = spell->sprite->sizeOrig;
        spell->sprite->palette = spell->sprite->paletteOrig;
        spell->sprite->totalNbAnimFrame = spell->sprite->totalNbAnimFrameOrig;
    } else if (spell->travelDistance >= spell->maxTravelDistance && spell->sprite->frameOffset != 48) {
        //spcPlaySound(0);
        spell->sprite->frameIdx = 0;
        spell->sprite->framesPerFrame = 10;
        spell->sprite->frameCounter = 0;
        spell->sprite->frameOffsetOrig = spell->sprite->frameOffset;
        spell->sprite->frameOffset = 48;
        spell->sprite->totalNbAnimFrameOrig = spell->sprite->totalNbAnimFrame;
        spell->sprite->totalNbAnimFrame = 4;
        spell->sprite->sizeOrig = spell->sprite->size;
        spell->sprite->size = OBJ_LARGE;
        spell->sprite->paletteOrig = spell->sprite->palette;
        spell->sprite->palette = 3;
        spell->sprite->x -= 8;
        spell->sprite->y -= 8;
    }
}

void animateThrownSpell(struct spell_t *spell, bool animationLoopComplete) {
    if (spell->travelDistance <= spell->maxTravelDistance) {
        switch (spell->castDirection) {
            case PLAYER_DIR_UP:
                spell->sprite->y -= spell->projectileMoveSpeed;
                break;
            case PLAYER_DIR_RIGHT:
                spell->sprite->x += spell->projectileMoveSpeed;
                break;
            case PLAYER_DIR_DOWN:
                spell->sprite->y += spell->projectileMoveSpeed;
                break;
            case PLAYER_DIR_LEFT:
                spell->sprite->x -= spell->projectileMoveSpeed;
                break;
        }
        spell->travelDistance += spell->projectileMoveSpeed;
    }
}

void animateFallOnTargetSpell(struct spell_t *spell, bool animationLoopComplete) {
    if (spell->travelDistance <= spell->maxTravelDistance) {
        spell->travelDistance += spell->projectileMoveSpeed;
        spell->sprite->y += spell->projectileMoveSpeed;
    }
}

void animateRecast(struct player_t *player, struct spell_t *spell, bool spellIsDone, bool isLastRepeat, struct object_manager_t *objManager) {
    if (spellIsDone && spell->repeatCounter > 0) {
        spell->repeatCounter--;
        spell->repeatTimer = spell->repeatInterval;
    }

    if (spell->repeatTimer == 0 && spell->sprite->visible == 0 && spell->repeatCounter > 0) {
        castSpell(player->objectId, spell, objManager);
    }
}

void animateSpell(struct player_t *player, struct spell_t *spell, struct object_manager_t *objManager) {
    bool animationLoopComplete = false;
    bool isLastRepeat = spell->repeatTimer > 0 && spell->repeatCounter == 0;
    bool wasVisible = spell->sprite->visible == 1;
    if (spell->sprite->visible == 1) {
        spell->sprite->frameCounter++;

        if (spell->sprite->frameCounter == spell->sprite->framesPerFrame) {
            spell->sprite->frameCounter = 0;
            spell->sprite->frameIdx++;
            if (spell->sprite->frameIdx >= spell->sprite->totalNbAnimFrame) {
                spell->sprite->frameIdx = 0;
                animationLoopComplete = true;
            }
        }

        switch (spell->type) {
            case SPELL_TYPE_THROWN:
            case SPELL_TYPE_THROWN_EXPLOSION:
                animateThrownSpell(spell, animationLoopComplete);
                break;
            case SPELL_TYPE_STATIC_CLOSE_ZONE:
                animateStaticZoneClose(spell, animationLoopComplete);
                break;
            case SPELL_TYPE_FALL_ON_TARGET_EXPLOSION:
                animateFallOnTargetSpell(spell, animationLoopComplete);
                break;
        }

        if (spell->type == SPELL_TYPE_THROWN_EXPLOSION || spell->type == SPELL_TYPE_FALL_ON_TARGET_EXPLOSION) {
            animateExplosion(spell, animationLoopComplete);
        }
    } else {
        animationLoopComplete = true;
    }

    bool isVisible = spell->sprite->visible == 1;
    bool spellIsDone = wasVisible && !isVisible;
    if (spell->repeatCount > 0) {
        animateRecast(player, spell, spellIsDone, isLastRepeat, objManager);
    }
}

void animateSpells(struct player_t *player, struct object_manager_t *objManager) {
    animateSpell(player, player->aSpell, objManager);
    animateSpell(player, player->bSpell, objManager);
    animateSpell(player, player->xSpell, objManager);
}

void handlePlayerSpells(struct object_manager_t *objManager) {
    u8 playerIdx;
    for (playerIdx = 0; playerIdx < 2; playerIdx++) {
        struct player_t *player = objManager->players[playerIdx];
        if (player == NULL || player->sprite->visible == 0) {
            continue;
        }

        if (player->xSpell->cooldownTimer > 0) player->xSpell->cooldownTimer--;
        if (player->ySpell->cooldownTimer > 0) player->ySpell->cooldownTimer--;
        if (player->aSpell->cooldownTimer > 0) player->aSpell->cooldownTimer--;
        if (player->bSpell->cooldownTimer > 0) player->bSpell->cooldownTimer--;
        if (player->lSpell->cooldownTimer > 0) player->lSpell->cooldownTimer--;
        if (player->rSpell->cooldownTimer > 0) player->rSpell->cooldownTimer--;

        if (player->xSpell->castTimer > 0) player->xSpell->castTimer--;
        if (player->ySpell->castTimer > 0) player->ySpell->castTimer--;
        if (player->aSpell->castTimer > 0) player->aSpell->castTimer--;
        if (player->bSpell->castTimer > 0) player->bSpell->castTimer--;
        if (player->lSpell->castTimer > 0) player->lSpell->castTimer--;
        if (player->rSpell->castTimer > 0) player->rSpell->castTimer--;

        if (player->xSpell->repeatTimer > 0) player->xSpell->repeatTimer--;
        if (player->ySpell->repeatTimer > 0) player->ySpell->repeatTimer--;
        if (player->aSpell->repeatTimer > 0) player->aSpell->repeatTimer--;
        if (player->bSpell->repeatTimer > 0) player->bSpell->repeatTimer--;
        if (player->lSpell->repeatTimer > 0) player->lSpell->repeatTimer--;
        if (player->rSpell->repeatTimer > 0) player->rSpell->repeatTimer--;

        animateSpells(player, objManager);

        u16 pad = padsCurrent(player->padId);
        if (pad) {
            struct spell_t *spell = NULL;
            if (pad & KEY_Y) {
                spell = player->ySpell;
            } else if (pad & KEY_X) {
                spell = player->xSpell;
            } else if (pad & KEY_A) {
                spell = player->aSpell;
            } else if (pad & KEY_B) {
                spell = player->bSpell;
            } else if (pad & KEY_L) {
                spell = player->lSpell;
            } else if (pad & KEY_R) {
                spell = player->rSpell;
                
            }

            if (spell != NULL && !isCastingSpell(player) && spell->cooldownTimer == 0) {
                player->sprite->frameIdx = player->sprite->totalNbAnimFrame - 1;
                spell->castTimer = spell->castTime;
                spell->cooldownTimer = spell->cooldown;
                castSpell(player->objectId, spell, objManager);
            }
        }
    }
}