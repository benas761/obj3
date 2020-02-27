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

int InLen(string input = "generated.txt") {// Programai laiko kainuoja, bet man sutaupo, atsiprasau.
	int n = 0;
	string t;
	std::ifstream fd(input);
	while(getline(fd, t)) if(t != "") n++; // Suskaiciuoja kiek viso mokiniu bus
	n--; //Nereikia pirmos linijos.
	fd.close();
	return n;
}

void Input(int n, stud x[], string input = "generated.txt") {
	string str;
	std::ifstream fd(input);
	getline(fd, str); // Praleidzia pirma linija
	for(int i=0; i<n; i++) {
		fd >> x[i].name >> x[i].lname;
	    int in;
		getline(fd, str);
		for(int i=0; i<str.length(); i++) if(str[i]==',') str[i]='.';
        std::istringstream ss(str);
	    while(ss >> in) {
	        if(in <= 10 && in > 0) {
	            x[i].n++;
	            x[i].nd.push_back(in);
	        }
	        else throw std::runtime_error("\nDirbama tik su sveikais skaiciais tarp 1 ir 10. Patikrinkite ivesti.\n");
	    }
	    if(x[i].n>0) {
	    	x[i].exam = x[i].nd.back();
	    	x[i].nd.pop_back();
	    	x[i].n--;
            if(x[i].n==0) { x[i].nd.push_back(0); x[i].n++; }
		}
		else x[i].exam = 0;
	}
	fd.close();
}

void Output(int n, vector<stud> x) {
	cout << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(int i=0; i<n; i++) {
		cout <<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
		cout <<std::setw(19)<<std::left<<x[i].avg<<setw(16)<<std::left<<x[i].medAvg<<endl;
	}
}

void Output2file(int n, vector<stud> x, string out) {
	std::ofstream fr(out);
	fr << setw(18) << std::left << "Vardas" << setw(18) << std::left << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)\n" <<"------------------------------------------------------------\n";
	for(int i=0; i<n; i++) {
		fr <<setw(18)<<std::left<<x[i].name<<setw(18)<<std::left<<x[i].lname;
		fr <<std::setw(19)<<std::left<<x[i].avg<<setw(16)<<std::left<<x[i].medAvg<<endl;
	}
	fr.close();
}

bool cmpr(stud a, stud b) {
    if (a.name != b.name)
        return a.name < b.name;
    return a.lname < b.lname;
}

string whichFile(int n) {
	string inpf = "kursiokai.txt";
	std::ifstream infile(inpf);
	if (infile.good()) { infile.close(); return(inpf); }
	else {
		infile.close();
		CreateInput(n, 5); // Kiek mokiniu, kiek namu darbu
		return("generated.txt");
	}
}
