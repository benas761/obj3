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
	float medAvg, avg;
	int exam;
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
void Input(vector<stud>&, string);
float Final(float, float);
float Average(stud);
float Median(stud);
void AssignGrades(vector<stud>&);
void Pick(vector<stud>&, vector<stud>&, vector<stud>&);
void Output(vector<stud>);
void Output2file(vector<stud>, string);
bool compareByName(stud, stud);
string whichFile(int);
