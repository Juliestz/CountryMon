//
// Created by Julie on 16/11/2020.
//

#include "Card.h"
#include <iostream>
#include <string.h>

Card::Card(std::string &name, char numSerie) : m_name{name}, m_numDeSerie{numSerie} {}

Card::Card() {
    m_name = {'\0'};
    m_numDeSerie = '\0';
};


void Card::setName(const std::string &name) {

};

void Card::afficher() const {
    std::cout << m_name << std::endl;
}


void Card::display(/*File *FichierFondCarte*/) {
    //m_fondCarte=al_load_bitmap(FichierFondCarte);
    //al_draw_bitmap(m_fondCarte,0,0,0);
}

char Card::getNum() const {
    return m_numDeSerie;
}

std::string Card::getName() const {
    return m_name;
}


