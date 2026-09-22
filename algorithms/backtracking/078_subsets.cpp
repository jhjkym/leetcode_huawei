#include <bits/stdc++.h>
using namespace std;

// 78. 子集
// 回溯：每个递归节点的当前路径都是一个子集。
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(nums, 0, path, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& path,
                   vector<vector<int>>& ans) {
        ans.push_back(path);

        int n = nums.size();
        for (int i = start; i < n; ++i) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, ans);
            path.pop_back();
        }
    }
};

int main() {
    struct TestCase {
        vector<int> nums;
        vector<vector<int>> expected;
    };

    const vector<TestCase> testCases = {
        {{1, 2, 3}, {{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}}},
        {{0}, {{}, {0}}},
        {{}, {{}}},
        {{1, 2}, {{}, {1}, {1, 2}, {2}}},
        {{-1, 2}, {{}, {-1}, {-1, 2}, {2}}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].nums;
        vector<vector<int>> actual = solution.subsets(nums);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期子集数 = "
             << testCases[i].expected.size() << "，实际子集数 = "
             << actual.size() << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
