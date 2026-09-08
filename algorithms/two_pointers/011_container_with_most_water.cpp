#include <bits/stdc++.h>
using namespace std;

// 11. 盛最多水的容器
// 算法：双指针；数据结构：数组。
// 选择两条竖线与横轴组成容器，返回能够容纳的最大水量。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size()-1;
        int maxWater = 0;
        while(left < right){
            int water = min(height[left],height[right])*(right - left);
            maxWater = max(water,maxWater);
            if(height[left] < height[right]){
                left ++;
            }else{
                right --;
            }
        }

        return maxWater;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, int>> testCases = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
        {{1, 1}, 1},
        {{0, 0}, 0},
        {{0, 0, 0, 0}, 0},
        {{4, 4, 4, 4}, 12},
        {{1, 2, 3, 4, 5}, 6},
        {{5, 4, 3, 2, 1}, 6},
        {{1, 2, 1}, 2},
        {{4, 3, 2, 1, 4}, 16},
        {{2, 3, 10, 5, 7, 8, 9}, 36},
        {{0, 5, 0, 0, 5, 0}, 15},
        {{1, 100, 100, 1}, 100},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto height = input;
        const int actual = solution.maxArea(height);
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
