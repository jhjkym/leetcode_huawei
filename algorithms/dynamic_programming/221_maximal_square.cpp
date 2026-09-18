#include <bits/stdc++.h>
using namespace std;

// 221. 最大正方形
// 在只含 '0' 和 '1' 的矩阵中，找到只由 '1' 组成的最大正方形，返回其面积。
// 掌握状态：没做过，已提供答案模板，待复习背诵。
// 口诀：遇零清零，遇一看左上；三者取最小再加一，最后边长平方。
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        // dp[i][j] 表示以 matrix[i-1][j-1] 为右下角的最大正方形边长。
        // 多开一行一列并初始化为 0，避免单独处理第一行和第一列。
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxSide = 0; // 保存整个矩阵中的最大边长。

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // dp 下标比 matrix 下标多 1，所以对应位置是 i-1、j-1。
                if (matrix[i - 1][j - 1] == '1') {
                    // 左、上、左上都要能支撑扩展，取三者最小值再加当前格。
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1],
                                    dp[i - 1][j - 1]}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
                // 当前格为 '0' 时，dp[i][j] 保持初始化值 0。
            }
        }
        // dp 保存边长，题目要求返回正方形面积。
        return maxSide * maxSide;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase { vector<string> rows; int expected; };
    const vector<TestCase> testCases = {
        {{"10100", "10111", "11111", "10010"}, 4},
        {{"0111", "1111", "1111", "1111"}, 9},
        {{"0"}, 0},
        {{"1"}, 1},
        {{"00", "00"}, 0},
        {{"11", "11"}, 4},
        {{"1111"}, 1},
        {{"1111", "1111"}, 4},
        {{"1", "1", "1", "1"}, 1},
        {{"101", "111", "111"}, 4},
        {{"111", "111", "111"}, 9},
        {{"1001", "1111", "1111", "1001"}, 4},
        {{"01010", "11111", "11111"}, 4},
        {{"000", "010", "000"}, 1},
        {{"11111", "10001", "10001", "11111"}, 1},
        {{"101010", "010101"}, 1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<vector<char>> matrix;
        for (const auto& row : testCases[i].rows) {
            matrix.emplace_back(row.begin(), row.end());
        }
        int actual = solution.maximalSquare(matrix);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": 预期面积 = " << testCases[i].expected
             << "，实际面积 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
