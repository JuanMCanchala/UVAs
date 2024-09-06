#include <iostream>
#include <vector>

using namespace std;
bool isSortedAscending(std::vector<int>& vec) {
    bool ans = true;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1] && ans == true) {
            ans = false;
        }

    }
    return ans;
}

bool isSortedDescending(std::vector<int>& vec) {
    bool ans = true;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] > vec[i - 1] && ans == true) {
            ans = false;
        }
    }
    return ans;
}

int main(){
    int numCasos;
    cin >> numCasos;
    cout<< "Lumberjacks:" << endl;
    while(numCasos--){
        vector<int> numeros;
        int primerNumero;
        for(int i = 0; i < 10; i++){
            int numero;
            cin >> numero;
            numeros.push_back(numero);
        }
    if (isSortedAscending(numeros)) {
        std::cout << "Ordered\n";
    } else if (isSortedDescending(numeros)) {
        std::cout << "Ordered\n";
    } else {
        std::cout << "Unordered\n";
    }



    }

    return 0;
}