#include "imports.h"

int main() {
	timer fileGen;
	string input = whichFile(100000); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
	fileGen.stop();
	try {
		timer fileRead;
		vector<stud> x;
		Input(x, input);
		fileRead.stop();
		timer calc;
		AssignGrades(x);
		calc.stop();
		timer pick;
		std::vector<stud> good, bad;
		std::sort(x.begin(), x.end(), compareByName);
		Pick(x, good, bad);
		pick.stop();
		timer out;
        Output2file(good, "Patenkinami.txt");
		Output2file(bad,  "Nepatenkinami.txt");
		out.stop();
		cout<<"Generavimas: "<<fileGen.duration()<<"s.\nSkaitymas: "<<fileRead.duration()<<"s.\nSkaiciavimas: "<<calc.duration()<<"s.\nAtrinkimas: ";
		cout<<pick.duration()<<"s.\nRasymas:"<<out.duration()<<"s.\nViso: "<<fileGen.duration()+fileRead.duration()+calc.duration()+pick.duration()<<"s.\n";
	} catch(std::exception& e) {
		cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
	}
	return 0;
}