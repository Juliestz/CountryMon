#include <iostream>
#include "Special.h"
#include "SpeBombeAt.h"
#include "Player.h"


void creationDesCartes(){
    SpeBombeAt sixAout45;
    //sixAout45.setName("sixAout45");
    SpeBombeAt neufAout45;
    //neufAout45.setName("neufAout45")
    sixAout45.afficher();
}

int main() {
    creationDesCartes();
    Player a;
    a.setPseudo();

    return 0;
}