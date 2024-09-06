#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int> S;
        queue<int> Q;
        priority_queue<int> PQ;
        bool s = true, q = true, pq = true;

        while (n--) {
            int cmd, x;
            cin >> cmd >> x;
            if (cmd == 1) {
                S.push(x);
                Q.push(x);
                PQ.push(x);
            } else {
                if (s && (!S.empty() && x == S.top())) S.pop();
                else s = false;
                if (q && (!Q.empty() && x == Q.front())) Q.pop();
                else q = false;
                if (pq && (!PQ.empty() && x == PQ.top())) PQ.pop();
                else pq = false;
            }
        }

        if (q && !s && !pq) cout << "queue";
        else if (pq && !s && !q) cout << "priority queue";
        else if (s && !q && !pq) cout << "stack";
        else if (!s && !q && !pq) cout << "impossible";
        else cout << "not sure";
        cout << endl;
    }
    return 0;
}
