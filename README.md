# obj2

v0.4 pakeitimai:
- Pridėta timer klasė, skaičiuojanti laiką.
- Pakeista failo generacija.
- Vidurkiai nebeskaičiuojami išvedime.
- Studentai išvedami dviejuose failuose: nepatenkinami.txt - kurių vidurkiai <5 ir patenkinami.txt - kurių vidurkiai >=5.

Laikai:
- Su 1000:
  - Generavimas: 0.00385726s.
  - Skaitymas: 0.00199291s.
  - Skaiciavimas: 0.000627293s.
  - Atrinkimas: 0.000419402s.
  - Rasymas:0.00231845s.
- Su 10000:
  - Generavimas: 0.0211149s.
  - Skaitymas: 0.0199951s.
  - Skaiciavimas: 0.00607036s.
  - Atrinkimas: 0.00394418s.
  - Rasymas:0.0219306s.
- Su 100000:
  - Generavimas: 0.191304s.
  - Skaitymas: 0.190955s.
  - Skaiciavimas: 0.0603658s.
  - Atrinkimas: 0.0381968s.
  - Rasymas:0.225144s.
- Su 1000000:
  - Generavimas: 2.09837s.
  - Skaitymas: 1.90887s.
  - Skaiciavimas: 0.593764s.
  - Atrinkimas: 0.401827s.
  - Rasymas:2.2395s.
- Su 10000000:
  - Generavimas: 19.6896s.
  - Skaitymas: 19.5779s.
  - Skaiciavimas: 5.9756s.
  - Atrinkimas: 3.74884s.
  - Rasymas:23.6103s.
Generavimas - pasirinkto dydžio failo generavimo laikas, skaitymas - sugeneruoto failo skaitymo laikas, skaičiavimas - vidurkių skaičiavimas, atrinkimas - studentų atskyrimas pagal jų vidurkius, rašymas - rašymas į failą.


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
