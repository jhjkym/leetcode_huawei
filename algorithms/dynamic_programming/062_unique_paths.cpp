#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tests = {
        {3, 7}, {3, 2}, {1, 1}, {1, 5}, {5, 1}, {3, 3}, {4, 4}, {10, 10}
    };
    vector<int> expected = {28, 3, 1, 1, 1, 6, 20, 48620};

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        int result = solution.uniquePaths(tests[i][0], tests[i][1]);
        bool ok = result == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
