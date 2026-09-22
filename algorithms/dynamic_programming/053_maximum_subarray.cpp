#include <bits/stdc++.h>
using namespace std;

// 53. 最大子数组和
// Kadane 算法：要么加入前面的连续子数组，要么从当前元素重新开始。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = nums[0];
        for (int num : nums) {
            sum = max(num, sum + num);
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {
    const vector<pair<vector<int>, int>> testCases = {
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},
        {{-3, -2, -5}, -2},
        {{0}, 0},
        {{-2, 1}, 1},
        {{1, -2, 3, 4, -1}, 7},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].first;
        int expected = testCases[i].second;
        int actual = solution.maxSubArray(nums);
        bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << "：nums = [";
        for (size_t j = 0; j < nums.size(); ++j) {
            cout << (j ? ", " : "") << nums[j];
        }
        cout << "]，预期 = " << expected << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
