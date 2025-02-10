#ifndef SPELL_INITIALIZER_H
#define SPELL_INITIALIZER_H

#include "../model/spell.h"

void initHumanXSpell(struct spell_t *spell, u8 teamIdx);
void initHumanYSpell(struct spell_t *spell, u8 teamIdx);
void initHumanASpell(struct spell_t *spell, u8 teamIdx);
void initHumanBSpell(struct spell_t *spell, u8 teamIdx);
void initHumanLSpell(struct spell_t *spell, u8 teamIdx);
void initHumanRSpell(struct spell_t *spell, u8 teamIdx);


void initExplosion(struct spell_t *spell, u8 teamIdx);

#endif