//
// Created by aymeric Ecole on 18/11/2020.
//

#include "Creature.h"


Creature::Creature(std::string name, char numSerie, int HP, bool available) : Card::Card{name, numSerie}, m_HP{HP}, m_available{available} {}


Creature::Creature() : m_HP{0}, m_available{false}, m_attacks{0} {

}


int Creature::mutHP(int montantDegats) {

    if (m_HP - montantDegats > 0) {
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



int Creature::utilisation(char phase) {

    return 0;
}

void Creature::newAttack(std::string name, std::vector<char> energyNeeded,int degats, bool available ) {
    m_attacks.push_back(new Attack(name, energyNeeded, degats, available));

}

