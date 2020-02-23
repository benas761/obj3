#include "imports.h"

int main() {
	string input = whichFile(); // Tikrina ar yra kursiokai.txt failas
	const int n = InLen(input);
	try {
		stud *x = new stud[n];
		Input(n, x, input);
		std::sort(x, x+n, cmpr);
		Output(n, x);
		Output2file(n, x);
		delete[] x;
	} catch(std::exception& e) {
		cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
		// if(n == -1)
	}
	return 0;
}
