//
// Created by aymeric Ecole on 21/11/2020.
//

#include "Game.h"



void Game::utilisationDeCarteEvent(Special Carte, GameBoard *GB) {
    switch (Carte.getNum()) {
        case 1:
            GB->utilisationDeCarteEvent(Carte.getNum());
            break;
        case 2:
            GB2.
            /*  Espion : « James Bond »

              Voir la première carte du deck de l’adversaire*/
            break;
        case 3:
            m_permanente=;
            /* Booster : « Coupe du monde » 

             Carte qui reste sur le terrain (permanente) et augmente la puissance de la créature alliée de 1*/

            break;
        case 4:
            this->pickUp();
            this->pickUp();

            /*Alliés : « Triple Entente »

             Piocher 2 nouvelles cartes pour les jouer dans ce tour*/
            break;
        case 5:


            /*Hopital : « PostCovid »

            Créature alliée +2 PV*/

            break;
        case 6:

            /*Pandémie : « Confinement »

            -1 carte énergie de chaque coté*/
            break;
    }


}

