// COMSC-210 | Lab 25 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <chrono>
using namespace std;
using namespace std::chrono;

void vectorracer(const string filename, vector<string> &vect);
void listracer(const string filename, list<string> &list);
void setracer(const string filename, set<string> &set);

int main() {
    string filename = "codes.txt";
    vector<string> vect;
    list<string> list;
    set<string> set;
    
    cout << "Test111" << endl;
    int vduration, lduration, sduration;
    vduration = vectorracer(filename, vect);
    lduration = listracer(filename, list);
    sduration = setracer(filename, set);

    cout << "Time taken: " <<  << " milliseconds" << endl;
    return 0;
}

void vectorreader(const string &filename, vector<string> &vect) {
    ifstream file(filename);
    
    auto start = high_resolution_clock::now();

    string value;
    while (file >> value) {
        vect.push_back(value);
    };

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count();
}

void setreader(const string &filename, set<string> &set) {
    ifstream file(filename);
    
    auto start = high_resolution_clock::now();
    
    string value;
    while (file >> value) {
        set.insert(value);
    };

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count();
}

void listreader(const string &filename, list<string> &list) {
    ifstream file(filename);
    
    auto start = high_resolution_clock::now();
    
    string value;
    while (file >> value) {
        list.push_back(value);
    };

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count();
}