#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cctype> // for std::toupper

using namespace std;

// Function to convert a string to uppercase
string toUpperCase(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> groupA, groupB;
    unordered_set<string> uniqueGroupB; // To store unique uppercase strings from group B for fast lookup

    // Read and process group A
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string upperS = toUpperCase(s);
        if (find(groupA.begin(), groupA.end(), upperS) == groupA.end()) {
            groupA.push_back(upperS);
        }
    }

    // Read and process group B, storing in unordered_set for fast lookup
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        string upperS = toUpperCase(s);
        uniqueGroupB.insert(upperS);
    }

    // Count how many strings from group A are also in group B
    int count = 0;
    for (const string& s : groupA) {
        if (uniqueGroupB.find(s) != uniqueGroupB.end()) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}