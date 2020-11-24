cmake_minimum_required(VERSION 3.10)
project(ecemon-T)

set(CMAKE_CXX_STANDARD 14)

add_executable(ecemon-T main.cpp Special.cpp Special.h Card/Card.cpp Card/Card.h GameBoard.cpp GameBoard.h Creature.cpp Creature.h Player.cpp Player.h Attack.cpp Attack.h Show.cpp Show.h Game.h Game.cpp Collection.cpp Collection.h Energy.h Energy.cpp Init_ALLEGRO.cpp Init_ALLEGRO.h)
target_link_libraries(ecemon-T -lmingw32 -lallegro-5.0.10-monolith-md-debug)