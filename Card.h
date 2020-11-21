//
// Created by Julie on 16/11/2020.
//

#ifndef ECEMON_T_CARD_H
#define ECEMON_T_CARD_H

#include <string>
#include <iostream>

class Card {
protected:
    std::string m_name;
    int m_numDeSerie;
    // ALLEGRO_BITMAP *m_fondCarte;
public:
    void setName(const std::string &name);

    void Draw(/*File *FichierFondCarte*/);

    Card();

    ~Card();

    int getNum();


};


#endif //ECEMON_T_CARD_H
