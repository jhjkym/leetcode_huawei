#include <bits/stdc++.h>
using namespace std;

// 33. 搜索旋转排序数组
// 每轮至少有一半有序，判断 target 是否位于有序区间内。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    struct TestCase {
        vector<int> nums;
        int target;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{4, 5, 6, 7, 0, 1, 2}, 0, 4},
        {{4, 5, 6, 7, 0, 1, 2}, 3, -1},
        {{1}, 0, -1},
        {{1}, 1, 0},
        {{1, 3}, 3, 1},
        {{3, 1}, 1, 1},
        {{5, 1, 3}, 5, 0},
        {{1, 2, 3, 4, 5}, 4, 3},
        {{6, 7, 1, 2, 3, 4, 5}, 7, 1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].nums;
        int actual = solution.search(nums, testCases[i].target);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
