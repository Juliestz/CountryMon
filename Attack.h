//
// Created by User on 21/11/2020.
//

#ifndef ECEMON_T_ATTACK_H
#define ECEMON_T_ATTACK_H

#include <string>
#include <iostream>
#include "Card/Energy.h"


class Attack {
private:
    std::string m_name;
    bool m_available = 0;
    std::vector<int> m_energyNeeded;
    int m_degats;
    bool m_chosen;
public:
    Attack(std::string name, std::vector<int> energyNeeded, int degats, bool available);

    bool attackAvailable(std::vector<char> elements);

    int getDeg() const;

    std::string getName() const ;

    void afficherBesoins();

    void afficher();

    bool isChosen(); // sert a indiquer a la creature qui joue si le joueur a choisi d utiliser l attaque 1 ou 2

    ~Attack();

};


#endif //ECEMON_T_ATTACK_H
