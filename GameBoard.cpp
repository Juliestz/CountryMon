//
// Created by aymeric Ecole on 18/11/2020.
//

#include "GameBoard.h"

GameBoard::GameBoard(Playeur *Playeur, Collection *Collection) : m_collection{Collection}, m_playeur{Playeur} {}


void GameBoard::envoyerCartAuCimetiere(Card carteMorte) {

    m_cemetary = m_creature;
}

Card GameBoard::pickUp() {
    Card pioche = m_deck.front();
    m_deck.pop();
    return pioche;
}

void GameBoard::display() {
    std::cout << "pas interressant a coder maintenant";
}

void GameBoard::putACard(Creature cartePioche) {
    m_creature = cartePioche;
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















