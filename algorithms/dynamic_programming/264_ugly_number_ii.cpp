#include <bits/stdc++.h>
using namespace std;

// 264. 丑数 II
// 丑数只包含质因数 2、3、5；返回从小到大排列的第 n 个丑数。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：dp 从 1 开始，三个指针乘 2、3、5；取最小，重复指针都前进。

class Solution {
public:
    int nthUglyNumber(int n) {
        // dp[i] 表示第 i 个丑数，题目规定第一个丑数 dp[1] = 1。
        // 使用 long long 计算乘法，避免中间结果溢出。
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        // 三个指针分别寻找下一个乘以 2、3、5 的候选丑数。
        int p2 = 1, p3 = 1, p5 = 1;

        for (int i = 2; i <= n; ++i) {
            // 下一个丑数一定来自已有丑数乘 2、3 或 5，取三个候选值的最小值。
            dp[i] = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5});
            // 三个 if 必须独立：同一个数字可能由多个方式生成，相关指针都要前进。
            if (dp[i] == dp[p2] * 2) ++p2;
            if (dp[i] == dp[p3] * 3) ++p3;
            if (dp[i] == dp[p5] * 5) ++p5;
        }
        // dp[n] 是答案；题目范围保证可以转成 int。
        return static_cast<int>(dp[n]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector<pair<int, int>> testCases = {
        {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6},
        {7, 8}, {8, 9}, {9, 10}, {10, 12}, {11, 15}, {12, 16},
        {15, 24}, {20, 36}, {50, 243}, {1690, 2123366400},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        int actual = solution.nthUglyNumber(testCases[i].first);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << ": n = " << testCases[i].first
             << "，预期 = " << testCases[i].second
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
