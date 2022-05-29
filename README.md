# Skaičiuoklė #
Programa skaičiuoklė yra skirta apskaičiuoti pažymių vidurkį arba medianą.

# Veikimo principas #

Paleidus programą yra prašoma įvesti duomenis:

* Studento vardą bei pavardę;
* Namų darbų kiekį;
* Namų darbų bei egzamino rezultatus.

> Taip pat programa suteikia galimybę sugeneruoti atsitiktinius namų darbų bei egzamino rezultatus.
> Galutiniai duomenys lentelėje yra automatiškai išrūšiuojami pagal studentų vardus.

# Programos veikimo pavyzdžiai #

### Programos veikimo greičio (spartos) analizė: ###

```
Ar norite atlikti programos veikimo (greicio) analize? (Y/N): Y

Ar norite apskaiciuoti mediana(1), vidurki(2)? 1

Failas kursiokai1000.txt
Failo kurimas uztruko: 26ms.
Duomenu nuskaitymas is failo uztruko: 15ms.
Studentu rusiavimas i dvi grupes uztruko: 0ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 20ms.


Failas kursiokai10000.txt
Failo kurimas uztruko: 245ms.
Duomenu nuskaitymas is failo uztruko: 145ms.
Studentu rusiavimas i dvi grupes uztruko: 13ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 243ms.


Failas kursiokai100000.txt
Failo kurimas uztruko: 2249ms.
Duomenu nuskaitymas is failo uztruko: 1594ms.
Studentu rusiavimas i dvi grupes uztruko: 159ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 1797ms.


Failas kursiokai1000000.txt
Failo kurimas uztruko: 21002ms.
Duomenu nuskaitymas is failo uztruko: 16365ms.
Studentu rusiavimas i dvi grupes uztruko: 1345ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 18348ms.

```

### Programos veikimas neaptikus tekstinio failo ir duomenis įvedus rankiniu būdu: ###

```
Ar norite atlikti programos veikimo (greicio) analize? (Y/N): N
Failas nerastas. Duomenys privalo buti ivesti rankiniu budu.

Iveskite varda: Andrius

Iveskite pavarde: Andriutis

Ar zinot namu darbu kieki? (Y/N): n

Sugeneruotas atliktu namu darbu kiekis: 19

Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): y

Sugeneruoti pazymiai: 5 6 10 9 9 8 2 5 3 5 1 4 6 7 8 7 10 3 3
Egzamino rezultatas: 6
Ar norite prideti dar viena studenta? (Y/N) y
Iveskite varda: Povilas

Iveskite pavarde: Povilaitis

Ar zinot namu darbu kieki? (Y/N): n

Sugeneruotas atliktu namu darbu kiekis: 24

Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): y

Sugeneruoti pazymiai: 8 3 3 4 2 9 7 5 2 1 10 9 9 10 7 7 10 9 7 9 3 9 3 3
Egzamino rezultatas: 3
Ar norite prideti dar viena studenta? (Y/N) n

Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? 3





Vardas         Pavarde        Galutinis (vid.)  Galutinis (med.)
----------------------------------------------------------------
Andrius        Andriutis      5.94              5.60
Povilas        Povilaitis     4.28              4.60
```

### Programos veikimas įvedant duomenis iš failo: ###
```
Ar norite atlikti programos veikimo (greicio) analize? (Y/N): N
File detected.

Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): y
Duomenu nuskaitymas is failo uztruko: 0ms.

Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? 3





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

[v0.4](https://github.com/LCious/Objektinis/releases/tag/v0.4) :
  * Sukurta funkcija leidžianti atlikti programos veikimo greičio (spartos) analizę.
  * Sukurta funkcija leidžianti sugeneruoti atsitiktinius studentų sarašų failus (1'000, 10'000, 100'000, 1'000'000, 10'000'000 įrašų).
  * Sukurtas studentų rūšiavimas į dvi grupes pagal pagal galutinį balą.
  * Sugrupuoti studentai yra atitinkamai išvedami į du skirtingus failus.
