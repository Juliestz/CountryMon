//
// Created by Julie on 19/11/2020.
//

#ifndef ECEMON_T_PLAYER_H
#define ECEMON_T_PLAYER_H

#include <iostream>
#include <string>
#include "Collection.h"
#include "Card.h"

class Collection;

class Card;

class Player {
private:
    std::string m_pseudo;
    int m_money;
    Collection m_collectionj;


public:
    Player();
    void setPseudo(std::string pseudo);
    //std::string getPseudo();
    //int setMoney(int money);
    void getInfo(std::string nameDoc);
    void afficher();
    void saveCollection(std::string nameDoc);
    void createCollection(std::string nameDoc);
    void addCardToMyCollection();
    Collection* getCollection();
    ~Player();
    void deathPlayer();
};


#endif //ECEMON_T_PLAYER_H
