//
// Created by Julie on 21/11/2020.
//

#include "Collection.h"
#include "Card/Special.h"
#include "Card/Energy.h"
#include "Card/Creature.h"

Collection::Collection() {}

void Collection::addCard(int type) {
    switch (type) {
        //Specials
        case 1 :
            m_collection.push_back(new Special{"Six Aout 45", 1,
                                               "Vous lancez une bombe atomique sur la creature adverse : elle perd 2 HP."
                                               " Malheureusement la deflagration est tres grande et fait perdre 1 HP a votre propre creature."});
            break;

        case 2 :
            m_collection.push_back(
                    new Special{"James Bond", 2, "Vous envoyez un espion pour savoir quelle sera la prochaine carte"
                                                 " tiree par le joueur adverse."});
            break;

        case 3 :
            m_collection.push_back(new Special{"Coupe du monde", 3, "Vous avez gagne la coupe du monde! Bravo! "
                                                                    "Le moral des troupes est au plus haut. La puissance de votre creature en jeu est augmentee de 1."});
            break;

        case 4 :
            m_collection.push_back(new Special{"Triple Entente", 4,
                                               "Vous vous alliez avec d'autres puissances. Vous pouvez deffausser cette carte"
                                               " et en piocher deux autre pour les jouer dans ce tour."});
            break;

        case 5 :
            m_collection.push_back(new Special{"Hopital", 5,
                                               "Votre systeme de sante se remet de la crise sanitaire mais est plus performant que jamais."
                                               " Votre creature gagne 2 PV."});
            break;

        case 6 :
            m_collection.push_back(new Special{"Pandemie", 6,
                                               "La crise fait rage, vous perdez beaucoup de ressources pendant que votre population "
                                               "est en confinement. Vous et votre ennemi perdez une carte Energie mais VOUS choisissez de quel type il s'agira."});
            break;

        case 7 :
            m_collection.push_back(new Special{"Territoire", 7,
                                               "Vous faites reculer l'ennemi dans son camp, enlevez lui une carte permanante "
                                               "qui se trouve sur son plateau."});
            break;

            //Energy
        case 8 :
            m_collection.push_back(new Energy{"Royaume", 8,
                                              "Votre nation possede un regime politique stable et puissant, cela vous permet "
                                              "de lancer des attaques de type Politique."});
            break;

        case 9 :
            m_collection.push_back(new Energy{"Loi de Programmation", 9,
                                              "Votre Hard Power se developpe, votre budget defense augmente,"
                                              "vous pouvez désormais lancer des attaques de type militaire."});
            break;

        case 10 :
            m_collection.push_back(new Energy{"R&D", 10,
                                              "Votre pays est un pays de savants, votre  avance technologique vous permet de "
                                              "lancer des attaques de type Scientifique."});
            break;

        case 11 :
            m_collection.push_back(new Energy{"ITER", 11,
                                              "Vous etes auto-suffisant en energie, vos centrales electriques tournent a plein regime"
                                              "vous pouvez lancer des attaques de type Ressource."});
            break;

            //Creatures
        case 12 :
            m_collection.push_back(new Creature{"FRANCE", 12, 7, 1});
            m_collection.back()->newAttack("Le Redoutable en eaux profondes", {2, 1, 0, 0}, 2, 0);
            m_collection.back()->newAttack("Constellation de satellites", {1, 0, 2, 1}, 3, 0);
            break;

        case 13 :
            m_collection.push_back(new Creature{"USA", 13, 7, 1});
            m_collection.back()->newAttack("OTAN", {2, 0, 1, 1}, 3, 0);
            m_collection.back()->newAttack("Bombe a hydrogen", {0, 1, 2, 1}, 2, 0);
            break;

        case 14 :
            m_collection.push_back(new Creature{"RUSSIA", 14, 7, 1});
            m_collection.back()->newAttack("KGB", {1, 2, 0, 1}, 2, 0);
            m_collection.back()->newAttack("Armee rouge", {1, 1, 1, 1}, 3, 0);
            break;

        case 15 :
            m_collection.push_back(new Creature{"CHINA", 15, 7, 1});
            m_collection.back()->newAttack("Invasion a la tibetaine", {1, 1, 1, 1}, 2, 0);
            m_collection.back()->newAttack("Piratage numerique", {0, 1, 2, 1}, 5, 0);
            break;

        case 16 :
            m_collection.push_back(new Creature{"NORTH KOREA", 16, 7, 1});
            m_collection.back()->newAttack("Invasion mondiale", {0, 2, 1, 1}, 2, 0);
            m_collection.back()->newAttack("Missile nucleaire", {1, 1, 2, 1}, 5, 0);
            break;

        case 17 :
            m_collection.push_back(new Creature{"GERMANY", 17, 7, 1});
            m_collection.back()->newAttack("Blitzkrieg", {1, 1, 2, 0}, 3, 0);
            m_collection.back()->newAttack("Luftwaffe", {0, 1, 1, 1}, 2, 0);
            break;

        case 18 :
            m_collection.push_back(new Creature{"IRAN", 18, 7, 1});
            m_collection.back()->newAttack("Crise du petrole", {2, 0, 0, 1}, 3, 0);
            m_collection.back()->newAttack("Bouclier spatiale", {0, 1, 1, 2}, 2, 0);
            break;
        case 19 :
            m_collection.push_back(new Creature{"JAPAN", 19, 7, 1});
            m_collection.back()->newAttack("Sous-marin nucleaire", {1, 1, 1, 1}, 2, 0);
            m_collection.back()->newAttack("Attaque DDOS", {0, 1, 2, 1}, 3, 0);
            break;
    }
}

void Collection::removeCard(char numSerie) {
    bool notRemove = true;
    /* std::list<Card *>::iterator it;
     std::list<Card *>::iterator debut;
     std::list<Card *>::iterator fin;
     debut = m_collection.begin();
     fin = m_collection.end();*/

    // for (it = debut; it != fin; ++it) {
    for (auto it:m_collection) {
        if (notRemove) {

            if ((it)->getNum() == numSerie) {

                m_collection.erase();
                delete it;
                notRemove = false;

            }
        }
    }

}

/*
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
*/

std::list<Card *> Collection::getCardsCollection() {
    return std::list<Card *>(m_collection);
}


Collection::~Collection() {

    std::list<Card *>::iterator it;
    std::list<Card *>::iterator debut;
    std::list<Card *>::iterator fin;
    debut = m_collection.begin();
    fin = m_collection.end();
    for (it = debut; it != fin; ++it) {
        delete *it;
    }

}