//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_CARD_H
#define ECEMON_T_CARD_H

#include <iostream>
#include <sstream>

class Card {
protected:
    std::string m_name;
    char m_numDeSerie;
    // ALLEGRO_BITMAP *m_fondCarte;
public:
    Card(std::string& name, char numSerie);

    void setName(const std::string &name);

    virtual void afficher() const;

    char getNum() const;

    std::string getName() const;

    void display(/*File *FichierFondCarte*/);

    Card();

    virtual ~Card() = default;

};


#endif //ECEMON_T_CARD_H
