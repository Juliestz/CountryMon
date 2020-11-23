//
// Created by aymeric Ecole on 18/11/2020.
//

#include "GameBoard.h"
#include <ctime>
#include <cstdio>


#define NB_MAX_CARD_DECK 30
#define NB_MIN_CARD_DECK 15

GameBoard::GameBoard(Player *Playeur, Collection *Collection)
        : m_collection{Collection},
          m_playeur{Playeur} {
    m_creature = nullptr;
    m_enjeu = nullptr;
    m_permanente = nullptr;
    m_cemetary = nullptr;
    m_PV = 20;
    m_tabElements = {0, 0, 0, 0};

}


void GameBoard::envoyerCartAuCimetiere(Card *carteMorte) {
    delete m_cemetary;
    m_cemetary = carteMorte;
}

Card *GameBoard::pickUp() {
    Card *pioche = m_deck.front();
    m_deck.pop();
    return pioche;
}

bool GameBoard::isEmpty() {
    return !m_deck.empty();
}

void GameBoard::displayL1() {
    std::cout << "pas interressant a coder maintenant";
    int taille;
    if (m_cemetary != nullptr){
        std::cout << m_cemetary.
    }else{
        std::cout << "cimetiere";
    }


}


void GameBoard::displayL2() {

}

void GameBoard::putACard(Creature *cartePiochee) {
    this->envoyerCartAuCimetiere(m_creature);
    m_creature = cartePiochee;
}

void GameBoard::creatADeck() {
    int choix;
    int choix2;
    std::cout << "choisire les cartes du deck? (0:oui, 1:non)";
    std::cin >> choix;

    std::list<Card *>::iterator it = m_collection->getCardsCollection().begin();
    std::vector<Card *> tabRepDeColl;

    Card carteAuDeck;

    for (it; it != m_collection->getCardsCollection().end(); ++it) {
        carteAuDeck = **it;

        if (carteAuDeck.getNum() < 8) {
            tabRepDeColl.push_back(new Special());
            *tabRepDeColl.back() = **it;

        } else if (carteAuDeck.getNum() < 12) {
            tabRepDeColl.push_back(new Energy());
            *tabRepDeColl.back() = **it;

        } else {
            tabRepDeColl.push_back(new Creature());
            *tabRepDeColl.back() = **it;

        }
    }
    int nbRand;

    if (choix) {

        int nbCarteColl = tabRepDeColl.size();
        nbCarteColl = std::min(NB_MAX_CARD_DECK, nbCarteColl);
        nbCarteColl = std::max(NB_MIN_CARD_DECK, nbCarteColl);

        for (int j = 0; j < nbCarteColl; ++j) {
            nbRand = rand() % tabRepDeColl.size();


            if (tabRepDeColl[nbRand]->getNum() < 8) {

                m_deck.push(new Special());
                *m_deck.back() = *tabRepDeColl[nbRand];

            } else if (tabRepDeColl[nbRand]->getNum() < 12) {
                m_deck.push(new Energy());
                *m_deck.back() = *tabRepDeColl[nbRand];

            } else {
                m_deck.push(new Creature());
                *m_deck.back() = *tabRepDeColl[nbRand];

            }

            delete tabRepDeColl[nbRand];


            if (tabRepDeColl.back()->getNum() < 8) {
                tabRepDeColl[nbRand] = (new Special());

            } else if (tabRepDeColl.back()->getNum() < 12) {
                tabRepDeColl[nbRand] = (new Energy());

            } else {
                tabRepDeColl[nbRand] = (new Creature());
            }

            tabRepDeColl[nbRand] = tabRepDeColl.back();
            delete tabRepDeColl.back();
            tabRepDeColl.pop_back();

        }


    } else {
        std::vector<Card *> tabRepDeDeck;
        do {
            //AFFICHER tabRepDeColl

            std::cout << std::endl << "choisisser une carte à ajouter au deck et mettez 0 quand vous avez fini :";
            std::cin >> choix2;

            //selection des cartes

            if (choix2 > 0 && choix2 < tabRepDeColl.size() && m_deck.size() < NB_MAX_CARD_DECK) {
                choix2--;

                if (tabRepDeColl[choix2]->getNum() < 8) {

                    tabRepDeDeck.push_back(new Special());
                    *tabRepDeDeck.back() = *tabRepDeColl[choix2];

                } else if (tabRepDeColl[choix2]->getNum() < 12) {
                    tabRepDeDeck.push_back(new Energy());
                    *tabRepDeDeck.back() = *tabRepDeColl[choix2];

                } else {
                    tabRepDeDeck.push_back(new Creature());
                    *tabRepDeDeck.back() = *tabRepDeColl[choix2];

                }

                delete tabRepDeColl[choix2];

                if (tabRepDeColl.back()->getNum() < 8) {
                    tabRepDeColl[choix2] = (new Special());

                } else if (tabRepDeColl.back()->getNum() < 12) {
                    tabRepDeColl[choix2] = (new Energy());

                } else {
                    tabRepDeColl[choix2] = (new Creature());
                }

                tabRepDeColl[choix2] = tabRepDeColl.back();
                delete tabRepDeColl.back();
                tabRepDeColl.pop_back();

            } else if (m_deck.size() < NB_MIN_CARD_DECK) {
                std::cout << "vous devez rajouter des cartes au deck";
            }


        } while (m_deck.size() > NB_MIN_CARD_DECK || (m_deck.size() < NB_MAX_CARD_DECK && choix2 == 0));

        //on bar les cartes

        int nbCarteDeck = tabRepDeDeck.size();
        for (int j = 0; j < nbCarteDeck; ++j) {
            nbRand = rand() % tabRepDeColl.size();


            if (tabRepDeDeck[nbRand]->getNum() < 8) {

                m_deck.push(new Special());
                *m_deck.back() = *tabRepDeDeck[nbRand];

            } else if (tabRepDeDeck[nbRand]->getNum() < 12) {
                m_deck.push(new Energy());
                *m_deck.back() = *tabRepDeDeck[nbRand];

            } else {
                m_deck.push(new Creature());
                *m_deck.back() = *tabRepDeDeck[nbRand];

            }

            delete tabRepDeDeck[nbRand];


            if (tabRepDeDeck.back()->getNum() < 8) {
                tabRepDeDeck[nbRand] = (new Special());

            } else if (tabRepDeDeck.back()->getNum() < 12) {
                tabRepDeDeck[nbRand] = (new Energy());

            } else {
                tabRepDeDeck[nbRand] = (new Creature());
            }

            tabRepDeDeck[nbRand] = tabRepDeDeck.back();
            delete tabRepDeDeck.back();
            tabRepDeDeck.pop_back();

        }

        for (auto c : tabRepDeDeck) {
            delete c;
        }

    }

    for (auto c : tabRepDeColl) {
        delete c;
    }

}

void GameBoard::recoisDegats(const int &montantDegats) {
    bool temoins = m_creature->getState();
    m_PV -= m_creature->mutHP(montantDegats);
    if (temoins != m_creature->getState()) {
        this->envoyerCartAuCimetiere(m_creature);
        m_creature = nullptr;
    }
}

int GameBoard::atkDeCreature() {
    int dmg;

    return dmg;
}

void GameBoard::utilisationDeCarteEvent(Special *Carte) {
    switch (Carte->getNum()) {
        case 3:
            this->destroyPermanent();
            m_permanente = Carte;
            /* Booster : « Coupe du monde » 

             Carte qui reste sur le terrain (permanente) et augmente la puissance de la créature alliée de 1*/

            break;
        case 5:
            m_creature->mutHP(-2);
            /*Hopital : « PostCovid »

            Créature alliée +2 PV*/

            break;
    }


}

void GameBoard::putBack(Card *cartePiochee) {
    m_deck.push(cartePiochee);
}

void GameBoard::putAnEnergy(const char &numCarte) {
    m_tabElements[numCarte - 7] += 1;
}

void GameBoard::enleverHP(const int &nb) {
    bool temoins = m_creature->getState();
    m_creature->mutHP(nb);
    if (temoins != m_creature->getState()) {
        this->envoyerCartAuCimetiere(m_creature);
        m_creature = nullptr;
    }
}

Card *GameBoard::getFirstCard() {
    return m_deck.front();
}

bool GameBoard::destroyPermanent() {
    if (m_permanente != nullptr) {
        this->envoyerCartAuCimetiere(m_permanente);
        m_permanente = nullptr;
        return false;
    } else {
        return true;
    }
}

int GameBoard::getPV() {
    return m_PV;
}

void GameBoard::getCarteEnjeux() {
    m_enjeu = this->pickUp();
}

int GameBoard::removeCardToColl() {
    m_collection->removeCard(m_enjeu->getNum());
    return m_enjeu->getNum();
}

void GameBoard::addCardToColl(int type) {
    m_collection->addCard(type);
}

GameBoard::~GameBoard() {
    while (!m_deck.empty()) {
        delete m_deck.front();
        m_deck.pop();

    }

    delete m_cemetary;
    delete m_creature;
    delete m_permanente;
}
















