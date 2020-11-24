//
// Created by aymeric Ecole on 18/11/2020.
//

#include "GameBoard.h"
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define NB_CARD_DECK 20

GameBoard::GameBoard(Player *Playeur, Collection *Collection)
        : m_collection{Collection},
          m_playeur{Playeur} {
    m_creature = nullptr;
    m_enjeu = nullptr;
    m_permanente = nullptr;
    m_cemetary = nullptr;
    m_PV = 20;
    m_tabElements = {0, 0, 0, 0};

}

void GameBoard::enleverEnergy(int n) {

    if (m_tabElements[n] != 0){
        m_tabElements[n] -=1;
    }


}

void GameBoard::envoyerCartAuCimetiere(Card *carteMorte) {
    delete m_cemetary;
    m_cemetary = carteMorte;
}

Card *GameBoard::pickUp() {
    Card *pioche = m_deck.front();
    m_deck.pop();
    return pioche;
}

bool GameBoard::isEmpty() {
    return !m_deck.empty();
}

void GameBoard::displayL1() {
    int taille;
    if (m_cemetary != nullptr) {
        std::cout << "\n" << m_cemetary->getName();
        taille = m_cemetary->getName().size();
    } else {
        std::cout << "\ncimetiere";
        taille = 9;
    }

    if (m_creature != nullptr && m_creature->getState()) {
        taille = 60 - (taille + m_creature->getName().size() / 2);
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }
        std::cout << m_creature->getName();

    } else {
        taille = 60 - (taille + 10);
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }
        std::cout << "pas de creature posee";
    }

    if (m_permanente != nullptr) {

        taille = 120 - (taille + m_permanente->getName().size());
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }

        std::cout << m_permanente->getName();

    } else {
        taille = 120 - (taille + 23);
        for (int i = 0; i < taille; ++i) {
            std::cout << " ";
        }
        std::cout << "pas de carte permanente";
    }


    std::cout << std::endl;
    if (m_creature != nullptr && m_creature->getState()) {
        for (int i = 0; i < 45; ++i) {
            std::cout << " ";
        }
        std::cout << "PV de la creature : " << m_creature->getHP();
    }
    std::cout << "\n";

}


void GameBoard::displayL2() {

    std::cout << "\nEnergies :\n";
    std::cout << "     Politique : " << m_tabElements[0] << "   Militaire : " << m_tabElements[1];

    for (int i = 0; i < 40; ++i) {
        std::cout << " ";
    }
    std::cout << " PV :" << m_PV;
    for (int i = 0; i < 40; ++i) {
        std::cout << " ";
    }
    std::cout << "DECK";

    std::cout << "\n     Scientifique : " << m_tabElements[2] << "   Ressources : " << m_tabElements[3];

}

void GameBoard::putACard(Creature *cartePiochee) {
    this->envoyerCartAuCimetiere(m_creature);
    m_creature = cartePiochee;
}


void GameBoard::addCardToDeck(int type) {
    switch (type) {
        //Specials
        case 1 :
            m_deck.push(new Special{"Six Aout 45", 1,
                                    "Vous lancez une bombe atomique sur la creature adverse : elle perd 2 HP."
                                    " Malheureusement la deflagration est tres grande et fait perdre 1 HP a votre propre creature."});
            break;

        case 2 :
            m_deck.push(new Special{"James Bond", 2, "Vous envoyez un espion pour savoir quelle sera la prochaine carte"
                                                     " tiree par le joueur adverse."});
            break;

        case 3 :
            m_deck.push(new Special{"Coupe du monde", 3, "Vous ave z gagne la coupe du monde! Bravo!"
                                                         "Le moral des troupes est au plus haut. La puissance de votre creature en jeu est augmentee de 1."});
            break;

        case 4 :
            m_deck.push(new Special{"Triple Entente", 4,
                                    "Vous vous alliez avec d'autres puissances. Vous pouvez deffausser cette carte"
                                    " et en piocher deux autre pour les jouer dans ce tour."});
            break;

        case 5 :
            m_deck.push(new Special{"Hopital", 5,
                                    "Votre systeme de sante se remet de la crise sanitaire mais est plus performant que jamais."
                                    " Votre creature gagne 2 PV."});
            break;

        case 6 :
            m_deck.push(new Special{"Pandemie", 6,
                                    "La crise fait rage, vous perdez beaucoup de ressources pendant que votre population "
                                    "est en confinement. Vous et votre ennemi perdez une carte Energie mais VOUS choisissez de quel type il s'agira."});
            break;

        case 7 :
            m_deck.push(new Special{"Territoire", 7,
                                    "Vous faites reculer l'ennemi dans son camp, enlevez lui une carte permanante "
                                    "qui se trouve sur son plateau."});
            break;

            //Energy
        case 8 :
            m_deck.push(new Energy{"Royaume", 8,
                                   "Votre nation possede un regime politique stable et puissant, cela vous permet "
                                   "de lancer des attaques de type Politique."});
            break;

        case 9 :
            m_deck.push(new Energy{"Loi de Programmation", 9,
                                   "Votre Hard Power se developpe, votre budget defense augmente,"
                                   "vous pouvez désormais lancer des attaques de type militaire."});
            break;

        case 10 :
            m_deck.push(new Energy{"R&D", 10,
                                   "Votre pays est un pays de savants, votre  avance technologique vous permet de "
                                   "lancer des attaques de type Scientifique."});
            break;

        case 11 :
            m_deck.push(new Energy{"ITER", 11,
                                   "Vous etes auto-suffisant en energie, vos centrales electriques tournent a plein regime"
                                   "vous pouvez lancer des attaques de type Ressource."});
            break;

            //Creatures
        case 12 :
            m_deck.push(new Creature{"FRANCE", 12, 7, 1});
            (m_deck.back())->newAttack("L'effroyable en eaux profondes", {2, 1, 0, 0}, 2, 0);
            (m_deck.back())->newAttack("Constellation de satellites", {1, 0, 2, 1}, 3, 0);
            break;

        case 13 :
            m_deck.push(new Creature{"USA", 13, 7, 1});
            (m_deck.back())->newAttack("Otan", {2, 0, 1, 1}, 3, 0);
            (m_deck.back())->newAttack("Bombe a hydrogen", {0, 1, 2, 1}, 2, 0);
            break;

        case 14 :
            m_deck.push(new Creature{"RUSSIA", 14, 7, 1});
            (m_deck.back())->newAttack("KGB", {1, 2, 0, 1}, 2, 0);
            (m_deck.back())->newAttack("Armee rouge", {1, 1, 1, 1}, 3, 0);
            break;

        case 15 :
            m_deck.push(new Creature{"CHINA", 15, 7, 1});
            (m_deck.back())->newAttack("Invasion a la tibetaine", {1, 1, 1, 1}, 2, 0);
            (m_deck.back())->newAttack("Piratage numerique", {0, 1, 2, 1}, 5, 0);
            break;

        case 16 :
            m_deck.push(new Creature{"NORTH KOREA", 16, 7, 1});
            (m_deck.back())->newAttack("Invasion mondiale", {0, 2, 1, 1}, 2, 0);
            (m_deck.back())->newAttack("Missile nucleaire", {1, 1, 2, 1}, 5, 0);
            break;

        case 17 :
            m_deck.push(new Creature{"DUTSCHLAND", 17, 7, 1});
            (m_deck.back())->newAttack("Blitzkrieg", {1, 1, 2, 0}, 3, 0);
            (m_deck.back())->newAttack("Luftwaffe", {0, 1, 1, 1}, 2, 0);
            break;

        case 18 :
            m_deck.push(new Creature{"IRAN", 18, 7, 1});
            (m_deck.back())->newAttack("Crise du petrole", {2, 0, 0, 1}, 3, 0);
            (m_deck.back())->newAttack("Bouclier spatiale", {0, 1, 1, 2}, 2, 0);
            break;
        case 19 :
            m_deck.push(new Creature{"JAPAN", 19, 7, 1});
            (m_deck.back())->newAttack("Sous-marin nucleaire", {1, 1, 1, 1}, 2, 0);
            (m_deck.back())->newAttack("Attaque DDOS", {0, 1, 2, 1}, 3, 0);
            break;
    }
}


void GameBoard::creatADeck() {
    int choix;
    int choix2;


    std::cout << "choisir les cartes du deck? (1:oui, 0:non)\n\n";
    std::cin >> choix;


    std::vector<Card *> tabRepDeColl;

    Card carteAuDeck;

    /*
    for (auto it : m_collection->getCardsCollection()) {

        carteAuDeck = *it;

        if (carteAuDeck.getNum() < 8) {
            tabRepDeColl.push_back(new Special());
            *tabRepDeColl.back() = *it;

        } else if (carteAuDeck.getNum() < 12) {
            tabRepDeColl.push_back(new Energy());
            *tabRepDeColl.back() = *it;

        } else {
            tabRepDeColl.push_back(new Creature());
            *tabRepDeColl.back() = *it;

        }
    }*/


    for (auto it : m_collection->getCardsCollection()) {

        carteAuDeck = *it;
        tabRepDeColl.push_back(new Card());
        *tabRepDeColl.back() = *it;

    }

    int nbRand;

    if (choix == 0) {


        for (int j = 0; j < NB_CARD_DECK; ++j) {
            nbRand = rand() % tabRepDeColl.size();

            this->addCardToDeck(tabRepDeColl[nbRand]->getNum());
            /*if (tabRepDeColl[nbRand]->getNum() < 8) {

                m_deck.push(new Special());
                *m_deck.back() = *tabRepDeColl[nbRand];

            } else if (tabRepDeColl[nbRand]->getNum() < 12) {
                m_deck.push(new Energy());
                *m_deck.back() = *tabRepDeColl[nbRand];

            } else {
                m_deck.push(new Creature());
                *m_deck.back() = *tabRepDeColl[nbRand];

            }*/

            delete tabRepDeColl[nbRand];

            /*
            if (tabRepDeColl.back()->getNum() < 8) {
                tabRepDeColl[nbRand] = (new Special());

            } else if (tabRepDeColl.back()->getNum() < 12) {
                tabRepDeColl[nbRand] = (new Energy());

            } else {
                tabRepDeColl[nbRand] = (new Creature());
            }
            */
            tabRepDeColl[nbRand] = (new Card());
            *tabRepDeColl[nbRand] = *tabRepDeColl.back();
            delete tabRepDeColl.back();
            tabRepDeColl.pop_back();

        }


    } else {
        std::vector<Card *> tabRepDeDeck;
        do {
            //AFFICHER tabRepDeColl
            std::cout << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
            for (int i = 0; i < tabRepDeColl.size(); ++i) {
                std::cout << i + 1 << "carte :" << tabRepDeColl[i]->getName() << std::endl;
            }

            std::cout << std::endl << "choisisser une carte a ajouter au deck :";
            std::cin >> choix2;

            //selection des cartes

            if (choix2 > 0 && choix2 < tabRepDeColl.size() + 1 && tabRepDeDeck.size() != NB_CARD_DECK) {
                choix2--;

                tabRepDeDeck.push_back(new Card());
                *tabRepDeDeck.back() = *tabRepDeColl[choix2];

                /*if (tabRepDeColl[choix2]->getNum() < 8) {

                    tabRepDeDeck.push_back(new Special());
                    *tabRepDeDeck.back() = *tabRepDeColl[choix2];

                } else if (tabRepDeColl[choix2]->getNum() < 12) {
                    tabRepDeDeck.push_back(new Energy());
                    *tabRepDeDeck.back() = *tabRepDeColl[choix2];

                } else {
                    tabRepDeDeck.push_back(new Creature());
                    *tabRepDeDeck.back() = *tabRepDeColl[choix2];

                }*/

                delete tabRepDeColl[choix2];

                /*if (tabRepDeColl.back()->getNum() < 8) {
                    tabRepDeColl[choix2] = (new Special());

                } else if (tabRepDeColl.back()->getNum() < 12) {
                    tabRepDeColl[choix2] = (new Energy());

                } else {
                    tabRepDeColl[choix2] = (new Creature());
                }*/
                tabRepDeColl[choix2] = (new Card());
                *tabRepDeColl[choix2] = *tabRepDeColl.back();
                delete tabRepDeColl.back();
                tabRepDeColl.pop_back();

            } else if (tabRepDeDeck.size() < NB_CARD_DECK) {
                std::cout << "\nvous devez rajouter des cartes existantes au deck\n";
            }


        } while (tabRepDeDeck.size() != NB_CARD_DECK);

        //on bar les cartes

        int nbCarteDeck = tabRepDeDeck.size();
        for (int j = 0; j < nbCarteDeck; ++j) {
            nbRand = rand() % tabRepDeColl.size();


            this->addCardToDeck(tabRepDeColl[nbRand]->getNum());

            /*
            if (tabRepDeDeck[nbRand]->getNum() < 8) {

                m_deck.push(new Special());
                *m_deck.back() = *tabRepDeDeck[nbRand];

            } else if (tabRepDeDeck[nbRand]->getNum() < 12) {
                m_deck.push(new Energy());
                *m_deck.back() = *tabRepDeDeck[nbRand];

            } else {
                m_deck.push(new Creature());
                *m_deck.back() = *tabRepDeDeck[nbRand];

            }*/

            delete tabRepDeDeck[nbRand];

            /*
            if (tabRepDeDeck.back()->getNum() < 8) {
                tabRepDeDeck[nbRand] = (new Special());

            } else if (tabRepDeDeck.back()->getNum() < 12) {
                tabRepDeDeck[nbRand] = (new Energy());

            } else {
                tabRepDeDeck[nbRand] = (new Creature());
            }*/
            tabRepDeDeck[nbRand] = (new Card());
            *tabRepDeDeck[nbRand] = *tabRepDeDeck.back();
            delete tabRepDeDeck.back();
            tabRepDeDeck.pop_back();

        }

        for (auto c : tabRepDeDeck) {
            delete c;
        }

    }

    for (auto c : tabRepDeColl) {
        delete c;
    }

}

void GameBoard::recoisDegats(const int &montantDegats) {
    if (m_creature != nullptr) {
        bool temoins = m_creature->getState();
        m_PV -= m_creature->mutHP(montantDegats);
        if (temoins != m_creature->getState()) {
            this->envoyerCartAuCimetiere(m_creature);
            m_creature = nullptr;
        }
    } else {
        m_PV -= montantDegats;
    }
}

int GameBoard::atkDeCreature() {

    if (m_creature == nullptr) {
        return 0;
    }

    int dmg = 0;
    int choix = 1;

    if (m_creature->getAttaque()[0]->attackAvailable(m_tabElements) ||
        m_creature->getAttaque()[1]->attackAvailable(m_tabElements)) {
        std::cout << "vous pouvez utiliser :\n\n";

        if (m_creature->getAttaque()[0]->attackAvailable(m_tabElements)) {
            std::cout << "         " << choix << ".  " << m_creature->getAttaque()[0]->getName() << " : fait "
                      << m_creature->getAttaque()[0]->getDeg() << " degats a l'ennemi\n";
            choix++;
        }
        if (m_creature->getAttaque()[1]->attackAvailable(m_tabElements)) {
            std::cout << "         " << choix << ".  " << m_creature->getAttaque()[1]->getName() << " : fait "
                      << m_creature->getAttaque()[1]->getDeg() << " degats a l'ennemi\n";
        }

        std::cin >> choix;

        if (m_creature->getAttaque()[0]->attackAvailable(m_tabElements)) {
            dmg = m_creature->getAttaque()[choix - 1]->getDeg();
        } else {
            dmg = m_creature->getAttaque()[choix]->getDeg();

        }

        if (m_permanente != nullptr) {
            dmg++;
        }

    } else {
        std::cout << "\n\nVous ne pouvez pas attaquer \n\n\n";

    }



    return dmg;
}

void GameBoard::utilisationDeCarteEvent(Special *Carte) {
    switch (Carte->getNum()) {
        case 3:
            this->destroyPermanent();
            m_permanente = Carte;
            /* Booster : « Coupe du monde » 

             Carte qui reste sur le terrain (permanente) et augmente la puissance de la créature alliée de 1*/

            break;
        case 5:
            if (m_creature->getHP() > 0 && m_creature->getHP() < 30) {
                m_creature->mutHP(-2);
            }
            /*Hopital : « PostCovid »

            Créature alliée +2 PV*/

            break;
    }


}

void GameBoard::putBack(Card *cartePiochee) {
    m_deck.push(cartePiochee);
}

void GameBoard::putAnEnergy(const char &numCarte) {
    m_tabElements[numCarte - 8] += 1;
}

void GameBoard::enleverHP(const int &nb) {
    if (m_creature != nullptr) {
        bool temoins = m_creature->getState();
        m_creature->mutHP(nb);
        if (temoins != m_creature->getState()) {
            this->envoyerCartAuCimetiere(m_creature);
            m_creature = nullptr;
        }
    }

}

Card *GameBoard::getFirstCard() {
    return m_deck.front();
}

bool GameBoard::destroyPermanent() {
    if (m_permanente != nullptr) {
        this->envoyerCartAuCimetiere(m_permanente);
        m_permanente = nullptr;
        return false;
    } else {
        return true;
    }
}

int GameBoard::getPV() {
    return m_PV;
}

void GameBoard::getCarteEnjeux() {
    m_enjeu = this->pickUp();
}

int GameBoard::removeCardToColl() {
    m_collection->removeCard(m_enjeu->getNum());
    return m_enjeu->getNum();
}

void GameBoard::addCardToColl(int type) {
    m_collection->addCard(type);
}

GameBoard::~GameBoard() {
    while (!m_deck.empty()) {
        delete m_deck.front();
        m_deck.pop();

    }

    delete m_cemetary;
    delete m_creature;
    delete m_permanente;
}

bool GameBoard::creatPos() {
    if (m_creature == nullptr) {
        return false;
    } else {
        return true;
    }
}
















