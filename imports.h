#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::setw;

struct stud {
	string name, lname;
	int n = 0;
	float exam, medAvg, avg;
	std::vector<int> nd;
};

class timer{
	std::chrono::high_resolution_clock::time_point start, end;
	std::chrono::duration<double> length;
public:
	timer() { start =  std::chrono::high_resolution_clock::now(); }
	void stop() { 
		end =  std::chrono::high_resolution_clock::now();
		length = std::chrono::duration_cast<std::chrono::duration<double>>(end-start);
	}
	double duration() { return length.count(); }
};

void CreateInput(int, int);
int InLen(string);
void Input(int, stud*, string);
float Final(float, float);
float Average(stud);
float Median(stud);
void AssignGrades(int, stud*);
void Pick(stud*, int, vector<stud>&, vector<stud>&, int&, int&);
void Output(int, vector<stud>);
void Output2file(int, vector<stud>, string);
bool compareByName(stud, stud);
string whichFile(int);
