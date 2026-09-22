#include <bits/stdc++.h>
using namespace std;

// 279. 完全平方数
// dp[i] 表示组成 i 所需的最少完全平方数数量。
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    const vector<pair<int, int>> testCases = {
        {12, 3},
        {13, 2},
        {1, 1},
        {4, 1},
        {2, 2},
        {3, 3},
        {43, 3},
        {100, 1},
        {0, 0},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        int actual = solution.numSquares(testCases[i].first);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：n = " << testCases[i].first
             << "，预期 = " << testCases[i].second
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
