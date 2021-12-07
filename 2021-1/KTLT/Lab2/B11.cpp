#include <iostream>
#include <complex>
#include <vector>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define cd complex<double>
#define PI acos(-1)

int n, m;
vector<cd> A, B;

void init();
void fft(vector<cd> &a, bool invert);
int multiply();

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    init();
    cout << multiply();

    return 0;
}

void init() {
    int temp;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    cin >> m;
    for (int i = 0; i <= m; i++) {
        cin >> temp;
        B.push_back(temp);
    }
}

void fft(vector<cd> &a, bool invert) {
    int size = a.size();
    if (size == 1) return;

    vector<cd> a0(size / 2), a1(size / 2);
    for (int i = 0; 2 * i < size; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert); fft(a1, invert);

    double ang = 2 * PI / size * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < size; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + size / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + size / 2] /= 2;
        }
        w *= wn;
    }
}

int multiply() {
    int size = 1;
    while (size < A.size() + B.size()) size <<= 1;
    A.resize(size); B.resize(size);
    fft(A, false); fft(B, false);

    for (int i = 0; i < size; i++) A[i] *= B[i];
    fft(A, true);

    int res = (int)round(A[0].real());
    for (int i = 1; i < size; i++) {
        res ^= (int)round(A[i].real());
    }

    return res;
}