#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fl(i, a, b) for (int i = a; i < b; ++i)

#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))

#define pb push_back
#define mp make_pair

#define dig(i) (s[i] - '0')
#define slen(s) s.length()

#define fr first
#define sc second

#define len(x) x.size()
#define fill(x, y) memset(x, y, sizeof(x))
#define clr(a) fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1) cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2) \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)                                                  \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 \
         << ": " << x3 << endl;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <typename T>
T power(T x, T y, ll m = MOD) {
    T ans = 1;
    x %= m;
    while (y > 0) {
        if (y & 1ll) ans = (ans * x) % m;
        y >>= 1ll;
        x = (x * x) % m;
    }
    return ans % m;
}

int main() {
    FAST_IO;
    int n, c = 0;
    string c1, c2, city;

    while (cin >> n) {
        map<string, vs> graph;
        map<string, bool> visited;
        map<string, string> parent;
        stack<pair<string, string>> route;
        bool found = false;
        queue<string> q;
        c++;

        fl(i, 0, n) {
            cin >> c1 >> c2;
            graph[c1].pb(c2);
            graph[c2].pb(c1);
        }

        cin >> c1 >> c2;

        q.push(c1);
        visited[c1] = true;

        while (!q.empty() and !found) {
            city = q.front();
            q.pop();

            if (city == c2)
                found = true;
            else {
                for (string &s : graph[city]) {
                    if (!visited[s]) {
                        visited[s] = true;
                        q.push(s);
                        parent[s] = city;
                    }
                }
            }
        }

        if (c > 1) cout << endl;

        if (!found)
            cout << "No route" << endl;
        else {
            // Rehacer la ruta

            while (c2 != c1) {
                route.push({parent[c2], c2});
                c2 = parent[c2];
            }

            while (!route.empty()) {
                cout << route.top().fr << " " << route.top().sc << endl;
                route.pop();
            }
        }
    }

    return 0;
}