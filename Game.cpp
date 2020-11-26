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
            std::cout << "la prochaine carte de l'adversaire est : " << M_opponent->getFirstCard()->getName();
            /*  Espion : « James Bond »
              Voir la première carte du deck de l’adversaire*/

            break;
        case 4:
            this->drawPhase(GB, M_opponent);
            this->drawPhase(GB, M_opponent);
            break;
        case 6:
            std::cout
                    << "\nquelle energie voulez-vous retirer ? \n(1 : politique  2 : militaire  3 : scientifique  4 : ressource)\n";
            int n;
            std::cin >> n;
            m_GB1->enleverEnergy(n - 1);
            m_GB2->enleverEnergy(n - 1);

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

void Game::playTheGame() {

    m_GB1->creatADeck();
    m_GB2->creatADeck();
    char perdant = 1;
    bool partieContinue = true;
    char inutil;
    m_GB2->getCarteEnjeux();
    m_GB1->getCarteEnjeux();

    //preparation phase

    for (int i = 0; i < 5; ++i) {
        this->dislay(m_GB1, m_GB2);
        this->drawPhase(m_GB1, m_GB2);

        std::cout << "\n\n terminez votre tour";
        std::cin >> inutil;

        this->dislay(m_GB2, m_GB1);
        this->drawPhase(m_GB2, m_GB1);

        std::cout << "\n\n terminez votre tour";
        std::cin >> inutil;

    }

    do {

        perdant = 2;
        this->dislay(m_GB1, m_GB2);
        partieContinue = playATurn(m_GB1, m_GB2);

        std::cout << "\n\n terminez votre tour";
        std::cin >> inutil;

        if (partieContinue && isEmpty(m_GB2)) {
            perdant = 1;

            this->dislay(m_GB2, m_GB1);
            partieContinue = playATurn(m_GB2, m_GB1);

            std::cout << "\n\n terminez votre tour";
            std::cin >> inutil;

        }

    } while (partieContinue || isEmpty(m_GB1) || isEmpty(m_GB2));

    std::cout << "\n\n\n\nvous avez perdu ";

    if (perdant == 1) {

        m_GB2->addCardToColl(m_GB1->removeCardToColl());


    } else if (perdant == 2) {
        m_GB1->addCardToColl(m_GB2->removeCardToColl());

    } else {
        std::cout << "problemme de perdant";
    }

}

bool Game::playATurn(GameBoard *GB, GameBoard *GB2) {
//le joueur 1 joue en premier
    this->drawPhase(GB, GB2);
    this->battlePhase(GB, GB2);//attaque...
    //this->verification(GB2);//on vérifie que l'autre joueur ne soit pas mort.
    return !this->verification(GB2);
}

void Game::drawPhase(GameBoard *GB, GameBoard *GB2) {
    Card *carteManipulee = GB->pickUp();
    int choix;

    std::cout << "\n\n\n\nvous avez tire : ";
    carteManipulee->afficher();
//rajouter description carte
    std::cout << "\n\n              voulez vous utiliser cette carte (oui:1, non:0):\n";
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
        int nbCard = carteManipulee->getNum();
        delete carteManipulee;
        GB->addCardToDeck(nbCard);

        //GB->putBack(carteManipulee);
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

void Game::battlePhase(GameBoard *GB, GameBoard *GB2) {
    if (GB->creatPos()) {
        GB2->recoisDegats(GB->atkDeCreature());

    }
}

bool Game::verification(GameBoard *GB) {
    return GB->getPV() <= 0;
}

bool Game::isEmpty(GameBoard *GB) {
    return GB->isEmpty();
}

void Game::dislay(GameBoard *GB, GameBoard *GB2) {
    char a = 6;

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    GB2->displayL2();
    std::cout << "\n";
    GB2->displayL1();
    for (int i = 0; i < 120; ++i) {
        std::cout << a;
    }
    std::cout << "\n                              BATTLEFIELD\n\n";

    for (int i = 0; i < 120; ++i) {
        std::cout << a;
    }
    GB->displayL1();
    std::cout << "\n";
    GB->displayL2();
    std::cout << "\n";

}








