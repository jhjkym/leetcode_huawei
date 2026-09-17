#include <bits/stdc++.h>
using namespace std;

// 88. 合并两个有序数组
// nums1 长度为 m+n，前 m 个数有效，末尾 n 个零为预留空间。
// nums2 包含 n 个有效元素，两个有效序列都按非递减顺序排列。
// merge 返回 void，直接修改 nums1；零也可以是有效数据，重复元素需保留。
// 算法：从后往前合并，时间 O(m+n)，辅助空间 O(1)。
// 口诀：两尾比大小，大的往后放；二号没放完，循环不能停。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tail = m + n - 1;
        // nums2 放完后，nums1 剩余的元素已在正确位置。
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[tail--] = nums1[i--];
            } else {
                nums1[tail--] = nums2[j--];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<int> nums1;
        int m;
        vector<int> nums2;
        int n;
        vector<int> expected;
    };
    const vector<TestCase> testCases = {
        {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
        {{1}, 1, {}, 0, {1}},
        {{0}, 0, {1}, 1, {1}},
        {{0, 0, 0}, 0, {-2, 0, 4}, 3, {-2, 0, 4}},
        {{-1, 0, 0, 3}, 4, {}, 0, {-1, 0, 0, 3}},
        {{4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3, {1, 2, 3, 4, 5, 6}},
        {{1, 2, 3, 0, 0}, 3, {4, 5}, 2, {1, 2, 3, 4, 5}},
        {{2, 2, 0, 0}, 2, {2, 2}, 2, {2, 2, 2, 2}},
        {{0, 0, 0, 0}, 2, {0, 0}, 2, {0, 0, 0, 0}},
        {{-3, -1, 0}, 2, {-2}, 1, {-3, -2, -1}},
        {{-5, 0, 3, 0, 0, 0}, 3, {-2, 0, 4}, 3, {-5, -2, 0, 0, 3, 4}},
        {{3, 0, 0, 0, 0}, 1, {1, 2, 4, 5}, 4, {1, 2, 3, 4, 5}},
        {{1, 2, 4, 5, 0}, 4, {3}, 1, {1, 2, 3, 4, 5}},
        {{-1000000000, 1000000000, 0, 0}, 2, {-1000000000, 1000000000}, 2,
         {-1000000000, -1000000000, 1000000000, 1000000000}},
        {{2, 0}, 1, {1}, 1, {1, 2}},
        {{1, 3, 3, 0, 0, 0}, 3, {2, 3, 4}, 3, {1, 2, 3, 3, 3, 4}},
    };

    auto printVector = [](const vector<int>& values) {
        cout << '[';
        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << values[i];
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto nums1 = testCase.nums1;
        auto nums2 = testCase.nums2;
        solution.merge(nums1, testCase.m, nums2, testCase.n);
        bool ok = nums1 == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": nums1 = ";
        printVector(testCase.nums1);
        cout << "，m = " << testCase.m << "，nums2 = ";
        printVector(testCase.nums2);
        cout << "，n = " << testCase.n << "，预期 = ";
        printVector(testCase.expected);
        cout << "，实际 = ";
        printVector(nums1);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
