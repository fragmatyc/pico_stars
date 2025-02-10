#ifndef PLAYER_INITIALIZER_H
#define PLAYER_INITIALIZER_H

#include <snes.h>
#include "../model/player.h"

void initHuman(struct player_t *player);
void initMage(struct player_t *player);
void initTank(struct player_t *player);

#endif