#include <bits/stdc++.h>
using namespace std;

// 239. 滑动窗口最大值
// 大小为 k 的窗口从数组左端逐次向右移动一位，返回每个窗口的最大值。
// 输入保证 1 <= k <= nums.size()。练习目标：O(n) 时间复杂度。
// 掌握状态：忘记做法，已提供答案模板，待复习背诵。
// 口诀：队头去过期，队尾去小值；下标入队尾，窗满取队头。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 存下标；下标递增，对应数值从队头到队尾递减。
        vector<int> result;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            // 当前窗口左边界为 i-k+1，下标 <= i-k 的元素已经过期。
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 新元素更大或相等，而且更晚过期，队尾旧元素不再有用。
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // 第一个完整窗口的右边界是 k-1；队头对应窗口最大值。
            if (i >= k - 1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<int> nums;
        int k;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7}},
        {{1}, 1, {1}},
        {{1, -1}, 1, {1, -1}},
        {{9, 11}, 2, {11}},
        {{4, -2}, 2, {4}},
        {{1, 2, 3, 4, 5}, 3, {3, 4, 5}},
        {{5, 4, 3, 2, 1}, 3, {5, 4, 3}},
        {{2, 2, 2, 2}, 2, {2, 2, 2}},
        {{-4, -2, -5, -1}, 2, {-2, -2, -1}},
        {{0, 0, 0}, 2, {0, 0}},
        {{2, 1, 2, 1, 2}, 3, {2, 2, 2}},
        {{9, 1, 2, 3}, 2, {9, 2, 3}},
        {{1, 3, 1, 2, 0, 5}, 3, {3, 3, 2, 5}},
        {{4, 1, 7, 3, 2}, 5, {7}},
        {{-10000, 10000, -10000}, 2, {10000, 10000}},
        {{7, 2, 4}, 2, {7, 4}},
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
        const TestCase& testCase = testCases[i];
        auto nums = testCase.nums;
        const vector<int> actual = solution.maxSlidingWindow(nums, testCase.k);
        const bool ok = actual == testCase.expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = ";
        printVector(testCase.nums);
        cout << "，k = " << testCase.k << "，预期 = ";
        printVector(testCase.expected);
        cout << "，实际 = ";
        printVector(actual);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
