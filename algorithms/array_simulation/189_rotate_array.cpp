#include <bits/stdc++.h>
using namespace std;

// 189. 轮转数组
// 三次翻转：整体翻转，再分别翻转前 k 个和剩余元素。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    const vector<tuple<vector<int>, int, vector<int>>> testCases = {
        {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
        {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
        {{1, 2}, 3, {2, 1}},
        {{1}, 10, {1}},
        {{1, 2, 3}, 0, {1, 2, 3}},
        {{1, 2, 3}, 3, {1, 2, 3}},
        {{1, 2, 3}, 4, {3, 1, 2}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto [nums, k, expected] = testCases[i];
        solution.rotate(nums, k);
        bool ok = nums == expected;
        passed += ok;

        cout << "用例 " << i + 1 << "：k = " << k << "，预期 = [";
        for (size_t j = 0; j < expected.size(); ++j) {
            cout << (j ? ", " : "") << expected[j];
        }
        cout << "]，实际 = [";
        for (size_t j = 0; j < nums.size(); ++j) {
            cout << (j ? ", " : "") << nums[j];
        }
        cout << "]，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
