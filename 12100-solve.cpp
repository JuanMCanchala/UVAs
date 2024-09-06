#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> vec, vec2;
    while (T--) {
        int n, m; //n es el numero de prints
        cin >> n >> m;

        vec.clear();  
        vec2.clear();

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            vec.push_back(num);
            vec2.push_back(num);
        }
        sort(vec2.begin(), vec2.end(), greater<int>());
        int flag = 1;
        int count = 0;
        int i = 0, j = 0;
        while (flag) {
            if (j == n) {
                j = 0;
            }
            if (vec2[i] == vec[j] && j == m) {
                flag = 0;
                count++;
            } else if (vec2[i] == vec[j]) {
                j++;
                i++;
                count++;
            } else {
                j++;
            }
        }
        cout << count << endl;
    }

    return 0;
}