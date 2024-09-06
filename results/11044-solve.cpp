#include <vector>
#include <iostream>

using namespace std;
int main(){
    int c, ans = 0;
    cin >> c;
    while(c--){
        int a, b;
        cin >> a >> b;
        a = a/3;
        b = b/3;
        ans = a*b;
    cout << ans << endl;
    }

    return 0;
}
