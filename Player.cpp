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


    std::list<Card*>::iterator it;
    std::list<Card*>::iterator debut;
    std::list<Card*>::iterator fin;
    debut = m_collection.getCardsCollection().begin();
    fin = m_collection.getCardsCollection().end();

    for (it = debut ; it != fin ; ++it) {
        (**it).afficher();
    }
}

void Player::saveCollection(std::string nameDoc) {

    int taille;
    int type;
    std::ofstream player{nameDoc};

    taille = m_collection.getCardsCollection().size();

    player<< taille <<std::endl;
    player<< m_pseudo <<std::endl;

    std::list<Card*>::iterator it;
    Card carteAuDeck;

    for (it = m_collection.getCardsCollection().begin() ; it != m_collection.getCardsCollection().end(); ++it) {
        carteAuDeck = **it;
        type = carteAuDeck.getNum();
        player<< type <<std::endl;
    }

    player.close();
}

void Player::createCollection(std::string nameDoc){

    std::ifstream player{nameDoc};

    int taille;
    std::string pseudo;
    int type;

    player>> taille;
    player>> pseudo;

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