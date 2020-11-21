#include <iostream>
#include "Special.h"
#include "SpeBombeAt.h"
#include "Player.h"
#include "SpeEspion.h"
#include "SpeBoost.h"
#include "SpeAllies.h"
#include "SpeHopital.h"
#include "SpePandemie.h"
#include "SpeTerritoire.h"
#include "Creature.h"
#include "Attack.h"

void creationDesCartesSpeciales(){
    SpeBombeAt sixAout45;
    SpeEspion bond;
    SpeBoost cdm;
    SpeAllies entente;
    SpeHopital postCovid;
    SpePandemie confinement;
    SpeTerritoire alsace;
}

void creationDesCartesCreatures(){
    Creature {"FRANCE",7,8,1};
    Creature {"USA",7,8,1};
    Creature {"RUSSIA",7,8,1};
    Creature {"CHINA",7,8,1};
    Creature {"NORTH KOREA",7,8,1};
    Creature {"DUTSCHLAND",7,8,1};
    Creature {"IRAN",7,8,1};
    Creature {"JAPAN",7,8,1};
}


int main() {
    creationDesCartesSpeciales();
    creationDesCartesCreatures();
    Player a;
    a.setPseudo();

    return 0;
}