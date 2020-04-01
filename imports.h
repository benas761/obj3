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
float Final(float, float);
float Average(stud);
float Median(stud);
bool compareByName(stud, stud);
string whichFile(int);
void OutputTime(int, timer, timer, timer, timer, timer);
void OutputTime(timer, timer, timer);

void FileInput(vector<stud>&, string);
void CmdInput(vector<stud> &x);
void AssignGrades(vector<stud>&);
void PickBad(vector<stud>&, vector<stud>&, vector<stud>&);
void PickGood(vector<stud>&, vector<stud>&, vector<stud>&);
void Output(vector<stud>&);
void Output2file(vector<stud>&, string);

void FileInput(deque<stud>&, string);
void CmdInput(deque<stud> &x);
void AssignGrades(deque<stud>&);
void PickBad(deque<stud>&, deque<stud>&, deque<stud>&);
void PickGood(deque<stud>&, deque<stud>&, deque<stud>&);
void Output(deque<stud>&);
void Output2file(deque<stud>&, string);

void FileInput(list<stud>&, string);
void CmdInput(list<stud> &x);
void AssignGrades(list<stud>&);
void PickBad(list<stud>&, list<stud>&, list<stud>&);
void PickGood(list<stud>&, list<stud>&, list<stud>&);
void Output(list<stud>&);
void Output2file(list<stud>&, string);