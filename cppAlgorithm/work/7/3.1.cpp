#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, Q, S, T;
    cin >> N >> Q >> S >> T;
    
    // 正确数组大小：N+1个地点（0到N），N段路径（1到N）
    vector<long long> A(N+1);    // 地点0到N的海拔
    vector<long long> diff(N+2, 0); // 路径1到N的海拔差（索引1到N）
    long long temp = 0;
    
    // 读入海拔：A0到AN（共N+1个值）
    cin >> A[0]; // 地点0（题目保证为0）
    for (long long i = 1; i <= N; i++) {
        cin >> A[i];
        // 只计算有效路径段（1到N）
        diff[i] = A[i] - A[i-1];
        if (diff[i] > 0) {
            temp -= diff[i] * S;
        } else {
            temp += (-diff[i]) * T;
        }
    }
    
    // 处理每天的更新
    while (Q--) {
        long long L, R, X;
        cin >> L >> R >> X;
        
        // 1. 更新左边界L的路径段（L→L-1→L路径）
        // 移除旧贡献
        if (diff[L] > 0) temp += diff[L] * S;
        else temp -= (-diff[L]) * T;
        
        // 修改海拔差
        diff[L] += X;
        
        // 添加新贡献
        if (diff[L] > 0) temp -= diff[L] * S;
        else temp += (-diff[L]) * T;
        
        // 2. 更新右边界R+1的路径段（如果存在）
        if (R + 1 <= N) { // 确保R+1是有效路径段
            // 移除旧贡献
            if (diff[R+1] > 0) temp += diff[R+1] * S;
            else temp -= (-diff[R+1]) * T;
            
            // 修改海拔差
            diff[R+1] -= X;
            
            // 添加新贡献
            if (diff[R+1] > 0) temp -= diff[R+1] * S;
            else temp += (-diff[R+1]) * T;
        }
        
        cout << temp << '\n';
    }
    
    return 0;
}