#include "imports.h"

void CreateInput(int n, int m) {
	int num = 32;
	std::random_device rd;
	std::mt19937 mt0(rd());
	std::mt19937 mt1(rd());
	std::uniform_int_distribution<int> names(0, num-1);
	std::uniform_int_distribution<int> grades(1, 10);
	string name[] = {
		"Lisa", "Tom", "Steve", "Karen", "Jimmy", "Tim", "Frank", "Charlie", "Charlotte", "Abus", "Gus",
		"Vincent", "Douglas", "Kim", "Jim", "Henry", "Lenny", "Homer", "Kate", "Stacy", "Mary", "Jenny",
		"Susy", "Quin", "George", "Gin", "Asira", "Amy", "Abigail", "Thomas"
	};
	string lname[] =  {
		"Jobs", "Williams", "Smith", "Johnson", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore",
		"Taylor", "Anderson", "Thoas", "Jackson", "White", "Black", "Pink", "Harris", "Martin", "Thompson",
		"Garcia", "Martinez", "Robinson", "Clark", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young",
		"King", "Kernel"
	};
	std::ofstream fr("Generated.txt");
	fr << setw(33) << std::left << "Vardas" << setw(30) << std::left << "Pavarde";
	for(int j = 0; j < m; j++) fr << setw(3) << std::right << j+1 << "nd";
	fr << setw(5) << "egz." << endl;
	for(int i=0; i<n; i++) {
		fr << setw(33) << std::left <<  name[names(mt0)];
		fr << setw(33) << std::left << lname[names(mt0)];
		for(int j = 0; j < m+1; j++) fr << setw(5) << grades(mt1);
		fr << endl;
	}
	fr.close();
}

int InLen(string input = "Generated.txt") {// Programai laiko kainuoja, bet man sutaupo, atsiprasau.
	int n = 0;
	string t;
	std::ifstream fd(input);
	while(getline(fd, t)) if(t != "") n++; // Suskaiciuoja kiek viso mokiniu bus
	n--; //Nereikia pirmos linijos.
	fd.close();
	return n;
}

void Input(int n, stud x[], string input = "Generated.txt") {
	string str;
	std::ifstream fd(input);
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

float Final(float avg, int m) {
	return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

float Average(stud x) {
    double avg=0;
    for(int i=0; i<x.n; i++) {
        avg += x.nd[i];
    }
    return Final(avg/x.n, x.exam);
}

float Median(stud x) {
    int i = x.n/2 - 1;
    if(x.n%2 == 0) {
        float t = (x.nd[i]+x.nd[i+1])/2.0;
        return(Final(t, x.exam));
    }
    else return(Final(x.nd[i], x.exam));
}

void Output(int n, stud x[]) {
	cout<< setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n";
    cout<<"------------------------------------------------------------\n";
    for(int i=0; i<n; i++) {
	    cout<<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
		if(n == 0)
	    	 cout<<std::setw(19)<<std::left<<Final(0, x[i].exam)<<endl;
		else cout<<std::setw(19)<<std::left<<Average(x[i])<<setw(16)<<std::left<<Median(x[i])<<endl;
	}
}

bool cmpr(stud a, stud b) {
    if (a.name != b.name)
        return a.name < b.name;
    return a.lname < b.lname;
}

bool youAreHere() {
    std::ifstream infile("kursiokai.txt");
    return infile.good();
}

string whichFile() {
	if (youAreHere()) return("kursiokai.txt");
	else {
		CreateInput(25, 5); // Kiek mokiniu, kiek namu darbu
		return("Generated.txt");
	}
}

int main() {
	string input = whichFile(); // Tikrina ar yra kursiokai.txt failas
	const int n = InLen(input);
	if(n == -1) cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
	else {
		stud *x = new stud[n];
		Input(n, x, input);
		std::sort(x, x+n, cmpr);
		Output(n, x);
		delete[] x;
	}
	return 0;
}
