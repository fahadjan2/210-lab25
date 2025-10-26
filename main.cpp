// COMSC-210 | Lab 25 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <chrono>
using namespace std;

int main() {
    ifstream file("codes.txt");
    vector<string> vect;
    list<string> list;
    set<string> set;
    
    cout << "Test" << endl;
    string value;
    while (file >> value) {
        vect.push_back(value);
        list.push_back(value);
        set.insert(value);

        cout << value << endl;
    };

    file.close();
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/