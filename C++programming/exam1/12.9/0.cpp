#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> reshape_matrix(const vector<vector<int>>& M, int n, int m, int p, int q) {
    vector<int> flat;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            flat.push_back(M[i][j]);
        }
    }
    if (flat.size() != p * q) {
        throw runtime_error("ERROR");
    }
    
    vector<vector<int>> new_matrix(p, vector<int>(q));
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            new_matrix[i][j] = flat[i * q + j];
        }
    }
    
    return new_matrix;
}
vector<vector<int>> transpose_matrix(const vector<vector<int>>& M, int n, int m) {
    vector<vector<int>> new_matrix(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            new_matrix[j][i] = M[i][j];
        }
    }
    return new_matrix;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < t; ++i) {
        int op;
        cin >> op;
        
        if (op == 1) {
            int p, q;
            cin >> p >> q;
            
            try {
                M = reshape_matrix(M, n, m, p, q);
                n = p;
                m = q;
            } catch (const runtime_error& e) {
                cout << "ERROR" << endl;
            }
        }
        else if (op == 2) {
            M = transpose_matrix(M, n, m);
            swap(n, m);
        }
        else if (op == 3) {
            int i, j;
            cin >> i >> j;
            cout << M[i][j] << endl;
        }
    }

    return 0;
}