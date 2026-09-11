#include <bits/stdc++.h>
using namespace std;

// 57. 插入区间
// intervals 已按起点升序排列，且互不重叠。
// 插入 newInterval，合并重叠区间，返回仍有序且互不重叠的区间数组。
// 区间为闭区间，端点相同也算重叠。无需原地修改。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：左边直接放，中间合成段，右边接着放。
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = static_cast<int>(intervals.size());
        int i = 0;
        int left = newInterval[0], right = newInterval[1];

        // 1. 完全在新区间左边：旧终点 < 新起点。
        while (i < n && intervals[i][1] < left) {
            result.push_back(intervals[i]);
            ++i;
        }

        // 2. 合并重叠区间。左侧已排除，只需检查旧起点 <= 当前右边界。
        while (i < n && intervals[i][0] <= right) {
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
            ++i;
        }
        result.push_back({left, right}); // 合并结束后只加入一次。

        // 3. 剩余区间完全在右边，直接追加。
        while (i < n) {
            result.push_back(intervals[i]);
            ++i;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<vector<int>> intervals;
        vector<int> newInterval;
        vector<vector<int>> expected;
    };
    const vector<TestCase> testCases = {
        {{{1, 3}, {6, 9}}, {2, 5}, {{1, 5}, {6, 9}}},
        {{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}, {{1, 2}, {3, 10}, {12, 16}}},
        {{}, {5, 7}, {{5, 7}}},
        {{{3, 5}, {7, 9}}, {0, 1}, {{0, 1}, {3, 5}, {7, 9}}},
        {{{1, 2}, {4, 5}}, {7, 9}, {{1, 2}, {4, 5}, {7, 9}}},
        {{{1, 2}, {6, 8}}, {3, 4}, {{1, 2}, {3, 4}, {6, 8}}},
        {{{1, 10}}, {3, 5}, {{1, 10}}},
        {{{2, 3}, {5, 7}}, {0, 10}, {{0, 10}}},
        {{{1, 3}}, {1, 3}, {{1, 3}}},
        {{{1, 3}, {6, 8}}, {3, 6}, {{1, 8}}},
        {{{1, 3}}, {3, 5}, {{1, 5}}},
        {{{3, 5}}, {1, 3}, {{1, 5}}},
        {{{1, 3}, {7, 9}}, {5, 5}, {{1, 3}, {5, 5}, {7, 9}}},
        {{{1, 3}}, {2, 2}, {{1, 3}}},
        {{{0, 0}, {2, 2}, {4, 4}}, {0, 4}, {{0, 4}}},
        {{{0, 1}, {99999, 100000}}, {1, 99999}, {{0, 100000}}},
    };

    auto printIntervals = [](const vector<vector<int>>& values) {
        cout << '[';
        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << '[' << values[i][0] << ", " << values[i][1] << ']';
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto intervals = testCase.intervals;
        auto newInterval = testCase.newInterval;
        const auto actual = solution.insert(intervals, newInterval);
        bool ok = actual == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": intervals = ";
        printIntervals(testCase.intervals);
        cout << "，newInterval = [" << testCase.newInterval[0] << ", "
             << testCase.newInterval[1] << "]，预期 = ";
        printIntervals(testCase.expected);
        cout << "，实际 = ";
        printIntervals(actual);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
