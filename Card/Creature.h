//
// Created by aymeric Ecole on 18/11/2020.
//

#ifndef ECEMON_T_CREATURE_H
#define ECEMON_T_CREATURE_H

#include "Card.h"
#include <iostream>
#include <vector>
#include "../Attack.h"



class Creature : public Card {

private:
    int m_HP;
    bool m_available;
    std::vector<Attack*> m_attacks;

public:
    Creature();

    Creature(std::string name, char numSerie, int HP, bool available);

    //Creature(std::istream& name, std::istream& HP, bool available);

    virtual std::vector<Attack*> getAttaque();

    void newAttack(std::string name, std::vector<int> energyNeeded,int degats, bool available);

    virtual void afficher() const;

    virtual ~Creature() = default;

    virtual int mutHP(int montantDegats);

    virtual bool getState() const;

    virtual int getHP();

    /*void attack(GameBoard gameBoard, std::vector<Attack*> attacks); */// sert a efectuer l attaque donc retrancher les points de degats au nb d HP de la creature adverse


    //void serialize(std::ostream &os) const;

};


#endif //ECEMON_T_CREATURE_H
