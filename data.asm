.include "hdr.asm"

.section ".rodata1" superfree

// TITLE SCREEN - START
titlescreen_tileset:
.incbin "maps/titlescreen_tileset.pic"
titlescreen_tileset_end:

titlescreenpal:
.incbin "maps/titlescreen_tileset.pal"

titlescreen:
.incbin "maps/titlescreen.m16"

titlescreenatt:
.incbin "maps/titlescreen.b16"

titlescreendef:
.incbin "maps/titlescreen.t16"
// TITLE SCREEN - END


// CAVE - START
cave_tileset:
.incbin "maps/cave_tileset.pic"
cave_tileset_end:

cavepal:
.incbin "maps/cave_tileset.pal"

cave:
.incbin "maps/cave.m16"

caveatt:
.incbin "maps/cave.b16"

cavedef:
.incbin "maps/cave.t16"
// CAVE - END

// SPRITES - TOWER1
tower1sprite:
.incbin "gfx/sprites/tower1.pic"
tower1sprite_end:

tower1spritepal:
.incbin "gfx/sprites/tower1.pal"
// SPRITES - TOWER1 - END

// SPRITES - HUMAN
humansprite:
.incbin "gfx/sprites/human.pic"
humansprite_end:

humanspritepal:
.incbin "gfx/sprites/human.pal"
// SPRITES - HUMAN - END

// SPRITES - BLOB
blobsprite:
.incbin "gfx/sprites/blob.pic"
blobsprite_end:

blobspritepal:
.incbin "gfx/sprites/blob.pal"
// SPRITES - BLOB - END

// SOUNDS
hit_brr:
.incbin "sounds/hit.brr"
hit_brr_end:

towershot_brr:
.incbin "sounds/towershot.brr"
towershot_brr_end:

// SOUNDS - END
.ends

.section ".rodata2" superfree

// SPRITES - iceball
iceballsprite:
.incbin "gfx/sprites/iceball.pic"
iceballsprite_end:

iceballspritepal:
.incbin "gfx/sprites/iceball.pal"
// SPRITES - iceball - END

// SPRITES - healthbar
healthbarsprite:
.incbin "gfx/sprites/healthbar.pic"
healthbarsprite_end:

healthbarspritepal:
.incbin "gfx/sprites/healthbar.pal"
// SPRITES - healthbar - END

// SPRITES - grenade
grenadesprite:
.incbin "gfx/sprites/grenade.pic"
grenadesprite_end:

grenadespritepal:
.incbin "gfx/sprites/grenade.pal"
// SPRITES - grenade - END

// SPRITES - explosion
explosionsprite:
.incbin "gfx/sprites/explosion.pic"
explosionsprite_end:

explosionspritepal:
.incbin "gfx/sprites/explosion.pal"
// SPRITES - explosion - END

// SPRITES - shotgun
shotgunsprite:
.incbin "gfx/sprites/shotgun.pic"
shotgunsprite_end:

shotgunspritepal:
.incbin "gfx/sprites/shotgun.pal"
// SPRITES - shotgun - END

// SPRITES - missile
missilesprite:
.incbin "gfx/sprites/missile.pic"
missilesprite_end:

missilespritepal:
.incbin "gfx/sprites/missile.pal"
// SPRITES - missile - END

// SPRITES - mage
magesprite:
.incbin "gfx/sprites/mage.pic"
magesprite_end:

magespritepal:
.incbin "gfx/sprites/mage.pal"
// SPRITES - mage - END

// SPRITES - playerstatuses
playerstatusessprite:
.incbin "gfx/sprites/playerstatuses.pic"
playerstatusessprite_end:

playerstatusesspritepal:
.incbin "gfx/sprites/playerstatuses.pal"
// SPRITES - playerstatuses - END

.ends