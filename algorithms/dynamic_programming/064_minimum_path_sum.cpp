#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);

        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<vector<int>>> tests = {
        {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
        {{1, 2, 3}, {4, 5, 6}},
        {{5}},
        {{1, 2, 3, 4}},
        {{1}, {2}, {3}, {4}},
        {{0, 0}, {0, 0}},
        {{1, 9, 1}, {1, 1, 1}},
        {{1, 2}, {1, 1}}
    };
    vector<int> expected = {7, 12, 5, 10, 10, 0, 4, 3};

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        int result = solution.minPathSum(tests[i]);
        bool ok = result == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
