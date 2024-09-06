#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

bool sonMatrioshkas(vector<int>& secuencia) {
    stack<int> s;
    bool ans = true; 
    int n = secuencia.size();

    for (int i = 0; i < n; ++i) {
        if (secuencia[i] < 0) {
            s.push(secuencia[i]);
        } else {
            if (s.empty() || s.top() != -secuencia[i]) {
                ans = false;
            }
            s.pop();
        }
    }

    return s.empty() && ans;
}


int main() {
    string linea;
    while (getline(cin, linea)) {
        istringstream iss(linea);
        vector<int> secuencia;
        int num;
        while (iss >> num) {
            secuencia.push_back(num);
        }

        if (sonMatrioshkas(secuencia)) {
            cout << ":-) Matrioshka!" << endl;
        } else {
            cout << ":-( Try again." << endl;
        }
    }

    return 0;
}
