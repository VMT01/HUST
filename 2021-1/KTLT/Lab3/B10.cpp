#include <iostream>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define BASE 25

int t, n, h;
int x[BASE];

void init();
void solve(int k);
void sol();

int main() {
    faster;
    freopen("input.inp", "r", stdin);

    cin >> t;
    while (t--) {
        init();
        solve(0);
        cout << endl;
    }

    return 0;
}

void init() {
    cin >> n >> h;
    for (int i = 0; i < n; i++) x[i] = 0;
}

void solve(int k) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        if (k == n - 1) sol();
        else solve(k + 1);
    }
}

void sol() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) cnt++;
        if (cnt > h) return;
    }

    if (cnt == h) {
        for (int i = 0; i < n; i++) cout << x[i];
        cout << endl;
    }
}