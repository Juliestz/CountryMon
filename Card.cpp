//
// Created by Julie on 16/11/2020.
//

#include "Card.h"
#include <iostream>
#include <string.h>

Card::Card(std::string& name, char numSerie) : m_name{name}, m_numDeSerie{numSerie}{}

Card::Card() {};



void Card::setName(const std::string &name) {

};

void Card::afficher() const{
    std::cout<< m_name <<std::endl;
}

void Card::display (/*File *FichierFondCarte*/) {
    //m_fondCarte=al_load_bitmap(FichierFondCarte);
    //al_draw_bitmap(m_fondCarte,0,0,0);
}

char Card::getNum() {
    return m_numDeSerie;
}


