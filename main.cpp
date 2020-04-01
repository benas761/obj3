#include "imports.h"

int main() {
	cout << "Dirbti su komandine eilute - 0, dirbti su failu - 1" << endl;
	bool choice;
	vector<stud> x;
	bool inChoice;
	std::cin >> inChoice;
	cout << "Su kokiu tipu dirbti?\n0 - Vector | 1 - Deque | 2 - List\n";
	int typeChoice;
	std::cin >> typeChoice;
	if(typeChoice == 0) vector<stud> x;
	if(typeChoice == 1) deque<stud> x;
	if(typeChoice == 2) list<stud> x;
	cout << "Kaip rinkti?\n0 - i 2 naujus konteinerius\n1 - i 1 nauja, istrinant perkeltus studentus sename\n";
	bool pickChoice;
	std::cin >> pickChoice;
	if(inChoice) {
		cout << "|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso  |\n";
		for(int i=1000; i<pow(10, 8); i*=10) {
			timer fileGen;
			string input = whichFile(i); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
			fileGen.stop();
			try {
				timer fileRead;
				FileInput(x, input);
				fileRead.stop();
				timer calc;
				AssignGrades(x);
				calc.stop();
				timer pick;
				std::vector<stud> bad;
				if(!pickChoice) std::vector<stud> good;
				std::sort(x.begin(), x.end(), compareByName);
				if(!pickChoice) PickBad(x, good, bad);
				else PickGood(x, good, bad);
				pick.stop();
				timer out;
		        if(!pickChoice) Output2file(good, "Patenkinami.txt");
		        else Output2file(x, "Patenkinami");
				Output2file(bad,  "Nepatenkinami.txt");
				out.stop();
				OutputTime(i, fileGen, fileRead, calc, pick, out);
				} catch(std::exception& e) {
				cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
				break;
			}
		}
	}
	else {
		CmdInput(x);
		AssignGrades(x);
		std::vector<stud> good, bad;
		std::sort(x.begin(), x.end(), compareByName);
        Output2file(x, "cmdOutput.txt");
        Output(x);
	}
	return 0;
}