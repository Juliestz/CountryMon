#include <iostream>
#include "Card/Special.h"
#include "Player.h"
#include "Card/Creature.h"
#include "Attack.h"

#include "GameBoard.h"
#include "Game.h"
#include <fstream>
#include "ALLEGRO/Init_ALLEGRO.h"



std::string fonctionNum(int n){
    std::string var;
    switch(n){
        case 0 :
            var = "1";
            break;
        case 1 :
            var = "2";
            break;
        case 2 :
            var = "3";
            break;
        case 3 :
            var = "4";
            break;
        case 4 :
            var = "5";
            break;
        case 5 :
            var = "6";
            break;
        case 6 :
            var = "7";
            break;
        case 7 :
            var = "8";
            break;
        case 8 :
            var = "9";
            break;
        case 9 :
            var = "10";
            break;
    }
    return var;
}


void ecritureDoc(std::string nameDoc, int n) {
    std::ofstream file_input_player{nameDoc};
    file_input_player << n;

    file_input_player.close();
}

int lectureDoc(std::string nameDoc) {
    int n = 0;
    std::ifstream file_input_player{nameDoc};
    file_input_player >> n;

    file_input_player.close();
    return n;
}


void acheterUnPack(Player *joueur, int i){
    if (i == 1) {
        joueur->addCardToMyCollection();
        std::cout << "felicitations, vous avez achete un pack hors de prix !!!" << std::endl;

    } else {
        std::cout
                << "vous n'avez pas achete de carte, "
                   "\n vous aurez de nouveau la possibilite d'agrandir votre collection"
                   " \navant votre prochain match. "
                << std::endl;
    }
}


std::string initialisationDuJoueur(Player *joueur, int i, int n) {
    std::string name;
    std::string numero;
    int k = 0;
    if (i == 1) {
        std::string fichier = "../player";
        std::string extension = ".txt";
        for (int m = 0; m < n; m++){
            numero = fonctionNum(m);
            std::string nomFichier = fichier + numero + extension;
            name = joueur->getPseudo(nomFichier);
            std::cout<< numero << " :  " << name <<std::endl;
        }

        std::cout<< " quel compte souhaitez vous utiliser ? (entrez son numero)" << std::endl;
        std::string j;
        std::cin>> j;
        std::string nomFichier = fichier + j + extension;

        joueur->getInfo(nomFichier);
        joueur->createCollection(nomFichier);//recréation de la collection du joueur depuis la sauvegarde
        joueur->afficher();

        std::cout
                << "avant que la partie commence vous avez la possibilte d'agrandir votre collection en achetant des cartes. 1/oui   0/non?"
                << std::endl;
        std::cin >> k;
        acheterUnPack(joueur, k);
        joueur->afficher();
        joueur->saveCollection(nomFichier);

        return j;

    }
    else {

        std::string fichier = "../player";
        std::string extension = ".txt";
        numero = fonctionNum(n);
        std::string nomFichier = fichier + numero + extension;
        std::cout << "Joueur  qu'elle est votre nom de guerre ?" <<
                  std::endl;
        std::cin>> name;
        joueur->setPseudo(name);
        std::cout << "Une collection de depart vous est attribue" <<
                  std::endl;
        joueur->createCollection("../MaPremiereCollection.txt");
        joueur->afficher();

        joueur->saveCollection(nomFichier);


        n += 1;
        ecritureDoc("../file_save_player", n);

        std::cout<< "avant que  la partie commence vous avez la possibilte d'agrandir votre collection en achetant des cartes. 1/oui   2/non?"<< std::endl;
        std::cin >> k;

        joueur->afficher();

        acheterUnPack(joueur, k);
        joueur->afficher();
        joueur->saveCollection(nomFichier);

    }
}

void miseAJourFin(std::string j, Player *joueur){
    std::string fichier = "../player";
    std::string extension = ".txt";
    std::string nomFichier = fichier + j + extension;
    joueur->saveCollection(nomFichier);
}

int main() {
    srand((unsigned int) time(0));

    std::string j1;
    std::string j2;

    Player joueur1;
    Player joueur2;


    int i, n = 0;

    std::cout << "Bienvenue dans CountryMon, preparez vous a vivre des combats intenses!!!!" << std::endl;

    n = lectureDoc("../file_save_player");// on lit le fichier avec le nombre de joueur sauvegardé

    std::cout << "il y a : " << n << " joueur sauvegarde" << std::endl;
    std::cout << " Joueur 1 voulez-vous utiliser un compte existant? 1/oui   0/non?" << std::endl;
    std::cin >> i;
    if (i == 1){
        if (n != 0){
            j1 = initialisationDuJoueur(&joueur1, i, n);
        }
        else{
            std::cout<< "Il n'y a pas encore de compte, vous devez en creer un." <<std::endl;
            initialisationDuJoueur(&joueur1, 2, n);
            j1 = "1";
        }
    }
    else{
        initialisationDuJoueur(&joueur1, i, n);
        j1 = "1";
    }


    n = lectureDoc("../file_save_player");
    std::cout << "il y a : " << n << " joueur sauvegarde" << std::endl;

    std::cout << " Joueur 2 voulez-vous utiliser un compte existant? 1/oui   0/non?" << std::endl;
    std::cin >> i;
    j2 = initialisationDuJoueur(&joueur2, i,n);

    Game *jeu =new Game(new GameBoard(&joueur2, joueur1.getCollection()),new GameBoard(&joueur2,joueur2.getCollection())) ;
    jeu->playTheGame();

    miseAJourFin(j1, &joueur1);
    miseAJourFin(j2, &joueur2);














///ne pas oublier les delete


    return 0;
}