cmake_minimum_required(VERSION 3.14)
project(Novo_TPED2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Novo_TPED2 main.c headers/grafos.h grafos.c algoritmos_de_busca.c headers/algoritmos_de_busca.h headers/estruturas.h mini_controller.c headers/mini_controller.h headers/helper.h)