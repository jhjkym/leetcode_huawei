#include <bits/stdc++.h>
using namespace std;

// 240. 搜索二维矩阵 II
// 每行从左到右升序，每列从上到下升序，判断 target 是否存在。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：右上开始走，小了向下，大了向左。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int row = 0;
        int col = static_cast<int>(matrix[0].size()) - 1;
        while (row < static_cast<int>(matrix.size()) && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) ++row;
            else --col;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    struct TestCase { vector<vector<int>> matrix; int target; bool expected; };
    const vector<TestCase> testCases = {
        {{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 5, true},
        {{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 20, false},
        {{{1}}, 1, true},
        {{{1}}, 2, false},
        {{{1,2},{3,4}}, 3, true},
        {{{1,2},{3,4}}, 5, false},
        {{{-5,-2,0},{-3,1,4},{2,6,9}}, -3, true},
        {{{-5,-2,0},{-3,1,4},{2,6,9}}, 7, false},
        {{{1,2,3,4}}, 4, true}, {{{1,2,3,4}}, 0, false},
        {{{1},{2},{3},{4}}, 3, true}, {{{1},{2},{3},{4}}, 5, false},
        {{{1,1,1},{1,1,1}}, 1, true},
        {{{1,3,5},{7,9,11},{13,15,17}}, 15, true},
        {{{1,3,5},{7,9,11},{13,15,17}}, 8, false},
        {{{-1000000000,0},{1,1000000000}}, 1000000000, true},
    };
    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto matrix = testCases[i].matrix;
        bool actual = solution.searchMatrix(matrix, testCases[i].target);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": target = " << testCases[i].target
             << "，预期 = " << boolalpha << testCases[i].expected
             << "，实际 = " << actual << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
