#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

float Final(float avg, int m) {
    return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

void Input(int &n, int &m, std::string &name, std::string &lname, auto &N) {
	std::cout << "Vardas ir pavarde:\n";
	std:: cin >> name >> lname;
	std::cout << "Namu darbu balai ir egzamino balas (paskutinis):\n";
	int temp;
	std::string tstr;
	getline(std::cin, tstr);
	getline(std::cin, tstr);
	std::istringstream ss(tstr);
    while(ss >> temp) if(temp <= 10 || temp >=0) N.push_back(temp);
	if(N.size()>0) {
        m = N.back();
        N.pop_back();
	}
	else m = 0;
}

/*void InputFromFile(int &n, int &m, std::string &name, std::string &lname, auto &N) { // Grieztas
    std::ifstream fd("input.txt");
    fd >> name;
    fd >> lname;
    std::string str;
    while(getline(fd, str)) { // Tikrina iki naujos eilutes (jeigu reikes daugiau mokiniu prideti)
        std::istringstream ss(str);
        int temp;
        while(ss >> temp)
            N.push_back(temp);
    }
	if(N.size()>0) {
        m = N.back();
        N.pop_back();
	}
	else m = 0;
    fd.close();
}*/

float Average(auto N, int m) {
    double avg=0;
    int n=N.size();
    for(int i=0; i<n; i++) {
        avg += N[i];
    }
    return Final(avg/n, m);
}

float Median(auto N, int m) {
    int i = N.size()/2 - 1;
    if(N.size()%2 == 0) {
        float x = (N[i]+N[i+1])/2.0;
        return(Final(x, m));
    }
    else return(Final(N[i], m));
}

void Output(int &n, int m, std::string name, std::string lname, auto N) {
	std::cout<<"Pavarde     Vardas      Galutinis (Vid.) / Galutinis (Med.)\n";
    std::cout<<"------------------------------------------------------------\n";
    std::cout<<std::setw(12)<<std::left<<name<<std::setw(12)<<std::left<<lname;
	if(N.size() == 0)
    	 std::cout<<std::setw(18)<<std::left<<Final(0, m)<<std::endl;
	else std::cout<<std::setw(18)<<std::left<<Average(N, m)<<std::setw(16)<<std::left<<Median(N, m)<<std::endl;
}

int main()
{
    std::string name, lname;
    int n, m;
    std::vector<int> N;
    Input(n, m, name, lname, N);
    Output(n, m, name, lname, N);
    return 0;
}
