#include <bits/stdc++.h>
using namespace std;

// 34. 在排序数组中查找元素的第一个和最后一个位置
// 两次左边界二分：找 target 和 target + 1 的起点。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lowerBound(nums, target);
        if (first == n || nums[first] != target) return {-1, -1};

        int last = lowerBound(nums, target + 1) - 1;
        return {first, last};
    }

private:
    int lowerBound(vector<int>& nums, int target) {
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
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{5, 7, 7, 8, 8, 10}, 8, {3, 4}},
        {{5, 7, 7, 8, 8, 10}, 6, {-1, -1}},
        {{}, 0, {-1, -1}},
        {{1}, 1, {0, 0}},
        {{2, 2}, 2, {0, 1}},
        {{1, 2, 3, 3, 3, 4}, 3, {2, 4}},
        {{1, 2, 3}, 4, {-1, -1}},
        {{-3, -1, -1, 0, 2}, -1, {1, 2}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].nums;
        vector<int> actual = solution.searchRange(nums, testCases[i].target);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = ["
             << testCases[i].expected[0] << ", " << testCases[i].expected[1]
             << "]，实际 = [" << actual[0] << ", " << actual[1] << "]，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
