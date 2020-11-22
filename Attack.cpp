//
// Created by User on 21/11/2020.
//

#include "Attack.h"
#include <iostream>
#include <string.h>


Attack::Attack(std::string name, std::vector<char> energyNeeded,int degats, bool available ) : m_name{name}, m_energyNeeded{energyNeeded},m_degats{degats}, m_available{available}{}

bool Attack::attackAvailable(std::vector<char> elements) {
    if (elements[0] >= m_energyNeeded[0] && elements[1] >= m_energyNeeded[1] && elements[2] == m_energyNeeded[2] && elements[3] == m_energyNeeded[3] ){
        m_available = 1;
    }
    else m_available =0;
    return m_available;
}



