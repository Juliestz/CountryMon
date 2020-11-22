//
// Created by User on 21/11/2020.
//

#include "Attack.h"
#include <iostream>
#include <string.h>

Attack::Attack(){}

Attack::Attack(std::string name, std::string energyNeeded, bool available ) : m_name{name}, m_available{available}, m_energyNeeded{energyNeeded}{}

void Attack::isAvailable(){

}


