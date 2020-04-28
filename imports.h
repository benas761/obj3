#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
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

class stud {
	string name, lname;
	float medAvg, avg;
	int exam;
	vector<int> nd;
public:
	stud(string);
	void Average();
	void Median();
	float Final(float avg, float m);
	inline string getName() { return name; }
	inline string getLname() { return lname; }
	inline float getMed() { return medAvg; }
	inline float getAvg() { return avg; }
	stud& operator =  (const stud&);
	bool operator == (stud&); // Netikrina ar namu darbu balai lygus.
	bool operator != (stud);
	bool operator >  (stud);
	bool operator <  (stud);
	bool operator <= (stud);
	bool operator >= (stud);
	friend std::ostream& operator << (std::ostream&, stud&);
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
void Output2file(vector<stud>&, string);
void Output2file(deque<stud>&, string);
void Output2file(list<stud>&, string);
void OutputTime(int, timer, timer, timer, timer, timer);
void OutputTime(timer, timer, timer);
string whichFile(int);

//gradeGen.cpp

bool cmprName(stud&, stud&);
bool cmprAvg(stud&, stud&);
bool cmprTo5(stud&);
float Final(float, float);
void Pick(vector<stud>&, vector<stud>&);
void ImprovedPick(vector<stud>&, vector<stud>&);
void Pick(deque<stud>&, deque<stud>&);
void Pick(list<stud>&, list<stud>&);
void Ask(bool&, int&);
void Run(vector<stud>&, vector<stud>&, bool);
void Run(deque<stud>&, deque<stud>&);
void Run(list<stud>&, list<stud>&);
