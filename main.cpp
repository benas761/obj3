#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

float Final(float avg, int m) {
    return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

void Input(int &n, int &m, std::string &name, std::string &lname, auto &N) { // Grieztas
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
    m = N.back();
    N.pop_back();
    fd.close();
}

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
    std::cout<<std::setw(18)<<std::left<<Average(N, m)<<std::setw(16)<<std::left<<Median(N, m)<<std::endl;
}

int main()
{
    std::string name, lname;
    int n, m;
    std::vector<int> N; // Truksta skaitymo su masyvu
    Input(n, m, name, lname, N);
    Output(n, m, name, lname, N);
    return 0;
}
