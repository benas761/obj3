#include "imports.h"

bool cmprName(stud &a, stud &b) { return a.getName() < b.getName(); }
//bool cmprAvg(stud &a, stud &b) { return a.getAvg() > b.getAvg(); }
bool cmprTo5(stud &a) { return a.getAvg()<5; }

float Final(float avg, float m) {
    return (round(100.0*(0.4*avg + 0.6*m))/100.0); // Rounds to 2 decimal points
}

void Pick(vector<stud>& x, vector<stud>& bad) {
    sort(x.rbegin(), x.rend());
    while(cmprTo5(x.back())) {
        bad.push_back(x.back());
        x.pop_back();
    }
}

void ImprovedPick(vector<stud>& x, vector<stud>& bad) {
    std::copy_if(x.begin(), x.end(), back_inserter(bad), cmprTo5);
    x.erase(
        remove_if(x.begin(), x.end(), cmprTo5),
        x.end());
}

void Pick(deque<stud>& x, deque<stud>& bad) {
    sort(x.rbegin(), x.rend());

    while(x.back().getAvg()<5) {
        bad.push_back(x.back());
        x.pop_back();
    }
}

void Pick(list<stud>& x, list<stud>& bad) {
    x.sort([](stud& a, stud& b) { return a.getAvg() > b.getAvg(); });
    cout << endl;
    while(cmprTo5(x.back())) {
        bad.push_back(x.back());
        x.pop_back();
    }
}

void Ask(bool& inChoice, int& typeChoice){
    cout << "Dirbti su komandine eilute - 0, dirbti su failu - 1" << endl;
    std::cin >> inChoice;
    if(inChoice) {
        cout << "Su kokiu tipu dirbti?\n0 - Vector | 1 - Deque | 2 - List\n";
        std::cin >> typeChoice;
    }
}

void Run(vector<stud>& good, vector<stud>& bad, bool pickChoice){
    string input = whichFile(0); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
    if(input != "kursiokai.txt") {
        cout << "|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i);
            fileGen.stop();

            timer fileRead;
            FileInput(good, input);
            fileRead.stop();

            timer pick;
            if(!pickChoice) Pick(good, bad);
            else   ImprovedPick(good, bad);
            pick.stop();

            timer sortName;
            sort(good.begin(), good.end(), cmprName);
            sort(bad.begin(), bad.end(), cmprName); 
            sortName.stop();

            timer out;
            Output2file(good, "Patenkinami.txt");
            Output2file(bad,  "Nepatenkinami.txt");
            out.stop();

            OutputTime(i, fileGen, fileRead, pick, sortName, out);
        }
    }
    else try {
        FileInput(good, input);
        if(!pickChoice) Pick(good, bad);
        else   ImprovedPick(good, bad);

        sort(good.begin(), good.end(), cmprName);
        sort(bad.begin(), bad.end(), cmprName); 
        
        Output2file(good, "Patenkinami.txt");
        Output2file(bad,  "Nepatenkinami.txt");
        
        cout << "Nepatenkinami:\n";
        Output(bad);
        cout << "Patenkinami:\n";
        Output(good);
        } catch(std::exception& e) {
        cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
    }
}

void Run(deque<stud>& good, deque<stud>& bad){
    string input = whichFile(0); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
    if(input != "kursiokai.txt") {
        cout << "|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i);
            fileGen.stop();

            timer fileRead;
            FileInput(good, input);
            fileRead.stop();

            timer pick;
            Pick(good, bad);
            pick.stop();

            timer sortName;
            sort(good.begin(), good.end(), cmprName);
            sort(bad.begin(), bad.end(), cmprName); 
            sortName.stop();

            timer out;
            Output2file(good, "Patenkinami.txt");
            Output2file(bad,  "Nepatenkinami.txt");
            out.stop();

            OutputTime(i, fileGen, fileRead, pick, sortName, out);
        }
    }
    else try {
        FileInput(good, input);
        Pick(good, bad);

        sort(good.begin(), good.end(), cmprName);
        sort(bad.begin(), bad.end(), cmprName);

        Output2file(good, "Patenkinami.txt");
        Output2file(bad,  "Nepatenkinami.txt");
        
        cout << "Nepatenkinami:\n";
        Output(bad);
        cout << "Patenkinami:\n";
        Output(good);
        } catch(std::exception& e) {
        cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
    }
}

void Run(list<stud>& good, list<stud>& bad){
    string input = whichFile(0); // Tikrina ar yra kursiokai.txt failas. Jeigu nera, kokio dydzio testo faila sukurti.
    if(input != "kursiokai.txt") {
        cout << "|  Dydis   | Generavimas | Skaitymas | Atrinkimas | Rikiavimas | Rasymas |   Viso  |\n";
        for(int i=1000; i<pow(10, 8); i*=10) {
            timer fileGen;
            string input = whichFile(i);
            fileGen.stop();

            timer fileRead;
            FileInput(good, input);
            fileRead.stop();

            timer pick;
            Pick(good, bad);
            pick.stop();

            timer sortName;
            good.sort(cmprName);
            bad.sort(cmprName); 
            sortName.stop();

            timer out;
            Output2file(good, "Patenkinami.txt");
            Output2file(bad,  "Nepatenkinami.txt");
            out.stop();

            OutputTime(i, fileGen, fileRead, pick, sortName, out);
        }
    }
    else try {
        FileInput(good, input);
        Pick(good, bad);

        good.sort(cmprName);
        bad.sort(cmprName); 
        
        Output2file(good, "Patenkinami.txt");
        Output2file(bad,  "Nepatenkinami.txt");
        
        cout << "Nepatenkinami:\n";
        Output(bad);
        cout << "Patenkinami:\n";
        Output(good);
        } catch(std::exception& e) {
        cout << "Papildykite kursiokai.txt faila arba ji istrinkite" << endl;
    }
}
