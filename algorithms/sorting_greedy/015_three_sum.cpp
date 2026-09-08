#include <bits/stdc++.h>
using namespace std;

// 15. 三数之和
// 算法：排序、双指针；数据结构：数组。
// 找出所有和为 0 且不重复的三元组。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-2;i++){
            if(nums[i] > 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1,right = nums.size()-1;
            while(left < right){
                int sum = nums[i]+ nums[left]+nums[right];
                if(sum == 0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]){
                        left ++;
                    }
                    while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left ++;
                    right --;
                }else if(sum < 0){
                    left ++;
                }else{
                    right --;
                }
            } 
        }
        return ans;
    }
};

static vector<vector<int>> normalize(vector<vector<int>> triples) {
    for (auto& triple : triples) {
        sort(triple.begin(), triple.end());
    }
    sort(triples.begin(), triples.end());
    return triples;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
        {{0, 1, 1}, {}},
        {{0, 0, 0}, {{0, 0, 0}}},
        {{1, 1, 1}, {}},
        {{1, 2, 4}, {}},
        {{-2, 0, 0, 2, 2}, {{-2, 0, 2}}},
        {{-2, -1, 0, 1, 2}, {{-2, 0, 2}, {-1, 0, 1}}},
        {{-1, -1, -1, 2, 2}, {{-1, -1, 2}}},
        {{1, -1, -1, 0}, {{-1, 0, 1}}},
        {{-5, 2, 3, 0, 2}, {{-5, 2, 3}}},
        {{-3, -3, 0, 3, 3}, {{-3, 0, 3}}},
        {{-4, -2, 0, 2, 4}, {{-4, 0, 4}, {-2, 0, 2}}},
    };

    const auto printTriples = [](const vector<vector<int>>& triples) {
        cout << '[';
        for (size_t i = 0; i < triples.size(); ++i) {
            if (i > 0) {
                cout << ", ";
            }
            cout << '[';
            for (size_t j = 0; j < triples[i].size(); ++j) {
                if (j > 0) {
                    cout << ", ";
                }
                cout << triples[i][j];
            }
            cout << ']';
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        const auto& input = testCase.first;
        const auto& expected = testCase.second;
        auto nums = input;
        const auto actual = normalize(solution.threeSum(nums));
        const auto normalizedExpected = normalize(expected);
        const bool ok = actual == normalizedExpected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = ";
        printTriples({input});
        cout << "，预期 = ";
        printTriples(normalizedExpected);
        cout << "，实际 = ";
        printTriples(actual);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
