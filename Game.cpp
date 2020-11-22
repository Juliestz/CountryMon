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

bool Game::playATurn(GameBoard *GB, GameBoard *GB2) {
//le joueur 1 joue en premier
    this->drawPhase(GB, GB2);
    this->battlePhase(GB);//attaque...
    this->verification(GB2);//on vérifie que l'autre joueur ne soit pas mort.
    if (verification(GB2)) {//si la vérification est vraie donc le joueur 2 à été tué pendant la battlePhase
        return false;//donc on retourne false et dans le main ça mettra fin à la partie
    } else {
        return true;//sinon on continue la partie et c'est au tour du joueur 2
    }
}

//  FAIRE ATENTION AU DYNAMIQUE CASTE !!!!

void Game::drawPhase(GameBoard *GB, GameBoard *GB2) {
    Card *carteManipulee = GB->pickUp();

    Special *cs = dynamic_cast<Special *>(carteManipulee);
    if (cs) {
        this->utilisationDeCarteEvent(cs, GB, GB2);
    }

    Creature *cc = dynamic_cast<Creature *>(carteManipulee);
    if (cc) {
        GB->putACard(cc);
    }

    Energy *ce = dynamic_cast<Energy *>(carteManipulee);
    if (ce) {
        GB->putAnEnergy(ce->getNum());
    }
    /*
    if (carteManipulee->getNum() < 10) {
        GB.utilisationDeCarteEvent(dynamic_cast<Special *>(carteManipulee));
    } else {
        if (carteManipulee->getNum() < 20) {
            *carteManipulee;
        } else {
            GB.putACard(dynamic_cast<Creature *>(carteManipulee));
        }
    }*/

}

void Game::battlePhase(GameBoard *GB) {

}

bool Game::verification(GameBoard *GB) {
    if (GB->getPV() == 0) {//si les PV sont nulles alors la vérification devient vraie.
        return true;
    } else
        return false;
}
bool isEmpty(GameBoard *GB){
    if(GB->isEmpty()){
        return false;
    }
    else{
        return true;
    }
}




void Game::playTheGame() {

}








