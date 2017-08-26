ROOTDIR = $(N64_INST)

GCCN64PREFIX = $(ROOTDIR)/bin/mips64-elf-

CHKSUM64PATH = $(ROOTDIR)/bin/chksum64

MKDFSPATH = $(ROOTDIR)/bin/mkdfs

HEADERPATH = $(ROOTDIR)/lib

N64TOOL = $(ROOTDIR)/bin/n64tool

HEADERNAME = header

LINK_FLAGS = -L$(ROOTDIR)/lib -L$(ROOTDIR)/mips64-elf/lib -ldragon -lc -lm -ldragonsys -Tn64ld.x

PROG_NAME = BowandArrow64

CFLAGS = -std=gnu99 -march=vr4300 -mtune=vr4300 -O2 -Wall -Werror -I$(ROOTDIR)/include -I$(ROOTDIR)/mips64-elf/include

ASFLAGS = -mtune=vr4300 -march=vr4300

CC = $(GCCN64PREFIX)gcc

AS = $(GCCN64PREFIX)as

LD = $(GCCN64PREFIX)ld

OBJCOPY = $(GCCN64PREFIX)objcopy



$(PROG_NAME).v64: $(PROG_NAME).elf spritemap.dfs

	$(OBJCOPY) $(PROG_NAME).elf $(PROG_NAME).bin -O binary

	rm -f $(PROG_NAME).v64

	$(N64TOOL) -b -l 2M -t "Bow and Arrow 64" -h $(HEADERPATH)/$(HEADERNAME) -o $(PROG_NAME).v64 $(PROG_NAME).bin -s 1M spritemap.dfs

	$(CHKSUM64PATH) $(PROG_NAME).v64


$(PROG_NAME).elf : $(PROG_NAME).o map.o hero.o enemy.o weapon.o

	$(LD) -o $(PROG_NAME).elf $(PROG_NAME).o map.o hero.o enemy.o weapon.o $(LINK_FLAGS)



copy: $(PROG_NAME).v64

	cp $(PROG_NAME).v64 ~/public_html/



spritemap.dfs:

	./mkSprite

	$(MKDFSPATH) spritemap.dfs ./sprites/



all: $(PROG_NAME).v64



clean:

	rm -f *.v64 *.elf *.o *.bin *.dfs