//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_CARD_H
#define ECEMON_T_CARD_H

#include <iostream>

class Card {
protected:
    std::string m_name;
    char m_numDeSerie;
    // ALLEGRO_BITMAP *m_fondCarte;
public:
    Card(std::string name);

    void setName(const std::string &name);

    virtual void afficher();

    char getNum();

    void display(/*File *FichierFondCarte*/);

    Card();

    virtual int utilisation(char phase)=0;

    virtual ~Card() = default;

};


#endif //ECEMON_T_CARD_H
