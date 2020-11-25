//
// Created by Julie on 21/11/2020.
//

#ifndef ECEMON_T_COLLECTION_H
#define ECEMON_T_COLLECTION_H

#include <iostream>
#include <list>
#include "Card/Card.h"

class Card;

class Collection {
private:
    std::list<Card*> m_collection;
public:
    Collection();
    void addCard(int type);
    void removeCard(char numSerie);
    std::list<Card*> getCardsCollection();
    ~Collection();
};


#endif //ECEMON_T_COLLECTION_H
