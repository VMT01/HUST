#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define bigNum vector<int>
#define BASE 10000
#define BASE_DIGIT 4

void str2big(string s, bigNum &a);
ostream &operator<<(ostream &cout, const bigNum &a);
bigNum operator + (bigNum a, const bigNum &b);
bigNum operator - (bigNum a, const bigNum &b);
bigNum operator * (bigNum a, int k);
bigNum operator * (const bigNum &a, const bigNum &b);
bool operator > (const bigNum &a, const bigNum &b);

void init();
void firstCheck();
void secondCheck();

bigNum a, b, c;
bool aSign, bSign, cSign;

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    init();
    c = a * b;
    a = a * 3;
    b = b * 4;

    firstCheck();
    secondCheck();
    cout << !cSign;
    cout << c << endl;

    return 0;
}

void str2big(string s, bigNum &a) {
    s[0] = '0';
    while (s.size() % BASE_DIGIT) s = '0' + s;
    for (int i = s.size() - 1; i >= 0; i -= BASE_DIGIT) {
        int x = 0;
        for (int j = i - BASE_DIGIT + 1; j <= i; j++) x = x * 10 + s[j] - '0';
        a.push_back(x);
    }
}

ostream &operator << (ostream &cout, const bigNum &a) {
    cout << a.back();
    for (int i = a.size() - 2; i >= 0; i--)
        cout << setw(BASE_DIGIT) << setfill('0') << a[i];
    return cout;
}

bigNum operator + (bigNum a, const bigNum &b){
    for (int i = 0, carry = 0; i < max(a.size(),b.size()) || carry; i++){
        if (i == a.size()) a.push_back(0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= BASE;
        if (carry) a[i] -= BASE;
    }
   return a;
}

bigNum operator - (bigNum a, const bigNum &b){
    for (int i=0, carry = 0; i < a.size() || carry; i++){
        a[i] = a[i] - carry - (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry) a[i] += BASE;
    }
    while (a.size() > 1 && !a.back()) a.pop_back();
    return a;
}

bigNum operator * (bigNum a, int k) {
    for (int i = 0, carry = 0; i < a.size() || carry; i++) {
        if (i == a.size()) a.push_back(0);
        long long t = (long long) k * a[i] + carry;
        carry = (int) (t / BASE);
        a[i] = (int) (t % BASE);
    }
    return a;
}

bigNum operator * (const bigNum &a, const bigNum &b) {
    bigNum t,c;
    int nc = a.size() + b.size();
    for (int i = 0; i < nc; i++) c.push_back(0);
    for (int i = 0; i < b.size(); i++){
        t = a * b[i];
        for (int j = 0; j <i; j++) t.insert(t.begin(),0);
        c = c + t;
    }
    while (c.size() > 1 && !c.back()) c.pop_back();
    return c;
}

bool operator < (const bigNum &a, const bigNum &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}


void init() {
    string sa, sb;
    cin >> sa >> sb;
    if (sa[0] == '0') aSign = true;
    if (sb[0] == '0') bSign = true;
    cSign = aSign ^ bSign;
    str2big(sa, a); str2big(sb, b);
}

void firstCheck() {
    /* 
        Nếu c và a cùng dương thì c = c - a, cần kiểm tra c < a hay không 
        Nếu c < a thì c = a - c, đồng thời chuyển dấu c về âm
        Ngươc lại, c = c - a, c giữ nguyên dấu
    */
    if (cSign == false && aSign == false) {
        if (c < a) {
            c = a - c;
            cSign = true;
        } else {
            c = c - a;
        }
        return;
    }

    /*
        Nếu c và a cùng âm thì c = a - c, cần kiểm tra a < c hay không
        Nếu c < a thì c = a - c, đồng thời chuyển dấu c về dương
        Ngược lại, c = c - a, c giữ nguyên dấu
    */
    if (cSign == true && aSign == true) {
        if (c < a) {
            c = a - c;
            cSign = false;
        } else {
            c = c - a;
        }
        return;
    }

    /*
        Các trường hợp còn lại, do c và a trái dấu nên biểu thức c - a sẽ trở thành cùng dấu với c
        Vì vậy, biểu thức cần tính là c = c + a và giữ nguyên gấu của c
    */
    c = c + a;
    return;
}

void secondCheck() {
    /*
        Nếu c dương và b âm, biểu thức trở thành c = c - b, ta cần kiểm tra c < b hay không
        Nếu c < b thì c = b - c, đồng thời chuyển dấu c về âm.
        Ngược lại, c = c - b, giữ nguyên dấu của c
    */
    if (cSign == false && bSign == true) {
        if (c < b) {
            c = b - c;
            cSign = true;
        } else {
            c = c - b;
        }
        return;
    }

    /*
        Nếu c âm và b dương, biểu thức trở thành c = b - c, ta cần kiểm tra c < b hay không
        Nếu c < b thì c = b - c, đồng thời chuyển dấu của c về dương
        Ngược lại, c = c - b, giữ nguyên dấu của c
    */
    if (cSign == true && bSign == false) {
        if (c < b) {
            c = b - c;
            cSign = false;
        } else {
            c = c - b;
        }
        return;
    }

    /*
        Các trường hợp còn lại, do c và a cùng dấu nên biểu thức c + a sẽ trở thành cùng dấu với c
        Vì vậy, biểu thức cần tính là c = c + a và giữ nguyên gấu của c
    */
    c = c + b;
    return;
}