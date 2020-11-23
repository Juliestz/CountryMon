#include <iostream>
#include "Special.h"
#include "Player.h"
#include "Creature.h"
#include "Attack.h"
#include "Collection.h"
#include "Energy.h"
#include "GameBoard.h"
#include <fstream>
#include "Init_ALLEGRO.h"

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


std::string fonctionNum(int n) {
    std::string var;
    switch (n) {
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
        case 5 :
            var = '6';
            break;
        case 6 :
            var = '7';
            break;
        case 7 :
            var = '8';
            break;
        case 8 :
            var = '9';
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


void acheterUnPack(Player joueur, int i) {
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


void initialisationDuJoueur(Player joueur, int i, int n) {
    int k = 0;
    if (i == 1) {
        std::cout << " quel compte souhaitez vous utiliser ?" << std::endl;
        std::string fichier = "../player";
        std::string extension = ".txt";
        std::string j;
        std::cin >> j;
        std::string nomFichier = fichier + j + extension;

        joueur.createCollection(nomFichier);//recréation de la collection du joueur depuis la sauvegarde
        joueur.afficher();

        std::cout
                << "avant que  la partie commence vous avez la possibilte d'agrandir votre collection en achetant des cartes. 1/oui   2/non?"
                << std::endl;
        std::cin >> k;
        acheterUnPack(joueur, k);
        joueur.afficher();
        joueur.saveCollection(nomFichier);

    } else {

        std::string fichier = "../player";
        std::string extension = ".txt";
        std::string numero;
        numero = fonctionNum(n);
        std::string nomFichier = fichier + numero + extension;
        std::cout << "Joueur  qu'elle est votre nom de guerre ?" <<
                  std::endl;
        joueur.setPseudo();

        std::cout << "Une collection de depart vous est attribue" <<
                  std::endl;
        joueur.createCollection("../MaPremiereCollection.txt");
        joueur.afficher();
        joueur.saveCollection(nomFichier);

        n += 1;
        ecritureDoc("../file_save_player", n);

        std::cout
                << "avant que  la partie commence vous avez la possibilte d'agrandir votre collection en achetant des cartes. 1/oui   2/non?"
                << std::endl;
        std::cin >> k;
        acheterUnPack(joueur, k);
        joueur.afficher();
        joueur.saveCollection(nomFichier);

    }
}


int main() {
  /*  ///initialisation des données nécessaire à ALLEGRO
    int mousePosX = 0;
    int mousePosY = 0;
    int isEnd = 0;
    int screenW = 0, screenH = 0;
    int w, h = 0; // dimension bitmap*/
    /*******************************************************************************************
      *                               déclaration ALLEGRO                                        *
       ******************************************************************************************/
/*
    ALLEGRO_DISPLAY *display = NULL;

    ALLEGRO_BITMAP  *nomBitmaps = NULL;

    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT  event = {0};

    ALLEGRO_TIMER  *timer = NULL;

    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_MOUSE_CURSOR *cursor;

    ALLEGRO_COLOR blanc;


    assert(al_init());
    assert(al_install_mouse());
    assert(al_install_keyboard());
    assert(al_init_image_addon());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    //création
    // timer
    // texte
    //couleur Blanc et noir
    blanc = al_map_rgb(255, 255, 255);

    screenW = al_get_display_width(display);
    screenH = al_get_display_height(display);
    //chargement des images

    //registre evenements
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));*/
    /*******************************************************************************************
      *                              fin déclaration ALLEGRO                                    *
       ******************************************************************************************/
    /*******************************************************************************************
      *                             chargement des images nécesaire au jeu                      *
       ******************************************************************************************/



    Player joueur1;
    Player joueur2;

/*
    ALLEGRO_DISPLAY *display;
    assert(al_init());
    display = al_create_display(1280, 752);
    assert(display);


    joueur1.setPseudo();

    creerMaPremiereCollection(joueur1);
    joueur1.createCollection("MaPremiereCollection.txt");

    joueur1.afficher();

    joueur1.addCardToMyCollection();
    joueur1.afficher();

    joueur1.saveCollection("Joueur1.txt");


    creationDesCartesSpeciales();
    creationDesCartesCreatures();
    */


    int i, n = 0;

    std::cout << "Bienvenue dans CountryMon, preparez vous a vivre des combats intenses!!!!" << std::endl;

    n = lectureDoc("../file_save_player");// on lit le fichier avec le nombre de joueur sauvegardé

    std::cout << "il y a : " << n << " joueur sauvegarde" << std::endl;
    std::cout << " Joueur 1 voulez-vous utiliser un compte existant? 1/oui   2/non?" << std::endl;
    std::cin >> i;
    if (i == 1) {
        if (n != 0) {
            initialisationDuJoueur(joueur1, i, n);
        } else {
            std::cout << "Il n'y a pas encore de compte, vous devez en creer un." << std::endl;
            initialisationDuJoueur(joueur1, 2, n);
        }
    } else {
        initialisationDuJoueur(joueur1, i, n);
    }


    n = lectureDoc("../file_save_player");
    std::cout << "il y a : " << n << " joueur sauvegarde" << std::endl;

    std::cout << " Joueur 2 voulez-vous utiliser un compte existant? 1/oui   2/non?" << std::endl;
    std::cin >> i;
    initialisationDuJoueur(joueur2, i, n);
















///ne pas oublier les delete
///destruction des bitmaps


    return 0;
}