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

Laikas su vektoriais (optimizuotas):

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso   |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:--------:|
| 1000     |  0.00654    | 0.00257   | 0.00079      | 0.00659    | 0.07414 | 0.01649  |
| 10000    |  0.01943    | 0.02305   | 0.00704      | 0.09525    | 0.02259 | 0.14477  |
| 100000   |  0.19097    | 0.21308   | 0.07004      | 1.34645    | 0.22135 | 1.82055  |
| 1000000  |  2.12008    | 2.24186   | 0.70714      | 17.79551   | 2.62027 | 22.86459 |
| 10000000 |  22.47535   | 21.34342  | 7.06124      | 192.91809  | 28.64635| 243.79810|

Laikas su vektoriais (optimizuotas+):

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso   |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:--------:|
| 1000     |  0.00720    | 0.00280   | 0.00077      | 0.00985    | 0.00425 | 0.02061  |
| 10000    |  0.03967    | 0.02314   | 0.00785      | 0.13136    | 0.03339 | 0.20202  |
| 100000   |  0.33416    | 0.22042   | 0.07449      | 1.72162    | 0.40581 | 2.35070  |
| 1000000  |  3.60345    | 2.34546   | 0.79106      | 20.86110   | 3.52088 | 27.60106 |
| 10000000 |  45.72980   | 28.20733  | 9.42945      | 277.93448  | 28.25235| 361.30106|

Laikas su deque:

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso   |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:--------:|
| 1000     |  0.00821    | 0.00230   | 0.00233      | 0.01944    | 0.00385 | 0.03229  |
| 10000    |  0.03340    | 0.01775   | 0.02124      | 0.25262    | 0.03731 | 0.32501  |
| 100000   |  0.32158    | 0.15894   | 0.19140      | 3.53672    | 0.37067 | 4.20864  |
| 1000000  |  3.36204    | 1.68653   | 2.02515      | 44.21737   | 3.78167 | 51.29108 |
| 10000000 |             |           |              |            |         | Out of memory |

Laikas su deque (optimizuotas):

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso   |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:--------:|
| 1000     |  0.00663    | 0.00204   | 0.00068      | 0.01077    | 0.06709 | 0.02012  |
| 10000    |  0.02029    | 0.02187   | 0.00771      | 0.13232    | 0.02160 | 0.18218  |
| 100000   |  0.19153    | 0.20407   | 0.07619      | 1.72889    | 0.23905 | 2.20069  |
| 1000000  |  2.33628    | 2.02560   | 0.76279      | 22.32969   | 2.57279 | 27.45436 |
| 10000000 |  24.01862   | 20.43449  | 7.74453      | 267.89818  | 27.24499| 320.09583|

Laikas su list:

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:-------:|
| 1000     |  0.00758    | 0.00198   | 0.01481      | 0.00518    | 0.01121 | 0.02954 |
| 10000    |  0.03897    | 0.01711   | 1.66128      | 0.84446    | 1.13534 | 2.56183 |
| 100000   |  0.32091    | 0.17872   | 713.51093    | 432.60932  | 517.713 | 1146.61 |
| 1000000  |             |           |              |            |         | ~142 val. |
| 10000000 |             |           |              |            |         | ∞ |
  
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

Programa raides, simbolius ir kitus netinkamus pažymių formatus ignoruoja.
Pažymiuose kablelius pavercia į taskus, bet viską, kas eina po tasko ignoriuoja (dirba su int).
Perskaičius string formato pažymio įvestį ignoruoja viską, kas eina po jo toje eilutėje.

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

![Programos pavyzdys](https://github.com/benas761/obj2/blob/v0.4/v0.4%20ex)

Rezultatai rašomi į failus.
