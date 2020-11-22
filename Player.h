//
// Created by Julie on 19/11/2020.
//

#ifndef ECEMON_T_PLAYER_H
#define ECEMON_T_PLAYER_H

#include <iostream>
#include <string>
#include "Collection.h"

class Collection;

class Player {
private:
    std::string m_pseudo;
    int m_money;
    Collection m_collection;

public:
    Player();
    void setPseudo();
    std::string getPseudo();
    void afficher();
    void saveCollection(std::string nameDoc);
    void createCollection(std::string nameDoc);
    void addCardToMyCollection(Collection collection);
    Collection* getCollection();
    ~Player();
    void deathPlayer();
};


#endif //ECEMON_T_PLAYER_H
