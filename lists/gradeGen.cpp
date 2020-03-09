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
    x.nd.sort();
    if(x.nd.size()%2 == 0) {
        float t = ((*next(x.nd.begin(), i))+(*next(x.nd.begin(), i)))/2.0;
        return(Final(t, x.exam));
    }
    else return(Final(*next(x.nd.begin(), i), x.exam));
}

void AssignGrades(list<stud> &x) {
    for(int i=0; i<x.size(); i++) {
        (*next(x.begin(), i)).avg = Average(*next(x.begin(), i));
        (*next(x.begin(), i)).medAvg = Median(*next(x.begin(), i));
    }
}

void Pick(list<stud> &x, list<stud> &good, list<stud> &bad) {
    for(int i=0; i<x.size(); i++) {
        if((*next(x.begin(), i)).avg >= 5) good.push_back(*next(x.begin(), i));
        else bad.push_back(*next(x.begin(), i));
    }
    x.clear();
}
