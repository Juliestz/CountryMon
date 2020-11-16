//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_SPECIAL_H
#define ECEMON_T_SPECIAL_H

#include <iostream>
#include <string>
#include "Card.h"


class Special : public Card {
private :
    std::string m_description;
public:
    Special();
    ~Special();
};


#endif //ECEMON_T_SPECIAL_H
