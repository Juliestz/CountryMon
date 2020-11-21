//
// Created by matth on 21/11/2020.
//

#ifndef ECEMON_T_ENERGY_H
#define ECEMON_T_ENERGY_H

#include "Card.h"
#include <string>

class Energy : public Card {

protected:

    std::string m_description;
public:
    Energy();

    Energy(const std::string& name, const std::string& description);

    virtual ~Energy() = default;

    void setDescription(const std::string &description);

};


#endif //ECEMON_T_ENERGY_H
