#include <bits/stdc++.h>
using namespace std;

// 46. 全排列
// 算法：回溯；数据结构：路径数组、使用标记。
// 返回给定互不相同数字的全部排列。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    void backtracking(vector<int> &path,vector<int>& nums,vector<vector<int>> &ans,vector<bool> &used){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return ;
        }
        for(int i = 0;i < nums.size();i++){
            if(used[i] == true){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(path,nums,ans,used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        vector<bool>used(nums.size(),false);
        backtracking(path,nums,ans,used);
        return ans;
    }
};

static vector<vector<int>> normalize(vector<vector<int>> permutations) {
    sort(permutations.begin(), permutations.end());
    return permutations;
}

static vector<vector<int>> expectedPermutations(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> expected;
    do {
        expected.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return expected;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<vector<int>> testCases = {
        {1, 2, 3},
        {0, 1},
        {7},
        {-1, 0, 1},
        {1, 2, 3, 4},
        {2, 5},
        {-2, -1},
        {3, 0, -1},
        {10, 20, 30},
        {1, 4, 2},
        {0, -1, 2},
        {-3, 1, 5},
    };

    const auto printVector = [](const vector<int>& values) {
        cout << '[';
        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) {
                cout << ", ";
            }
            cout << values[i];
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& input = testCases[i];
        auto nums = input;
        const auto actual = normalize(solution.permute(nums));
        const auto expected = expectedPermutations(input);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = ";
        printVector(input);
        cout << "，预期排列数 = " << expected.size()
             << "，实际排列数 = " << actual.size()
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
