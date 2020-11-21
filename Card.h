//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_CARD_H
#define ECEMON_T_CARD_H

#include <iostream>

class Card {
protected:
    std::string m_name;
    int m_numDeSerie;
public:
    void setName(const std::string& name);
    int getNum();
};


#endif //ECEMON_T_CARD_H
