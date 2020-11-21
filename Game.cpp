//
// Created by aymeric Ecole on 21/11/2020.
//

#include "Game.h"
#include "Energy.h"


void Game::utilisationDeCarteEvent(Special *Carte, GameBoard *GB) {
    if (Carte->getNum() < 4 || Carte->getNum() > 4) {
        GB->utilisationDeCarteEvent(Carte);
    } else {
        GB->pickUp();
        GB->pickUp();
    }



    /*Alliés : « Triple Entente »

     Piocher 2 nouvelles cartes pour les jouer dans ce tour*/



    /*Hopital : « PostCovid »

    Créature alliée +2 PV*/


    /*Pandémie : « Confinement »

    -1 carte énergie de chaque coté*/
}

Game::Game(GameBoard *GB1, GameBoard *GB2) : m_GB1{GB1}, m_GB2{GB2} {}

void Game::playATurn(GameBoard *GB) {


}

//  FAIRE ATENTION AU DYNAMIQUE CASTE !!!!

void Game::drawPhase(GameBoard *GB) {
    Card *carteManipulée = GB->pickUp();

    Special *cs = dynamic_cast<Special *>(carteManipulée);
    if (cs) {
        this->utilisationDeCarteEvent(cs, GB);
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

void Game::endPhase(GameBoard *GB) {

}








