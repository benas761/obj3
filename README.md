# obj2

v0.4 pakeitimai:
- Pridėta timer klasė, skaičiuojanti laiką.
- Pakeista failo generacija.
- Vidurkiai nebeskaičiuojami išvedime.
- Studentai išvedami dviejuose failuose: nepatenkinami.txt - kurių vidurkiai <5 ir patenkinami.txt - kurių vidurkiai >=5.

Laikai:

|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso   |
| 1000     |  0.00627    | 0.00311   | 0.00093      | 0.00809    | 0.00459 | 0.01841  |
| 10000    |  0.03405    | 0.02457   | 0.00704      | 0.09799    | 0.03448 | 0.16365  |
| 100000   |  0.42496    | 0.31002   | 0.08916      | 1.56641    | 0.45567 | 2.39054  |
| 1000000  |  5.46784    | 2.84301   | 0.86178      | 19.29207   | 2.48252 | 28.46469 |
| 10000000 |  23.36243   | 24.03756  | 6.86270      | 202.00982  | 24.86446| 256.27250|
  
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
