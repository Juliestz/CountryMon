//
// Created by aymeric Ecole on 18/11/2020.
//

#ifndef ECEMON_T_GAMEBOARD_H
#define ECEMON_T_GAMEBOARD_H

#include <iostream>
#include <queue>
#include "Card/Card.h"
#include "Card/Creature.h"
#include "Player.h"
#include "Card/Special.h"
#include "Collection.h"
#include "Card/Energy.h"


class GameBoard {

private:
    std::queue<Card *> m_deck;
    std::vector<char> m_tabElements;
    Card *m_enjeu;
    Creature *m_creature;
    Special *m_permanente;
    int m_PV;
    Card *m_cemetary;
    Player *m_playeur;
    Collection *m_collection;

public:
    GameBoard(Player *Playeur, Collection *Collection);

    ~GameBoard();

    void displayL1();

    void displayL2();

    void addCardToDeck(int type);

    void creatADeck();

    bool isEmpty();

    Card *pickUp();

    Card *getFirstCard();

    void putBack(Card *cartePiochee);

    void putACard(Creature *cartePiochee);

    int atkDeCreature(); //a faire

    void recoisDegats(const int &montantPV);

    void enleverHP(const int &nb);

    void utilisationDeCarteEvent(Special *Carte);

    bool destroyPermanent();

    void putAnEnergy(const char &numCarte);

    void envoyerCartAuCimetiere(Card *carteMorte);

    int getPV();

    void getCarteEnjeux();

    void addCardToColl(int type);

    int removeCardToColl();

};


#endif //ECEMON_T_GAMEBOARD_H
