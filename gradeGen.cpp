#include "imports.h"

float Final(float avg, float m) {
	return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

float Average(stud x) {
    double avg=0;
    cout << "hello!" << endl;
    try {
        for(int i=0; i<x.n; i++) {
            avg += x.nd[i];
        }
    } // Negaudo segmentation klaidu!
    catch(std::exception& e) {
        avg = 0;
        cout << "Netinkamai apskaiciuotas vidurkis!\n";
    }
    return Final(avg/x.n, x.exam);
}

float Median(stud x) {
    int i = x.n/2 - 1;
    sort(x.nd.begin(), x.nd.end());
    if(x.n%2 == 0) {
        float t = (x.nd[i]+x.nd[i+1])/2.0;
        return(Final(t, x.exam));
    }
    else return(Final(x.nd[i], x.exam));
}
