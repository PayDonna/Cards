#include <iostream>

using namespace std;

int main()
{
    double x;
    double y;

    cin >> x;
    cin >> y;

    double z;
    z = x * y;

    if (z > 100) {
        cout << "LORGE BOI" << endl;
    }

    else if (z < 50) {
       for (double n =0; n < z; n++) {
         cout << "smol lad" << endl;
       }
    }
    else {
             cout << "The value is: " << z << endl;
    }

    return 0;
}
