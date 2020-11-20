#include <iostream>
#include "Special.h"
#include "SpeBombeAt.h"
#include "Player.h"
#include "SpeEspion.h"
#include "SpeBoost.h"


void creationDesCartes(){
    SpeBombeAt sixAout45;
    //sixAout45.setName("sixAout45");
    SpeEspion bond;
    //bond.setName("James Bond");
    SpeBoost cdm;
    //cdm.setName("Coupe du monde");
}


int main() {
    creationDesCartes();
    Player a;
    a.setPseudo();

    return 0;
}