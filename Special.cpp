//
// Created by Julie on 16/11/2020.
//

#include "Special.h"
#include "Card.h"
#include <iostream>

Special::Special() : m_description(NULL){}

Special::Special(std::string& name, char numSerie, std::string& description): Card::Card{name, numSerie}, m_description{description}{}


void Special::setDescription(const std::string& description){
    m_description = description;
}


void Special::afficher() const{
    Card::afficher();
    std::cout<< "Description :" <<std::endl << m_description <<std::endl;
}


Special::~Special(){}