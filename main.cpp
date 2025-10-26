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

void vectorreader(const string filename, vector<string> &vect);
void listreader(const string filename, list<string> &list);
void setreader(const string filename, set<string> &set);

int main() {
    ifstream file("codes.txt");
    vector<string> vect;
    list<string> list;
    set<string> set;

    auto start = high_resolution_clock::now();
    
    cout << "Test" << endl;
    string value;
    while (file >> value) {
        vect.push_back(value);
        list.push_back(value);
        set.insert(value);
    };

    auto end = high_resolution_clock::now();

 
    auto duration = duration_cast<milliseconds>(end - start);


    std::cout << "Time taken: " << duration.count() << " milliseconds\n";

    file.close();
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

void vectorreader(const string filename, vector<string> &vect) {

}

void setreader(const string filename, set<string> &set) {

}

void listreader(const string filename, list<string> &list) {

}