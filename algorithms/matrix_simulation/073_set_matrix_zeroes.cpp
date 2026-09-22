#include <bits/stdc++.h>
using namespace std;

// 73. 矩阵置零
// 用首行和首列充当标记数组，额外空间复杂度为 O(1)。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) firstRow = true;
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) firstCol = true;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRow) fill(matrix[0].begin(), matrix[0].end(), 0);
        if (firstCol) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};

int main() {
    using Matrix = vector<vector<int>>;
    const vector<pair<Matrix, Matrix>> testCases = {
        {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
         {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}},
        {{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
         {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}},
        {{{1}}, {{1}}},
        {{{0}}, {{0}}},
        {{{1, 0, 3}}, {{0, 0, 0}}},
        {{{1}, {0}, {3}}, {{0}, {0}, {0}}},
        {{{1, 2}, {3, 4}}, {{1, 2}, {3, 4}}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        Matrix matrix = testCases[i].first;
        const Matrix& expected = testCases[i].second;
        solution.setZeroes(matrix);
        bool ok = matrix == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
