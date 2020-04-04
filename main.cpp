#include "imports.h"


int main() {
	bool inChoice; int typeChoice;
	Ask(inChoice, typeChoice);
	if(inChoice) {
		if(typeChoice == 0) {
			vector<stud> good, bad;
			Run(good, bad);
		}
		else if(typeChoice == 1) {
			deque<stud> good, bad;
			Run(good, bad);
		}
		else {
			list<stud> good, bad;
			Run(good, bad);
		}
	}
	else {
		vector<stud> x;
		CmdInput(x);
		AssignGrades(x);
		std::vector<stud> good, bad;
		std::sort(x.begin(), x.end(), 
			[](stud &a, stud &b){ return a.name<b.name; });
        Output2file(x, "cmdOutput.txt");
        Output(x);
	}
	return 0;
}