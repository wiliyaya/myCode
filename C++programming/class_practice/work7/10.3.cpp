#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int n, m;
        cin >> n >> m;
        char **chr = new char *[n];
        for (int i = 0; i < n; i++) {
            chr[i] = new char[m];
        }

        // 读取字符矩阵
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> chr[i][j];
            }
        }

        // 检查每一个单元格作为炸弹位置是否可以摧毁所有墙
        bool canDestroy = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool allDestroyed = true;

                // 检查每一行是否有未被摧毁的墙
                for (int k = 0; k < n; k++) {
                    if (k != i && chr[k][j] == '*') { // 如果炸弹不在第k行但第k行有墙
                        allDestroyed = false;
                        break;
                    }
                }

                // 如果前面检查失败，则无需继续检查列，直接进行下一个单元格
                if (!allDestroyed) continue;

                // 检查每一列是否有未被摧毁的墙
                for (int k = 0; k < m; k++) {
                    if (k != j && chr[i][k] == '*') { // 如果炸弹不在第k列但第k列有墙
                        allDestroyed = false;
                        break;
                    }
                }

                // 如果找到一个可以摧毁所有墙的位置
                if (allDestroyed) {
                    canDestroy = true;
                    break; // 可以提前退出循环，因为已经找到解
                }
            }
            if (canDestroy) break; // 同样，可以提前退出外层循环
        }

        // 输出结果
        cout << (canDestroy ? "YES" : "NO") << endl;

        // 释放内存
        for (int i = 0; i < n; i++) {
            delete[] chr[i];
        }
        delete[] chr;
    }
    return 0;
}