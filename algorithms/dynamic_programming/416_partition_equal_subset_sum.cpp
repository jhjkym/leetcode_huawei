#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};

int main() {
    Solution solution;

    vector<vector<int>> tests = {
        {1, 5, 11, 5},
        {1, 2, 3, 5},
        {1, 1},
        {2, 2, 3, 5},
        {2, 2, 1, 1},
        {100},
        {3, 3, 3, 4, 5},
        {1, 2, 5}
    };
    vector<bool> expected = {
        true, false, true, false, true, false, true, false
    };

    int testCount = tests.size();
    for (int i = 0; i < testCount; i++) {
        bool result = solution.canPartition(tests[i]);
        cout << "测试 " << i + 1 << ": "
             << (result == expected[i] ? "通过" : "失败") << '\n';
    }

    return 0;
}
