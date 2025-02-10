#ifndef SPELL_MANAGER_H
#define SPELL_MANAGER_H

#include <snes.h>
#include "../model/spell.h"
#include "object_manager.h"

void castSpell(u8 casterObjId, struct spell_t *spell, struct object_manager_t *objManager);

#endif