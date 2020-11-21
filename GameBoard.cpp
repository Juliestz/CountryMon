//
// Created by aymeric Ecole on 18/11/2020.
//

#include "GameBoard.h"

#define NB_MAX_CARD_DECK 20

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

void GameBoard::display() {
    std::cout << "pas interressant a coder maintenant";
}

void GameBoard::putACard(Creature *cartePiochee) {
    //delete *m_creature;
    m_creature = cartePiochee;
}

void GameBoard::creatADeck() {
    int choix;
    std::cout << "choisire les cartes du deck? (0:oui, 1:non)";
    std::cin >> choix;
    if (choix) {
        std::list<Card *>::iterator it = m_collection->getCardsCollection().begin();
        std::vector<Card> tabRepDeColl;


        for (it; it != m_collection->getCardsCollection().end(); ++it) {
            tabRepDeColl.push_back(**it);
        }


        int nbRand;
        Card carteAuDeck;
        for (int j = 0; j < NB_MAX_CARD_DECK; ++j) {
            nbRand = rand() % tabRepDeColl.size();

            carteAuDeck = tabRepDeColl[nbRand];
            tabRepDeColl[nbRand] = tabRepDeColl.back();
            tabRepDeColl.pop_back();

            if (carteAuDeck.getNum() < 8) {
                m_deck.push(new Special());
                *m_deck.back() = carteAuDeck;

            } else if (carteAuDeck.getNum() < 12) {
                m_deck.push(new Energy());
                *m_deck.back() = carteAuDeck;

            } else {
                m_deck.push(new Creature());
                *m_deck.back() = carteAuDeck;
            }
            //m_deck.push(;
        }


        return;
    } else {

        m_collection->display();


    }


}

void GameBoard::recoisDegats(int montantDegats) {
    bool temoins = m_creature->getState();
    m_PV -= m_creature->mutHP(montantDegats);
    if (temoins != m_creature->getState()) {
        this->envoyerCartAuCimetiere(m_creature);
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
            *m_permanente = *Carte;
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

void GameBoard::putAnEnergy(char numCarte) {
    m_tabElements[numCarte] += 1;
}

void GameBoard::enleverHP(int nb) {
    m_creature->mutHP(nb);
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















