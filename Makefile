include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

.PHONY: all

export ROMNAME := pico_stars
MAPSDIR := ./maps
SPRITESDIR := ./gfx/sprites
SNDDIR := ./sounds

all: 
	$(MAKE) -C $(MAPSDIR)
	$(MAKE) -C $(SPRITESDIR)
	$(MAKE) -C $(SNDDIR)
	$(MAKE) $(ROMNAME).sfc

clean:
	$(MAKE) clean -C $(MAPSDIR)
	$(MAKE) clean -C $(SPRITESDIR)
	$(MAKE) clean -C $(SNDDIR)
	find . -type f -name "*.obj" -delete
	rm $(ROMNAME).sfc $(ROMNAME).sym
	