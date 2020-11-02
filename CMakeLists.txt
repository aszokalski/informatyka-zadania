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
add_executable(klasy Tablice_Petle/klasy.cpp)

add_executable(podslowo Znaki_Teksty/podslowo.cpp)
add_executable(statystyki Znaki_Teksty/statystyki.cpp)
add_executable(zliczacz Znaki_Teksty/zliczacz.cpp)
add_executable(dzielniki2 Znaki_Teksty/dzielniki2.cpp)

add_executable(ulamki NWD_Sito_Sumy/ulamki.cpp)
add_executable(dyzio NWD_Sito_Sumy/Dyzio.cpp)
add_executable(sumy NWD_Sito_Sumy/sumy.cpp)

add_executable(bombelkowe Sortowanie/bombelkowe.cpp)
add_executable(rekurencyjne Sortowanie/sortowanie_rekurencyjne.cpp)

add_executable(inwersje Inne/inwersje.cpp)

add_executable(dodawanie DuzeLiczby/dodawanie.cpp)
add_executable(jas DuzeLiczby/jas.cpp)
add_executable(jas_plag DuzeLiczby/jas_plag.cpp)

add_executable(hurtownia test/hurtownia.cpp)
add_executable(podslowo2 test/podslowo2.cpp)
add_executable(naszyjnik test/naszyjnik.cpp)
add_executable(nwps test/najdluzsze_wspolne_podslowo.cpp)

add_executable(medal Sortowanie_sort/medal.cpp)
add_executable(bizuteria Sortowanie_sort/bizuteria.cpp)
add_executable(telefony Sortowanie_sort/telefony.cpp)
add_executable(unikaty Sortowanie_sort/unikaty.cpp)

add_executable(kapusty Gasienica/kapusty.cpp)
add_executable(tarasy Gasienica/tarasy.cpp)
add_executable(bierki Gasienica/bierki.cpp)

add_executable(imiona ezkonkurs/imiona.cpp)
add_executable(lazik ezkonkurs/laziki.cpp)

add_executable(worek Wyszukiwanie_Binarne/worek.cpp)
add_executable(wieza Wyszukiwanie_Binarne/wieza.cpp)
add_executable(wycinek Wyszukiwanie_Binarne/wycinek.cpp)
add_executable(krazki Wyszukiwanie_Binarne/krazki.cpp)
add_executable(kalendarze Wyszukiwanie_Binarne/kalendarze.cpp)

add_executable(waz Dynamiki/waz.cpp)
add_executable(bankomat Dynamiki/skapy.cpp)
add_executable(reszta Dynamiki/reszta.cpp)
add_executable(banknoty Dynamiki/banknoty.cpp)

add_executable(onp Struktury_danych/onp.cpp)
add_executable(talerze Struktury_danych/tal.cpp)
add_executable(ctrl-z Struktury_danych/ctrl-z.cpp)

add_executable(stos Struktury_danych_2/stos.cpp)
add_executable(kolejka Struktury_danych_2/kolejka.cpp)
add_executable(lista Struktury_danych_2/lista.cpp)
add_executable(trwaly Struktury_danych_2/trwaly.cpp)

add_executable(pary matura/2020/pary.cpp)

add_executable(czekolada zadania/czekolada.cpp)
add_executable(przedzialy zadania/przedziały.cpp)

add_executable(srednia Biblioteczka/srednia.cpp)
add_executable(mediana Biblioteczka/mediana.cpp)
add_executable(minmax Biblioteczka/minmax.cpp)
add_executable(parzyste Biblioteczka/parzyste.cpp)
add_executable(podslowo1 Biblioteczka/podslowo.cpp)
add_executable(32 Biblioteczka/32.cpp)
add_executable(rozne Biblioteczka/rozne.cpp)

add_executable(rycerze Zachłanne/rycerze.cpp)
add_executable(tri Zachłanne/trikontenerowiec.cpp)

add_executable(plecak Dynamiki_2/plecak.cpp)
add_executable(cukiernia Dynamiki_2/cukiernia.cpp)

add_executable(bisekcja Matematyczne/bisekcja.cpp)
add_executable(pi Matematyczne/montecarlo.cpp)
add_executable(figura Matematyczne/figura.cpp)
add_executable(zaslona Matematyczne/zaslona.cpp)

add_executable(podciag_kwad Dynamiki_2/najdluzszy_rosnacy_podciag_kwadratowe.cpp)
add_executable(podciag_nlogn Dynamiki_2/najdluzszy_rosnacy_podciag_nlogn.cpp)

add_executable(podciag_wspolny Dynamiki_2/najdluzszy_wspolny_podciag.cpp)