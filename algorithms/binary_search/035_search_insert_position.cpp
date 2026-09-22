#include <bits/stdc++.h>
using namespace std;

// 35. 搜索插入位置
// 二分查找第一个大于等于 target 的位置。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    struct TestCase {
        vector<int> nums;
        int target;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{1, 3, 5, 6}, 5, 2},
        {{1, 3, 5, 6}, 2, 1},
        {{1, 3, 5, 6}, 7, 4},
        {{1, 3, 5, 6}, 0, 0},
        {{1}, 1, 0},
        {{1}, 2, 1},
        {{-3, -1, 2, 4}, 0, 2},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].nums;
        int actual = solution.searchInsert(nums, testCases[i].target);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
