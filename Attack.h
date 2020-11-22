//
// Created by User on 21/11/2020.
//

#ifndef ECEMON_T_ATTACK_H
#define ECEMON_T_ATTACK_H
#include <string.h>
#include <iostream>


class Attack {
private:
    std::string m_name;
    bool m_available;
    std::string m_energyNeeded;
public:
    Attack();
    Attack(std::string name, std::string energyNeeded, bool available);
    void isAvailable();


};


#endif //ECEMON_T_ATTACK_H
