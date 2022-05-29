# Skaičiuoklė #
Programa skaičiuoklė yra skirta apskaičiuoti pažymių vidurkį arba medianą.

# Veikimo principas #

Paleidus programą yra prašoma įvesti duomenis:

* Studento vardą bei pavardę;
* Namų darbų kiekį;
* Namų darbų bei egzamino rezultatus.

> Taip pat programa suteikia galimybę sugeneruoti atsitiktinius namų darbų bei egzamino rezultatus.
> Galutiniai duomenys lentelėje yra automatiškai išrūšiuojami pagal studentų vardus.

# Spartos analizė #

Spartos analizėje buvo lyginami skirtingi konteinerių tipai ir skirtingo dydžio failai.

Spartos analizei buvo panaudotas kompiuteris su šiomis specifikacijomis:

* Intel Core i7  2.60GHz
* 16GB RAM DDR4
* SATA 1TB HDD


### 1 Strategija ###
```
Ar norite atlikti programos veikimo (greicio) analize? (Y/N): Y

Pasirinkite testavimo strategija (1 / 2 / 3):
(1 - studentai yra skaidomi i du naujus konteinerius)
(2 - studentai yra skaidomi panaudojant tik viena nauja konteineri)
(3 - programos veikimo spartos palyginimas naudojant optimizuota ir paprasta vector konteineri (naudojantis 2 strategija))
1

Ar norite sugeneruoti studentu failus? (Y/N): Y

Ar norite apskaiciuoti mediana(1), vidurki(2)? 2
NAUDOJAMA 1 STRATEGIJA. 

--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.001s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.098s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.008s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.833s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.116s.
Bendras failo kursiokai100000.txt testavimo laikas: 9.731s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 1.267s.
Bendras failo kursiokai1000000.txt testavimo laikas: 117.697s.

-------------------------- Pradedamas testavimas naudojant deque: ------------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.092s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.005s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.936s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.062s.
Bendras failo kursiokai100000.txt testavimo laikas: 10.014s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.724s.
Bendras failo kursiokai1000000.txt testavimo laikas: 118.975s.

----------------------------- Pradedamas testavimas naudojant list: ---------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.077s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.009s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.768s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.08s.
Bendras failo kursiokai100000.txt testavimo laikas: 7.721s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.868s.
Bendras failo kursiokai1000000.txt testavimo laikas: 79.576s.
```

### 2 Strategija ###
```
Ar norite atlikti programos veikimo (greicio) analize? (Y/N): Y

Pasirinkite testavimo strategija (1 / 2 / 3):
(1 - studentai yra skaidomi i du naujus konteinerius)
(2 - studentai yra skaidomi panaudojant tik viena nauja konteineri)
(3 - programos veikimo spartos palyginimas naudojant optimizuota ir paprasta vector konteineri (naudojantis 2 strategija))
2

Ar norite sugeneruoti studentu failus? (Y/N): Y

Ar norite apskaiciuoti mediana(1), vidurki(2)? 2
NAUDOJAMA 2 STRATEGIJA. 

--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.091s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.01s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.86s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.131s.
Bendras failo kursiokai100000.txt testavimo laikas: 9.917s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 1.316s.
Bendras failo kursiokai1000000.txt testavimo laikas: 119.713s.

-------------------------- Pradedamas testavimas naudojant deque: ------------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.084s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.012s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.89s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.122s.
Bendras failo kursiokai100000.txt testavimo laikas: 10.24s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 1.233s.
Bendras failo kursiokai1000000.txt testavimo laikas: 114.293s.

----------------------------- Pradedamas testavimas naudojant list: ---------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.073s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.015s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.746s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.146s.
Bendras failo kursiokai100000.txt testavimo laikas: 7.166s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 1.432s.
Bendras failo kursiokai1000000.txt testavimo laikas: 73.69s.
```
### OPTIMIZUOTAS VECTOR ir paprastas (2strategija) ###
```
Ar norite atlikti programos veikimo (greicio) analize? (Y/N): Y

Pasirinkite testavimo strategija (1 / 2 / 3):
(1 - studentai yra skaidomi i du naujus konteinerius)
(2 - studentai yra skaidomi panaudojant tik viena nauja konteineri)
(3 - programos veikimo spartos palyginimas naudojant optimizuota ir paprasta vector konteineri (naudojantis 2 strategija))
3

Ar norite sugeneruoti studentu failus? (Y/N): Y

Ar norite apskaiciuoti mediana(1), vidurki(2)? 2
VYKDOMAS VECTOR VEIKIMO SPARTOS PALYGINIMAS. 
(Palyginimui naudojama antroji strategija)

--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.102s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.011s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.876s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.114s.
Bendras failo kursiokai100000.txt testavimo laikas: 9.778s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 1.14s.
Bendras failo kursiokai1000000.txt testavimo laikas: 110.58s.

--------------------------- Pradedamas testavimas naudojant optimizuota vector: -----------------------------------------------

Failas kursiokai1000.txt
Studentu rusiavimas i dvi grupes uztruko: 0s.
Bendras failo kursiokai1000.txt testavimo laikas: 0.09s.

Failas kursiokai10000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.007s.
Bendras failo kursiokai10000.txt testavimo laikas: 0.942s.

Failas kursiokai100000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.075s.
Bendras failo kursiokai100000.txt testavimo laikas: 10.232s.

Failas kursiokai1000000.txt
Studentu rusiavimas i dvi grupes uztruko: 0.722s.
Bendras failo kursiokai1000000.txt testavimo laikas: 110.576s.
```


# Programos įdiegimas ir naudojimasis #

* Atsisiųskite vieną programos versijų iš [Releases](https://github.com/LCious/Objektinis/releases) aplanko ir ją išarchyvuokite.
* Atsisiųskite jums patinkančią __C++__ palaikančią programą (_[Visual Studio](https://visualstudio.microsoft.com/downloads/), [CodeBlocks](https://www.codeblocks.org/downloads/)_).
* Atsidarykite pateiktą programos kodą ir jį paleiskite arba komandinėje eiltuėje įrašykite `g++ -o main *.cpp` ir paleiskite su `./main`


# Releases #

[v0.1](https://github.com/LCious/Objektinis/releases/tag/V0.1) : pirminė programos versija.

[v0.2](https://github.com/LCious/Objektinis/releases/tag/V0.2) : 
  * Pridėta galimybė nuskaityti duomenis iš failo.
  * Pridėta galimybė spausdinti vidurkį ir medianą kartu.
  * Studentai yra automatiškai išrūšiuojami pagal jų vardus.
 
[v0.3](https://github.com/LCious/Objektinis/releases/tag/V0.3) :
  * Sukurtas `functions.cpp` failas, kuriame yra sudėtos visos programoje naudojamos funkcijos.
  * Sukurtas `functions.hpp` header failas, kuriame yra saugoma studentų struct.
  * Sukurtas išimčių valdymas ([Exception Handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)).

[v0.4](https://github.com/LCious/Objektinis/releases/tag/v0.4) :
  * Sukurta funkcija leidžianti atlikti programos veikimo greičio (spartos) analizę.
  * Sukurta funkcija leidžianti sugeneruoti atsitiktinius studentų sarašų failus (1'000, 10'000, 100'000, 1'000'000, 10'000'000 įrašų).
  * Sukurtas studentų rūšiavimas į dvi grupes pagal pagal galutinį balą.
  * Sugrupuoti studentai yra atitinkamai išvedami į du skirtingus failus.

[v0.5](https://github.com/LCious/Objektinis/releases/tag/v0.5) :
  * Sukurta konteinerių testavimo funkcija, kuri leidžia išmatuoti programos veikimo spartą priklausomai nuo naudojamo vieno iš trijų konteinerių.

[v1.0](https://github.com/LCious/Objektinis/releases/tag/v1.0) :
  * Sukurta testavimo funkcija, leidžianti pasirinkti testavimo strategijos būdą.
  * Sukurta funkcija, leidžianti palyginti testavimo rezultatus tarp paprasto ir optimizuoto vektoriaus.
