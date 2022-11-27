#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

struct xorshift32_state {
    uint32_t a;
};

uint32_t xorshift32(struct xorshift32_state *state) {
    uint32_t x = state->a;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return state->a = x;
}

struct xorshift32_state *global_state = NULL;

int last_max = 0;

float rnd(int max) {
    if (global_state == NULL) {
        global_state = malloc(sizeof(struct xorshift32_state));
    }
    if (max == 0) {
        float value = global_state->a / (float)UINT32_MAX;
        return last_max*value;
    }
    last_max = max;
    global_state->a = xorshift32(global_state);
    float value = global_state->a / (float)UINT32_MAX;
    return value*max;
}

int cursor = 0;
char data[18][29] = {
    "U-BOAT",
    "210 MM SHORE GUN",
    "70,000 TON CRUISER",
    "BATTLESHIP",
    "TORPEDO BOAT",
    "HEAVYFRIGATE",
    "E-TYPE DESTROYER",
    "GUIDED-MISSLE SHIP",
    "AIRCRAFT CARRIER",
    "ONE OF YOUR DESTROYERS!!",
    "YOUR HEAVY CRUISER!!",
    "ANOTHER OF YOUR DESTROYERS!!",
    "ONE OF YOUR BATTLESHIPS!!",
    "YOUR LAST DESTROYER!!",
    "YOUR AIRCRAFT CARRIER!!",
    "YOUR LIGHT CRUISER!!",
    "YOUR LAST AIRCRAFT CARRIER!!",
    "YOUR LAST BATTLESHIP!!"
    };


char* read(){
    char* value = data[cursor];
    cursor += 1;
    return value;
}

void restore(){
    cursor = 0;
}

void tab(int value){
    for(int i = 0; i < value; i++){
        printf(" ");
    }
}

char* n1850(int o){
    restore();
    for(int c = 0; c <= 9+o; c++) {
        read();
    }
    char* d = read();
    return d;
}

char* n250(int a){
    restore();
    for (int x = 1; x <= a; ++x){
        read();
    }
    char* z = read();
    return z;
}

int main(){
    tab(26);
    printf("SEAWAR\n");
    tab(20);
    printf("CREATIVE COMPUTING\n");
    tab(18);
    printf("MORRISTOWN, NEW JERSEY\n");
    printf("\n\n\n");
    printf("YOU COMMAND A FLEET OF SHIPS OPERATING IN\n");
    printf("ENEMY TERRITORY!!!\n");
    printf("DO YOU NEED ANY ASSISTANCE\n");
    char *q;
    int s1 = 0;
    int s = 0;
    int p2 = 0;
    int a = 0;
    int p = 0;
    float b = 0;
    int e = 0;
    int p4 = 0;
    int s2 = 0;
    int p1 = 0;
    int r2 = 0;
    int o = 0;
    int pi = 0;
    int t = 0;


help:
    scanf("%s", q);
    if (strcmp (q, "YES") == 0){
        goto yes;
    } else if(strcmp (q, "NO") == 0){
        goto no;
    } else {
        printf("INPUT 'YES' OR 'NO'\n");
        goto help;
    }

yes:
    printf("YOU TELL YOUR GUN CREWS THE ELEVATION TO SET THEIR GUNS.\n");
    printf("ELEVATION IS IN DEGREES FROM 0 TO 360.\n");
    printf("YOUR TASK FORCE CONSISTS OF 3 DESTROYERS, 2 CRUISERS,\n");
    printf("2 BATTLESHIPS, AND 2 HEAVY AIRCRAFT CARRIERS.\n");
    printf("THE ENEMY HAS 9 SHIPS FOR HIS DEFENSE.\n");
    printf("IF YOU SUCCEED IN SINKING ALL HIS SHIPS BEFORE HE SINKS\n");
    printf("YOURS, YOU HAVE WON. HOWEVER, IF HE SINKS ALL YOUR SHIPS\n");
    printf("BEFORE YOU HAVE DEFEATED HIM, YOU HAVE LOST!!\n");

no:
    printf("LET US BEGIN!!!\n");
    printf("\n");
    char* z = read();
    a += 1;
    goto n320;

n250:
    z = n250(a);
    a += 1;

n320:
    if (!strcmp (z, "AIRCRAFT CARRIER")) goto n390;
    if (!strcmp (z, "U-BOAT")) goto n2000;
    if (!strcmp (z, "TORPEDO BOAT")) goto n360;
    p = 1;

n360:
    goto n405;

n390:
    restore();

n405:
    printf("\n");
    printf("YOUR FLAGSHIP REPORTS THE SIGHTING OF AN ENEMY %s", z);
    printf("\n");

n410:
    t = 43000 - 30000*rnd(0)+(rnd(0)*10)*0.987654 + 102;
    if (t < 10000) goto n410;
    s = 0;
    p2 = 0;
    t = (int)t;
    if(!strcmp (z, "U-BOAT")) goto n2030;
    printf("YOUR INSTRUMENTS READ THE RANGE TO THE TARGET AS %i", t);
    printf(" METERS.\n");
    if (p == 1) goto n1480;

n490:
    if (s > 4) goto n510;
    goto n540;

n510:
    printf("ALL RIGHT, BAD SHOT, THE TARGET HAS MOVED OUT OF\n");
    printf("RANGE !!! LET'S TRY IT AGAIN !!!\n");
    s1 += s;
    goto n320;

n540:
    printf("WHAT ELEVATION ** ? ");
    scanf("%f", &b);
    printf("\n\n");
    printf("-----FIRE!!!\n");
    s += 1;
    if (b > 360) goto n1410;
    if(b < 0) goto n750;
    if (b == 0) goto n770;
    if(b == 90) goto n980;
    if (b > 330) goto n770;
    if(b > 180) goto n1370;
    if (b > 150) goto n1310;
    if(b > 90) goto n1020;
    float v1 = 675.285;
    e = (int)(t-(v1*v1/9.80665*sin(2*b/57.3)));
    if (abs(e) <= 100) goto n1050;
    if (e > 100) goto n1200;
    if (e <-100) goto n1250;

n750:
    printf("GUN BACKFIRED, KILLING CREW!\n");
    goto n820;

n770:
    printf("WHAT ARE YOU TRYING TO DO? KILLSOME FISH? THE SHELL\n");
    printf("EXPLODED UNDER WATER FIFTY METERS FROM YOUR SHIP!!!\n");
    goto n1590;
    
n820:
    printf("              ADMIRAL PLEASE !!!!\n");
    goto n1590;

n840:
    printf("            ********  PEACE  ********\n");
    printf("\n\n\n");
    printf("YOU FIRED %i", s1); 
    printf(" ROUNDS. THE ENEMY FIRED %i", s2);
    printf(" ROUNDS.\n");
    if (o == 9) goto n920;
    if (a == 9) goto n950;

n920:
    printf("ALL OF YOUR SHIPS HAVE BEEN SUNK.  SO SORRY\n");
    printf("THE BATTLE IS OVER..........THE ENEMY WINS!\n");
    goto n2220;

n950:
    printf("YOU HAVE DECIMATED THE ENEMY..........THAT'S NICE\n");
    printf("THE BATTLE IS OVER..........YOU WIN!!!!!\n");
    goto n2220;

n980:
    printf("YOU IDIOT!! YOU SHOT STRAIGHT UP!!, AND THE SHELL\n");
    printf("LANDED ON YOUR OWN GUN POSITION, DESTROYING IT!!!\n");
    goto n1590;

n1020:
    printf("HEY STUPID, YOU'RE FIRING ON YOUR OWN SHIPS!!!\n");
    goto n1590;

n1050:
    if(!strcmp (z, "U-BOAT")) goto n1070;
    goto n1090;

n1070:
    printf("DEPTH CHARGE EXPLODED RIGHT ON TOP OF THAT BABY!!!\n");
    goto n1100;

n1090:
    printf("  ** BOOM  **\n");
    printf("\n");

n1100:
    printf("TARGET DESTROYED!!!     **\n %i", s);
    printf("\n ** ROUNDS EXPENDED.\n");
    printf("YOU HAVE LOST %i", o);
    printf(" SHIPS, AND THE ENEMY HAS LOST %i", a);
    printf(".\n");
    s1 += s;
    pi = 0;
    goto n250;

n1200:
    if (!strcmp (z, "U-BOAT")) goto n2130;
    printf("SHOT FELL %i", abs(e));
    printf(" METERS SHORT OF TARGET.\n");
    goto n1590;

n1250:
    if (!strcmp (z, "U-BOAT")) goto n2160;
    printf("SHELL OVERSHOT TARGET BY %i", abs(e));
    printf(" METERS.\n");
    goto n1590;

n1310:
    printf("  YOU SHOT A PROJECTILE, INTO THE AIR,\n");
    printf("  IT FELL TO THE WATER, YOU KNOW NOT WHERE.\n");
    printf("BUT I DO, YOU IDIOT, YOU JUST SANK YOUR OWN FLEET TANKER!!\n");
    s1 += 1;
    if (p==1) goto n1590;
    goto n490;

n1370:
    printf("WHAT ARE YOU TRYING TO DO?? DRILL A NEW HATCH?? THE SHELL\n");
    printf("EXPLODED IN YOUR SHIP, DESTROYING IT!!!\n");
    o += 1;
    if (o == 9) goto n840;
    if (p == 1) goto n1590;
    goto n820;

n1410:
    printf("WHERE DID U LEARN TO TYPE? %i", b);
    printf(" DEGREES EXCEEDS 360 BY\n");
    printf("%i", b-360);
    printf(" DEGREES\n");
    s1 += 1;
    if (p==1) goto n1590;
    goto n490;

n1480:
    printf("THE ENEMY %s", z);
    printf(" IS FIRING ON YOUR SHIPS!\n");

n1490:
    p4 = 1234*rnd(rnd(0))+(rnd(0)*10);
    if (p4 > 500) goto n1490;
    if (p2 == 1) goto n1600;
    if ((int)(p4 < 100)) goto n1800;
    if (!strcmp (z, "U-BOAT")) goto n2100;
    printf("HIS FIRST ROUND FELL %i", p4); 
    printf(" METERS SHORT.\n");

n1560:
    s2 += 1;
    goto n490;

n1590:
    if (p2 == 1) goto n1490;

n1600:
    p1 = 1250*rnd(rnd(0))+(rnd(0)*10);
    if (p1 > p4) goto n1600;
    if (p1 < (p4-400)) goto n1600;
    if (p1 < 100) goto n1710;
    p4 = p1;
    s2 += 1;
    if (!strcmp (z, "U-BOAT")) goto n2190;
    printf("THE ENEMY ROUND FELL %i", p1);
    printf(" METERS SHORT.\n");
    goto n490;

n1710:
    s2 += 1;
    p2 = 1;
    char* d = n1850(o);
    printf("THE ENEMY %s", z);
    printf(" SANK %s", d);
    printf("\n");
    o += 1;

n1770:
    if (o == 9) goto n840;
    if (!strcmp (d, "YOUR LAST BATTLESHIP!!")) goto n840;
    goto n490;

n1800:
    r2 = 1;
    d = n1850(o);
    printf("IN FACT, HE JUST SANK %s", d);
    printf("\n");
    o += 1;
    goto n1770;

n2000:
    printf("YOUR FLAGSHIP HAS DETECTED A U-BOAT APPROACHING AT 5 PHANTOMS. \n");
    p = 1;
    goto n410;

n2030:
    printf("YOUR SUBMARINE DETECTION EQUIPMENT READS THE RANGE TO THE TARGET\n");
    t -= 1500;
    if (t < 0) goto n410;
    printf("AS %i", t);
    printf(" METERS.\n");
    printf("THE U-BOAT HAS COMMENCED FIRING TORPEDOES AT YOUR SHIPS.\n");
    goto n1490;

n2100:
    printf("HIS FIRST TORPEDO EXPLODED %i", (int)(p4-50));
    printf(" METERS BEHIND\n");
    printf(" YOUR SHIP.\n");
    goto n1560;

n2130:
    printf("DEPTH CHARGE EXPLODED %i", abs(e));
    printf(" METERS SHORT OF TARGET.\n");
    goto n1590;

n2160:
    printf("DEPTH CHARGE EXPLODED %i", abs(e)); 
    printf(" METERS SHORT OF TARGET.\n");
    goto n1590;

n2190:
    printf("THE ENEMY TORPEDO EXPLODED %i", (int)(p1-50));
    printf("METERS IN FRONT OF YOUR SHIP.\n");
    goto n490;

n2220:
    return -1;

}