#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

int n = 0;

float Final(float avg, int m) {
    return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

float Average(int *arr, int m) {
    double avg=0;
    for(int i=0; i<n; i++) {
        avg += arr[i];
    }
    return Final(avg/n, m);
}

float Median(int *arr, int m) {
    int i = n/2 - 1;
    if(n%2 == 0) {
        float x = (arr[i]+arr[i+1])/2.0;
        return(Final(x, m));
    }
    else return(Final(arr[i], m));
}

void Output(int m, std::string name, std::string lname, int *arr) {
	std::cout<<"Pavarde     Vardas      Galutinis (Vid.) / Galutinis (Med.)\n";
    std::cout<<"------------------------------------------------------------\n";
    std::cout<<std::setw(12)<<std::left<<name<<std::setw(12)<<std::left<<lname;
	if(n == 0)
    	 std::cout<<std::setw(18)<<std::left<<Final(0, m)<<std::endl;
	else std::cout<<std::setw(18)<<std::left<<Average(arr, m)<<std::setw(16)<<std::left<<Median(arr, m)<<std::endl;
}

int main()
{
    std::string name, lname;
    int m;
    int *arr = new int[0];

    /// Nesugeba void funkcija nusiusti atgal pakitusios rodykles, tad viskas vyks main.
    std::cout << "Vardas ir pavarde:\n";
	std:: cin >> name >> lname;
	std::cout << "Namu darbu balai ir egzamino balas (paskutinis):\n";
    int in;
	std::string tstr;
	getline(std::cin, tstr); // Su cin.ignore ir cin.clear padejus tarpa neignoruojamas '\n'
	getline(std::cin, tstr);
	std::istringstream ss(tstr);
    while(ss >> in) {
        if(in <= 10 || in > 0) {
            n++;
            int *temp = arr;
            int *temp1 = arr;
            //delete[] arr;
            arr = new int[n];
            for(int i=0; i<n; i++) arr[i]=temp[i];
            arr[n-1] = in;
            delete[] temp; /// ar istrina visa masyva?
        }
    }
    if(n>0) {
        m = arr[n-1];
        //delete arr[n-1]; - nezinau kaip istringti paskutini elementa, tad tiesiog paaukoju tuos 4 baitus
        n--;
	}
	else m = 0;


    Output(m, name, lname, arr);
    return 0;
}
