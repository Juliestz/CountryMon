//
// Created by Julie on 16/11/2020.
//

#include "Card.h"
#include <iostream>
#include <string.h>

Card::Card(std::string name) : m_name{name}{}

Card::Card() {};

Card::~Card() {};

void Card::setName(const std::string &name) {

};

void Card::afficher(){
    std::cout<< m_name <<std::endl;
}

void Card::display (/*File *FichierFondCarte*/) {
    //m_fondCarte=al_load_bitmap(FichierFondCarte);
    //al_draw_bitmap(m_fondCarte,0,0,0);
}

char Card::getNum() {
    return m_numDeSerie;
}

