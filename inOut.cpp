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

void FileInput(vector<stud> &x, string input) {
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

void FileInput(deque<stud> &x, string input) {
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

void FileInput(list<stud> &x, string input) {
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

void CmdInput(vector<stud> &x) {
	using std::cin;
	string str; stud temp;
    getline(cin, str);  // Ignoruoja pasilikusi \n (getline, nes ignore tarpus priskaiciuoja)
	cout << "Iveskite mokiniu vardus, pavardes ir pazymius (egzamino pazymys paskutinis, vienas mokinys - viena eilute)\nNorint baigti iveskite tuscia eilute.\n";
	while(getline(cin, str)) {
		if(str == "") break;
		x.push_back(temp);
		std::istringstream ss(str);
		ss >> x.back().name >> x.back().lname;
		int in;
	    while(ss >> in) if(in <= 10 || in > 0) x.back().nd.push_back(in);
	    if(x.back().nd.size() > 1) {
	    	x.back().exam = x.back().nd.back();
	    	x.back().nd.pop_back();
		}
		else if(x.back().nd.size() == 1) {
			x.back().exam = x.back().nd.back();
			x.back().nd.back() = 0;
		}
		else {
			x.back().exam = 0;
			x.back().nd.push_back(0);
		}
	}
}

void Output(vector<stud> &x) {
	cout << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud const& it : x) {
		cout <<setw(18)<<std::left<<it.name<<setw(18)<<std::left<<it.lname;
		cout <<std::setw(19)<<std::left<<it.avg<<setw(16)<<std::left<<it.medAvg<<endl;
	}
}

void Output(deque<stud> &x) {
	cout << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud const& it : x) {
		cout <<setw(18)<<std::left<<it.name<<setw(18)<<std::left<<it.lname;
		cout <<std::setw(19)<<std::left<<it.avg<<setw(16)<<std::left<<it.medAvg<<endl;
	}
}

void Output(list<stud> &x) {
	cout << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud const& it : x) {
		cout <<setw(18)<<std::left<<it.name<<setw(18)<<std::left<<it.lname;
		cout <<std::setw(19)<<std::left<<it.avg<<setw(16)<<std::left<<it.medAvg<<endl;
	}
}

void Output2file(vector<stud> &x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud const& it : x) {
		fr <<setw(18)<<std::left<<it.name<<setw(18)<<std::left<<it.lname;
		fr <<std::setw(19)<<std::left<<it.avg<<setw(16)<<std::left<<it.medAvg<<endl;
	}
	fr.close();
}

void Output2file(deque<stud> &x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud const& it : x) {
		fr <<setw(18)<<std::left<<it.name<<setw(18)<<std::left<<it.lname;
		fr <<std::setw(19)<<std::left<<it.avg<<setw(16)<<std::left<<it.medAvg<<endl;
	}
	fr.close();
}

void Output2file(list<stud> &x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(stud const& it : x) {
		fr <<setw(18)<<std::left<<it.name<<setw(18)<<std::left<<it.lname;
		fr <<std::setw(19)<<std::left<<it.avg<<setw(16)<<std::left<<it.medAvg<<endl;
	}
	fr.close();
}

void OutputTime(int i, timer fileGen, timer fileRead, timer calc, timer pick, timer out) {
	cout << std::setprecision(5) << std::fixed << "| " << setw(9) << std::left << std::fixed << i << "|  " << setw(11) << fileGen.duration() << "| " << setw(10) << fileRead.duration() << "| " << setw(13) << calc.duration() << "| ";
	cout << setw(11) << pick.duration() << "| " << setw(8) << out.duration() << "| " << setw(8) << fileGen.duration()+fileRead.duration()+calc.duration()+pick.duration() << "|\n";
}

void OutputTime(timer calc, timer pick, timer out) {
	cout << std::setprecision(5) << std::fixed << "| " << setw(13) << calc.duration() << "| ";
	cout << setw(11) << pick.duration() << "| " << setw(8) << out.duration() << "| " << setw(8) << calc.duration()+pick.duration() << "|\n";
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
