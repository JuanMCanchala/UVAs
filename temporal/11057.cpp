/*
basicamente debo encontrar los dos indices en la lista que sumen el numero que esta arriba debe ser la suma mas 
grande sin pasarse

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pareja{
    int firstnum;
    int secondnum;
};

Pareja exactSumm(vector<int> &n, int total){

sort(n.begin(), n.end());
int l = 0;
int h = n.size();
Pareja pareja;
while(l-h > 1){
if(n[l] + n[h] == total) {
n[l] = pareja.firstnum;
n[h] = pareja.secondnum;
l += 1;
h -= 1;
} else if(n[l] + n[h] > total){
h -=1;
} else if(n[l] + n[h] < total){
l += 1;
}
}
return pareja;
};



int main(){
int numVaires;
while(cin >> numVaires){
    vector<int> summ;
    for(int i = 0; i < numVaires; i++){
        int precios;
        cin >> precios;
        summ.push_back(precios);
    }
    int total;
    cin >> total;

    Pareja resultado = exactSumm(summ, total);
    
}

    return 0;
}