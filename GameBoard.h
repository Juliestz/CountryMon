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
#include "Collection.h"


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

public:
    GameBoard(Player *Playeur, Collection *Collection, Creature *mCreature);

    void display();

    void creatADeck();

    Card *pickUp();

    Card* getFirstCard();

    void putBack(Card* cartePiochee);

    void putACard(Creature *cartePiochee);

    int atkDeCreature(); //a faire

    void recoisDegats(int montantPV);

    void enleverHP(int nb);

    void utilisationDeCarteEvent(Special *Carte);

    bool destroyPermanent();

    void putAnEnergy(char numCarte);

    void envoyerCartAuCimetiere(Card *carteMorte);


//bool pile.empty()

};


#endif //ECEMON_T_GAMEBOARD_H
