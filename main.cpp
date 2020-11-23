#include <iostream>
#include "Special.h"
#include "Player.h"
#include "Creature.h"
#include "Attack.h"
#include "Collection.h"
#include "Energy.h"

#include <fstream>

void creationDesCartesSpeciales() {
    Special sixAout45{"Six Aout 45", 1,
                      "Vous lancez une bombe atomique sur la creature adverse : elle perd 2 HP. Malheureusement la deflagration est tres grande et fait perdre 1 HP a votre propre creature."};
    Special bond{"James Bond", 2, "Vous envoyez un espion pour savoir quelle sera la prochaine carte"
                                  " tirée par le joueur adverse."};
    Special cdm{"Coupe du monde", 3, "Vous avez gagné la coupe du monde! Bravo!"
                                     "Le moral des troupes est au plus haut. La puissance de votre créature en jeu est augmentée de 1."};
    Special entente{"Triple Entente", 4, "Vous vous alliez avec d'autres puissances. Vous pouvez deffausser cette carte"
                                         " et en piocher deux autre pour les jouer dans ce tour."};
    Special hopital{"Hopital", 5,
                    "Votre systeme de sante se remet de la crise sanitaire mais est plus performant que jamais."
                    " Votre créature gagne 2 PV."};
    Special pandemie{"Pandemie", 6,
                     "La crise fait rage, vous perdez beaucoup de ressources pendant que votre population "
                     "est en confinement. Vous et votre ennemi perdez une carte Energie mais VOUS choisissez de quel type il s'agira."};
    Special territoire{"Territoire", 7, "Vous faites reculer l'ennemi dans son camp, enlevez lui une carte permanante "
                                        "qui se trouve sur son plateau."};
}

void creationDesCartesCreatures() {
    Creature France{"FRANCE", 12, 7, 1};
    Creature USA{"USA", 13, 7, 1};
    Creature Russia{"RUSSIA", 14, 7, 1};
    Creature China{"CHINA", 15, 7, 1};
    Creature NorthKorea{"NORTH KOREA", 16, 7, 1};
    Creature Germany{"GERMANY", 17, 7, 1};
    Creature Iran{"IRAN", 18, 7, 1};
    Creature Japan{"JAPAN", 19, 7, 1};


    // initialisation des attaques propres à chaque créatures


    France.newAttack("L'effroyable en eaux profondes", {2, 1, 0, 0}, 2, 0);
    France.newAttack("Constellation de satellites", {1, 0, 2, 1}, 3, 0);

    USA.newAttack("Otan", {2, 0, 1, 1}, 3, 0);
    USA.newAttack("Bombe a hydrogen", {0, 1, 2, 1}, 2, 0);

    Russia.newAttack("KGB", {1, 2, 0, 1}, 2, 0);
    Russia.newAttack("Armee rouge", {1, 1, 1, 1}, 3, 0);

    China.newAttack("Invasion a la tibetaine", {1, 1, 1, 1}, 2, 0);
    China.newAttack("Piratage numerique", {0, 1, 2, 1}, 5, 0);

    NorthKorea.newAttack("Invasion mondiale", {0, 2, 1, 1}, 2, 0);
    NorthKorea.newAttack("Missile nucleaire", {1, 1, 2, 1}, 5, 0);

    Germany.newAttack("3ieme Reich", {1, 1, 2, 0}, 3, 0);
    Germany.newAttack("Luftwaffe", {0, 1, 1, 1}, 2, 0);

    Iran.newAttack("Crise du petrole", {2, 0, 0, 1}, 3, 0);
    Iran.newAttack("Bouclier spatiale", {0, 1, 1, 2}, 2, 0);

    Japan.newAttack("Sous-marin nucleaire", {1, 1, 1, 1}, 2, 0);
    Japan.newAttack("Attaque DDOS", {0, 1, 2, 1}, 3, 0);


}


void creerMaPremiereCollection(Player joueur) {
    std::ofstream player{"../MaPremiereCollection.txt"};

    player << 5 << std::endl;
    player << joueur.getPseudo() << std::endl;

    player << 1 << std::endl;
    player << 2 << std::endl;
    player << 3 << std::endl;
    player << 18 << std::endl;
    player << 8 << std::endl;

}


std::string fonctionNum(int n){
    std::string var;
    switch(n){
        case 0 :
            var = '1';
            break;
        case 1 :
            var = '2';
            break;
        case 2 :
            var = '3';
            break;
        case 3 :
            var = '4';
            break;
        case 4 :
            var = '5';
            break;
    }
    return var;
}

void ecritureDoc(std::string nameDoc, int n) {
    std::ofstream file_input_player{nameDoc};
    file_input_player << n;
}

int lectureDoc(std::string nameDoc) {
    int n = 0;
    std::ifstream file_input_player{nameDoc};
    file_input_player >> n;
    return n;
}

void initialisationDuJoueur(Player joueur, int i, int n) {
    if (i == 1) {
        std::cout << " quel compte souhaitez vous utiliser ?" << std::endl;
        std::string fichier = "player";
        std::string extension = ".txt";
        std::string j;
        std::cin >> j;
        std::string nomFichier = fichier + j + extension;

        std::cout<< nomFichier <<std::endl;

        joueur.createCollection(nomFichier);//recréation de la collection du joueur depuis la sauvegarde


    }
    else {
        std::string fichier = "player";
        std::string extension = ".txt";
        std::string numero;
        numero = fonctionNum(n);
        std::string nomFichier = fichier + numero + extension;
        std::cout<< nomFichier;
        std::cout << "Joueur  qu'elle est votre nom de guerre ?" <<
                  std::endl;
        joueur.setPseudo();

        std::cout << "Une collection de depart vous est attribue" <<
                  std::endl;
        joueur.createCollection("MaPremiereCollection.txt");
        joueur.afficher();
        joueur.saveCollection(nomFichier);

        n += 1;
        ecritureDoc("file_save_player", n);
    }
}






void acheterUnPack(Player joueur, int i){
    if (i == 1) {
        joueur.addCardToMyCollection();
        std::cout << "felicitations, vous avez achete un pack hors de prix !!!" << std::endl;

    } else {
        std::cout
                << "vous n'avez pas achete de carte, "
                   "\n vous aurez de nouveau la possibilite d'agrandir votre collection"
                   " \navant votre prochain match. "
                << std::endl;
    }
}


int main(){


    Player joueur1;
    Player joueur2;

    /*
    joueur1.setPseudo();

    creerMaPremiereCollection(joueur1);
    joueur1.createCollection("MaPremiereCollection.txt");

    joueur1.afficher();

    joueur1.addCardToMyCollection();
    joueur1.afficher();

    joueur1.saveCollection("Joueur1.txt");
    */


    int i = 0;
    creationDesCartesSpeciales();
    creationDesCartesCreatures();



    std::cout << "Bienvenue dans CountryMon, preparez vous a vivre des combats intenses!!!!" << std::endl;



    int n = 0;
    n = lectureDoc("file_save_player");// on lit le fichier avec le nombre de joueur sauvegardé

    std::cout << "il y a : " << n << " joueur sauvegarde" << std::endl;
    std::cout << " Joueur 1 voulez-vous utiliser un compte existant? 1/oui   2/non?" << std::endl;
    std::cin >> i;
    initialisationDuJoueur(joueur1, i, n);
    joueur1.afficher();
    std::cout
            << "avant que  la partie commence vous avez la possibilte d'agrandir votre collection en achetant des cartes. 1/oui   2/non?"
            << std::endl;
    std::cin >> i;
    acheterUnPack(joueur1, i);
    joueur1.afficher();

    n = lectureDoc("file_save_player");
    std::cout << "il y a : " << n << " joueur sauvegarde" << std::endl;

    std::cout << " Joueur 2 voulez-vous utiliser un compte existant? 1/oui   2/non?" << std::endl;
    std::cin >> i;
    initialisationDuJoueur(joueur2, i,n);
    std::cout
            << "avant que  la partie commence vous avez la possibilte d'agrandir votre collection en achetant des cartes. 1/oui   2/non?"
            << std::endl;
    std::cin >> i;
    acheterUnPack(joueur2, i);


















///ne pas oublier les delete


    return 0;
}