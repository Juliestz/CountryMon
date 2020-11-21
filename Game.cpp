//
// Created by aymeric Ecole on 21/11/2020.
//

#include "Game.h"


void Game::utilisationDeCarteEvent(Special Carte, GameBoard *GB) {
    if (Carte.getNum() < 4 || Carte.getNum() > 4) {
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

void Game::playATurn(GameBoard GB) {
    GB.pickUp();

}








