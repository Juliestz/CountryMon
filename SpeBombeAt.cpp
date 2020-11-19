//
// Created by Julie on 16/11/2020.
//

#include "SpeBombeAt.h"
#include "GameBoard.h"

SpeBombeAt::SpeBombeAt(){
    this->setDescription("Vous lancez une bombe atomique sur la creature adverse : elle perd 2 HP."
                         " Malheureusement la deflagration est tres grande et fait perdre 1 HP a votre propre creature.");
}

void SpeBombeAt::fonctionSpe() {
    //La créature enemie perd 2 HP
    //La créature du joueur perd 1 HP
}

SpeBombeAt::~SpeBombeAt(){}