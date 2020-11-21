cmake_minimum_required(VERSION 3.10)
project(ecemon-T)

set(CMAKE_CXX_STANDARD 14)

add_executable(ecemon-T main.cpp Special.cpp Special.h Card.cpp Card.h SpeBombeAt.cpp SpeBombeAt.h GameBoard.cpp GameBoard.h Creature.cpp Creature.h Player.cpp Player.h SpeEspion.cpp SpeEspion.h SpeBoost.cpp SpeBoost.h SpeAllies.cpp SpeAllies.h SpeHopital.cpp SpeHopital.h SpePandemie.cpp SpePandemie.h Energy_politique.cpp Energy_politique.h Energy_Scientifique.cpp Energy_Scientifique.h Energy.cpp Energy.h Energy_Militaire.cpp Energy_Militaire.h Energy_Ressource.cpp Energy_Ressource.h)
target_link_libraries(ecemon-T -lmingw32 -lallegro-5.0.10-monolith-md-debug)