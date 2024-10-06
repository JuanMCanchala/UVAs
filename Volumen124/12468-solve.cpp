#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b;

    while (cin >> a >> b && !(a == -1 && b == -1)) {
        int distancias = min((b - a + 100) % 100, (a - b + 100) % 100);
        cout << distancias << endl;
    }

    return 0;
}