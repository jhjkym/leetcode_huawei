#include <bits/stdc++.h>
using namespace std;

// 198. 打家劫舍
// 算法：动态规划；数据结构：状态数组或滚动变量。
// 沿街房屋各有金额 nums[i]，不能偷相邻两家，求能偷到的最大金额。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    int rob(vector<int>& nums) {
        // TODO: 在这里填写核心实现。
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1]; // 占位返回值，完成实现后替换。
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 1}, 4},
        {{2, 7, 9, 3, 1}, 12},
        {{1}, 1},
        {{2, 1}, 2},
        {{1, 2}, 2},
        {{2, 1, 1, 2}, 4},
        {{5, 5, 10, 100, 10, 5}, 110},
        {{1, 3, 1, 3, 100}, 103},
        {{0, 0, 0}, 0},
        {{100, 1, 1, 100}, 200},
        {{4, 1, 2, 7, 5, 3, 1}, 14},
        {{10, 10, 10}, 20},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].first;
        const int expected = testCases[i].second;
        const int actual = solution.rob(nums);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < nums.size(); ++j) {
            if (j) cout << ", ";
            cout << nums[j];
        }
        cout << "]，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
