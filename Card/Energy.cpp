//
// Created by matth on 21/11/2020.
//

#include "Energy.h"

Energy::Energy() {
    m_name = {'\0'};
    m_numDeSerie = '\0';
}


Energy::Energy(std::string name, char numSerie, std::string description): Card::Card{name, numSerie}, m_description{description}{}


void Energy::afficher() const{
    Card::afficher();
    std::cout<< "Description :" <<std::endl << m_description <<std::endl;
}




Energy::~Energy() {}
