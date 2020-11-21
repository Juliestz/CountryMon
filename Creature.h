//
// Created by aymeric Ecole on 18/11/2020.
//

#ifndef ECEMON_T_CREATURE_H
#define ECEMON_T_CREATURE_H

#include "Card.h"
#include <vector>
#include "Attack.h"


class Creature : public Card {

private:

    int m_HP;
    int m_LP;
    bool m_available;


public:
    Creature(std::string name, int HP, int LP, bool available);

    virtual ~Creature() = default;

    virtual int mutHP(int montantDegats);

    virtual void availableAttack();

    virtual bool getState() const;


};


#endif //ECEMON_T_CREATURE_H
