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

stud& stud::operator = (const stud& st){
	name = st.name;
	lname = st.lname;
	nd = st.nd;
	avg = st.avg;
	medAvg = st.medAvg;
	exam = st.exam;
}
bool stud::operator == (stud& st){
	if(name==st.name && lname==st.lname) return true;
	else return false;
}
bool stud::operator != (stud st){
	if(name==st.name && lname==st.lname) return false;
	else return true;
}
bool stud::operator > (stud st){
	if(avg>st.avg) return true;
	else return false;
}
bool stud::operator < (stud st){
	if(avg<st.avg) return true;
	else return false;
}
bool stud::operator <= (stud st){
	if(avg<=st.avg) return true;
	else return false;
}
bool stud::operator >= (stud st){
	if(avg>=st.avg) return true;
	else return false;
}

std::ostream& stud::operator << (std::ostream& fr) {
	fr <<setw(18)<<std::left<<getName()<<setw(18)<<std::left<<getLname();
	fr <<std::setw(19)<<std::left<<getAvg()<<setw(16)<<std::left<<getMed()<<endl;
}
