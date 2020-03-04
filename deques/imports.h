#include <fstream>
#include <iostream>
#include <deque>
#include <sstream>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>
#include <cmath>

using std::string;
using std::deque;
using std::cout;
using std::endl;
using std::setw;

struct stud {
	string name, lname;
	float medAvg, avg;
	int exam;
	std::deque<int> nd;
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
void Input(deque<stud>&, string);
float Final(float, float);
float Average(stud);
float Median(stud);
void AssignGrades(deque<stud>&);
void Pick(deque<stud>&, deque<stud>&, deque<stud>&);
void Output(deque<stud>);
void Output2file(deque<stud>, string);
bool compareByName(stud, stud);
string whichFile(int);
