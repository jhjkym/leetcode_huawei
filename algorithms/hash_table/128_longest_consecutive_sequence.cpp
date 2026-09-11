#include <bits/stdc++.h>
using namespace std;

// 128. 最长连续序列
// 给定未排序的整数数组，返回数值连续的最长序列长度。
// 序列元素不要求在原数组中相邻，重复数字不增加长度。
// 算法：哈希集合去重，只从没有前驱的数字开始查找连续序列。
// 平均时间复杂度 O(n)，空间复杂度 O(n)。16 组固定测例全部通过。

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;
        unordered_set<int> set(nums.begin(),nums.end());
        for(int num : set){
            if(set.count(num - 1)){
                continue;
            }
            int cur = num;
            int length = 1;
            while(set.count(cur+1)){
                length ++;
                cur++;
            }
            maxLength = max(maxLength,length);
        }
        return maxLength;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, int>> testCases = {
        {{100, 4, 200, 1, 3, 2}, 4},
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
        {{1, 0, 1, 2}, 3},
        {{}, 0},
        {{7}, 1},
        {{2, 2, 2}, 1},
        {{1, 3, 5, 7}, 1},
        {{1, 2, 3, 4, 5}, 5},
        {{5, 4, 3, 2, 1}, 5},
        {{-4, -2, -3, -1}, 4},
        {{-2, 0, -1, 1, 3}, 4},
        {{10, 11, 12, 1, 2, 3, 4}, 4},
        {{1, 2, 10, 11}, 2},
        {{1, 2, 2, 3, 3, 4}, 4},
        {{-1000000000, -999999999, 999999999, 1000000000}, 2},
        {{8, 1, 6, 3, 5, 2, 4, 7}, 8},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto nums = input;
        const int actual = solution.longestConsecutive(nums);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < input.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << input[j];
        }
        cout << "]，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
