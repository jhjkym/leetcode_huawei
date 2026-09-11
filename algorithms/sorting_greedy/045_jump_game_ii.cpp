#include <bits/stdc++.h>
using namespace std;

// 45. 跳跃游戏 II
// nums[i] 表示从下标 i 最多能向右跳多少步，返回到达末尾的最少跳跃次数。
// 输入保证能到达末尾；只有一个元素时不需要跳跃。
// 掌握状态：不熟，待复习。核心实现已完成，16 组固定测例全部通过。
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int count = 0;
        int maxLength = 0;
        for(int i = 0;i < nums.size()-1;i++){
            maxLength = max(maxLength,i+nums[i]);
            if(i == end){
                end = maxLength;
                count ++;
            }
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector<pair<vector<int>, int>> testCases = {
        {{2, 3, 1, 1, 4}, 2},
        {{2, 3, 0, 1, 4}, 2},
        {{0}, 0},
        {{5}, 0},
        {{1, 0}, 1},
        {{1, 1, 1, 1}, 3},
        {{4, 0, 0, 0, 0}, 1},
        {{10, 0, 0}, 1},
        {{2, 0, 2, 0, 1}, 2},
        {{1, 2, 0, 1}, 2},
        {{3, 2, 1, 1, 4}, 2},
        {{2, 2, 2, 2, 2}, 2},
        {{1, 1, 1, 1, 1, 1}, 5},
        {{2, 3, 1}, 1},
        {{1, 3, 1, 1, 1, 1}, 3},
        {{2, 1, 1, 1, 1}, 3},
    };
    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto nums = input;
        int actual = solution.jump(nums);
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < input.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << input[j];
        }
        cout << "]，预期 = " << expected << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
