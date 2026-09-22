#include <bits/stdc++.h>
using namespace std;

// 4. 寻找两个正序数组的中位数
// 在较短数组上二分，寻找正确的左右分割位置。
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i;

            long long left1 = i == 0 ? LLONG_MIN : nums1[i - 1];
            long long right1 = i == m ? LLONG_MAX : nums1[i];
            long long left2 = j == 0 ? LLONG_MIN : nums2[j - 1];
            long long right2 = j == n ? LLONG_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) {
                long long leftMax = max(left1, left2);
                if ((m + n) % 2 == 1) return leftMax;

                long long rightMin = min(right1, right2);
                return (leftMax + rightMin) / 2.0;
            }

            if (left1 > right2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    struct TestCase {
        vector<int> nums1;
        vector<int> nums2;
        double expected;
    };

    const vector<TestCase> testCases = {
        {{1, 3}, {2}, 2.0},
        {{1, 2}, {3, 4}, 2.5},
        {{0, 0}, {0, 0}, 0.0},
        {{}, {1}, 1.0},
        {{2}, {}, 2.0},
        {{1, 3, 5}, {2, 4, 6}, 3.5},
        {{-5, -3, -1}, {-2, 0, 4}, -1.5},
        {{1, 2}, {10, 11, 12, 13}, 10.5},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums1 = testCases[i].nums1;
        vector<int> nums2 = testCases[i].nums2;
        double actual = solution.findMedianSortedArrays(nums1, nums2);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
