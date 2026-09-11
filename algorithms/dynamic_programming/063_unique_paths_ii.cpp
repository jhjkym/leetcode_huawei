#include <bits/stdc++.h>
using namespace std;

// 63. 不同路径 II
// 从左上角到右下角，每次只能向右或向下移动。
// 0 表示空地，1 表示障碍物；返回不经过障碍物的路径数量。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：起点置一；遇障碍置零；否则上方加左方。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = static_cast<int>(obstacleGrid.size());
        int n = static_cast<int>(obstacleGrid[0].size());
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    struct TestCase {
        vector<vector<int>> grid;
        int expected;
    };
    const vector<TestCase> testCases = {
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2},
        {{{0, 1}, {0, 0}}, 1},
        {{{0}}, 1},
        {{{1}}, 0},
        {{{1, 0}, {0, 0}}, 0},
        {{{0, 0}, {0, 1}}, 0},
        {{{0, 0, 0, 0}}, 1},
        {{{0, 1, 0, 0}}, 0},
        {{{0}, {0}, {0}, {0}}, 1},
        {{{0}, {1}, {0}, {0}}, 0},
        {{{0, 0}, {0, 0}}, 2},
        {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 6},
        {{{0, 0, 0}, {1, 1, 1}, {0, 0, 0}}, 0},
        {{{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 3},
        {{{0, 0, 0}, {1, 0, 0}, {0, 0, 0}}, 3},
        {{{0, 0, 0, 0}, {0, 0, 0, 0}}, 4},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto grid = testCase.grid;
        int actual = solution.uniquePathsWithObstacles(grid);
        bool ok = actual == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": obstacleGrid = [";
        for (size_t r = 0; r < testCase.grid.size(); ++r) {
            if (r > 0) cout << ", ";
            cout << '[';
            for (size_t c = 0; c < testCase.grid[r].size(); ++c) {
                if (c > 0) cout << ", ";
                cout << testCase.grid[r][c];
            }
            cout << ']';
        }
        cout << "]，预期 = " << testCase.expected << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
