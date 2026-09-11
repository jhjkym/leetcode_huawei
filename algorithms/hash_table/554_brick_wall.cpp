#include <bits/stdc++.h>
using namespace std;

// 554. 砖墙
// 每行给出各块砖的宽度，各行总宽度相同。
// 从墙顶到底画一条竖线，返回最少穿过的砖块数。
// 经过砖缝不算穿砖，但不能沿墙的左右外边缘画线。
// 算法：统计内部砖缝位置，答案为行数减去最多对齐的砖缝数。
// 核心实现已完成，16 组固定测例全部通过。
// 掌握状态：不熟悉，待复习。

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m = wall.size();
        unordered_map<long long,int> map;
        for(auto nums : wall){
            long long sum = 0;
            for(int i = 0;i < nums.size()-1;i++){
                sum +=nums[i];
                map[sum]++;
            }
        }
        int result = 0;
        for(auto &[key,value] : map){
            result = max(result,value);
        }
        return m-result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<vector<int>> wall;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}}, 2},
        {{{1}, {1}, {1}}, 3},
        {{{5}}, 1},
        {{{2, 3}}, 0},
        {{{1, 1}, {1, 1}, {1, 1}}, 0},
        {{{1, 2}, {2, 1}}, 1},
        {{{3}, {1, 2}, {2, 1}}, 2},
        {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 0},
        {{{1, 3}, {2, 2}, {3, 1}}, 2},
        {{{2, 2}, {1, 1, 2}, {2, 1, 1}}, 0},
        {{{6}, {6}, {6}, {6}}, 4},
        {{{1, 4}, {1, 2, 2}, {2, 3}, {1, 1, 3}}, 1},
        {{{4, 1}, {2, 2, 1}, {3, 2}, {1, 3, 1}}, 1},
        {{{1, 2, 3}, {3, 3}, {2, 2, 2}, {6}}, 2},
        {{{1000000000, 1000000000}, {1000000000, 1000000000}, {2000000000}}, 1},
        {{{1, 1, 1, 1}, {4}}, 1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        auto wall = testCase.wall;
        const int actual = solution.leastBricks(wall);
        const bool ok = actual == testCase.expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": wall = [";
        for (size_t row = 0; row < testCase.wall.size(); ++row) {
            if (row > 0) cout << ", ";
            cout << '[';
            for (size_t col = 0; col < testCase.wall[row].size(); ++col) {
                if (col > 0) cout << ", ";
                cout << testCase.wall[row][col];
            }
            cout << ']';
        }
        cout << "]，预期 = " << testCase.expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
