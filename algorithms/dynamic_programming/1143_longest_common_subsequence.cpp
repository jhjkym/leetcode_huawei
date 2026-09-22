#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;
    vector<vector<string>> tests = {
        {"abcde", "ace"},
        {"abc", "abc"},
        {"abc", "def"},
        {"a", "a"},
        {"a", "b"},
        {"abcba", "abcbcba"},
        {"aaaa", "aa"},
        {"sea", "eat"}
    };
    vector<int> expected = {3, 3, 0, 1, 0, 5, 2, 2};

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        int result = solution.longestCommonSubsequence(tests[i][0], tests[i][1]);
        bool ok = result == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
