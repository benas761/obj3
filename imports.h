#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>

using std::string;
using std::vector;
using std::deque;
using std::list;
using std::cout;
using std::endl;
using std::setw;
using std::sort;

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

//inOut.cpp

void CreateInput(int, int);
void FileInput(vector<stud>&, string);
void FileInput(deque<stud>&, string);
void FileInput(list<stud>&, string);
void CmdInput(vector<stud>&);
void Output(vector<stud>&);
void Output(deque<stud>&);
void Output(list<stud>&);
void Output2file(vector<stud>&, string);
void Output2file(deque<stud>&, string);
void Output2file(list<stud>&, string);
void OutputTime(int, timer, timer, timer, timer, timer);
void OutputTime(timer, timer timer);
string whichFile(int);

//gradeGen.cpp

float Final(float, float);
float Average(stud);
float Median(stud);
void AssignGrades(vector<stud>&);
void AssignGrades(deque<stud>&);
void AssignGrades(list<stud>&);
void Pick(vector<stud>&, vector<stud>&);
void Pick(deque<stud>&, deque<stud>&);
void Pick(list<stud>&, list<stud>&);
void Ask(bool&, int&);
void Run(vector<stud>&, vector<stud>&);
void Run(deque<stud>&, deque<stud>&);
void Run(list<stud>&, list<stud>&);
