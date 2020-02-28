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

void Output(vector<stud> x) {
	cout<< setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n";
    cout<<"------------------------------------------------------------\n";
    for(int i=0; i<x.size(); i++) {
	    cout<<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
	    cout<<std::setw(19)<<std::left<<Average(x[i])<<setw(16)<<std::left<<Median(x[i])<<endl;
	}
}

void Output2file(std::vector<stud> x) {
	std::ofstream fr("results.txt");
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n";
    fr <<"------------------------------------------------------------\n";
    for(int i=0; i<x.size(); i++) {
	    fr <<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
		fr <<std::setw(19)<<std::left<<Average(x[i])<<setw(16)<<std::left<<Median(x[i])<<endl;
	}
	fr.close();
}

string whichFile() {
	std::ifstream infile("kursiokai.txt");
	if (infile.good()) return("kursiokai.txt");
	else {
		CreateInput(25, 5); // Kiek mokiniu, kiek namu darbu
		return("Generated.txt");
	}
}