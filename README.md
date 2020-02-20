# obj2

v0.2 pakeitimai:
- Dirba su mokinių sąrašu, kuriame gali būti skirtingas kiekvieno mokinio padarytų namų darbų kiekis.
- Išveda pagal vardą (jei vardai vienodi, pavardę) surūšiuotą mokinių galutinių balų sąrašą.
- Jei nėra kursiokai.txt failo sugeneruoja naują failą Generated.txt, su kuriuo toliau vykdo operacijas.

Skaitymui:
- Įvesti vardą ir pavardę. Spausti enter.
- Įvesti visus pažymius __vienoje eilutėje__. Egzamino balas paskutinis.
- Ignoruojamos visos raidės ir skaičiai, nesantys intervale [1, 10].

Programa skaičiuoja galutinį balą pagal:
- Pagal vidurkį: 0.4 * [namų darbų balų vidurkis] + 0.6 * [egzamino balas].
- Pagal medianą: 0.4 * [namų darbų balų mediana] + 0.6 * [egzamino balas].

Programos pavyzdys:

![Programos pavyzdys](https://github.com/benas761/obj2/blob/v0.1/cmd.png)

Neskaito 25 ir s (GCC kompileris raides paverčia į 0).
