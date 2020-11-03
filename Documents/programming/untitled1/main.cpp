#include <iostream>

using namespace std;


void multTable(int x, int y) {
    for (int i = 0; i < x; i++) {
        cout << "#" << endl;
        for (int j = 0; j < y; j++) {
            cout << "*";
        }
    }
}

int main()
{
    int x;
    int y;
    cin >> x;
    cin >> y;
    multTable(x, y);
}


