#include <bits/stdc++.h>
using namespace std;

// 300. 最长递增子序列
// dp[i] 表示以 nums[i] 结尾的最长递增子序列长度。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    const vector<pair<vector<int>, int>> testCases = {
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7, 7, 7}, 1},
        {{1}, 1},
        {{3, 5, 7, 1, 2, 8}, 4},
        {{}, 0},
        {{1, 2, 3, 4, 5}, 5},
        {{5, 4, 3, 2, 1}, 1},
        {{4, 10, 4, 3, 8, 9}, 3},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int actual = solution.lengthOfLIS(nums);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].second
             << "，实际 = " << actual << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
