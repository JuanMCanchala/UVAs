/*
Juan Manuel Canchala
8983809
Carlos Ramirez
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool cartaValida(string &number, string &simbolo) {
    bool ans = number[0] == simbolo[0] || number[1] == simbolo[1];
    return ans;
}

int main() {
    string carta;
    while (cin >> carta && carta != "#") {
        vector<stack<string> > pila(1);
        pila[0].push(carta);

        for (int i = 1; i < 52; ++i) {
            cin >> carta;
            stack<string> p;
            p.push(carta);
            pila.push_back(p);
        }

        bool flag = true;
        while (flag) {
            flag = false;
            for (int j = 1; j < pila.size(); ++j) {
                string cartaCard = pila[j].top();
                int cartaindi = -1;

                if (j >= 3 && cartaValida(cartaCard, pila[j - 3].top())) {
                    cartaindi = j - 3;
                } else if (j >= 1 && cartaValida(cartaCard, pila[j - 1].top())) {
                    cartaindi = j - 1;
                }

                if (cartaindi != -1) {
                    pila[cartaindi].push(cartaCard);
                    pila[j].pop();

                    if (pila[j].empty()) {
                        pila.erase(pila.begin() + j);
                    }

                    flag = true;
                    j = 0; 
                }
            }
        }

cout << pila.size() << " pile";
if (pila.size() != 1) {
    cout << "s";
}
cout << " remaining:";
for (int i = 0; i < pila.size(); ++i) {
    cout << " " << pila[i].size();
}
cout << endl;
    }

    return 0;
}
