#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pii pair<int, int>

vector<pii> arr;

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    int key, value;
    while (cin >> key >> value) arr.push_back(pii(key, value));

    sort(arr.begin(), arr.end(), [](pii a, pii b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    });
    
    for (int i = 0; i < arr.size(); i++) cout << arr[i].first << ' ' << arr[i].second << endl;

    return 0;
}