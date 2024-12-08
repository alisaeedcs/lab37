#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);
void menu();

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

    int choice = 0;

    while (choice != 6) {
        menu();
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int n = 0;
            for (auto &i : hash_table) {
                cout << "Index: " << i.first << endl;
                cout << "\tCodes" << endl;
                for (string &code : i.second) {
                    cout << "\t\t" << code << endl;
                }
                cout << endl;
                n++;
                if (n>=5) {
                    break;
                }
            }
        }
        if (choice == 2) {
            cout << "Enter the key: ";
            int key;
            cin >> key;
            cin.ignore();
            cout << endl;

            if (hash_table[key].size() > 0) {
                cout << "Key: " << key << endl;
                for (const string &code : hash_table[key]) {
                    cout << "\t" << code << endl;
                }
            }
            else {
                cout << "Key not found\n";
            }
            cout << endl;
        }
        if (choice == 6) {
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

void menu() {
    cout << "1. Output first 100 entries" << endl;
    cout << "2. Search for key" << endl;
    cout << "3. Add a key\n";
    cout << "4. Remove a key\n";
    cout << "5. Modify a key\n";
    cout << "6. Exit\n";
}
