#include "imports.h"

float Final(float avg, float m) {
	return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

float Average(stud x) {
    double avg = std::accumulate(x.nd.begin(), x.nd.end(), 0.0)/x.nd.size();
    return Final(avg/x.nd.size(), x.exam);
}

float Median(stud x) {
    int i = x.nd.size()/2;
    sort(x.nd.begin(), x.nd.end());
    if(x.nd.size()%2 == 0) {
        float t = (x.nd[i]+x.nd[i+1])/2.0;
        return(Final(t, x.exam));
    }
    else return(Final(x.nd[i], x.exam));
}

bool cmpr(stud a, stud b) {
    if (a.name != b.name)
        return a.name < b.name;
    return a.lname < b.lname;
}