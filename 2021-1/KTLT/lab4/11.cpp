#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pii pair<int, int>

struct compare {
    bool operator() (pii a, pii b) {
        return min(a.first, a.second) < min(b.first, b.second);
    }
};

int n, s, killed, total;
priority_queue<pii, vector<pii>, compare> pq;

void init();
void solve();

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    init();
    solve();
    cout << total - killed;

    return 0;
}

void init() {
    cin >> n >> s;

    int temp1, temp2;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        total += temp1;
        pq.push({temp1, temp2});
    }
}

void solve() {
    while(!pq.empty() && s) {
        pii inf = pq.top(); pq.pop();

        if (inf.first <= inf.second) killed += inf.first;
        else {
            int ene = inf.first - inf.second;
            pq.push({ene, inf.second});
            killed += inf.second;
        }

        s--;
    }
}