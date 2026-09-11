#include <bits/stdc++.h>
using namespace std;

// 48. 旋转图像
// 将 n×n 矩阵顺时针旋转 90 度，必须原地修改，不能另建矩阵保存旋转结果。
// rotate 返回 void；测试会检查调用后的 matrix。
// 掌握状态：不熟，待复习。14 组固定测例全部通过。
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先沿主对角线转置，再反转每一行，得到顺时针旋转 90 度。
        for(int i = 0;i < matrix.size();i++){
            for(int j = i+1;j <matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0;i < matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;
    };
    const vector<TestCase> testCases = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}},
        {{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
         {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}},
        {{{1}}, {{1}}},
        {{{0}}, {{0}}},
        {{{-7}}, {{-7}}},
        {{{1, 2}, {3, 4}}, {{3, 1}, {4, 2}}},
        {{{-1, -2}, {-3, -4}}, {{-3, -1}, {-4, -2}}},
        {{{0, 1}, {-1, 0}}, {{-1, 0}, {0, 1}}},
        {{{2, 2}, {2, 2}}, {{2, 2}, {2, 2}}},
        {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}}},
        {{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}}, {{3, 2, 1}, {3, 2, 1}, {3, 2, 1}}},
        {{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}}},
        {{{-1000, 1000}, {999, -999}}, {{999, -1000}, {-999, 1000}}},
        {{{-4, -3, -2}, {-1, 0, 1}, {2, 3, 4}}, {{2, -1, -4}, {3, 0, -3}, {4, 1, -2}}},
    };

    auto printMatrix = [](const vector<vector<int>>& matrix) {
        cout << '[';
        for (size_t r = 0; r < matrix.size(); ++r) {
            if (r > 0) cout << ", ";
            cout << '[';
            for (size_t c = 0; c < matrix[r].size(); ++c) {
                if (c > 0) cout << ", ";
                cout << matrix[r][c];
            }
            cout << ']';
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto matrix = testCase.input;
        solution.rotate(matrix);
        bool ok = matrix == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": matrix = ";
        printMatrix(testCase.input);
        cout << "，预期 = ";
        printMatrix(testCase.expected);
        cout << "，实际 = ";
        printMatrix(matrix);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
