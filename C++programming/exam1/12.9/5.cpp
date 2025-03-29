#include<bits/stdc++.h>
using namespace std;

string changetolower(string str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

void coutstr(vector<string>& str) {
    for (const auto &n : str) {
        cout << n << endl;
    }
}

int main() {
    vector<string> a, b;
    int an, bn;
    cin >> an >> bn;
    a.resize(an), b.resize(bn);
    
    for (int i = 0; i < an; i++) {
        cin >> a[i];
        a[i]=changetolower(a[i]);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());  // 去重
    
    for (int i = 0; i < bn; i++) {
        cin >> b[i];
        b[i]=changetolower(b[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());  // 去重
    
    int same = 0;
    set<string> a_set(a.begin(), a.end());
    set<string> b_set(b.begin(), b.end());
    for (const auto &word : a_set) {
        if (b_set.find(word) != b_set.end()) {
            same++;
        }
    }

    int both = a.size() + b.size() - same;
    
    cout << same << endl << both << endl;
    return 0;
}