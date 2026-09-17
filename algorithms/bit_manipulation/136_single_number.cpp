#include <bits/stdc++.h>
using namespace std;

// 136. 只出现一次的数字
// 非空整数数组中，只有一个元素出现一次，其余每个元素都恰好出现两次。
// 返回只出现一次的元素，要求时间复杂度 O(n)、额外空间 O(1)。
// 核心实现已完成，16 组固定测例全部通过。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            ans ^=num;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, int>> testCases = {
        {{2, 2, 1}, 1},
        {{4, 1, 2, 1, 2}, 4},
        {{1}, 1},
        {{0}, 0},
        {{-7}, -7},
        {{0, 3, 3}, 0},
        {{0, 0, 5}, 5},
        {{-1, -1, -2}, -2},
        {{-2, 3, 3}, -2},
        {{6, 2, 2, 4, 4}, 6},
        {{2, 2, 6, 4, 4}, 6},
        {{2, 4, 2, 4, 6}, 6},
        {{1, 2, 3, 2, 1}, 3},
        {{30000, -30000, 30000}, -30000},
        {{-30000, 0, -30000}, 0},
        {{8, -4, 0, 8, 7, -4, 7}, 0},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto nums = input;
        const int actual = solution.singleNumber(nums);
        const bool ok = actual == expected;
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
