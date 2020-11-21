//
// Created by Julie on 16/11/2020.
//

#include "Special.h"
#include <iostream>

Special::Special(){}

Special::Special(const std::string& name, const std::string& description): m_description{description}{
    this->setName(name);
}

void Special::setDescription(const std::string& description){
    m_description = description;
}


void Special::afficher() {                               //Polymorphisqme de la fonction Afficher ???
    //std::cout<< m_name << " :" <<std::endl;
    std::cout<< "Description :" <<std::endl << m_description <<std::endl;
}

Special::~Special(){}