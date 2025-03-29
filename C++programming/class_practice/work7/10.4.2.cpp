#include <iostream>
#include <vector>
using namespace std;

bool canDestroyAllWalls(char** chr, int n, int m) {
    int totalWalls = 0;
    vector<vector<int>> wallsPerBomb(n, vector<int>(m, 0));

    // 首先计算总的墙的数量和每个位置放置炸弹时能摧毁的墙的数量
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (chr[i][j] == '*') {
                totalWalls++;
                for (int k = 0; k < n; k++) {
                    if (k != i && chr[k][j] == '*') wallsPerBomb[i][j]++; // 统计同一列的墙
                }
                for (int k = 0; k < m; k++) {
                    if (k != j && chr[i][k] == '*') wallsPerBomb[i][j]++; // 统计同一行的墙
                }
                // 注意：我们不加上chr[i][j]自己，因为炸弹不摧毁自己所在位置的墙
            }
        }
    }

    // 检查是否存在一个炸弹可以摧毁所有的墙
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (chr[i][j] != '*' && wallsPerBomb[i][j] == totalWalls - 1) {
                // 如果当前位置不是墙，并且放置炸弹时能摧毁的墙的数量等于总墙数减一（因为炸弹会摧毁自己所在行和列的墙，但不包括自己）
                return true;
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        char** chr = new char*[n];
        for (int i = 0; i < n; i++) {
            chr[i] = new char[m];
            for (int j = 0; j < m; j++) {
                cin >> chr[i][j];
            }
        }

        if (canDestroyAllWalls(chr, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        for (int i = 0; i < n; i++) {
            delete[] chr[i];
        }
        delete[] chr;
    }
    return 0;
}