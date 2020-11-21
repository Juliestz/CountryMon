cmake_minimum_required(VERSION 3.10)
project(ecemon-T)

set(CMAKE_CXX_STANDARD 14)

add_executable(ecemon-T main.cpp Special.cpp Special.h Card.cpp Card.h SpeBombeAt.cpp SpeBombeAt.h GameBoard.cpp GameBoard.h Creature.cpp Creature.h Player.cpp Player.h SpeEspion.cpp SpeEspion.h SpeBoost.cpp SpeBoost.h SpeAllies.cpp SpeAllies.h SpeHopital.cpp SpeHopital.h SpePandemie.cpp SpePandemie.h Attack.cpp Attack.h Show.cpp Show.h Game.h Game.cpp SpeTerritoire.cpp SpeTerritoire.h Collection.cpp Collection.h Energy.h Energy.cpp Init_ALLEGRO.cpp Init_ALLEGRO.h)
