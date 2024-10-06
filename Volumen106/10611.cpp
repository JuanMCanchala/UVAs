#include <vector>
#include <iostream>

using namespace std;

int upperBound(vector<int>& A, int x) {
    int lo = 0, hi = A.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] > x) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int lowerBound(vector<int>& A, int x) {
    int lo = 0, hi = A.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main(){
    int numHembras;
    cin >> numHembras;
    vector<int> hembras(numHembras);
    for(int i = 0; i < numHembras; i++){
        cin >> hembras[i];
    }
    
    int numConsultas;
    cin >> numConsultas;
    vector<int> alturas(numConsultas);
    for(int j = 0; j < numConsultas; j++){
        cin >> alturas[j];
    }

    for(int ind = 0; ind < numConsultas; ind++){
        int alturaLuchu = alturas[ind];
        
        int mBaja = lowerBound(hembras, alturaLuchu) - 1;
        
        int mAlta = upperBound(hembras, alturaLuchu);
        
        if (mBaja >= 0) {
            cout << hembras[mBaja] << " ";
        } else {
            cout << "X ";
        }
        
        if (mAlta < hembras.size()) {
            cout << hembras[mAlta] << endl;
        } else {
            cout << "X" << endl;
        }
    }

    return 0;
}
