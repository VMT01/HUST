#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define BASE 1005

int n, r;
int price[BASE][BASE];
vector<int> points;
int start, destination, numPoints;
int x[BASE];
bool visited[BASE];
int sumPrice, minPrice;

void init();
void convert(string s);
void preSetup();
void solve(int k);
bool check(int k, int i);
void printSol();

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    init();
    string str;
    
    getline(cin, str);
    while (r--) {
        getline(cin, str);
        convert(str);
        preSetup();
        solve(1);

        if (minPrice == INT_MAX) cout << 0 << endl;
        else cout  << minPrice << endl;
    }

    return 0;
}

void init() {
    cin >> n >> r;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> price[i][j];
        }
    }
}

void convert(string s) {
    points.clear();
    stringstream ss(s);
    int tmp = 0;
    while (ss >> tmp) points.push_back(tmp);
}

void preSetup() {
    start = points.front(), destination = points.back();
    numPoints = points.size();
    x[0] = start, x[numPoints - 1] = destination;

    memset(visited, false, n * sizeof(bool));

    minPrice = INT_MAX;
    sumPrice = 0;
}

void solve(int k) {
    for (int i = 1; i < numPoints - 1; i++) {
        if (check(k, i)) {
            x[k] = points[i];
            visited[x[k]] = true;
            sumPrice += price[x[k - 1]][x[k]];

            if (k == numPoints - 2) printSol();
            else solve(k + 1);

            visited[x[k]] = false;
            sumPrice -= price[x[k - 1]][x[k]];
        }
    }
}

bool check(int k, int i) {
    if (visited[points[i]]) return false;
    if (price[x[k - 1]][points[i]] == 0) return false;
    return true;
}

void printSol() {
    if (price[x[numPoints - 2]][destination] == 0) return;
    minPrice = min(minPrice, sumPrice + price[x[numPoints - 2]][destination]);
}