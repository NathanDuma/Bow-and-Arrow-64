/* 
 * File:   animation.c
 * Author: Nathan Duma
 *
 */

#include "animation.h"
#include "common_sprites.h"

static void drawText(Gfx **pglistp);
void drawSprite(Gfx **pglistp, Sprite *sp, vector2D *v, vector2D *scale);

void drawSprite(Gfx **pglistp, Sprite *sp, vector2D *v, vector2D *scale) {
    Gfx *gp, *dl;

    gp = *pglistp;

    sp->rsp_dl_next = sp->rsp_dl;

    spMove(sp, (int) (v->x), (int) (v->y));

    spScale(sp, scale->x, scale->y);

    sp->alpha = 255;

    dl = spDraw(sp);

    gSPDisplayList(gp++, dl);

    *pglistp = gp;
}

// starting level text

static const char text0[] = {
    "\t\t\t Target Practice\n\n"
    "Our journey begins on the\n"
    "target range. Target\n"
    "launchers release balloons\n"
    "up range for the archers to\n"
    "shoot. Your task - Shoot all\n"
    "of the balloons.\n\n\n"
};
static const char text2[] = {
    "\t\t\t\tMore Target Practice\n\n"
    "Nice shooting! The only way\n"
    "to become a great archer is\n"
    "to practice. After all,\n"
    "practice makes perfect.\n"
    "Now it gets a little \n"
    "tougher. Only shoot the\n"
    "RED balloons."
};


static const char text4[] = {
    "\t\t\t\t\tBouncing Bubbles\n\n"
    "Having had enough target\n"
    "practice for one day, you\n"
    "take a walk. In a small\n"
    "glade you spy a number of\n"
    "butterflies imprisoned by\n"
    "bubbles. Taking pity on the\n"
    "little creatures, you decide\n"
    "to free them..."
};

static const char text6[] = {
    "\t\t\t\t\t\t\t\t\t\tSLIMED\n\n"
    "The greatful butterflies tell\n"
    "of an evil imprisonment spell\n"
    "cast by The Black Archer,\n"
    "The greatest archer in all\n"
    "the Land! Greatest? Hah! you\n"
    "snicker. The Quest begins.\n"
    "In your path: the SWAMP..."
};

static const char text8[] = {
    "\t\t\t\t\t\t\t\tBulls Eye\n\n"
    "As the Quest proceeds you\n"
    "will be tested for speed, \n"
    "cunning, and accuracy. The\n"
    "tests begin! You Need a\n"
    "Bull's Eye to Continue..."
};

static const char text10[] = {
    "\t\t\t\t\t\t\t\tFIREBALLS\n\n"
    "Nice Shot! Suddenly you hear\n"
    "an earth shattering raport.\n"
    "The hillside nearest you\n"
    "explodes into thousands of\n"
    "flaming lava rocks, many of\n"
    "which are heading straight\n"
    "for you. No time to seek\n"
    "shelter..."
};

static const char text12[] = {
    "\t\t\t  Unfriendly Skies\n\n"
    "Thinking those rocks may have\n"
    "been meant for you, you\n"
    "decide to send a message to\n"
    "your friendKhanin the Wizard.\n"
    "A passing dove agrees to\n"
    "deliver your message. Just\n"
    "then the skies went BLACK..."
};

static const char text14[] = {
    "\t\t\t\t   Whrrrrrrrrrr\n\n"
    "The Black Archer is\n"
    "definitely on to you. His\n"
    "servants are everywhere and\n"
    "will stop at nothing in an\n"
    "effort terminate your\n"
    "existence. From beyond\n"
    "sight, you hear a strange\n"
    " whirring noise..."
};

static const char text16[] = {
    "\t\t\t\t   Dark Forest\n\n"
    "As you wind your way along\n"
    "the path unseen eyes are\n"
    "glaring at you. When you\n"
    "reach the edge of a line of\n"
    "trees you are in for\n"
    "nothing but trouble...\n"
    "I hope the Message got\n"
    "through to Khanin."
};

static const char text18[] = {
    "\t\t\t\t\t\t\t\tBulls Eye\n\n"
    "You're getting pretty good\n"
    "at this game. Time to test\n"
    "your skill again You need a\n"
    "Bull's Eye to Continue..."
};

static const char text20[] = {
    "\t\t\t\t\tMarching Pyronians\n"
    "The Pyronians are an ancient\n"
    "race of Fire Walkers. They\n"
    "are invulnerable at their\n"
    "Hottest and they are marching\n"
    "straight for you. Sometimes\n"
    "its best to get out of their\n"
    "way..."
};

static const char text22[] = {
    "\t\t\t\tImprisoned Stumbling\n"
    "into an open meadow you are\n"
    "shocked at the sight. So the\n"
    "Black Archer was only\n"
    "practicing his evil spells\n"
    "on the Butterflies. He\n"
    "won't get away with this!\n"
    "Be careful, strange clouds\n"
    "are among the fairies.."
};


static const char text24[] = {
    "Wow! You made it to the end!\n"
    "Thank you for playing!\n\n\n"
    "\t\t\t\tThe end."
};


// now for the losing levels
static const char textLose1[] = {
    "  What is an archer without\n"
    "  his arrows? He doesn't\n"
    "  continue in this game.\n\n\n"
    "\t\t\t\t\t\t\t\t\tThe end."
};


static const char textLose7[] = {
    "\n\n\n\n"
    "\t\t\tYou've been Slimed...\n\n\n"
    "\t\t\t\t\t\t\t\t\tThe end."
};

static const char textLose9[] = {
    "\n\n\n\n"
    "You'll have to shoot\n"
    "better than that to continue\n"
    "this Quest..\n\n\n"
    "\t\t\t\t\t\t\t\tThe end."
};


static const char textLose11[] = {
    "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tOUCH!\n\n\n"
    "\t\t\t\t\t\t\t\t\t\tThe end."
};

static const char textLose13[] = {
    "\n\n\n\n    "
    "Don't loose your head!\n\n\n"
    "\t\t\t\t\t\t\t\t\tThe end."
};

static const char textLose15[] = {
    "\n\n\n\n"
    "They must have thought you were a pigeon.\n\n\n"
    "\t\t\t\t\t\t\t\t\tThe end."
};

static const char textLose17[] = {
    "\n\n\n\n"
    " You can't make apple sauce\n"
    " with those apples!\n\n\n"
    "\t\t\t\t\t\t\t\t\tThe end."
};

static const char textLose21[] = {
    "\n\n\n\n"
    " Yeow, they're HOT!!!\n\n\n"
    "\t\t\t\t\t\t\tThe end."
};

static const char textLose23[] = {
    "\t\t\t\t\t    ---ZAP---\n\n\n\n"
    " Watch out for the GUARDIANS\n\n\n"
    "\t\t\t\t\t\t\tThe end."
};


static char titleText [] = {
    "\t\t\t\t\tBow and Arrow 64\n\n\n\n\n"
    "\t\t\t\tPress START to play!"
};


// output the time on the screen

static void drawText(Gfx **pglistp) {
    Gfx *gp;
    int textX;
    int textY;
    static int count = 0;
    char str[270];

    gp = *pglistp;

    font_init(&gp);

    font_set_transparent(1);

    textX = 70;
    textY = 50;

    font_set_pos(textX, textY);
    font_set_color(0, 0, 0, 255);
    font_set_scale(0.8, 0.75);
    font_set_win(50, 13);


    switch (mapNumber) {
        case 0:
            sprintf(str, text0);
            font_show_string(&gp, str);
            break;
        case 2:
            sprintf(str, text2);
            font_show_string(&gp, str);
            break;
        case 4:
            sprintf(str, text4);
            font_show_string(&gp, str);
            break;
        case 6:
            sprintf(str, text6);
            font_show_string(&gp, str);
            break;
        case 8:
            sprintf(str, text8);
            font_show_string(&gp, str);
            break;
        case 10:
            sprintf(str, text10);
            font_show_string(&gp, str);
            break;
        case 12:
            sprintf(str, text12);
            font_show_string(&gp, str);
            break;
        case 14:
            sprintf(str, text14);
            font_show_string(&gp, str);
            break;
        case 16:
            sprintf(str, text16);
            font_show_string(&gp, str);
            break;
        case 18:
            sprintf(str, text18);
            font_show_string(&gp, str);
            break;
        case 20:
            sprintf(str, text20);
            font_show_string(&gp, str);
            break;
        case 22:
            sprintf(str, text22);
            font_show_string(&gp, str);
            break;
        case 24:
            sprintf(str, text24);
            font_show_string(&gp, str);
            break;
        case -1:
            sprintf(str, textLose1);
            font_show_string(&gp, str);
            break;
        case -3:
            sprintf(str, textLose1);
            font_show_string(&gp, str);
            break;
        case -5:
            sprintf(str, textLose1);
            font_show_string(&gp, str);
            break;
        case -7:
            sprintf(str, textLose7);
            font_show_string(&gp, str);
            break;
        case -9:
            sprintf(str, textLose9);
            font_show_string(&gp, str);
            break;
        case -11:
            sprintf(str, textLose11);
            font_show_string(&gp, str);
            break;
        case -13:
            sprintf(str, textLose13);
            font_show_string(&gp, str);
            break;
        case -15:
            sprintf(str, textLose15);
            font_show_string(&gp, str);
            break;
        case -17:
            sprintf(str, textLose17);
            font_show_string(&gp, str);
            break;
        case -19:
            sprintf(str, textLose9);
            font_show_string(&gp, str);
            break;
        case -21:
            sprintf(str, textLose21);
            font_show_string(&gp, str);
            break;
        case -23:
            sprintf(str, textLose23);
            font_show_string(&gp, str);
            break;
        case 100:
            sprintf(str, titleText);
            font_show_string(&gp, str);
            break;
        default:
            sprintf(str, "ERROR");
            font_show_string(&gp, str);
            break;
    }


    font_show_string(&gp, str);

    font_finish(&gp);

    *pglistp = gp;

    count++;
}

// add the sprites to the animation

static void drawAnimation(animation *self, Gfx **glistp, vector2D *pos) {
    Gfx *gp;
    static int g = 0;

    gp = *glistp;


    spInit(&gp);

    if ((self->state >= self->size)) {
        self->state = 0;
    }
    // every animation has their own displaylist
    self->s[self->state]->rsp_dl = self->dsp;

    drawSprite(&gp, self->s[self->state], pos, &self->scale);

    if ((mapNumber % 2) == 0 || (mapNumber < 0)) {
        drawText(&gp);
    }

    spFinish(&gp);

    // remove the enddisplaylist so we can draw other things
    gp--;

    *glistp = gp;
    g++;
}


// destruct the animation
// caller frees

static void destructAnimation(animation *self) {
    free(self->dsp);
    self->s = NULL;
}

// because the scroll takes a lot

void initAnimation2(animation *self, Sprite **s, int size, vector2D *scale) {
    int gfxSize;
    self->state = 0;
    self->size = size;
    self->s = s;

    initVector2D(&self->scale);
    self->scale.x = scale->x;
    self->scale.y = scale->y;

    // obviously a magic number
    // just use the maximum gfxsize 
    // for the biggest sprite
    gfxSize = 64;

    self->dsp = malloc(sizeof (Gfx) * NUM_DL(gfxSize));

    if (self->dsp == NULL) {
        errors |= ERRORFLAG3;
    }

    self->drawAnimation = drawAnimation;
    self->destructAnimation = destructAnimation;
}

void initAnimation(animation *self, Sprite **s, int size, vector2D *scale) {
    int gfxSize;
    self->state = 0;
    self->size = size;
    self->s = s;

    initVector2D(&self->scale);
    self->scale.x = scale->x;
    self->scale.y = scale->y;

    // obviously a magic number
    // just use the maximum gfxsize 
    // for the biggest sprite
    gfxSize = 16;

    self->dsp = malloc(sizeof (Gfx) * NUM_DL(gfxSize));

    if (self->dsp == NULL) {
        errors |= ERRORFLAG4;
    }

    self->drawAnimation = drawAnimation;
    self->destructAnimation = destructAnimation;
}

