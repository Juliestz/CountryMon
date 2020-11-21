//
// Created by aymeric Ecole on 18/11/2020.
//

#include "GameBoard.h"

GameBoard::GameBoard(Player *Playeur, Collection *Collection, GameBoard *opponent) : m_collection{Collection},
                                                                                     m_playeur{Playeur},
                                                                                     M_opponent{opponent} {}


void GameBoard::envoyerCartAuCimetiere(Card carteMorte) {
    m_cemetary = carteMorte;
}

Card GameBoard::pickUp() {
    Card pioche = m_deck.front();
    m_deck.pop();
    return pioche;
}

void GameBoard::display() {
    std::cout << "pas interressant a coder maintenant";
}

void GameBoard::putACard(Creature cartePiochee) {
    m_creature = cartePiochee;
}

void GameBoard::creatADeck(std::queue<Card> m_deck, Collection &collection) {

}

void GameBoard::recoisDegats(int montantDegats) {
    bool temoins = m_creature.getState();
    m_PV -= m_creature.mutHP(montantDegats);
    if (temoins != m_creature.getState()) {
        this->envoyerCartAuCimetiere(m_creature);
    }
}

int GameBoard::atkDeCreature() {
    int dmg;

    return dmg;
}

void GameBoard::utilisationDeCarteEvent(char numDeCarte) {
    switch (numDeCarte) {
        case 1:
            m_creature.mutHP(1);
            M_opponent->m_creature.mutHP(2);

            /* Bombe Atomique : « six Aout 45 »

             Créature adverse -2 PV

             Créature allié -1 PV*/
            break;
        case 2:
            M_opponent->m_deck.front().display();
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















