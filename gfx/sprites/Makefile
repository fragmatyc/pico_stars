include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

clean: cleanGfx

all: tower1.pic human.pic blob.pic fireball.pic healthbar.pic grenade.pic explosion.pic shotgun.pic missile.pic

tower1.pic: tower1.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 16 -o 16 -u 16 -p -i $<

human.pic: human.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 16 -o 16 -u 16 -p -i $<

blob.pic: blob.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 16 -o 16 -u 16 -p -i $<

fireball.pic: fireball.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 16 -o 16 -u 16 -p -i $<

healthbar.pic: healthbar.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 16 -o 16 -u 16 -p -i $<

grenade.pic: grenade.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 16 -o 16 -u 16 -p -i $<

explosion.pic: explosion.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 32 -o 32 -u 16 -p -i $<

shotgun.pic: shotgun.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 32 -o 32 -u 16 -p -i $<

missile.pic: missile.png
	@echo convert sprite bitmap ... $(notdir $@)
	$(GFXCONV) -s 16 -o 16 -u 16 -p -i $<