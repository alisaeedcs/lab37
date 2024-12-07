#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string);

int main() {
    ifstream fin("data.txt");

    string inp;
    int total = 0;

    while (getline(fin, inp)) {
        total += sum_ascii(inp);
    }
    cout << total << endl;

    cout << "Correct? (Should output 0) " << total - 69893419 << endl;


    return 0;
}

int sum_ascii(string str) {
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
