# Skaičiuoklė #
Programa skaičiuoklė yra skirta apskaičiuoti pažymių vidurkį arba medianą.

# Veikimo principas #

Paleidus programą yra prašoma įvesti duomenis:

* Studento vardą bei pavardę;
* Namų darbų kiekį;
* Namų darbų bei egzamino rezultatus.

> Taip pat programa suteikia galimybę sugeneruoti atsitiktinius namų darbų bei egzamino rezultatus.
> Galutiniai duomenys lentelėje yra automatiškai išrūšiuojami pagal studentų vardus.

# Programos veikimo pavyzdys #
```
File detected.

Ka norite daryti? Skaityti duomenis is failo ar duomenis ivesti? (y - file / n - manual): n
Iveskite varda: Marius

Iveskite pavarde: Mantvydas

Ar zinote namu darbu kieki? (Y/N): Y

Iveskite namu darbu kieki:3

Ar norite, kad pazymiai butu generuojami automatiskai? (Y/N): n

Iveskite atliktu namu darbu pazymius:
10 4 8

Iveskite egzamino pazymi: 9

Ar norite prideti studenta? (Y/N) y
Iveskite varda: Laurynas

Iveskite pavarde: Laurynauskas

Ar zinote namu darbu kieki? (Y/N): n

Sugeneruotas atliktu namu darbu kiekis:24

Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): y

Sugeneruoti pazymiai:4 8 1 2 9 8 4 3 4 7 7 5 9 6 7 7 8 8 2 1 6 6 2 4
Egzamino rezultatas:1
Ar norite prideti studenta? (Y/N) n

Ka noretumete apskaiciuoti mediana(1), vidurki(2), ar abu(3)? 3





Vardas         Pavarde        Galutinis (vid.)  Galutinis (med.)
----------------------------------------------------------------
Laurynas       Laurynauskas   2.73              3.00
Marius         Mantvydas      8.33              7.00
```

### Programos veikimas įvedant duomenis iš failo: ###
```
File detected.

Ka norite daryti? Skaityti duomenis is failo ar duomenis ivesti? (y - file / n - manual): y

Ka noretumete apskaiciuoti mediana(1), vidurki(2), ar abu(3)? 3





Vardas         Pavarde        Galutinis (vid.)  Galutinis (med.)
----------------------------------------------------------------
Adomas         Avomaitis      7.33              7.20
Agne           Agnaityte      9.52              9.60
Arnas          Arnaitis       6.21              6.00
Birute         Birutyte       7.76              7.60
Deimantas      Deimantukas    6.60              6.60
Lukas          Lukaitis       4.23              4.20
Mantas         Mantaitis      4.92              4.60
Monika         Monikaityte    4.72              4.80
Toma           Tomaityte      7.27              7.00
```
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
