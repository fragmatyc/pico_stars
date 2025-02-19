#include "spell_initializer.h"
#include "../model/spell.h"

#define HUMAN_Y_SPELL_COOLDOWN 180
#define HUMAN_X_SPELL_COOLDOWN 180
#define HUMAN_ULT_COOLDOWN 180
#define HUMAN_Y_SPELL_CAST_TIME 15
#define HUMAN_X_SPELL_CAST_TIME 15
#define HUMAN_ULT_CAST_TIME 15
#define HUMAN_Y_SPELL_FRAME_OFFSET 24
#define HUMAN_X_SPELL_FRAME_OFFSET 176
#define MISSILE_FRAME_OFFSET 272
#define HUMAN_Y_SPELL_PAL 2
#define HUMAN_X_SPELL_PAL 4
#define MISSILE_PALETTE 5
#define HUMAN_Y_SPELL_MAX_TRAVEL_DIST 64
#define SPRITE_PRIORITY 3

void initMageXSpell(struct spell_t *spell, u8 teamIdx) {
}

void initMageYSpell(struct spell_t *spell, u8 teamIdx) {
}

void initMageASpell(struct spell_t *spell, u8 teamIdx) {
}

void initMageBSpell(struct spell_t *spell, u8 teamIdx) {
    spell->type = SPELL_TYPE_THROWN_EXPLOSION;
    spell->sprite->size = OBJ_SMALL;
    spell->sprite->visible = 0;
    spell->sprite->totalNbAnimFrame = 2;
    spell->sprite->framesPerFrame = 10;
    spell->sprite->frameCounter = 0;
    spell->repeatCount = 0;
    spell->sprite->palette = 2;
    spell->sprite->priority = SPRITE_PRIORITY;
    spell->cooldown = HUMAN_Y_SPELL_COOLDOWN;
    spell->cooldownTimer = 0;
    spell->castTimer = 0;
    spell->castTime = HUMAN_Y_SPELL_CAST_TIME;
    spell->maxTravelDistance = HUMAN_Y_SPELL_MAX_TRAVEL_DIST;
    spell->sprite->frameOffset = HUMAN_Y_SPELL_FRAME_OFFSET;
    spell->sprite->initialized = 1;
    spell->projectileMoveFrameCountTimer = 0;
    spell->projectileMoveSpeed = 2;
}

void initMageLSpell(struct spell_t *spell, u8 teamIdx) {
}

void initMageRSpell(struct spell_t *spell, u8 teamIdx) {
}




void initHumanYSpell(struct spell_t *spell, u8 teamIdx) {
}

void initHumanXSpell(struct spell_t *spell, u8 teamIdx) {
    spell->type = SPELL_TYPE_FALL_ON_TARGET_EXPLOSION;
    spell->sprite->size = OBJ_SMALL;
    spell->sprite->visible = 0;
    spell->sprite->totalNbAnimFrame = 2;
    spell->sprite->framesPerFrame = 10;
    spell->sprite->frameCounter = 0;
    spell->sprite->priority = SPRITE_PRIORITY;
    spell->cooldown = HUMAN_ULT_COOLDOWN;
    spell->cooldownTimer = 0;
    spell->repeatCount = 3;
    spell->repeatCounter = 0;
    spell->repeatInterval = 60;
    spell->repeatTimer = 0;
    spell->castTimer = 0;
    spell->castTime = HUMAN_ULT_CAST_TIME;
    spell->sprite->initialized = 1;
    spell->projectileMoveFrameCountTimer = 0;
    spell->projectileMoveSpeed = 3;
}

void initHumanASpell(struct spell_t *spell, u8 teamIdx) {
    spell->type = SPELL_TYPE_THROWN_EXPLOSION;
    spell->sprite->size = OBJ_SMALL;
    spell->sprite->visible = 0;
    spell->sprite->totalNbAnimFrame = 2;
    spell->sprite->framesPerFrame = 10;
    spell->sprite->frameCounter = 0;
    spell->repeatCount = 0;
    spell->sprite->priority = SPRITE_PRIORITY;
    spell->cooldown = HUMAN_Y_SPELL_COOLDOWN;
    spell->cooldownTimer = 0;
    spell->castTimer = 0;
    spell->castTime = HUMAN_Y_SPELL_CAST_TIME;
    spell->maxTravelDistance = HUMAN_Y_SPELL_MAX_TRAVEL_DIST;
    spell->sprite->initialized = 1;
    spell->projectileMoveFrameCountTimer = 0;
    spell->projectileMoveSpeed = 2;
}

void initHumanBSpell(struct spell_t *spell, u8 teamIdx) {
    spell->type = SPELL_TYPE_STATIC_CLOSE_ZONE;
    spell->sprite->size = OBJ_LARGE;
    spell->sprite->visible = 0;
    spell->repeatCount = 0;
    spell->sprite->totalNbAnimFrame = 3;
    spell->sprite->framesPerFrame = 4;
    spell->sprite->frameCounter = 0;
    spell->sprite->priority = SPRITE_PRIORITY;
    spell->cooldown = HUMAN_X_SPELL_COOLDOWN;
    spell->cooldownTimer = 0;
    spell->castTimer = 0;
    spell->castTime = HUMAN_X_SPELL_CAST_TIME;
    spell->sprite->initialized = 1;
}

void initHumanLSpell(struct spell_t *spell, u8 teamIdx) {

}

void initHumanRSpell(struct spell_t *spell, u8 teamIdx) {

}

void initExplosion(struct spell_t *spell, u8 teamIdx) {

}