#include <bits/stdc++.h>
using namespace std;

// 1. 两数之和
// 算法：哈希表；数据结构：unordered_map。
// 返回数组中和为 target 的两个元素下标；同一元素不能重复使用。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0;i < nums.size();i++){
            int complement = target - nums[i];
            if(map.count(complement)){
                return{i,map[complement]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, int>> testCases = {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
        {{-1, -2, -3, -4, -5}, -8},
        {{0, 4, 3, 0}, 0},
        {{1, 5, 1, 5}, 10},
        {{2, 5, 5, 11}, 10},
        {{1000000000, 1000000000}, 2000000000},
        {{-3, 4, 3, 90}, 0},
        {{5, 75, 25, 10}, 100},
        {{1, 9, 6, 4, 2}, 10},
        {{-10, 8, 12, -2, 3}, 1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, target] = testCases[i];
        auto nums = input;
        const vector<int> actual = solution.twoSum(nums, target);

        const bool validSize = actual.size() == 2;
        const bool validIndex = validSize &&
            actual[0] >= 0 && actual[0] < static_cast<int>(input.size()) &&
            actual[1] >= 0 && actual[1] < static_cast<int>(input.size()) &&
            actual[0] != actual[1];
        const bool validSum = validIndex &&
            static_cast<long long>(input[actual[0]]) + input[actual[1]] == target;
        const bool ok = validSum;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < input.size(); ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << input[j];
        }
        cout << "]，target = " << target << "，返回下标 = [";
        for (size_t j = 0; j < actual.size(); ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << actual[j];
        }
        cout << "]，" << (ok ? "PASS" : "FAIL") << '\n';
        if (!ok) {
            cout << "  下标有效：" << (validIndex ? "是" : "否")
                 << "，两数之和正确：" << (validSum ? "是" : "否") << '\n';
        }
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
