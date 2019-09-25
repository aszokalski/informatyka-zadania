cmake_minimum_required(VERSION 3.9)
project(zadanka_na_informatyke)

set(CMAKE_CXX_STANDARD 11)

add_executable(flaga Inne/flaga.cpp)

add_executable(data IF/data.cpp)

add_executable(mecz IF/mecz.cpp)

add_executable(przestepnosc IF/przestepnosc.cpp)

add_executable(papryczki Tablice_Petle/papryczki.cpp)

add_executable(roznica Tablice_Petle/roznica.cpp)

add_executable(kasztany Tablice_Petle/kasztany.cpp)

add_executable(suma Tablice_Petle/suma.cpp)

add_executable(odwrot Tablice_Petle/odwrot.cpp)

add_executable(hipoteza Tablice_Petle/hipoteza.cpp)

add_executable(latarnie Tablice_Petle/latarnie.cpp)

add_executable(skoczek Tablice_Petle/skoczek.cpp)