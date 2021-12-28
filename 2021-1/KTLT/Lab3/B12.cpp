#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define vect vector<int>
#define BASE 105

int n, k, m;
vector<vect> edges;
bool visited[BASE];
int x[BASE];
int res;

void init();
void solve(int a);
bool check(int a, int i);

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    init();
    solve(0);
    cout << res / 2;

    return 0;
}

void init() {
    cin >> n >> k;
    cin >> m;

    int a, b;
    edges.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    memset(visited, false, n * sizeof(bool));
    res = 0;
}

void solve(int a) {
    for (int i = 0; i < n; i++) {
        if (check(a, i)) {
            visited[i] = true;
            x[a] = i;

            if (a == k) res++;
            else solve(a + 1);

            visited[i] = false;
        }
    }
}

bool check(int a, int i) {
    if (a == 0) return true;
    if (visited[i]) return false;

    int cnt = 0;
    for (int j = 0; j < edges[x[a - 1]].size(); j++) {
        if (i == edges[x[a - 1]][j]) cnt++;
    }

    if (cnt == 0) return false;
    return true;
}