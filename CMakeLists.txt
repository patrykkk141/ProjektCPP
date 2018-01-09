cmake_minimum_required(VERSION 3.9)
project(Projekt_KalkulatorMacierzowy)

set(CMAKE_CXX_STANDARD 11)

add_executable(Projekt_KalkulatorMacierzowy main.cpp Macierz.h Macierz.cpp Interfejs.h Interfejs.cpp ONP.h ONP.cpp StosZnakow.h StosZnakow.cpp)