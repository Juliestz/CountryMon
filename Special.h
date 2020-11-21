//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_SPECIAL_H
#define ECEMON_T_SPECIAL_H

#include <iostream>
#include "Card.h"


class Special : public Card {
protected :
    std::string m_description;
public:
    Special();
    Special(std::string& name, char numSerie, std::string& decription);
    virtual void setDescription(const std::string& description);
    virtual void afficher() const;
    ~Special();
};


#endif //ECEMON_T_SPECIAL_H
