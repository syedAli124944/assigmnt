#include <iostream>


using namespace std;

void printKMap(int kmap[4][4]) {
    cout << "Karnaugh Map:" << endl;
    cout << "        CD" << endl;
    cout << "       00 01 11 10" << endl;
    cout << "AB" << endl;
    
    for (int i = 0; i < 4; ++i) {
        if (i == 0) cout << "00   ";
        else if (i == 1) cout << "01   ";
        else if (i == 2) cout << "11   ";
        else if (i == 3) cout << "10   ";
        for (int j = 0; j < 4; ++j) {
            cout << setw(2) << kmap[i][j] << " ";
        }
        cout << endl;
    }
}

string mintermToEquation(int minterm) {
    string equation;
    if (minterm & 8) equation += "A"; else equation += "A'";
    if (minterm & 4) equation += "B"; else equation += "B'";
    if (minterm & 2) equation += "C"; else equation += "C'";
    if (minterm & 1) equation += "D"; else equation += "D'";
    return equation;
}

void printEquation(int kmap[4][4]) {
    bool first = true;
    cout << "F = ";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (kmap[i][j] == 1) {
                int minterm = (i & 2) << 2 | (i & 1) << 2 | (j & 2) >> 1 | (j & 1);
                if (!first) cout << " + ";
                cout << mintermToEquation(minterm);
                first = false;
            }
        }
    }
    cout << endl;
}

int main() {
    int kmap[4][4] = {0}; // Initialize all to 0

    int numMinterms;
    cout << "Enter the number of minterms: ";
    cin >> numMinterms;

    cout << "Enter the minterms (0-15):" << endl;
    for (int i = 0; i < numMinterms; ++i) {
        int minterm;
        cin >> minterm;
        if (minterm >= 0 && minterm < 16) {
            int row = ((minterm & 8) >> 3) * 2 + ((minterm & 4) >> 2);
            int col = ((minterm & 2) >> 1) * 2 + (minterm & 1);
            kmap[row][col] = 1;
        } else {
            cout << "Invalid minterm: " << minterm << ". Please enter a value between 0 and 15." << endl;
            --i; 
        }
    }

    printKMap(kmap);
    printEquation(kmap);

    return 0;
}
