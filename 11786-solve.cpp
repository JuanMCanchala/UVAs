#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(){

   int cases;
    string montains;

    cin >> cases;

    while (cases--) {
        cin >> montains;

        stack<int> pil;
        int ans = 0;

        for (int i = 0; i < montains.size(); i++) {
            if (montains[i] == '\\') {
                pil.push(i);
            } else if (montains[i] == '/') {
                if (!pil.empty()) {
                    ans += i - pil.top();
                    pil.pop();
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}