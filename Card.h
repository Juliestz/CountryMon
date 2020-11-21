//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_CARD_H
#define ECEMON_T_CARD_H

#include <iostream>

class Card {
protected:
    std::string m_name;
public:
    Card(std::string name);
    void setName(const std::string& name);
};


#endif //ECEMON_T_CARD_H
