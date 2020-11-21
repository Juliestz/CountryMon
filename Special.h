//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_SPECIAL_H
#define ECEMON_T_SPECIAL_H

#include <iostream>
#include <string>
#include "Card.h"


class Special : public Card {
protected :
    std::string m_description;
public:
    Special();
    Special(const std::string& name, const std::string& decription);
    void setDescription(const std::string& description);
    virtual void afficher();
    virtual ~Special()=default;
};


#endif //ECEMON_T_SPECIAL_H
