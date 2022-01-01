#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define vect vector<ll>

ll n;
vect vt, L, R;

void init();
void solve();

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    init();
    solve();

    return 0;
}

void init() {
    cin >> n;
    vt.push_back(-1);
    ll tmp;

    for (ll i = 0; i < n; i++) {
        cin >> tmp;
        vt.push_back(tmp);
    }
    vt.push_back(-1);
}

void solve() {
    if (n == 0) return;

    stack<ll> st;
    L.resize(n + 2); R.resize(n + 2);
    for (ll i = 1; i < n + 2; i++) {
        while (!st.empty() && vt[i] < vt[st.top()]) {
            L[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    for (ll i = n; i >= 0; i--) {
        while (!st.empty() && vt[i] < vt[st.top()]) {
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    ll maxH = 0;
    for (ll i = 1; i <= n; i++) {
        maxH = max(maxH,  (L[i] - R[i] - 1) * vt[i]);
    }

    cout << maxH;
}