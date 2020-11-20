#include <iostream>
#include "Special.h"
#include "SpeBombeAt.h"
#include "Player.h"
#include "SpeEspion.h"
#include "SpeBoost.h"
#include "SpeAllies.h"
#include "SpeHopital.h"

void creationDesCartes(){
    SpeBombeAt sixAout45;
    SpeEspion bond;
    SpeBoost cdm;
    SpeAllies entente;
    SpeHopital postCovid;
}


int main() {
    creationDesCartes();
    Player a;
    a.setPseudo();

    return 0;
}