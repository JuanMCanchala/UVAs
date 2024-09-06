#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int numCasos, n, m, x, y;
    bool flag = true;
    while(flag){
        cin >> numCasos;
        if(numCasos == 0)
        flag = false;
        cin >> n >> m;
        for(int i = 0; i < numCasos != 0; i++){
            cin >> x >>  y;
            if(x == n ||  y == m){
                cout << "divisa" << endl;
            }
            if(n > x && m > y){
                cout << "SO" << endl; //SO 
            }
            if(n < x && m < y){
                cout << "NE" << endl; //NE
            }
            if(x > n && y < m){
                cout << "SE" << endl; 
            }
            if(x < n && y > m){
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}