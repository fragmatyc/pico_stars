#include <snes.h>
#include "player_initializer.h"
#include "spell_initializer.h"
#include "../model/player.h"
#include "../model/sprite.h"
#include "../model/unit.h"

#define PLAYER_SPRITE_PRIORITY 3

// Human
#define HUMAN_FRAME_OFFSET 0
#define MAGE_FRAME_OFFSET 0
#define HUMAN_PALETTE 1
#define MAGE_PALETTE 1
#define HUMAN_MOVE_SPEED 1
#define HUMAN_MOVE_FRAME_COUNT 1
#define HUMAN_FRAMES_PER_FRAME 10
#define HUMAN_ANIM_FRAME_COUNT 3

void initHumanUnit(struct player_t *player) {
    struct unit_t *unit = player->unit;
    unit->level = 1;
    unit->moveSpeed = HUMAN_MOVE_SPEED;
    unit->moveFrameCount = HUMAN_MOVE_FRAME_COUNT;
    unit->maxHealthPoints = 800;
    unit->healthPoints = 54;
}

void initHumanSprite(struct player_t *player) {
    struct sprite_t *sprite = player->sprite;
    sprite->flipX = 0;
    sprite->flipY = 0;
    sprite->frameIdx = 0;
    sprite->size = OBJ_SMALL;
    sprite->totalNbAnimFrame = HUMAN_ANIM_FRAME_COUNT;
    sprite->framesPerFrame = HUMAN_FRAMES_PER_FRAME;
    sprite->priority = 2;
    sprite->initialized = 1;
}

void initHumanSpells(struct player_t *player) {
    initHumanXSpell(player->xSpell, player->unit->teamId);
    initHumanYSpell(player->ySpell, player->unit->teamId);
    initHumanASpell(player->aSpell, player->unit->teamId);
    initHumanBSpell(player->bSpell, player->unit->teamId);
    initHumanLSpell(player->lSpell, player->unit->teamId);
    initHumanRSpell(player->rSpell, player->unit->teamId);
}

void initHuman(struct player_t *player) {
    initHumanUnit(player);
    initHumanSprite(player);
    initHumanSpells(player);
}

// Mage

void initMageUnit(struct player_t *player) {
    struct unit_t *unit = player->unit;
    unit->level = 1;
    unit->moveSpeed = HUMAN_MOVE_SPEED;
    unit->moveFrameCount = HUMAN_MOVE_FRAME_COUNT;
    unit->maxHealthPoints = 800;
    unit->healthPoints = 54;
}

void initMageSprite(struct player_t *player) {
    struct sprite_t *sprite = player->sprite;
    sprite->flipX = 0;
    sprite->flipY = 0;
    sprite->frameIdx = 0;
    sprite->size = OBJ_SMALL;
    sprite->totalNbAnimFrame = HUMAN_ANIM_FRAME_COUNT;
    sprite->framesPerFrame = HUMAN_FRAMES_PER_FRAME;
    sprite->priority = PLAYER_SPRITE_PRIORITY;
    sprite->palette = MAGE_PALETTE;
    sprite->initialized = 1;
}

void initMageSpells(struct player_t *player) {
    initMageXSpell(player->xSpell, player->unit->teamId);
    initMageYSpell(player->ySpell, player->unit->teamId);
    initMageASpell(player->aSpell, player->unit->teamId);
    initMageBSpell(player->bSpell, player->unit->teamId);
    initMageLSpell(player->lSpell, player->unit->teamId);
    initMageRSpell(player->rSpell, player->unit->teamId);
}

void initMage(struct player_t *player) {
    initMageUnit(player);
    initMageSprite(player);
    initMageSpells(player);
}

// Tank

void initTankUnit(struct player_t *player) {
    struct unit_t *unit = player->unit;
}

void initTankSprite(struct player_t *player) {
    struct sprite_t *sprite = player->sprite;
}

void initTankSpells(struct player_t *player) {

}

void initTank(struct player_t *player) {
    initTankUnit(player);
    initTankSprite(player);
    initTankSpells(player);
}