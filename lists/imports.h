#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>

using std::string;
using std::list;
using std::cout;
using std::endl;
using std::setw;

struct stud {
	string name, lname;
	float medAvg, avg;
	int exam;
	std::list<int> nd;
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
void FileInput(list<stud>&, string);
void CmdInput(list<stud> &x);
float Final(float, float);
float Average(stud);
float Median(stud);
void AssignGrades(list<stud>&);
void Pick(list<stud>&, list<stud>&, list<stud>&);
void Output(list<stud>&);
void Output2file(list<stud>&, string);
bool compareByName(stud, stud);
string whichFile(int);
void OutputTime(int, timer, timer, timer, timer, timer);
void OutputTime(timer, timer, timer);
