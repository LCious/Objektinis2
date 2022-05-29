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


### Duomenų nuskaitymas ###

Container |   1000  |  10000  |  100000 | 1000000 | 10000000 |
----------|---------|---------|---------|---------|----------|
Vector    | 0.016s. | 0.152s. | 1.345s. | 13.513s.| 130.762s.|
Deque     | 0.020s. | 0.159s. | 1.465s. | 14.649s.| 142.873s.|
List      | 0.018s. | 0.153s. | 1.449s. | 15.304s.| 150.835s.|

### Duomenų grupavimas ###

Container |   1000  |  10000  |  100000 | 1000000 | 10000000 |
----------|---------|---------|---------|---------|----------|
Vector    | 0.010s. | 0.050s. | 0.372s. | 1.507s. | 14.449s. |
Deque     |    0s.  | 0.007s. | 0.077s. | 0.869s. |  8.765s. |
List      | 0.002s. | 0.007s. | 0.085s. | 0.989s. |  9.823s. |


# Programos įdiegimas ir naudojimasis #

* Atsisiųskite vieną programos versijų iš [Releases](https://github.com/LCious/Objektinis/releases) aplanko ir ją išarchyvuokite.
* Atsisiųskite jums patinkančią __C++__ palaikančią programą (_[Visual Studio](https://visualstudio.microsoft.com/downloads/), [CodeBlocks](https://www.codeblocks.org/downloads/)_).
* Atsidarykite pateiktą programos kodą ir jį paleiskite.


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
