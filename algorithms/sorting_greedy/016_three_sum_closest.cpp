#include <bits/stdc++.h>
using namespace std;

// 16. 最接近的三数之和
// 选取三个不同下标的元素，返回与 target 最接近的三数之和。
// 返回的是和，不是三个元素；题目保证最接近的和唯一。
// 算法：排序后固定一个数，另外两个数用双指针寻找。
// 核心实现已完成，16 组固定测例全部通过。

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int best = nums[0]+nums[1]+nums[2];
        for(int i = 0;i < nums.size()-2;i++){
            int left = i+1,right = nums.size()-1;
            while(left < right){
                int sum = nums[i]+nums[left] + nums[right];
                if(sum == target){
                    return sum;
                }else if(abs(sum - target) < abs(best - target)){
                    best = sum;
                }
                if(sum < target){
                    left ++;
                }else{
                    right --;
                }
            }
        }
        return best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<int> nums;
        int target;
        int expected;
    };
    const vector<TestCase> testCases = {
        {{-1, 2, 1, -4}, 1, 2},
        {{0, 0, 0}, 1, 0},
        {{1, 2, 3}, 100, 6},
        {{-3, -2, -1}, -10, -6},
        {{1, 2, 3, 4}, 6, 6},
        {{1, 2, 3, 4}, 20, 9},
        {{1, 2, 3, 4}, -10, 6},
        {{2, 2, 2, 2}, 5, 6},
        {{-8, -5, -3, -1}, -10, -9},
        {{-5, -2, 0, 3, 8}, 1, 1},
        {{0, 0, 0, 1}, 2, 1},
        {{-2, -2, 1, 1, 4}, 0, 0},
        {{-1000, -1000, -1000, 1000}, 10000, -1000},
        {{1000, 1000, 1000, -1000}, -10000, 1000},
        {{5, 4, 3, 2, 1}, 11, 11},
        {{-4, -1, 1, 2, 7}, 11, 10},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto nums = testCase.nums;
        const int actual = solution.threeSumClosest(nums, testCase.target);
        const bool ok = actual == testCase.expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < testCase.nums.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << testCase.nums[j];
        }
        cout << "]，target = " << testCase.target
             << "，预期 = " << testCase.expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
