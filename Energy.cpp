//
// Created by matth on 21/11/2020.
//

#include "Energy.h"

Energy::Energy() {}

Energy::Energy(const std::string& name, const std::string& description): Card{name}, m_description{description}{}

void Energy::setDescription(const std::string &description) {
    m_description = description;
}
