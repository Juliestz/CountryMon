//
// Created by aymeric Ecole on 18/11/2020.
//

#include "Creature.h"


Creature::Creature(std::string name, int HP, int LP, bool available) : Card{name},m_HP{HP}, m_LP{LP}, m_available{available} {}


int Creature::mutHP(int montantDegats) {

    if (m_HP - montantDegats < 0) {
        m_HP -= montantDegats;
        return 0;
    } else {
        int difference = montantDegats - m_HP;
        m_HP = 0;
        m_available = false;
        return difference;
    }
}

bool Creature::getState() const {
    return m_available;
}
