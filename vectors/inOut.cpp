#include "imports.h"

void CreateInput(int n, int m) { // pakeista i sablona
	std::random_device rd;
	std::mt19937 mt0(rd());
	std::uniform_int_distribution<int> grades(1, 10);
	std::ofstream fr("generated.txt"); // one change only pls
	fr << setw(33) << std::left << "Vardas" << setw(30) << std::left << "Pavarde";
	for(int j = 0; j < m; j++) fr << setw(3) << std::right << j+1 << "nd";
	fr << setw(5) << "egz." << endl;
	for(int i=1; i<=n; i++) {
		fr << "Vardas" << setw(27) << std::left << i;
		fr << "Pavarde" << setw(26) << std::left << i;
		for(int j = 0; j < m+1; j++) fr << setw(5) << grades(mt0);
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
	cout << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(int i=0; i<x.size(); i++) {
		cout <<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
		cout <<std::setw(19)<<std::left<<x[i].avg<<setw(16)<<std::left<<x[i].medAvg<<endl;
	}
}

void Output2file(vector<stud> x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(int i=0; i<x.size(); i++) {
		fr <<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
		fr <<std::setw(19)<<std::left<<x[i].avg<<setw(16)<<std::left<<x[i].medAvg<<endl;
	}
	fr.close();
}

bool compareByName(stud a, stud b) {
    if (a.name != b.name)
        return a.name < b.name;
    return a.lname < b.lname;
}

string whichFile(int n) {
	std::ifstream infile("kursiokai.txt");
	if (infile.good()) return("kursiokai.txt");
	else {
		infile.close();
		CreateInput(n, 5); // Kiek mokiniu, kiek namu darbu
		return("generated.txt");
	}
}