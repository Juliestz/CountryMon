//
// Created by matth on 21/11/2020.
//

#include "Energy.h"

Energy::Energy() {}

Energy::Energy(const std::string& name, const std::string& description): Card{name}, m_description{description}{}

void Energy::setDescription(const std::string &description) {
    m_description = description;
}

Energy::~Energy() {}

bool Energy::read(std::istream &stream) {
    m_OK = false;
    return m_OK;
}

bool Energy::IsOK() const {
    return m_OK;
}
Energy::Energy( std::string type, std::string description):m_description{description}{
    this->m_name;
}