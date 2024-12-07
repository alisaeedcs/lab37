#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

int main() {
    map<int, list<string>> hash_table;

    ifstream fin("data.txt");

    string inp;
    int total = 0;

    while (getline(fin, inp)) {
        int index = gen_hash_index(inp);
        hash_table[index].push_back(inp);
    }
    fin.close();

    int n = 0;
    for (auto &i : hash_table) {
        cout << "Index: " << i.first << endl;
        cout << "\tCodes" << endl;
        for (string &code : i.second) {
            cout << "\t\t" << code << endl;
        }
        cout << endl;
        n++;
        if (n>=100) {
            break;
        }
    }

    return 0;
}

int gen_hash_index(string str) {
    int total = 0;
    for (int i = 0; i < str.length(); i++) {
        total += (int) str[i];
    }
    return total;
}
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
