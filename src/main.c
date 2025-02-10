#include <snes.h>
#include "maps/cavemap.h"

extern char hit_brr, hit_brr_end, towershot_brr, towershot_brr_end;
brrsamples sfxHit;
brrsamples sfxTower;

int main(void) {
    //spcBoot();
    consoleInit();

    //spcAllocateSoundRegion(48);
    //spcSetSoundEntry(15, 8, 4, &towershot_brr_end - &towershot_brr, &towershot_brr, &sfxTower);
    //spcSetSoundEntry(15, 8, 6, &hit_brr_end - &hit_brr, &hit_brr, &sfxHit);

    initCaveMap();
}