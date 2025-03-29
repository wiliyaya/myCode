#include <iostream>
#include <cmath> // 如果需要使用 std::pow，但实际上这里不需要
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int I = 0; I < T; I++) {
        int n, m;
        cin >> n >> m;
        char **chr = new char*[n];
        for (int i = 0; i < n; i++) {
            chr[i] = new char[m];
        }

        int **arr = new int*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new int[m];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> chr[i][j];
                arr[i][j] = (chr[i][j] == '.') ? 0 : 1;
            }
        }

        long long *sum = new long long[n];
        bool foundNonZero = false;
        long long firstNonZeroSum = 0;
        for (int i = 0; i < n; i++) {
            sum[i] = 0; // 初始化 sum[i]
            for (int j = 0; j < m; j++) {
                sum[i] += (arr[i][j] << (m - 1 - j)); // 使用位左移来计算二进制数的十进制值
            }
            if (sum[i] != 0) {
                if (!foundNonZero) {
                    foundNonZero = true;
                    firstNonZeroSum = sum[i];
                } else if (sum[i] != firstNonZeroSum) {
                    break; // 如果找到不同的非零和，则无需继续检查，直接跳出循环
                }
            }
        }

        bool a = true;
        if (foundNonZero) { // 只有当找到至少一个非零和时，才继续检查其余的行
            for (int i = 0; i < n; i++) {
                if (sum[i] != firstNonZeroSum && sum[i] != 0) {
                    a = false;
                    break;
                }
            }
        } else {
            // 如果没有找到任何非零和，根据题目要求，可能需要特殊处理（这里假设全零也是有效的）
            // 但由于后续逻辑已经检查了所有非零情况，这里可以不做处理，直接令 a = true（实际上是多余的，因为已经初始化为 true）
            a = true; // 实际上这行代码是多余的，因为 a 已经在前面初始化为 true 了
        }

        cout << (a ? "YES" : "NO") << endl;

        // 释放内存
        for (int i = 0; i < n; i++) {
            delete[] chr[i];
            delete[] arr[i];
        }
        delete[] chr;
        delete[] arr;
        delete[] sum;
    }
    return 0;
}