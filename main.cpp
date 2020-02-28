#include "imports.h"

int main() {
	string input = whichFile(); // Tikrina ar yra kursiokai.txt failas
	try {
		vector<stud> x;
		Input(x, input);
		std::sort(x.begin(), x.end(), cmpr);
		Output(x);
		Output2file(x);
	} catch(std::exception& e) {
		cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
	}
	return 0;
}