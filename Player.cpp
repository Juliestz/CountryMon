//
// Created by Julie on 19/11/2020.
//

#include <fstream>
#include "Player.h"
#include "Collection.h"
#include "Card.h"

Player::Player(){
    m_money = 50;
}

void Player::setPseudo(){
    std::cout<< "Entrez votre pseudo" <<std::endl;
    std::cin>> m_pseudo;
}

std::string Player::getPseudo(){
    return m_pseudo;
}

void Player::afficher(){

    std::cout<< m_pseudo <<std::endl;

    std::list<Card*> liste;
    std::list<Card*>::iterator it;
    std::list<Card*>::iterator debut;
    std::list<Card*>::iterator fin;

    liste.merge(m_collection.getCardsCollection()); //transfere d'une liste à une autre

    debut = liste.begin();
    fin = liste.end();

    for (it = debut ; it != fin ; ++it) {
        (**it).afficher();
    }
}

void Player::saveCollection(std::string nameDoc) {

    int taille;
    int type;
    std::ofstream player{nameDoc};

    std::list<Card*> liste;
    liste.merge(m_collection.getCardsCollection());

    taille = liste.size();

    player<< taille <<std::endl;

    std::list<Card*>::iterator it;
    std::list<Card*>::iterator debut;
    std::list<Card*>::iterator fin;
    debut = liste.begin();
    fin = liste.end();

    for (it = debut ; it != fin ; ++it) {
        type = (**it).getNum();
        player<< type <<std::endl;
    }

    player.close();
}

void Player::createCollection(std::string nameDoc){

    std::ifstream player{nameDoc};

    int taille;
    std::string pseudo;
    int type = 0;

    player>> taille;

    for (int i = 0; i < taille; i++){
        player>> type;
        m_collection.addCard(type);
    }

    player.close();
}

/*Collection* Player::getCollection(){
    return m_collection.getCollection();
}*/

void Player::addCardToMyCollection(){

    for (int i=0;i<3; ++i){
        int nRand = rand()%19 +1 ;
        m_collection.addCard(nRand);
        m_money-=5;
    }
}


Player::~Player(){}