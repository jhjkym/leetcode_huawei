#include <bits/stdc++.h>
using namespace std;

// 55. 跳跃游戏
// 贪心：维护遍历过程中能够到达的最远位置。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; ++i) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) return true;
        }
        return true;
    }
};

int main() {
    const vector<pair<vector<int>, bool>> testCases = {
        {{2, 3, 1, 1, 4}, true},
        {{3, 2, 1, 0, 4}, false},
        {{0}, true},
        {{2, 0, 0}, true},
        {{1, 0, 1, 0}, false},
        {{0, 1}, false},
        {{5, 0, 0, 0, 0}, true},
        {{1, 1, 1, 1}, true},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        bool actual = solution.canJump(nums);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha
             << testCases[i].second << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
