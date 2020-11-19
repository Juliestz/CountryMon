//
// Created by Julie on 19/11/2020.
//

#include "Player.h"


Player::Player(){
    m_money = 50;
    m_pv = 3;
    m_isAlive = true;
}

void Player::setPseudo(){
    std::cout<< "Entrez votre pseudo" <<std::endl;
    std::cin>> m_pseudo;
}

Player::~Player(){}