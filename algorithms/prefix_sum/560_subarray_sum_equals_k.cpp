#include <bits/stdc++.h>
using namespace std;

// 560. 和为 K 的子数组
// 前缀和 + 哈希表：统计每种前缀和出现的次数。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        // 空前缀的和为 0，出现一次，覆盖从下标 0 开始的子数组。
        count[0] = 1;
        int prefix = 0;
        int answer = 0;

        for (int x : nums) {
            prefix += x;
            // 若此前有 prefix-k，则中间部分的和就是 k。
            if (count.count(prefix - k)) answer += count[prefix - k];
            ++count[prefix];
        }
        return answer;
    }
};

int main() {
    const vector<tuple<vector<int>, int, int>> testCases = {
        {{1, 1, 1}, 2, 2},
        {{1, 2, 3}, 3, 2},
        {{1, -1, 0}, 0, 3},
        {{-1, -1, 1}, 0, 1},
        {{}, 0, 0},
        {{0, 0, 0, 0, 0}, 0, 15},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto [nums, k, expected] = testCases[i];
        int actual = solution.subarraySum(nums, k);
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << expected
             << "，实际 = " << actual << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
