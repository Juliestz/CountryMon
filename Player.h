//
// Created by Julie on 19/11/2020.
//

#ifndef ECEMON_T_PLAYER_H
#define ECEMON_T_PLAYER_H

#include <iostream>
#include <string>

class Player {
private:
    std::string m_pseudo;
    int m_money;
    int m_pv;
    bool m_isAlive;
public:
    Player();
    void setPseudo();
    void setIsAlive();
    ~Player();
};


#endif //ECEMON_T_PLAYER_H
