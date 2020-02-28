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

void Input(vector<stud> &x, string input = "Generated.txt") {
	string str; stud temp;
	std::ifstream fd(input);
	getline(fd, str); // Praleidzia pirma linija
	while(getline(fd, str)) {
		x.push_back(temp);
		std::istringstream ss(str);
		ss >> x.back().name >> x.back().lname;
		int in;
	    while(ss >> in) if(in <= 10 || in > 0) x.back().nd.push_back(in);
	    if(x.back().nd.size() > 1) {
	    	x.back().exam = x.back().nd.back();
	    	x.back().nd.pop_back();
		}
		else if(x.back().nd.size() == 0) {
			x.back().exam = x.back().nd.back();
			x.back().nd.back() = 0;
		}
		else {
			x.back().exam = 0;
			x.back().nd.back() = 0;
		}

	}
	fd.close();
}

float Final(float avg, int m) {
	return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

float Average(stud x) {
    double avg = std::accumulate(x.nd.begin(), x.nd.end(), 0.0)/x.nd.size();
    return Final(avg/x.nd.size(), x.exam);
}

float Median(stud x) {
	sort(x.nd.begin(), x.nd.end());
    int i = x.nd.size()/2;
    if(x.nd.size()%2 == 0) {
        float t = (x.nd[i]+x.nd[i+1])/2.0;
        return(Final(t, x.exam));
    }
    else return(Final(x.nd[i], x.exam));
}

void Output(vector<stud> x) {
	cout<< setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n";
    cout<<"------------------------------------------------------------\n";
    for(int i=0; i<x.size(); i++) {
	    cout<<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
	    cout<<std::setw(19)<<std::left<<Average(x[i])<<setw(16)<<std::left<<Median(x[i])<<endl;
	}
}

bool cmpr(stud a, stud b) {
    if (a.name != b.name)
        return a.name < b.name;
    return a.lname < b.lname;
}

string whichFile() {
	std::ifstream infile("kursiokai.txt");
	if (infile.good()) return("kursiokai.txt");
	else {
		CreateInput(25, 5); // Kiek mokiniu, kiek namu darbu
		return("Generated.txt");
	}
}

int main() {
	string input = whichFile(); // Tikrina ar yra kursiokai.txt failas
	try {
		std::vector<stud> x;
		Input(x, input);
		std::sort(x.begin(), x.end(), cmpr);
		Output(x);
	} catch(std::exception& e) { cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl; }
	return 0;
}
