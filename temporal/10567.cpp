#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct letritas{
    int indiceInicial = 0;
    int indiceFinal = 0;
    int numLetras = 0;
};

int main(){

    string s;
    cin >> s;
    int querys;
    cin >> querys;
    vector<letritas> ss(52);
    vector<char> letras(s.begin(), s.end());
    vector<string> empleados;
    string empleado;
    int casos=querys;
    while(casos--){
        cin >> empleado;
        empleados.push_back(empleado);
    }

    for(int i = 0; i < letras.size(); i++){
        if(ss[i].numLetras == 0 ){
            ss[i].indiceInicial == i;
            ss[i].indiceFinal == i;

        }else{
            ss[i].indiceFinal == i;
        }
        ss[i].numLetras += 1;
    }

    for (int i = 0 ; i < querys ; i++){
        vector<int> contar(52);
        int posicion;
        for (int j = 0; j < empleados[i].size(); j++){
            if (empleados[i][j] <= 'Z' && empleados[i][j] >= 'A'){
            posicion = empleados[i][j] - 65;
            contar[posicion] += 1;
            }
            else{
                posicion = empleados[i][j] - 71;
                contar[posicion] += 1;
            }
        }
        bool flag= true;
        for (int j = 0; j < 52; j++){
            if(contar[j]> ss[i].numLetras)
                flag=false;
        }
        
        if (flag)
            cout << "Matched" << endl;
        else 
            cout << "No matched" << endl;
    }
    return 0;
}