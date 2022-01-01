#include <iostream>
#include <map>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

string str;
map<int, int> m;

void solve();

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    cin >> str;
    solve();

    return 0;
}


void solve() {
    int flag0 = 0, flag1 = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') flag0++; 
        else flag1++;    
        m[flag1 - flag0]++;
    }

    map<int, int>::iterator it = m.begin();
    int res = 0;
    while (it != m.end()) {
        res += it->second * (it->second - 1) / 2;
        if (it->first == 0) res += it->second;
        it++;
    }

    cout << res;
}
