cmake_minimum_required(VERSION 3.10)
project(ecemon-T)

set(CMAKE_CXX_STANDARD 14)

add_executable(ecemon-T main.cpp Special.cpp Special.h Card.cpp Card.h GameBoard.cpp GameBoard.h Creature.cpp Creature.h Player.cpp Player.h Attack.cpp Attack.h Show.cpp Show.h Game.h Game.cpp Collection.cpp Collection.h Energy.h Energy.cpp Init_ALLEGRO.cpp Init_ALLEGRO.h)
