#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    vector<int> temp;
    for (int v : a) {
        if (v % 2) temp.push_back(v);
    }
    a.clear();
    for (int v : temp) a.push_back(v);
}

void sort_decrease(vector<int> &a) {
    sort(a.begin(), a.end(), [](int a, int b) {
        return a > b;
    });
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> temp;
    for (int v : a) temp.push_back(v);
    for (int v : b) temp.push_back(v);
    sort(temp.begin(), temp.end(), [](int a, int b) { return a > b; });
    return temp;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}