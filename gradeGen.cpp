#include "imports.h"

float Final(float avg, float m) {
    return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

float Average(stud x) {
    double avg = std::accumulate(x.nd.begin(), x.nd.end(), 0.0)/x.nd.size();
    return Final(avg, x.exam);
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

void AssignGrades(int n, stud x[]) { // merge w/ pick?
    for(int i=0; i<n; i++) {
        x[i].avg = Average(x[i]);
        x[i].medAvg = Median(x[i]);
    }
}

void Pick(stud *x, int n, vector<stud> &good, vector<stud> &bad, int &g, int &b) {
    g=0; b=0;
    for(int i=0; i<n; i++) {
        if(x[i].avg >= 5) { good.push_back(x[i]); g++; }
        else { bad.push_back(x[i]); b++; }
        //delete &x[i]; - SIGABRT
    }
    delete[] x;
}
