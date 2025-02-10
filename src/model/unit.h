#ifndef UNIT_H
#define UNIT_H

#include <snes.h>
#include "sprite.h"

struct unit_t {
    u8 objectId;
    u8 teamId;

    u8 level;
    u16 healthPoints;
    u8 status;

    u8 direction;
    u16 visionRange;

    u8 moveSpeed;
    u8 moveFrameCount;
    u8 moveFrameCountTimer;
    
    u16 maxHealthPoints;
    u16 attackDamage;
    u16 abilityDamage;
    u16 armor;
    u16 magicResist;

    struct sprite_t *healthBarSprite; 
};

#endif