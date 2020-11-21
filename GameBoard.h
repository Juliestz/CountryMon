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
#include "Special.h"


class Collection;


class GameBoard {

private:
    std::queue<Card*> m_deck;
    std::vector<char> m_tabElements;
    Card *m_enjeu;
    Creature *m_creature;
    Special *m_permanente;
    int m_PV;
    Card *m_cemetary;
    Player *m_playeur;
    Collection *m_collection;
    GameBoard *M_opponent;

public:
    GameBoard(Player *Playeur, Collection *Collection, GameBoard *opponent, Creature *mCreature);

    void display();

    void creatADeck();

    Card *pickUp();

    void putBack(Card* cartePiochee);

    void putACard(Creature *cartePiochee);

    int atkDeCreature(); //a faire

    void recoisDegats(int montantPV);

    void utilisationDeCarteEvent(Special *Carte);

    void putAnEnergy(char numCarte);

    void envoyerCartAuCimetiere(Card *carteMorte);


//bool pile.empty()

};


#endif //ECEMON_T_GAMEBOARD_H
