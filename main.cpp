#include <iostream>
using namespace std;

int sum_ascii(string);

int main() {
    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';
    cout << (int) a << endl;
    cout << (int) b << endl;
    cout << (int) c << endl;
    cout << (int) d << endl;

    cout << (int) a + (int) b + (int) c + (int) d << endl;
    cout << sum_ascii("abcd");
    

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
