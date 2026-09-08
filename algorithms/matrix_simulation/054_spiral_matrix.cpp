#include <bits/stdc++.h>
using namespace std;

// 54. 螺旋矩阵
// 算法：矩阵边界模拟；数据结构：二维数组、结果数组。
// 按顺时针方向返回矩阵中的所有元素。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // TODO: 在这里填写核心实现。
        int m = matrix.size(),n = matrix[0].size();
        int top = 0,bottom = m-1,left = 0,right = n-1;
        vector<int> ans;
        while(top <= bottom && left <= right){
            for(int j = left;j <=right;j++){
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int i = top;i<= bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right -- ;
            if(top <= bottom){
                for(int j = right;j>=left;j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom --;
            }
            if(left <= right){
                for(int i = bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left ++;
            }
        }

        return ans; // 占位返回值，完成实现后替换。
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<vector<int>>, vector<int>>> testCases = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
         {1, 2, 3, 6, 9, 8, 7, 4, 5}},
        {{{1, 2, 3, 4}, {5, 6, 7, 8}},
         {1, 2, 3, 4, 8, 7, 6, 5}},
        {{{1, 2, 3}}, {1, 2, 3}},
        {{{1}, {2}, {3}}, {1, 2, 3}},
        {{{1}}, {1}},
        {{{1, 2}, {3, 4}}, {1, 2, 4, 3}},
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
         {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}},
         {1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8}},
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
         {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10}},
        {{{1, 2, 3, 4, 5}}, {1, 2, 3, 4, 5}},
        {{{1}, {2}, {3}, {4}, {5}}, {1, 2, 3, 4, 5}},
        {{{-1, 0, 1}, {-2, -3, 2}}, {-1, 0, 1, 2, -3, -2}},
    };

    const auto printVector = [](const vector<int>& values) {
        cout << '[';
        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) {
                cout << ", ";
            }
            cout << values[i];
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto matrix = testCase.first;
        const auto& expected = testCase.second;
        const auto actual = solution.spiralOrder(matrix);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": 预期 = ";
        printVector(expected);
        cout << "，实际 = ";
        printVector(actual);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
