#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    long long unsigned a ,b, ans;
    while(cin >> a >> b){

    ans = max(a ,b) - min(a, b);

    cout << ans << endl;
    }
    return 0;
}