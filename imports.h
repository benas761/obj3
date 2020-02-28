#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>

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