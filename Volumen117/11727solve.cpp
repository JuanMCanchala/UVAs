#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int k, contador = 1, ans;

    cin >> k;
    while(k--){
        vector <int> promedio;
        int n1, n2, n3;
        ans = 0;
        cin >> n1 >> n2 >> n3;
        promedio.push_back(n1);
        promedio.push_back(n2);
        promedio.push_back(n3);

        sort(promedio.begin(), promedio.end());
        ans = promedio[1];

    cout << "Case " << contador << ": " << ans << endl;
    contador++;
    }

    return 0;
}