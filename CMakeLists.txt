cmake_minimum_required(VERSION 2.8.9)
project(Arbol-Binario)

include_directories(include)

set(SOURCES src/NodoA.cpp src/Arbol.cpp src/main.cpp)

add_executable(Arbol-Binario ${SOURCES})
