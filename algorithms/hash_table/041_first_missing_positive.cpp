#include <bits/stdc++.h>
using namespace std;

// 41. 缺失的第一个正数
// 原地哈希：把数字 x 放到下标 x - 1 的位置。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

int main() {
    const vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 0}, 3},
        {{3, 4, -1, 1}, 2},
        {{7, 8, 9, 11, 12}, 1},
        {{1}, 2},
        {{2}, 1},
        {{1, 1}, 2},
        {{2, 1}, 3},
        {{2, 2, 3, 1}, 4},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].first;
        int expected = testCases[i].second;
        int actual = solution.firstMissingPositive(nums);
        bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << "：预期 = " << expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
