#include "imports.h"

int main() {
	timer fileGen;
	string input = whichFile(); // Tikrina ar yra kursiokai.txt failas
	fileGen.stop();
	const int n = InLen(input);
	try {
		timer fileRead;
		stud *x = new stud[n];
		Input(n, x, input);
		fileRead.stop();
		timer calc;
		AssignGrades(n, x);
		calc.stop();
		timer pick;
		std::vector<stud> good, bad;
		int g, b;
		Pick(x, n, good, bad, g, b);
		pick.stop();
		timer out;
        Output2file(g, good, "Patenkinami.txt");
		Output2file(b, bad,  "Nepatenkinami.txt");
		out.stop();
		cout<<"Generavimas: "<<fileGen.duration()<<"s.\nSkaitymas: "<<fileRead.duration()<<"s.\nSkaiciavimas: "<<calc.duration()<<"s.\nAtrinkimas: "<<pick.duration()<<"s.\nRasymas:"<<out.duration()<<"s.\n";
		//Output(g, good);
		//Output(b, bad);
	} catch(std::exception& e) {
		cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
	}
	return 0;
}
