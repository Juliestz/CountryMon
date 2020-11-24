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
               // m_GB1
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
    //this->verification(GB2);//on vérifie que l'autre joueur ne soit pas mort.
    return !this->verification(GB2);
}

//  FAIRE ATENTION AU DYNAMIQUE CASTE !!!!

void Game::drawPhase(GameBoard *GB, GameBoard *GB2) {
    Card *carteManipulee = GB->pickUp();
    int choix;

    std::cout << "vous avez tire : " << carteManipulee->getName();

    std::cout << "voulez vous utiliser cette carte (oui:1, non:0):\n";
    std::cin >> choix;
    if (choix) {


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
    } else {
        GB->putBack(carteManipulee);
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
    return GB->getPV() == 0;
}

bool Game::isEmpty(GameBoard *GB) {
    return GB->isEmpty();
}


void Game::playTheGame() {

    m_GB1->creatADeck();
    m_GB2->creatADeck();
    char perdant = 1;
    bool partieContinue =  true;
    m_GB2->getCarteEnjeux();
    m_GB1->getCarteEnjeux();


    for (int i = 0; i < 5; ++i) {
        this->dislay(m_GB1, m_GB2);
        this->drawPhase(m_GB1, m_GB2);

        this->dislay(m_GB2, m_GB1);
        this->drawPhase(m_GB2, m_GB1);
    }

    do {

        this->dislay(m_GB1, m_GB2);
        partieContinue = playATurn(m_GB1, m_GB2);

        if (partieContinue && isEmpty(m_GB2)) {
            this->dislay(m_GB2, m_GB1);
            partieContinue = playATurn(m_GB2, m_GB1);

        } else {
            perdant = 2;
        }

    } while (partieContinue && isEmpty(m_GB1));

    if (perdant == 1) {
        m_GB2->addCardToColl(m_GB1->removeCardToColl());

    } else if (perdant == 2) {
        m_GB1->addCardToColl(m_GB2->removeCardToColl());

    } else {
        std::cout << "problemme de perdant";
    }

}

void Game::dislay(GameBoard *GB, GameBoard *GB2) {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    GB2->displayL2();
    GB2->displayL1();
    std::cout << "\n\n                 BATTLEFIELD\n\n";
    GB->displayL1();
    GB->displayL2();
}








