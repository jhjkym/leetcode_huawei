#include <bits/stdc++.h>
using namespace std;

// 39. 组合总和
// 回溯：从 start 开始选；数字可以重复使用，下一层仍从 i 开始。
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(candidates, target, 0, path, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        int n = candidates.size();
        for (int i = start; i < n && candidates[i] <= target; ++i) {
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }
};

int main() {
    struct TestCase {
        vector<int> candidates;
        int target;
        vector<vector<int>> expected;
    };

    const vector<TestCase> testCases = {
        {{2, 3, 6, 7}, 7, {{2, 2, 3}, {7}}},
        {{2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}},
        {{2}, 1, {}},
        {{1}, 2, {{1, 1}}},
        {{2, 4, 8}, 8, {{2, 2, 2, 2}, {2, 2, 4}, {4, 4}, {8}}},
        {{7, 3, 2}, 7, {{2, 2, 3}, {7}}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> candidates = testCases[i].candidates;
        vector<vector<int>> actual =
            solution.combinationSum(candidates, testCases[i].target);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期组合数 = "
             << testCases[i].expected.size() << "，实际组合数 = "
             << actual.size() << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
