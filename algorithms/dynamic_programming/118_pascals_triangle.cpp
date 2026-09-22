#include <bits/stdc++.h>
using namespace std;

// 118. 杨辉三角
// 每行两端是 1，中间元素等于上一行相邻两个元素之和。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            triangle.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] +
                                 triangle[i - 1][j];
            }
        }
        return triangle;
    }
};

int main() {
    using Triangle = vector<vector<int>>;
    const vector<pair<int, Triangle>> testCases = {
        {1, {{1}}},
        {2, {{1}, {1, 1}}},
        {5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}},
        {3, {{1}, {1, 1}, {1, 2, 1}}},
        {0, {}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        Triangle actual = solution.generate(testCases[i].first);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
