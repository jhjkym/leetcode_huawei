#include <bits/stdc++.h>
using namespace std;

// 704. 二分查找
// 在升序数组中查找 target，找到返回下标，否则返回 -1。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1; // 闭区间 [left, right]

        while (left <= right) {
            int mid = left + (right - left) / 2; // 防止 left + right 溢出
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                left = mid + 1;  // target 只可能在右半部分
            } else {
                right = mid - 1; // target 只可能在左半部分
            }
        }
        return -1;
    }
};

int main() {
    const vector<tuple<vector<int>, int, int>> testCases = {
        {{-1, 0, 3, 5, 9, 12}, 9, 4},
        {{-1, 0, 3, 5, 9, 12}, 2, -1},
        {{5}, 5, 0},
        {{5}, 1, -1},
        {{}, 3, -1},
        {{1, 2, 3, 4, 5}, 1, 0},
        {{1, 2, 3, 4, 5}, 5, 4},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto [nums, target, expected] = testCases[i];
        int actual = solution.search(nums, target);
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << expected
             << "，实际 = " << actual << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
