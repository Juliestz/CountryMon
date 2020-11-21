//
// Created by Julie on 16/11/2020.
//

#include "Card.h"

Card::Card() {};

Card::~Card() {};

void Card::setName(const std::string &name) {

};

void Card::Draw(/*File *FichierFondCarte*/) {
    //m_fondCarte=al_load_bitmap(FichierFondCarte);
    //al_draw_bitmap(m_fondCarte,0,0,0);
}

int Card::getNum() {
    return m_numDeSerie;
}
