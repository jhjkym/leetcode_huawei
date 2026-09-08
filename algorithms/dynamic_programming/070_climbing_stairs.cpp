#include <bits/stdc++.h>
using namespace std;

// 70. 爬楼梯
// 算法：动态规划；数据结构：数组或滚动变量。
// 每次可以爬 1 阶或 2 阶，返回爬到第 n 阶的不同方法数。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    int climbStairs(int n) {
        // TODO: 在这里填写核心实现。
        vector<int> dp(n+1);
        if(n <= 2){
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<= n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n]; // 占位返回值，完成实现后替换。
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<int, int>> testCases = {
        {0, 1},
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 5},
        {5, 8},
        {6, 13},
        {10, 89},
        {20, 10946},
        {30, 1346269},
        {40, 165580141},
        {45, 1836311903},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [n, expected] = testCases[i];
        const int actual = solution.climbStairs(n);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": n = " << n
             << "，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
