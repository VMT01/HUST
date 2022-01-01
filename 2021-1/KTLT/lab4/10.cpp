#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

#define faster ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define vect vector<string>
#define psi pair<string, int>

int n, q;
vector<vect> vTrain;
vector<vect> vTest;
vector<int> fMax;
map<string, int> df;
map<psi, int> fe;

void init();
void setup();
int freqWordInDoc(string word, int index);
int cntDocContainWord(string word);
int searchEngine(vect listWord);

int main() {
    faster;
    // freopen("input.inp", "r", stdin);

    init();
    setup();

    for (vect item: vTest) {
        cout << searchEngine(item) << endl;
    }

    return 0;
}

void init() {
    string s, substr;
    vect v;

    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        v.clear();
        getline(cin, s);
        stringstream ss(s);
        while (ss.good()) {
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        vTrain.push_back(v);
    }

    cin >> q;
    getline(cin, s);
    for (int i = 0; i < q; i++) {
        v.clear();
        getline(cin, s);
        stringstream ss(s);
        while(ss.good()) {
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        vTest.push_back(v);
    }
}

void setup() {
    for (vect vt: vTrain) {
        map<string, int> mp;
        int maxF = 0;

        for (string str: vt) {
            mp[str]++;
            maxF = max(maxF, mp[str]);
        }

        fMax.push_back(maxF);
    }
}

int freqWordInDoc(string word, int index) {
    if (fe.find(psi(word, index)) != fe.end()) return fe[psi(word, index)];
    
    int i = 0;
    vect temp = vTrain[index];
    for (string s: temp) {
        if (word == s) i++;
    }

    fe[psi(word, index)] = i;
    return i;
}

int cntDocContainWord(string word) {
    if (df.find(word) != df.end()) return df[word];

    int index = 0;
    for (vect item: vTrain) {
        if (find(item.begin(), item.end(), word) != item.end()) index++;
    }

    df[word] = index;
    return index;
}

int searchEngine(vect listWord) {
    double scoreMax = -1000;
    int predictLabel = -1;
    int index = 0;

    for (vect item: vTrain) {
        double score = 0;
        for (string word: listWord) {
            if (find(item.begin(), item.end(), word) == item.end()) continue;
            else {
                int ftd = freqWordInDoc(word, index);
                int dft = cntDocContainWord(word);
                int maxFD = fMax[index];

                double tfWord = 0.5 + 0.5 * ((double) ftd / maxFD);
                double idfWord = log2((double) n / dft);

                score += tfWord * idfWord;
            }
        }

        if (score > scoreMax) {
            predictLabel = index;
            scoreMax = score;
        }
        index++;
    }
    return predictLabel + 1;
}