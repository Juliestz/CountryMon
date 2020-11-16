#include <iostream>
#include "Special.h"


void creationDesCartes(){
    Special test;
    test.setDescription("Ceci est un test");
    test.afficher();
}

int main() {
    creationDesCartes();

    return 0;
}