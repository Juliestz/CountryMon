//
// Created by Julie on 20/11/2020.
//

#include "SpeBoost.h"

SpeBoost::SpeBoost(){
    this->setName("Coupe du monde");
    this->setDescription("Vous avez gagné la coupe du monde! Bravo!"
                         "Le moral des troupes est au plus haut. La puissance de votre créature en jeu est augmentée de 1");
}

void SpeBoost::fonctionSpe() {
    //Puissance de la créature +1 jusqu'à sa mort
}

SpeBoost::~SpeBoost(){}