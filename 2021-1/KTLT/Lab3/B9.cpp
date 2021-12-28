#include <iostream>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define BASE 205

int n, k1, k2;
int x[BASE];
int flag;

void init();
void solve(int k);
bool check(int k, int i);

int main() {
    faster;
    freopen("input.inp", "r", stdin);

    init();
    solve(1);

    return 0;
}

void init() {
    cin >> n >> k1 >> k2;
}

void solve(int k) {
    for (int i = 0; i <= 1; i++) {
        if (check(k, i)) {
            x[k] = i;
            int temp = flag;
            if (i == 1) {
                if (x[k - 1] == 1) flag++;
                else flag = 1;
            } else {
                flag = 0;
            }

            if (k == n) {
                for (int i = 1; i <= n; i++) cout << x[i];
                cout << endl;
            } else {
                solve(k + 1);
            }

            flag = temp;
        }
    }
}

bool check(int k, int i) {
    if (k == 1) return true;

    if (i == 0) {
        if (x[k - 1] == 0) return false;
        if (flag < k1) return false;
    } else {
        if (x[k - 1] == 0 && n - k + 1 < k1) return false;
        if (flag >= k2) return false;
    }

    return true;
}