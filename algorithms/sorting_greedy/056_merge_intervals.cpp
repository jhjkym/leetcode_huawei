#include <bits/stdc++.h>
using namespace std;

// 56. 合并区间
// 算法：排序、贪心；数据结构：区间数组。
// 合并所有有重叠的区间；端点相等也视为重叠。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(auto &interval :intervals){
            if(!ans.empty()&&interval[0]<= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1],interval[1]);
            }else{
                ans.push_back(interval);
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<vector<int>>, vector<vector<int>>>> testCases = {
        {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
        {{{1, 4}, {4, 5}}, {{1, 5}}},
        {vector<vector<int>>{}, vector<vector<int>>{}},
        {{{1, 4}}, {{1, 4}}},
        {{{1, 10}, {2, 3}}, {{1, 10}}},
        {{{1, 2}, {3, 4}}, {{1, 2}, {3, 4}}},
        {{{5, 7}, {1, 3}, {2, 6}}, {{1, 7}}},
        {{{1, 5}, {2, 3}, {4, 8}}, {{1, 8}}},
        {{{-5, -1}, {-3, 2}, {4, 6}}, {{-5, 2}, {4, 6}}},
        {{{1, 100}, {2, 3}, {50, 60}}, {{1, 100}}},
        {{{1, 2}, {2, 2}, {2, 5}}, {{1, 5}}},
        {{{6, 8}, {1, 9}, {2, 4}, {4, 7}}, {{1, 9}}},
    };

    const auto printIntervals = [](const vector<vector<int>>& intervals) {
        cout << '[';
        for (size_t i = 0; i < intervals.size(); ++i) {
            if (i > 0) {
                cout << ", ";
            }
            cout << '[' << intervals[i][0] << ", " << intervals[i][1] << ']';
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto intervals = input;
        const auto actual = solution.merge(intervals);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": intervals = ";
        printIntervals(input);
        cout << "，预期 = ";
        printIntervals(expected);
        cout << "，实际 = ";
        printIntervals(actual);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
