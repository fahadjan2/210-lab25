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
    milliseconds vreadduration, lreadduration, sreadduration; //Read durations
    milliseconds vsortduration, lsortduration;
    milliseconds vinsertduration, linsertduration, sinsertduration;
    milliseconds vdeleteduration, ldeleteduration, sdeleteduration;
    
    vduration = vectorracer(filename, vect);
    lduration = listracer(filename, list);
    sduration = setracer(filename, set);

    cout << "Time taken: " <<  << " milliseconds" << endl;
    return 0;
}

milliseconds vectorreader(const string &filename, vector<string> &vect) {
    ifstream file(filename);
 
    //Read
    auto start = high_resolution_clock::now();
    string value;
    while (file >> value) {
        vect.push_back(value);
    };
    auto end = high_resolution_clock::now();
    auto readduration = duration_cast<milliseconds>(end - start);

    return readduration;
}

milliseconds setreader(const string &filename, set<string> &set) {
    ifstream file(filename);
    
    //Read
    auto start = high_resolution_clock::now();
    string value;
    while (file >> value) {
        set.insert(value);
    };
    auto end = high_resolution_clock::now();
    auto readduration = duration_cast<milliseconds>(end - start);

    return readduration;
}

milliseconds listreader(const string &filename, list<string> &list) {
    //Read
    ifstream file(filename);
    auto start = high_resolution_clock::now();
    string value;
    while (file >> value) {
        list.push_back(value);
    };
    auto end = high_resolution_clock::now();
    auto readduration = duration_cast<milliseconds>(end - start);

    //Sort
    ifstream file(filename);
    auto start = high_resolution_clock::now();
    string value;
    while (file >> value) {
        list.sort();
    };
    auto end = high_resolution_clock::now();
    auto sortduration = duration_cast<milliseconds>(end - start);

    //Insert
    value = "TESTCODE";
    auto start = high_resolution_clock::now();
    int middle = list.end() - list.begin();
    list.insert(middle, value);
    auto end = high_resolution_clock::now();
    auto sortduration = duration_cast<milliseconds>(end - start);

    return readduration, sortduration;
}