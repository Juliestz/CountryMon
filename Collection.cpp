//
// Created by Julie on 21/11/2020.
//

#include "Collection.h"
#include "Special.h"
#include "Energy.h"
#include "Creature.h"

Collection::Collection(){}

void Collection::addCard(int type){
        switch (type){
                //Specials
            case 1 :
                m_collection.push_back(new Special{"Six Aout 45", "Vous lancez une bombe atomique sur la creature adverse : elle perd 2 HP."
                                                                  " Malheureusement la deflagration est tres grande et fait perdre 1 HP a votre propre creature."});
                break;

            case 2 :
                m_collection.push_back(new Special{"James Bond", "Vous envoyez un espion pour savoir quelle sera la prochaine carte"
                                                                " tirée par le joueur adverse."});
                break;

            case 3 :
                m_collection.push_back(new Special{"Coupe du monde", "Vous avez gagné la coupe du monde! Bravo!"
                                                                     "Le moral des troupes est au plus haut. La puissance de votre créature en jeu est augmentée de 1."});
                break;

            case 4 :
                m_collection.push_back(new Special{"Triple Entente", "Vous vous alliez avec d'autres puissances. Vous pouvez deffausser cette carte"
                                                                     " et en piocher deux autre pour les jouer dans ce tour."});
                break;

            case 5 :
                m_collection.push_back(new Special{"Hopital", "Votre systeme de sante se remet de la crise sanitaire mais est plus performant que jamais."
                                                              " Votre créature gagne 2 PV."});
                break;

            case 6 :
                m_collection.push_back(new Special{"Pandemie", "La crise fait rage, vous perdez beaucoup de ressources pendant que votre population "
                                                               "est en confinement. Vous et votre ennemi perdez une carte Energie mais VOUS choisissez de quel type il s'agira."});
                break;

            case 7 :
                m_collection.push_back(new Special{"Territoire","Vous faites reculer l'ennemi dans son camp, enlevez lui une carte permanante "
                                                   "qui se trouve sur son plateau."});
                break;

                //Energy
            case 8 :
                m_collection.push_back(new Energy{});
                break;

            case 9 :
                m_collection.push_back(new Energy{});
                break;

            case 10 :
                m_collection.push_back(new Energy{});
                break;

            case 11 :
                m_collection.push_back(new Energy{});
                break;

                //Creatures
            case 12 :
                m_collection.push_back(new Creature{});
                break;

            case 13 :
                m_collection.push_back(new Creature{});
                break;

            case 14 :
                m_collection.push_back(new Creature{});
                break;

            case 15 :
                m_collection.push_back(new Creature{});
                break;

            case 16 :
                m_collection.push_back(new Creature{});
                break;

            case 17 :
                m_collection.push_back(new Creature{});
                break;

            case 18 :
                m_collection.push_back(new Creature{});
                break;
            case 19 :
                m_collection.push_back(new Creature{});
                break;

        }
    }
}

void Collection::removeCard(char numSerie) {
    bool notRemove = true;
    std::list<Card*>::iterator it;
    std::list<Card*>::iterator debut;
    std::list<Card*>::iterator fin;
    debut = m_collection.begin();
    fin = m_collection.end();

    for (it = debut; it!=fin; ++it){

        if (notRemove){

            if ((*it)->getNum() == numSerie){
                m_collection.erase(it);
                notRemove = false;

            }
        }
    }
}

void Collection::display(){
    std::list<Card*>::iterator it;
    std::list<Card*>::iterator debut;
    std::list<Card*>::iterator fin;
    debut = m_collection.begin();
    fin = m_collection.end();
    for (it = debut; it!=fin; ++it){
        (*it)->afficher();
    }
}


Collection::~Collection(){}

std::list<Card *> Collection::getCardsCollection() {
    return std::list<Card *>(m_collection);
}
