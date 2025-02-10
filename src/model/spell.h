#ifndef SPELL_H
#define SPELL_H

#include <snes.h>
#include "sprite.h"
// SPELL_TYPE

#define SPELL_TYPE_FOLLOW_TARGET 0
#define SPELL_TYPE_FOLLOW_TARGET_EXPLOSION 0
#define SPELL_TYPE_THROWN 2
#define SPELL_TYPE_THROWN_EXPLOSION 3
#define SPELL_TYPE_THROWN_SKILLSHOT 4
#define SPELL_TYPE_THROWN_SKILLSHOT_EXPLOSION 5
#define SPELL_TYPE_STATIC_CLOSE_ZONE 6
#define SPELL_TYPE_FALL_ON_TARGET_EXPLOSION 7

#define X_SPELL 0
#define Y_SPELL 1
#define A_SPELL 2
#define B_SPELL 3
#define L_SPELL 4
#define R_SPELL 5

struct spell_t {
    u8 objectId;

    u8 type;
    u8 level;

    u16 cooldown;
    u16 range;

    u8 repeatCount;
    u8 repeatCounter;
    u8 repeatInterval;
    u8 repeatTimer;

    u8 projectileMoveSpeed;
    u8 projectileMoveFrameCount;
    u8 projectileMoveFrameCountTimer;

    u16 bonusAttackSpeed;
    u16 bonusResist;
    u16 bonusMoveSpeed;
    u16 bonusDamage;
    u16 maxTravelDistance;
    u16 travelDistance;
    u8 castTime;

    u8 bonusDamageType;
    u8 bonusResistType;

    u16 cooldownTimer;
    u8 castTimer;
    u8 castDirection;

    struct sprite_t *sprite;
};

#endif