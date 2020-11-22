//
// Created by User on 21/11/2020.
//

#ifndef ECEMON_T_ATTACK_H
#define ECEMON_T_ATTACK_H
#include <string.h>
#include <iostream>
#include "energy.h"
#include "GameBoard.h"
#include "Creature.h"


class Attack {
private:
    std::string m_name;
    bool m_available = 0;
    std::vector<char> m_energyNeeded;
    int m_degats;
public:
    Attack(std::string name, std::vector<char> energyNeeded,int degats, bool available);
    bool attackAvailable(std::vector<char> elements);


};


#endif //ECEMON_T_ATTACK_H
