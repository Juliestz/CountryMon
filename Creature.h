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
    bool m_available;
    std::vector<Attack> m_attacks;

public:
    Creature(std::string name, int HP, bool available);

    Creature();

    Creature(std::istream& name, std::istream& HP, bool available);

    virtual ~Creature() = default;

    virtual int mutHP(int montantDegats);

    virtual void availableAttack();

    virtual bool getState() const;

    virtual int utilisation(char phase);

    void serialize(std::ostream &os) const;

};


#endif //ECEMON_T_CREATURE_H
