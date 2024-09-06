#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int cero = 0, suma = 0;
        string palabra;
        cin >> palabra;
        vector<int> ceros;
        for(int i = 0; i < palabra.size(); i++){
            if( palabra[i] == 'O'){
                cero++;
                ceros.push_back(cero);
            }
            if(palabra[i] == 'X'){
                cero = 0;
            }
        }
        for(int j = 0; j < ceros.size(); j++){
            suma += ceros[j];
        }
        cout << suma << endl;

    }

    return 0;
}