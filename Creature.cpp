//
// Created by aymeric Ecole on 18/11/2020.
//

#include "Creature.h"

int Creature::mutHP(int montantDegats) {

    if (m_HP - montantDegats > 0) {
        m_HP -= montantDegats;
        return 0;
    } else {
        int difference = montantDegats - m_HP;
        m_HP = 0;
        m_state = false;
        return difference;
    }
}

bool Creature::getState() const {
    return m_state;
}
