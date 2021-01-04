cmake_minimum_required(VERSION 3.13)
project(HA_GIP C)

set(CMAKE_C_STANDARD 99)

add_executable(03_temperatur 3/temperatur.c)
add_executable(03_fragebogen 3/fragebogen.c)
add_executable(03_quader 3/quader.c)
add_executable(04_strassenbahn 4/strassenbahn.c)
add_executable(04_bool 4/bool.c)
add_executable(05_froehliche_zahlen 5/froehliche_zahlen.c)
add_executable(05_berechnung_pi 5/berechnung_pi.c)
add_executable(05_primfaktor 5/primfaktor.c)
add_executable(06_trainingsdaten 6/trainingsdaten.c)

add_executable(ilias_02_1 ilias/HA_ilias_02_1.c)
target_link_libraries(ilias_02_1 PRIVATE m)

add_executable(shutdown shutdown.c)