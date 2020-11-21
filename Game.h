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
    Game(GameBoard *GB1, GameBoard *GB2);

    void utilisationDeCarteEvent(Special Carte, GameBoard *GB);

    void playATurn(GameBoard GB);

    void drawPhase(GameBoard GB);

    void battlePhase(GameBoard GB);

    void endPhase(GameBoard GB);


};


#endif //ECEMON_T_GAME_H
