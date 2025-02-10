include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

clean: cleanMaps

cleanMaps:
	@echo "Removing map-generated files..."
	rm -f *.b16 *.m16 *.t16 *.map *.pic *.pal

all: titlescreen_tileset.pic titlescreen.m16 cave_tileset.pic cave.m16

##########################################
# Maps - Title Screen
##########################################
titlescreen_tileset.pic: titlescreen_tileset.png
	@echo Convert title screen tiles ... $(notdir $@)
	$(GFXCONV) -s 8 -o 48 -u 16 -p -m -i $<

titlescreen.m16: titlescreen.tmj titlescreen_tileset.pic
	@echo convert map tiled ... $(notdir $@)
	$(TMXCONV) $< titlescreen_tileset.map

##########################################
# Maps - Cave
##########################################
cave_tileset.pic: cave_tileset.png
	@echo Convert title screen tiles ... $(notdir $@)
	$(GFXCONV) -s 8 -o 48 -u 16 -p -m -i $<

cave.m16: cave.tmj cave_tileset.pic
	@echo convert map tiled ... $(notdir $@)
	$(TMXCONV) $< cave_tileset.map