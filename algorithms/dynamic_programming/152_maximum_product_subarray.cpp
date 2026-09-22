#include <bits/stdc++.h>
using namespace std;

// 152. 乘积最大子数组
// 同时维护以当前位置结尾的最大乘积和最小乘积。
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = nums[0];
        int minimum = nums[0];
        int ans = nums[0];

        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) swap(maximum, minimum);

            maximum = max(nums[i], maximum * nums[i]);
            minimum = min(nums[i], minimum * nums[i]);
            ans = max(ans, maximum);
        }
        return ans;
    }
};

int main() {
    const vector<pair<vector<int>, int>> testCases = {
        {{2, 3, -2, 4}, 6},
        {{-2, 0, -1}, 0},
        {{-2}, -2},
        {{-2, 3, -4}, 24},
        {{0, 2}, 2},
        {{-2, -3, -4}, 12},
        {{1, -2, -3, 0, 7, -8, -2}, 112},
        {{2, -5, -2, -4, 3}, 24},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int actual = solution.maxProduct(nums);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].second
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
