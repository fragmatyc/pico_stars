include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

clean: 
	rm -f *.brr *.obj

all: hit.brr towershot.brr

%.brr: %.wav
	$(BRCONV) -e $< $@
