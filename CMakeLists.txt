cmake_minimum_required(VERSION 3.10)
project(ecemon-T)

set(CMAKE_CXX_STANDARD 14)

add_executable(ecemon-T main.cpp Card/Special.cpp Card/Special.h Card/Card.cpp Card/Card.h GameBoard.cpp GameBoard.h Card/Creature.cpp Card/Creature.h Player.cpp Player.h Attack.cpp Attack.h Show.cpp Show.h Game.h Game.cpp Collection.cpp Collection.h Card/Energy.h Card/Energy.cpp ALLEGRO/Init_ALLEGRO.cpp ALLEGRO/Init_ALLEGRO.h)
target_link_libraries(ecemon-T -lmingw32 -lallegro-5.0.10-monolith-md-debug)