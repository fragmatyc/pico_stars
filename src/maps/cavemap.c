#include <snes.h>
#include "cavemap.h"
#include "../model/player.h"
#include "../model/unit.h"
#include "../model/spell.h"
#include "../model/sprite.h"
#include "../managers/sprite_manager.h"
#include "../managers/object_manager.h"
#include "../managers/player_manager.h"
#include "../initializers/player_initializer.h"
#include "../initializers/sprite_initializer.h"

extern char cave_tileset, cave_tileset_end, cavepal;
extern char cave, cavedef, caveatt;
extern char tower1sprite, tower1sprite_end, tower1spritepal;
extern char blobsprite, blobsprite_end, blobspritepal;
extern char fireballsprite, fireballsprite_end, fireballspritepal;
extern char grenadesprite, grenadesprite_end, grenadespritepal;

struct object_manager_t objManager;

struct player_t players[2];
struct unit_t playerUnits[2];
struct sprite_t playerSprites[2];
struct spell_t playerSpells[6];
struct sprite_t spellSprites[6];
struct sprite_t healthbarsSprites[1];

void loadMap() {
    bgInitTileSet(0, &cave_tileset, &cavepal, 0, (&cave_tileset_end - &cave_tileset), 16 * 2, BG_16COLORS, 0x2000);
    bgSetMapPtr(0, 0x6800, SC_64x32);
    mapLoad((u8 *)&cave, (u8 *)&cavedef, (u8 *)&caveatt);
}

void initPlayers() {
    u16 spriteIdx;
    for (spriteIdx = 0; spriteIdx < 6; spriteIdx++) {
        spellSprites[spriteIdx].initialized = 0;
    }

    players[0].unit = &playerUnits[0];
    players[0].sprite = &playerSprites[0];
    
    players[0].xSpell = &playerSpells[0];
    players[0].xSpell->sprite = &spellSprites[0];
    
    players[0].ySpell = &playerSpells[1];
    players[0].ySpell->sprite = &spellSprites[1];

    players[0].aSpell = &playerSpells[2];
    players[0].aSpell->sprite = &spellSprites[2];
    
    players[0].bSpell = &playerSpells[3];
    players[0].bSpell->sprite = &spellSprites[3];

    players[0].lSpell = &playerSpells[4];
    players[0].lSpell->sprite = &spellSprites[4];

    players[0].rSpell = &playerSpells[5];
    players[0].rSpell->sprite = &spellSprites[5];

    players[0].unit->healthBarSprite = &healthbarsSprites[0];

    players[0].padId = 0;
    initHuman(&players[0]);
    initHealthBar(players[0].sprite, players[0].unit);
}

void registerObjects() {
    initObjectManager(&objManager);
    registerPlayer(0, &players[0], &objManager);
}

void initCaveMap() {
    loadMap();
    
    loadHumanGfx(1, 2, 3, 4, 5);
    loadCommonGfx(6);
    initPlayers();
    registerObjects();


    players[0].sprite->visible = 1;
    players[0].sprite->x = 30;
    players[0].sprite->y = 30;
    
    players[0].unit->healthBarSprite->x = 30;
    players[0].unit->healthBarSprite->y = 30;

    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);

    setScreenOn();

    u8 gameInProgress = 1;

    u16 frame = 0;
    u16 baseFrame = 48;
    u16 frameIdx = 0;
    u16 fameCount = 4;
    while(gameInProgress) {
        frame++;

        handlePlayerMovements(&objManager);
        handlePlayerSpells(&objManager);
        handleSpritesDisplay(&objManager);

        //spcProcess();
        mapUpdate();
        WaitForVBlank();
        mapVblank();
    }

    return;
}

