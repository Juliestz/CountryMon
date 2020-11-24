//
// Created by aymeric Ecole on 18/11/2020.
//

#include "GameBoard.h"
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define NB_CARD_DECK 20

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
    int taille;
    if (m_cemetary != nullptr) {
        std::cout << m_cemetary->getName();
        taille = m_cemetary->getName().size();
    } else {
        std::cout << "cimetiere";
        taille = 9;
    }

    if (m_creature != nullptr && m_creature->getState()) {
        taille = 60 - (taille + m_creature->getName().size() / 2);
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }
        std::cout << m_creature->getName();

    } else {
        taille = 60 - (taille + 10);
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }
        std::cout << "pas de creature posee";
    }

    if (m_permanente != nullptr) {

        taille = 120 - (taille + m_permanente->getName().size());
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }

        std::cout << m_permanente->getName();

    } else {
        taille = 120 - (taille + 23);
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }
        std::cout << "pas de carte permanente";
    }


    std::cout << std::endl;
    if (m_creature != nullptr && m_creature->getState()) {
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }
        std::cout << "PV : " << m_creature->getHP();
    }
}


void GameBoard::displayL2() {

    std::cout << "\n\nEnergies :\n";
    std::cout << "     Politique : " << m_tabElements[0] << "   Militaire : " << m_tabElements[1];

    for (int i = 0; i < 50; ++i) {
        std::cout << " ";
    }
    std::cout << "DECK";

    std::cout << "\n     Scientifique : " << m_tabElements[2] << "   Militaire : " << m_tabElements[3];

}

void GameBoard::putACard(Creature *cartePiochee) {
    this->envoyerCartAuCimetiere(m_creature);
    m_creature = cartePiochee;
}

void GameBoard::creatADeck() {
    int choix;
    int choix2;


    std::cout << "choisir les cartes du deck? (0:oui, 1:non)\n\n";
    std::cin >> choix;


    std::vector<Card *> tabRepDeColl;

    Card carteAuDeck;

    for (auto it : m_collection->getCardsCollection()) {
        carteAuDeck = *it;

        if (carteAuDeck.getNum() < 8) {
            tabRepDeColl.push_back(new Special());
            *tabRepDeColl.back() = *it;

        } else if (carteAuDeck.getNum() < 12) {
            tabRepDeColl.push_back(new Energy());
            *tabRepDeColl.back() = *it;

        } else {
            tabRepDeColl.push_back(new Creature());
            *tabRepDeColl.back() = *it;

        }
    }
    int nbRand;

    if (choix) {

        srand((unsigned int) time(0));
        for (int j = 0; j < NB_CARD_DECK; ++j) {
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
            std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
            for (int i = 0; i < tabRepDeColl.size(); ++i) {
                std::cout << i + 1 << "carte :" << tabRepDeColl[i]->getName() << std::endl;
            }

            std::cout << std::endl << "choisisser une carte à ajouter au deck et mettez 0 quand vous avez fini :";
            std::cin >> choix2;

            //selection des cartes

            if (choix2 > 0 && choix2 < tabRepDeColl.size() + 1 && m_deck.size() != NB_CARD_DECK) {
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

            } else if (m_deck.size() < NB_CARD_DECK) {
                std::cout << "vous devez rajouter des cartes au deck";
            }


        } while (m_deck.size() != NB_CARD_DECK);

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
















