//
// Created by Julie on 19/11/2020.
//

#ifndef ECEMON_T_PLAYER_H
#define ECEMON_T_PLAYER_H

#include <iostream>
#include <string>
#include "Collection.h"


class Player {
private:
    std::string m_pseudo;
    int m_money;
    Collection m_collection;
public:
    Player();
    void setPseudo();
    void afficher();
    Collection* getCollection();
    ~Player();
};


#endif //ECEMON_T_PLAYER_H
