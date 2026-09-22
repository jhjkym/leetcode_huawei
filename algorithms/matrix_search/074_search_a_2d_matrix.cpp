#include <bits/stdc++.h>
using namespace std;

// 74. 搜索二维矩阵
// 把矩阵看成一维升序数组，再进行二分查找。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int value = matrix[mid / n][mid % n];

            if (value < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left < m * n && matrix[left / n][left % n] == target;
    }
};

int main() {
    struct TestCase {
        vector<vector<int>> matrix;
        int target;
        bool expected;
    };

    const vector<TestCase> testCases = {
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3, true},
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13, false},
        {{{1}}, 1, true},
        {{{1}}, 0, false},
        {{{1, 3, 5}}, 5, true},
        {{{1}, {3}, {5}}, 3, true},
        {{{-5, -2, 0}, {3, 8, 10}}, -2, true},
        {{}, 1, false},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<vector<int>> matrix = testCases[i].matrix;
        bool actual = solution.searchMatrix(matrix, testCases[i].target);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha
             << testCases[i].expected << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
