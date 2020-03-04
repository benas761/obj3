#include "imports.h"

int main() {
	cout << "10^";
	int t;
	std::cin >> t;
	timer fileGen;
	string input = whichFile(pow(10, t)); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
	fileGen.stop();
	try {
		timer fileRead;
		deque<stud> x;
		Input(x, input);
		fileRead.stop();
		timer calc;
		AssignGrades(x);
		calc.stop();
		timer pick;
		std::deque<stud> good, bad;
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