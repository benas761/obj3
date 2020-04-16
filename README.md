# obj3

v1.1 pakeitimai:
- Pakeista stud struktūra į klasę:
  - Sukurtas konstruktorius, nuskaitantis duomenis iš nusiųsto eilutės.
  - Vidurkio ir medianos funkcijos perkeltos į klasę ir dabar yra kviečiamos kostruktiuje.
- Pataisytos rinkimo (pick) funkcijos, kurios netinkamai rinko dėl netinkamos rūšiavimo funkcijos.
- Klasės vektoriaus laikai:

|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:----------:|:----------:|:--------|:-------:|
| 1000     |  0.00704    | 0.00272   | 0.00028    | 0.00220    | 0.00388 | 0.01004 |
| 10000    |  0.03035    | 0.02615   | 0.00255    | 0.02957    | 0.03423 | 0.05905 |
| 100000   |  0.32745    | 0.26163   | 0.02792    | 0.39831    | 0.34491 | 0.61699 |
| 1000000  |  3.71315    | 2.61334   | 0.26712    | 4.39285    | 4.22985 | 6.59361 |
| 10000000 |  41.32082   | 30.82113  | 3.06894    | 58.76650   | 47.80699| 75.21089|

- Vektoriaus optimizuoti laikai:
  - Pirmas optimizavimo lygis:

|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:----------:|:----------:|:--------|:-------:|
| 100000   |  0.36413    | 0.27442   | 0.03243    | 0.38728    | 0.50709 | 0.67098 |
| 1000000  |  5.28314    | 3.14204   | 0.31854    | 5.29234    | 5.44367 | 8.74372 |

  - Antras optimizavimo lygis:

|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:----------:|:----------:|:--------|:-------:|
| 100000   |  0.32697    | 0.23792   | 0.02704    | 0.31102    | 0.35412 | 0.59193 |
| 1000000  |  3.73011    | 2.56725   | 0.27212    | 4.68611    | 4.69143 | 6.56948 |

  - Trečias optimizavimo lygis:
  
|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:----------:|:----------:|:--------|:-------:|
| 100000   |  0.32807    | 0.24075   | 0.02700    | 0.30276    | 0.33292 | 0.59582 |
| 1000000  |  3.60244    | 2.57579   | 0.28109    | 4.86327    | 3.91890 | 6.45932 |

v1.0 pakeitimai:
- Pakeistos atrinkimo funkcijos:
  - Vietoje atrinkimo į 2 atskirus sąrašus dabar programa surūšiuoją sąrašą pagal vidurkį ir perkelia sąrašo pradžioje esančius mažesnius už 5 vidurkius į nepantenkinamų sąrašą.
  - Pridėtas dar vienas efektyvesnis atrinkimo būdas su vector tipu, naudjantis copy ir clear algoritmus.
- Atskirtas rūšiavimo laikas nuo atrinkimo laiko.
- Pridėti naujų atrinkimų laikai.

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

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:----------:|:-------:|:-------:|
| 1000     |  0.00236    | 0.00226   | 0.00072      | 0.00450    | 0.00527    | 0.00906 | 0.00984 |
| 10000    |  0.02038    | 0.02291   | 0.00763      | 0.06298    | 0.07227    | 0.02243 | 0.11390 |
| 100000   |  0.19542    | 0.21819   | 0.07610      | 0.82271    | 0.92603    | 0.25089 | 1.31241 |
| 1000000  |  2.28983    | 2.37047   | 0.87683      | 11.10279   | 12.85570   | 2.92107 | 16.63991|
| 10000000 |  27.22786   | 25.17174  | 8.91526      | 134.75796  | 146.92051  | 32.41613| 196.07282|

Laikas su vektoriais (optimizuotas+):

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:----------:|:-------:|:-------:|
| 1000     |  0.00535    | 0.00243   | 0.00073      | 0.00057    | 0.00557    | 0.06471 | 0.00907 |
| 10000    |  0.02053    | 0.02391   | 0.00765      | 0.00617    | 0.09420    | 0.02280 | 0.05826 |
| 100000   |  0.23369    | 0.21850   | 0.07628      | 0.05870    | 1.41245    | 0.24720 | 0.58716 |
| 1000000  |  2.64691    | 2.63435   | 0.86629      | 0.65392    | 19.06731   | 3.35368 | 6.80147 |
| 10000000 |  28.87411   | 24.92173  | 8.67349      | 7.04530    | 223.95305  | 33.81763| 69.51463|

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

Laikas su list (optimizuotas):

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso  |
|:--------:|:-----------:|:---------:|:------------:|:----------:|:--------|:-------:|
| 1000     |  0.11070    | 0.00218   | 0.00071      | 0.00632    | 0.06402 | 0.11991 |
| 10000    |  0.01940    | 0.02436   | 0.00837      | 0.09602    | 0.02163 | 0.14816 |
| 100000   |  0.22372    | 0.21413   | 0.07739      | 1.18563    | 0.25932 | 1.70088 |
| 1000000  |  2.42055    | 2.10598   | 0.76077      | 14.88204   | 2.58978 | 20.16934|
| 10000000 |  24.20797   | 20.60044  | 7.56890      | 176.03907  | 25.05437| 228.41637|
  
Generavimas - parinkto dydžio failo generavimas.
Skaitymas - sugeneruoto failo skaitymas.
Skaičiavimas - pažymių pagal vidurkį ir medianą skaičiavimas.
Atrinkimas - duomenų išrinkimas pagal paskutinį balą, skaičiuotą pagal vidurkį. Čia vyksta rikiavimas.
Rašymas - duomenų rašymas į 2 failus pagal atrinkimą.

Paleidimo instrukcija:
- Ant linux sistemos:
  - Komandinėje eilutėje atsidaryti aplanką, kuriame yra visi .cpp ir .h failai.
  - Parašyti: 'make' norint sukurti programą.
  - Parašyti 'make opt1' arba 'make obj2' arba 'make obj3' norint sukurti programą su optimizavimo lygiu.
  - Parašyti './main' norint paleisti programą.
  - Parašyti 'make clean' norint ištrinti visus .o ir .txt failus.
- Ant windows sistemos:
  - Parsisiųsti codeblocks ir kompiliatorių.
  - Atsidaryti .cbp failą.
  - Paspausti *build and run* mygtuką.

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
