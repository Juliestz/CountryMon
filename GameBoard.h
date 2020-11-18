//
// Created by aymeric Ecole on 18/11/2020.
//

#ifndef ECEMON_T_GAMEBOARD_H
#define ECEMON_T_GAMEBOARD_H

#include <iostream>
#include <queue>
#include "Card.h"
#include "Creature.h"

class Playeur;

class Collection;


class GameBoard {

private:
    std::queue<Card> m_deck;
    std::vector<char> m_tebElements;
    Card m_enjeu;
    Creature m_creature;
    int m_PV;
    Card m_cemetary;
    Playeur *m_playeur;
    Collection *m_collection;

public:
    GameBoard(Playeur *Playeur, Collection *Collection);

    void display();

    void envoyerCartAuCimetiere(Card carteMorte);

    Card pickUp();

    void creatADeck(std::queue<Card> m_deck, Collection &collection);

    void recoisDegats(int montantPV);

    void putACard(Creature cartePioche);



};


#endif //ECEMON_T_GAMEBOARD_H
