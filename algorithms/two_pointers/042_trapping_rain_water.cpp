#include <bits/stdc++.h>
using namespace std;

// 42. 接雨水
// 算法：双指针 / 前后缀最大值；数据结构：数组。
// 返回柱状图下雨后能够接住的总雨水量。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0,right = height.size()-1;
        int leftMax = 0,rightMax = 0;
        int water = 0;
        while(left < right){
            if(height[left] < height[right]){
                leftMax = max(leftMax,height[left]);
                water+=leftMax-height[left];
                left ++;
            }else{
                rightMax = max(rightMax,height[right]);
                water+=rightMax-height[right];
                right--;
            }
        }
        return water;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, int>> testCases = {
        {{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
        {{4, 2, 0, 3, 2, 5}, 9},
        {{}, 0},
        {{1}, 0},
        {{1, 2, 3}, 0},
        {{3, 2, 1}, 0},
        {{2, 0, 2}, 2},
        {{3, 0, 1, 3, 0, 5}, 8},
        {{5, 4, 1, 2}, 1},
        {{1, 0, 2, 1, 0, 1, 3}, 5},
        {{0, 1, 0, 1, 0}, 1},
        {{2, 1, 0, 1, 2}, 4},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto height = input;
        const int actual = solution.trap(height);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": height = [";
        for (size_t j = 0; j < input.size(); ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << input[j];
        }
        cout << "]，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
