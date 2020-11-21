//
// Created by Julie on 21/11/2020.
//

#include "Collection.h"
#include "Special.h"
#include "Energy.h"
#include "Creature.h"

Collection::Collection(){}

void Collection::addCard(int type){
    switch (type){
        case 1 :
            m_collection.push_back(new Special);
            break;

        case 2 :
            m_collection.push_back((new Energy));
            break;

        case 3 :
            m_collection.push_back((new Creature));
            break;

    }
}


void Collection::display(){
    std::list<Card*>::iterator it;
    std::list<Card*>::iterator debut;
    std::list<Card*>::iterator fin;
    debut = m_collection.begin();
    fin = m_collection.end();
    for (it = debut; it!=fin; ++it){
        (*it)->afficher();
    }
}


Collection::~Collection(){}

std::list<Card *> Collection::getCardsCollection() {
    return std::list<Card *>(m_collection);
}
