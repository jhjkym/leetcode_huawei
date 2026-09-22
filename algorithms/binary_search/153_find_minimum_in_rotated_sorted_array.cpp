#include <bits/stdc++.h>
using namespace std;

// 153. 寻找旋转排序数组中的最小值
// 比较中间值和右端点，判断最小值位于哪一半。
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    const vector<pair<vector<int>, int>> testCases = {
        {{3, 4, 5, 1, 2}, 1},
        {{4, 5, 6, 7, 0, 1, 2}, 0},
        {{11, 13, 15, 17}, 11},
        {{1}, 1},
        {{2, 1}, 1},
        {{1, 2}, 1},
        {{5, 1, 2, 3, 4}, 1},
        {{2, 3, 4, 5, 1}, 1},
        {{-2, -1, 0, -5, -4, -3}, -5},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int actual = solution.findMin(nums);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].second
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
