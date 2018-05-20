include $(ROOT)/usr/include/make/PRdefs

# The directory which has the include file and library of NuSYSTEM
#
N64KITDIR    = c:\nintendo\n64kit
NUSYSINCDIR  = $(N64KITDIR)/nusys/include
NUSYSLIBDIR  = $(N64KITDIR)/nusys/lib
NUSTDINCDIR  = $(N64KITDIR)/nustd/include
NUSTDLIBDIR  = $(N64KITDIR)/nustd/lib

LIB = $(ROOT)/usr/lib
LPR = $(LIB)/PR
INC = $(ROOT)/usr/include
CC  = gcc
LD  = ld
MAKEROM = mild

NUAUDIOLIB = -lnualstl_n_d -ln_gmus_d -ln_gaudio_sc

PRDEPTH = ../..

LCDEFS =	-DNU_DEBUG -DF3DEX_GBI_2 -DUSE_CFB32
LCINCS =	-I. -I$(NUSYSINCDIR) -I$(NUSTDINCDIR) -I$(ROOT)/usr/include/PR
LCOPTS =	-G 0
LDFLAGS = $(MKDEPOPT) -L$(LIB) -L$(NUSYSLIBDIR) -L$(NUSTDLIBDIR) $(NUAUDIOLIB) -lnustd_d -lnusys_d -lgultra_d -L$(GCCDIR)/mipse/lib -lkmc

OPTIMIZER       = -g

APP =		BowAndArrow64.out

TARGETS =	BowAndArrow64.n64

HFILES =	main.h cont.h graphic.h font.h font_ext.h vector.h hero.h \
		weapon.h enemy.h game_state.h logo.h map.h animation.h common.h \
		common_sprites.h \
		sp_apple.h \
		sp_arrow.h \
		sp_arrow_icon.h \
		sp_balloon.h \
		sp_arrow_fire.h \
		sp_balloon_dead.h \
		sp_balloon_y.h \
		sp_balloon_y_dead.h \
		sp_bulls_eye.h \
		sp_butterfly.h \
		sp_butterfly_burst.h \
		sp_butterfly_trapped.h \
		sp_dove1.h \
		sp_dove2.h \
		sp_fairy.h \
		sp_fairy_trapped.h \
		sp_fire1.h \
		sp_fire2.h \
		sp_fire_dead.h \
		sp_flame.h \
		sp_flashm1.h \
		sp_flashm2.h \
		sp_flashm3.h \
		sp_hero0.h \
		sp_hero1.h \
		sp_hero2.h \
		sp_hero3.h \
		sp_hero_dead.h \
		sp_hero_random.h \
		sp_slime.h \
		sp_slime_dead.h \
		sp_thunderbolt.h \
		sp_tree1.h \
		sp_tree_dead.h \
		sp_vulture2.h \
		sp_vulture_dead.h \
		sp_watcher1.h \
		sp_watcher2.h \
		sp_wind1.h \
		sp_wind2.h \
		sp_wind_dead.h \
		sp_null.h \
		sp_life.h \
		sp_tree2.h \
		sp_vulture1.h \
		sp_scroll.h \
		sp_nintendologo.h \
		sp_sixtyfour.h


CODEFILES   =	main.c cont.c graphic.c gfxinit.c font.c vector.c \
		hero.c weapon.c enemy.c logo.c game_over.c game_title.c \
		game_main.c map.c animation.c \
		sp_apple.c \
		sp_arrow.c \
		sp_arrow_icon.c \
		sp_balloon.c \
		sp_arrow_fire.c \
		sp_balloon_dead.c \
		sp_balloon_y.c \
		sp_balloon_y_dead.c \
		sp_bulls_eye.c \
		sp_butterfly.c \
		sp_butterfly_burst.c \
		sp_butterfly_trapped.c \
		sp_dove1.c \
		sp_dove2.c \
		sp_fairy.c \
		sp_fairy_trapped.c \
		sp_fire1.c \
		sp_fire2.c \
		sp_fire_dead.c \
		sp_flame.c \
		sp_flashm1.c \
		sp_flashm2.c \
		sp_flashm3.c \
		sp_hero0.c \
		sp_hero1.c \
		sp_hero2.c \
		sp_hero3.c \
		sp_hero_dead.c \
		sp_hero_random.c \
		sp_slime.c \
		sp_slime_dead.c \
		sp_thunderbolt.c \
		sp_tree1.c \
		sp_tree_dead.c \
		sp_vulture2.c \
		sp_vulture_dead.c \
		sp_watcher1.c \
		sp_watcher2.c \
		sp_wind1.c \
		sp_wind2.c \
		sp_wind_dead.c \
		sp_null.c \
		sp_life.c \
		sp_tree2.c \
		sp_vulture1.c \
		sp_scroll.c \
		sp_nintendologo.c \
		sp_sixtyfour.c

CODEOBJECTS =	$(CODEFILES:.c=.o)  $(NUSYSLIBDIR)/nusys.o

DATAFILES   =	

DATAOBJECTS =	$(DATAFILES:.c=.o)

CODESEGMENT =	codesegment.o

OBJECTS =	$(CODESEGMENT) $(DATAOBJECTS)


default:        $(TARGETS)

include $(COMMONRULES)

$(CODESEGMENT):	$(CODEOBJECTS) Makefile
		$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(TARGETS):	$(OBJECTS)
		$(MAKEROM) spec -I$(NUSYSINCDIR) -r $(TARGETS) -e $(APP)
