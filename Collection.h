//
// Created by Julie on 21/11/2020.
//

#ifndef ECEMON_T_COLLECTION_H
#define ECEMON_T_COLLECTION_H

#include <iostream>
#include <list>

class Card;

class Collection {
private:
    std::list<Card*> m_collection;
public:
    Collection();
    void addCard(int numSerie);
    void removeCard(char numSerie);
    Collection* getCollection();
    std::list<Card*> getCardsCollection();
    void display();
    ~Collection();
};


#endif //ECEMON_T_COLLECTION_H
