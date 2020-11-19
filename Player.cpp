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

void Player::afficher(){
    if (m_isAlive){
        std::cout<< m_pseudo << " :" <<std::endl;
        std::cout<< "Points de vie :" << m_pv <<std::endl;
        std::cout<< "Argent :" << m_money <<std::endl;
    }
    else{
        std::cout<< m_pseudo << " est mort." <<std::endl;
    }
}

void Player::notAlive(){
    m_isAlive = false;
}

Player::~Player(){}