#include <iostream>
#include "Special.h"
#include "Player.h"
#include "Creature.h"
#include "Attack.h"
#include "Collection.h"
#include "Energy.h"

#include <fstream>

void creationDesCartesSpeciales(){
    Special sixAout45{"Six Aout 45", '1', "Vous lancez une bombe atomique sur la creature adverse : elle perd 2 HP. Malheureusement la deflagration est tres grande et fait perdre 1 HP a votre propre creature."};
    Special bond{"James Bond", "Vous envoyez un espion pour savoir quelle sera la prochaine carte"
                               " tirée par le joueur adverse."};
    Special cdm{"Coupe du monde", "Vous avez gagné la coupe du monde! Bravo!"
                                  "Le moral des troupes est au plus haut. La puissance de votre créature en jeu est augmentée de 1."};
    Special entente{"Triple Entente", "Vous vous alliez avec d'autres puissances. Vous pouvez deffausser cette carte"
                                      " et en piocher deux autre pour les jouer dans ce tour."};
    Special hopital{"Hopital", "Votre systeme de sante se remet de la crise sanitaire mais est plus performant que jamais."
                                    " Votre créature gagne 2 PV."};
    Special pandemie{"Pandemie", "La crise fait rage, vous perdez beaucoup de ressources pendant que votre population "
                                       "est en confinement. Vous et votre ennemi perdez une carte Energie mais VOUS choisissez de quel type il s'agira."};
    Special territoire{"Territoire", "Vous faites reculer l'ennemi dans son camp, enlevez lui une carte permanante "
                             "qui se trouve sur son plateau."};
}

void creationDesCartesCreatures(){
    Creature {"FRANCE",7,8,1};
    Creature {"USA",7,8,1};
    Creature {"RUSSIA",7,8,1};
    Creature {"CHINA",7,8,1};
    Creature {"NORTH KOREA",7,8,1};
    Creature {"DUTSCHLAND",7,8,1};
    Creature {"IRAN",7,8,1};
    Creature {"JAPAN",7,8,1};
}


int main() {
    creationDesCartesSpeciales();
    creationDesCartesCreatures();
    Player a;
    a.setPseudo();

    Collection c;
    c.addCard();
    c.display();
    return 0;
}