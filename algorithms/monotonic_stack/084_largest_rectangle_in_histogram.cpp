#include <bits/stdc++.h>
using namespace std;

// 84. 柱状图中最大的矩形
// 单调递增栈：遇到更矮柱子时，计算被弹柱子能扩展的最大宽度。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;
        int n = heights.size();
        int ans = 0;

        for (int i = 0; i <= n; ++i) {
            int currentHeight = i == n ? 0 : heights[i];

            while (!indices.empty() &&
                   currentHeight < heights[indices.top()]) {
                int height = heights[indices.top()];
                indices.pop();
                int width = indices.empty() ? i : i - indices.top() - 1;
                ans = max(ans, height * width);
            }
            indices.push(i);
        }
        return ans;
    }
};

int main() {
    const vector<pair<vector<int>, int>> testCases = {
        {{2, 1, 5, 6, 2, 3}, 10},
        {{2, 4}, 4},
        {{1}, 1},
        {{0}, 0},
        {{2, 2, 2}, 6},
        {{1, 2, 3, 4, 5}, 9},
        {{5, 4, 3, 2, 1}, 9},
        {{2, 1, 2}, 3},
        {{}, 0},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> heights = testCases[i].first;
        int actual = solution.largestRectangleArea(heights);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].second
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
