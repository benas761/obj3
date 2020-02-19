#include "imports.h"

void CreateInput(int n, int m) {
	int num = 32;
	std::mt19937 mt0(4821);
	std::mt19937 mt1(5932);
	std::uniform_int_distribution<int> names(0, num-1);
	std::uniform_int_distribution<int> grades(1, 10);
	std::enum name {
		"Lisa", "Tom", "Steve", "Karen", "Jimmy", "Tim", "Frank", "Charlie", "Charlotte", "Abus", "Gus", 
		"Vincent", "Douglas", "Kim", "Jim", "Henry", "Lenny", "Homer", "Kate", "Stacy", "Mary", "Jenny",
		"Susy", "Quin", "George", "Gin", "Asira", "Amy", "Abigail", "Rhoshandiatellyneshiaunneveshenk"
	};
	std::enum lname {
		"Jobs", "Williams", "Smith", "Johnson", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore",
		"Taylor", "Anderson", "Thoas", "Jackson", "White", "Black", "Pink", "Harris", "Martin", "Thompson",
		"Garcia", "Martinez", "Robinson", "Clark", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young", 
		"King", "Kernel"
	};
	std::ofstream fr("Generated.txt");
	fr << setw(32) << std::left << "Vardas" << setw(32) << std::left << "Pavarde";
	for(int j = 0; j < m+1; j++) fr << setw(4) << "nd" << j;
	fr << setw(5) << "egz." << endl;
	for(int i=0; i<n; i++) {
		fr << setw(32) << std::left << name(names(mt0));
		fr << setw(32) << std::left << lname(names(mt0));
		for(int j = 0; j < m+1; j++) fr << setw(5) << grades(mt1);
	}
	fr.close();
}

int InLen() {// Programai laiko kainuoja, bet man sutaupo, atsiprasau.
	int n = 0;
	string t;
	std::ifstream fd("kursiokai.txt");
	while(getline(fd, t)) n++; // Suskaiciuoja kiek viso mokiniu bus
	n--; //Nereikia pirmos linijos.
	fd.close();
	return n;
}

void Input(int n, stud x[]) {
	string str;
	std::ifstream fd("kursiokai.txt");
	getline(fd, str); // Praleidzia pirma linija
	for(int i=0; i<n; i++) {
		fd >> x[i].name >> x[i].lname;
	    int in;
		getline(fd, str);
        std::istringstream ss(str);
	    while(ss >> in) {
	        if(in <= 10 || in > 0) {
	            x[i].n++;
	            x[i].nd.push_back(in);
	        }
	    }
	    if(n>0) {
	    	x[i].exam = x[i].nd.back();
	    	x[i].nd.pop_back();
		}
		else x[i].exam = 0;
	}
	fd.close();
}

void InOutput(int n, stud x[]) {
		for(int i=0; i<n; i++) {
		cout << setw(13) << std::left << x[i].name << setw(13) << std::left << x[i].lname << " ";
		for(int j=0; j<x[i].n; j++) cout << setw(5) << x[i].nd[j];
		cout << setw(5) << x[i].exam << endl;
	}
}

int main() {
	const int n = InLen();
	stud x[n];
	CreateInput(25, 5);
	Input(n, x);
	InOutput(n, x);
}