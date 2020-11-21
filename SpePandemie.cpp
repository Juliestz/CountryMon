//
// Created by Julie on 20/11/2020.
//

#include "SpePandemie.h"

SpePandemie::SpePandemie(){
    this->setName("Confinement");
    this->setDescription("La crise fait rage, vous perdez beaucoup de ressources pendant que votre population "
                         "est en confinement. Vous et votre ennemi perdez une carte Energie mais VOUS choisissez de quel type il s'agira.");
}

void SpePandemie::fonctionSpe() {
    // -1 carte energie dans chaque camps
}

SpePandemie::~SpePandemie(){}
