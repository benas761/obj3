# obj2

v0.5 pakeitimai:
- Padarytos 2 papildomos programos:
  - Deque - tiesiog pakeistas vector į deque duomenų tipą
  - List - pakeistas vector į list. Indeksų paieška pakeista į next funkciją, kuri gali būti prastai optimizuota (tai paaiškintu laikus).
- Pridėti deque ir list programų laikai.
- Pridėtas pasirinkimas įvesti duomenis per duomenų eilutę.

v0.4 pakeitimai:
- Pridėta timer klasė, skaičiuojanti laiką.
- Pakeista failo generacija.
- Vidurkiai nebeskaičiuojami išvedime.
- Studentai išvedami dviejuose failuose: nepatenkinami.txt - kurių vidurkiai <5 ir patenkinami.txt - kurių vidurkiai >=5.

Laikas su vektoriais:

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso   |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:--------:|
| 1000     |  0.00627    | 0.00311   | 0.00093      | 0.00809    | 0.00459 | 0.01841  |
| 10000    |  0.03405    | 0.02457   | 0.00704      | 0.09799    | 0.03448 | 0.16365  |
| 100000   |  0.42496    | 0.31002   | 0.08916      | 1.56641    | 0.45567 | 2.39054  |
| 1000000  |  5.46784    | 2.84301   | 0.86178      | 19.29207   | 2.48252 | 28.46469 |
| 10000000 |  23.36243   | 24.03756  | 6.86270      | 202.00982  | 24.86446| 256.27250|

Laikas su deque:

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso   |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:--------:|
| 1000     |  0.00821    | 0.00230   | 0.00233      | 0.01944    | 0.00385 | 0.03229  |
| 10000    |  0.03340    | 0.01775   | 0.02124      | 0.25262    | 0.03731 | 0.32501  |
| 100000   |  0.32158    | 0.15894   | 0.19140      | 3.53672    | 0.37067 | 4.20864  |
| 1000000  |  3.36204    | 1.68653   | 2.02515      | 44.21737   | 3.78167 | 51.29108 |
| 10000000 | Out of memory |

Laikas su list:

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:-------:|
| 1000     |  0.00758    | 0.00198   | 0.01481      | 0.00518    | 0.01121 | 0.02954 |
| 10000    |  0.03897    | 0.01711   | 1.66128      | 0.84446    | 1.13534 | 2.56183 |
| 100000   |  0.32091    | 0.17872   | 713.51093    | 432.60932  | 517.713 | 1146.61 |
| 1000000  |             |           |              |            |         | viso ~142 val. |
| 10000000 |             |           |              |            |         | viso ∞ |
  
Generavimas - parinkto dydžio failo generavimas.
Skaitymas - sugeneruoto failo skaitymas.
Skaičiavimas - pažymių pagal vidurkį ir medianą skaičiavimas.
Atrinkimas - duomenų išrinkimas pagal paskutinį balą, skaičiuotą pagal vidurkį. Čia vyksta rikiavimas.
Rašymas - duomenų rašymas į 2 failus pagal atrinkimą.

Sistemos aprašymas:
- Intel(R) Core(TM) i5-8265U CPU @ 1.60GH
- 2 * 4GB DDR4 RAM
- SSD

v0.3 pakeitimai:
- Pridėtas antraštės failas.
- Funkcijos perkeltos į 2 .cpp failus. inOut.cpp - išvesčiai, gradeGen.cpp - vidurkiui ir medianai.

v0.2 pakeitimai:
- Dirba su mokinių sąrašu, kuriame gali būti skirtingas kiekvieno mokinio padarytų namų darbų kiekis.
- Išveda pagal vardą (jei vardai vienodi, pavardę) surūšiuotą mokinių galutinių balų sąrašą.
- Jei nėra kursiokai.txt failo sugeneruoja naują failą Generated.txt, su kuriuo toliau vykdo operacijas.

Programa raides, simbolius ir kitus netinkamus pazymiu formatus ignoruoja.
Pazymiuose kablelius pavercia i taskus, bet viska, kas eina po tasko ignoriuoja (dirba su int).
Perskaičius string formato įvestį ignoruoja viską, kas eina po jo toje eilutėje.

Skaitymui:
- Sukurti failą kursiokai.txt. Pirma eilutė ignoruojama, tad duomenis pradėti rašyti nuo antros eilutės.
- Failo eilutės struktūra:
  - Vardas ir pavardė, atskirti tarpu.
  - Namų darbų balai.
  - Paskurinis balas - egzamino.

Programa skaičiuoja galutinį balą pagal:
- Pagal vidurkį: 0.4 * [namų darbų balų vidurkis] + 0.6 * [egzamino balas].
- Pagal medianą: 0.4 * [namų darbų balų mediana] + 0.6 * [egzamino balas].

Programos pavyzdys:

![Programos pavyzdys](https://github.com/benas761/obj2/blob/master/v0.3%20ex)
