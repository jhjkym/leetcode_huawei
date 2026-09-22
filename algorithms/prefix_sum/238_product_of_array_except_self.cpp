#include <bits/stdc++.h>
using namespace std;

// 238. 除了自身以外数组的乘积
// 答案数组保存前缀积，再从右向左乘上后缀积。
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};

int main() {
    const vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 2, 3, 4}, {24, 12, 8, 6}},
        {{-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}},
        {{2, 3}, {3, 2}},
        {{0, 1, 2, 3}, {6, 0, 0, 0}},
        {{0, 0, 2}, {0, 0, 0}},
        {{-1, -2, -3}, {6, 3, 2}},
        {{1, 1, 1, 1}, {1, 1, 1, 1}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].first;
        const vector<int>& expected = testCases[i].second;
        vector<int> actual = solution.productExceptSelf(nums);
        bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << "：预期 = [";
        for (size_t j = 0; j < expected.size(); ++j) {
            cout << (j ? ", " : "") << expected[j];
        }
        cout << "]，实际 = [";
        for (size_t j = 0; j < actual.size(); ++j) {
            cout << (j ? ", " : "") << actual[j];
        }
        cout << "]，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
