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

void AssignGrades(vector<stud> &x) {
    for(auto it = x.begin(); it!=x.end(); it++) {
        (*it).avg = Average(*it);
        (*it).medAvg = Median(*it);
    }
}

void AssignGrades(deque<stud> &x) {
    for(auto it = x.begin(); it!=x.end(); it++) {
        (*it).avg = Average(*it);
        (*it).medAvg = Median(*it);
    }
}

void AssignGrades(list<stud> &x) {
    for(auto it = x.begin(); it!=x.end(); it++) {
        (*it).avg = Average(*it);
        (*it).medAvg = Median(*it);
    }
}

void Pick(vector<stud> &x, vector<stud> &bad) {
    sort(x.begin(), x.end(),
        [](stud a, stud b){ return a.avg < b.avg; });

    while(x.back().avg<5) {
        bad.push_back(x.back());
        x.pop_back();
    }

    sort(x.begin(), x.end(), [](stud a, stud b){return a.name<b.name;});
    sort(bad.begin(), bad.end(), [](stud a, stud b){return a.name<b.name;});
}

void Pick(deque<stud> &x, deque<stud> &bad) {
    sort(x.begin(), x.end(),
        [](stud a, stud b){ return a.avg < b.avg; });

    while(x.back().avg<5) {
        bad.push_back(x.back());
        x.pop_back();
    }

    sort(x.begin(), x.end(), [](stud a, stud b){return a.name<b.name;});
    sort(bad.begin(), bad.end(), [](stud a, stud b){return a.name<b.name;});
}

void Pick(list<stud> &x, list<stud> &bad) {
    x.sort([](stud a, stud b){ return a.avg < b.avg; });
    for(auto it = x.begin(); it!=x.end(); it++) {
        if((*it).avg < 5) {
            bad.push_back(*it);
            x.erase(it);
        }
    }
    x.sort([](stud a, stud b){ return a.name<b.name; });
    bad.sort([](stud a, stud b){ return a.name<b.name; });
}

void Ask(bool &inChoice, int &typeChoice){
    cout << "Dirbti su komandine eilute - 0, dirbti su failu - 1" << endl;
    std::cin >> inChoice;
    if(inChoice) {
        cout << "Su kokiu tipu dirbti?\n0 - Vector | 1 - Deque | 2 - List\n";
        std::cin >> typeChoice;
    }
}

void Run(vector<stud>& good, vector<stud>& bad){
    cout << "|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
            fileGen.stop();
            try {
                timer fileRead;
                FileInput(good, input);
                fileRead.stop();

                timer calc;
                AssignGrades(good);
                calc.stop();

                timer pick;
                Pick(good, bad);
                pick.stop();

                timer out;
                Output2file(good, "Patenkinami.txt");
                Output2file(bad,  "Nepatenkinami.txt");
                out.stop();

                OutputTime(i, fileGen, fileRead, calc, pick, out);

                } catch(std::exception& e) {
                cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
                break;
            }
        }
}

void Run(deque<stud> &good, deque<stud> &bad){
    cout << "|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
            fileGen.stop();
            try {
                timer fileRead;
                FileInput(good, input);
                fileRead.stop();

                timer calc;
                AssignGrades(good);
                calc.stop();

                timer pick;
                Pick(good, bad);
                pick.stop();

                timer out;
                Output2file(good, "Patenkinami.txt");
                Output2file(bad,  "Nepatenkinami.txt");
                out.stop();

                OutputTime(i, fileGen, fileRead, calc, pick, out);

                } catch(std::exception& e) {
                cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
                break;
            }
        }
}

void Run(list<stud> &good, list<stud> &bad){
    cout << "|  Dydis   | Generavimas | Skaitymas | Skaiciavimas | Atrinkimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
            fileGen.stop();
            try {
                timer fileRead;
                FileInput(good, input);
                fileRead.stop();

                timer calc;
                AssignGrades(good);
                calc.stop();

                timer pick;
                Pick(good, bad);
                pick.stop();

                timer out;
                Output2file(good, "Patenkinami.txt");
                Output2file(bad,  "Nepatenkinami.txt");
                out.stop();

                OutputTime(i, fileGen, fileRead, calc, pick, out);

                } catch(std::exception& e) {
                cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
                break;
            }
        }
}
