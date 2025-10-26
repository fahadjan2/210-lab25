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
    milliseconds vsortduration, lsortduration, ssortduration;
    milliseconds vinsertduration, linsertduration, sinsertduration;
    milliseconds vdeleteduration, ldeleteduration, sdeleteduration;

    vreadduration, vsortduration, vinsertduration, vdeleteduration = vectorracer(filename, vect);
    lreadduration, lsortduration, linsertduration, ldeleteduration = listracer(filename, list);
    sreadduration, ssortduration, sinsertduration, sdeleteduration = setracer(filename, set);

    cout << "Time taken: " <<  << " milliseconds" << endl;
    return 0;
}

milliseconds vectorreader(const string &filename, vector<string> &vect) {
    //Read
    ifstream file(filename);
    auto start = high_resolution_clock::now();
    string value;
    while (file >> value) {
        vect.push_back(value);
    };
    auto end = high_resolution_clock::now();
    auto readduration = duration_cast<milliseconds>(end - start);

    //Sort
    ifstream file(filename);
    auto start = high_resolution_clock::now();
    string value;
    while (file >> value) {
        vect.sort();
    };
    auto end = high_resolution_clock::now();
    auto sortduration = duration_cast<milliseconds>(end - start);

    //Insert
    value = "TESTCODE";
    auto start = high_resolution_clock::now();
    auto it = vect.begin();
    advance(it, vect.size() / 2);
    vect.insert(it, value);
    auto end = high_resolution_clock::now();
    auto insertduration = duration_cast<milliseconds>(end - start);

    //Delete
    auto start = high_resolution_clock::now();
    vect.erase(it);
    auto end = high_resolution_clock::now();
    auto deleteduration = duration_cast<milliseconds>(end - start);

    return readduration, sortduration, insertduration, deleteduration;
}

milliseconds setreader(const string &filename, set<string> &set) {
    //Read
     ifstream file(filename);
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
    auto it = list.begin();
    advance(it, list.size() / 2);
    list.insert(it, value);
    auto end = high_resolution_clock::now();
    auto insertduration = duration_cast<milliseconds>(end - start);

    //Delete
    auto start = high_resolution_clock::now();
    list.erase(it);
    auto end = high_resolution_clock::now();
    auto deleteduration = duration_cast<milliseconds>(end - start);

    return readduration, sortduration, insertduration, deleteduration;
}