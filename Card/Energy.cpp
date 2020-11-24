//
// Created by matth on 21/11/2020.
//

#include "Energy.h"

Energy::Energy() {
    m_name = {'\0'};
    m_numDeSerie = '\0';
}


Energy::Energy(std::string name, char numSerie): Card::Card{name, numSerie}{}


void Energy::afficher() const{
    int num = m_numDeSerie;

    Card::afficher();
    std::cout<< num <<std::endl;
}

void Energy::setDescription(const std::string &description) {
    m_description = description;
}

bool Energy::read(std::istream &stream) {
    m_OK = false;
    return m_OK;
}

bool Energy::IsOK() const {
    return m_OK;
}

Energy::~Energy() {}
