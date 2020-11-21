//
// Created by aymeric Ecole on 18/11/2020.
//

#ifndef ECEMON_T_GAMEBOARD_H
#define ECEMON_T_GAMEBOARD_H

#include <iostream>
#include <queue>
#include "Card.h"
#include "Creature.h"
#include "Player.h"


class Collection;


class GameBoard {

private:
    std::queue<Card> m_deck;
    std::vector<char> m_tabElements;
    Card m_enjeu;
    Creature m_creature;
    int m_PV;
    Card m_cemetary;
    Player *m_playeur;
    Collection *m_collection;

public:
    GameBoard(Player *Playeur, Collection *Collection);

    void display();

    void envoyerCartAuCimetiere(Card carteMorte);

    Card pickUp();

    void creatADeck(std::queue<Card> m_deck, Collection &collection);

    void recoisDegats(int montantPV);

    void putACard(Creature cartePiochee);

    int atkDeCreature(); //a faire

    void utilisationDeCarteEvent(char numDeCarte);



};


#endif //ECEMON_T_GAMEBOARD_H
