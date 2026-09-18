#include <bits/stdc++.h>
using namespace std;

// 300. 最长递增子序列
// 掌握状态：动态规划基础实现，适合理解和背诵。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        // dp[i] 表示：以 nums[i] 作为最后一个元素的最长递增子序列长度。
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            // 枚举 nums[i] 前面的元素，寻找可以接在后面的递增子序列。
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    const vector<pair<vector<int>, int>> testCases = {
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7, 7, 7}, 1},
        {{1}, 1},
        {{3, 5, 7, 1, 2, 8}, 4},
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
