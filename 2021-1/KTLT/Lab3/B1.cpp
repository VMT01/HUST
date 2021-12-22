#include <iostream>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int n;
int lucas(int k) {
    if (k == 0) return 2;
    if (k == 1) return 1;
    return lucas(k - 1) + lucas(k - 2);
}

int main() {
    faster;
    // freopen("input.inp", "r", stdin);
    cin >> n;

    cout << lucas(n);

    return 0;
}