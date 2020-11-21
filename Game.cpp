//
// Created by aymeric Ecole on 21/11/2020.
//

#include "Game.h"


void Game::utilisationDeCarteEvent(Special *Carte, GameBoard *GB, GameBoard *M_opponent) {

    switch (Carte->getNum()) {
        case 1:
            GB->enleverHP(1);
            M_opponent->enleverHP(2);

             /*Bombe Atomique : « six Aout 45 »

             Créature adverse -2 PV

             Créature allié -1 PV*/
            break;
        case 2:
            M_opponent->getFirstCard()->display();
            /*  Espion : « James Bond »

              Voir la première carte du deck de l’adversaire*/
            break;
        case 4:
            this->drawPhase(GB, M_opponent);
            drawPhase(GB, M_opponent);
            break;
        case 6:

            /*Pandémie : « Confinement »

            -1 carte énergie de chaque coté*/
            break;
        case 7:
            if (M_opponent->destroyPermanent()) {
                std::cout << "il n'y avait pas de carte\n";
            }
            /*-	Territoire : « Alsace »

            -1 carte permanente adverse du plateau*/
            break;
        default:
            GB->utilisationDeCarteEvent(Carte);
            break;
    }
}

Game::Game(GameBoard *GB1, GameBoard *GB2) : m_GB1{GB1}, m_GB2{GB2} {}

bool Game::playATurn(GameBoard *GB,  GameBoard *GB2) {
//le joueur 1 joue en premier



}

//  FAIRE ATENTION AU DYNAMIQUE CASTE !!!!

void Game::drawPhase(GameBoard *GB, GameBoard *GB2) {
    Card *carteManipulée = GB->pickUp();

    Special *cs = dynamic_cast<Special *>(carteManipulée);
    if (cs) {
        this->utilisationDeCarteEvent(cs, GB, GB2);
    }

    Creature *cc = dynamic_cast<Creature *>(carteManipulée);
    if (cc) {
        GB->putACard(cc);
    }

    Energy *ce = dynamic_cast<Energy *>(carteManipulée);
    if (ce) {

    }
    /*
    if (carteManipulée->getNum() < 10) {
        GB.utilisationDeCarteEvent(dynamic_cast<Special *>(carteManipulée));
    } else {
        if (carteManipulée->getNum() < 20) {
            *carteManipulée;
        } else {
            GB.putACard(dynamic_cast<Creature *>(carteManipulée));
        }
    }*/

}

void Game::battlePhase(GameBoard *GB) {

}

bool Game::verification(GameBoard *GB)  {
if (GB->getPV()==0){
    return true;
}


}








