//
// Created by Julie on 16/11/2020.
//

#include "Card.h"
#include <iostream>
#include <string.h>

Card::Card(std::string name) : m_name{name}{}

void Card::setName(const std::string &name) {
    m_name = name;
}
