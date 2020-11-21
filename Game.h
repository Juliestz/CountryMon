//
// Created by aymeric Ecole on 21/11/2020.
//

#ifndef ECEMON_T_GAME_H
#define ECEMON_T_GAME_H

#include "GameBoard.h"


class Game {
private:
    GameBoard *m_GB1;
    GameBoard *m_GB2;

public:
    void utilisationDeCarteEvent(Special Carte, GameBoard *GB);


};


#endif //ECEMON_T_GAME_H
