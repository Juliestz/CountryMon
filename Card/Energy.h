//
// Created by matth on 21/11/2020.
//

#ifndef ECEMON_T_ENERGY_H
#define ECEMON_T_ENERGY_H

#include "Card.h"
#include <string>
#include <vector>
#include <fstream>

class Energy : public Card {

private:
    std::string m_description;
public:
    Energy();

    Energy(std::string name, char numSerie, std::string description);

    virtual void afficher() const;

    ~Energy();



};


#endif //ECEMON_T_ENERGY_H
