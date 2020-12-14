cmake_minimum_required(VERSION 3.17)
project(HA_GIP C)

set(CMAKE_C_STANDARD 99)

add_executable(HA_GIP_03_temperatur temperatur.c)
add_executable(HA_GIP_03_fragebogen fragebogen.c)
add_executable(HA_GIP_03_quader quader.c)
add_executable(HA_GIP_04_strassenbahn strassenbahn.c)
add_executable(HA_GIP_04_bool bool.c)
add_executable(HA_GIP_04_bool2 bool2.c)
add_executable(HA_GIP_05_froehliche_zahlen froehliche_zahlen.c)

add_executable(shutdown shutdown.c)