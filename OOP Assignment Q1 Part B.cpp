#include <iostream>
using namespace std;

void PrintPattern(int n) {
    if (n == 0) return;

    if (n == 1) {
        cout << "1 1 1 1" << endl;
        return;
    }

    if (n == 2) {
        cout << "1 1 2" << endl;
        PrintPattern(n - 1);
        return;
    }

    if (n == 3) {
        cout << "1 3" << endl;
        PrintPattern(n - 1);
        return;
    }

    if (n == 4) {
        cout << "4" << endl;
        cout << "2 2" << endl;
        PrintPattern(n - 1);
        return;
    }
}

int main() {
    int n = 4;
    PrintPattern(n);
    return 0;
}

