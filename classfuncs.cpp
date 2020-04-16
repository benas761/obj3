#include "imports.h"

stud::stud(string str) {
	std::istringstream ss(str);
	ss >> name >> lname;
	int in;
    while(ss >> in) if(in <= 10 || in > 0) nd.push_back(in);
    if(nd.size() > 1) {
  		exam = nd.back();
    	nd.pop_back();
	}
	else if(nd.size() == 0) {
		exam = nd.back();
		nd.back() = 0;
	}
	else {
		exam = 0;
		nd.back() = 0;
	}
	Average();
	Median();
}

void stud::Average() { 
	avg = std::accumulate(nd.begin(), nd.end(), 0.0)/nd.size(); 
}

void stud::Median() {
    int i = nd.size()/2;
    sort(nd.begin(), nd.end());
    if(nd.size()%2 == 0) {
        medAvg = Final((nd[i]+nd[i+1])/2.0, exam);
    }
    else medAvg = Final(nd[i], exam);
}