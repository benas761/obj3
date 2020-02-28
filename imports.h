#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>
//#include "functionDec.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::setw;

struct stud {
	string name, lname;
	int exam;
	std::vector<int> nd;
};

void CreateInput(int, int);
int InLen(string);
void Input(int, stud*, string);
float Final(float, float);
float Average(stud);
float Median(stud);
void Output(int, stud*);
void Output2file(int, stud*);
bool cmpr(stud, stud);
string whichFile();