//
// Created by aymeric Ecole on 18/11/2020.
//

#ifndef ECEMON_T_CREATURE_H
#define ECEMON_T_CREATURE_H

#include "Card.h"


class Creature : public Card {

private:
    int m_HP;
    bool m_state = true;

public:
    Creature();

    int mutHP(int montantDegats);
    bool getState()const;


};


#endif //ECEMON_T_CREATURE_H
