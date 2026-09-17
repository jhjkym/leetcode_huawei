#include <bits/stdc++.h>
using namespace std;

// 162. 寻找峰值
// 峰值元素严格大于它相邻的元素；边界外的元素视为负无穷。
// 返回任意一个峰值下标，要求时间复杂度 O(log n)。
// 核心实现已完成，16 组固定测例全部通过。
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 二分比较 mid 与 mid+1，向上坡方向收缩。
        int left = 0,right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[mid+1]){
                left = mid +1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    struct TestCase { vector<int> nums; int expected; };
    const vector<TestCase> testCases = {
        {{1, 2, 3, 1}, 2},
        {{1, 2, 1, 0, -1}, 1},
        {{1}, 0},
        {{1, 2}, 1},
        {{2, 1}, 0},
        {{1, 0, 2}, 2},
        {{2, 1, 0}, 0},
        {{1, 2, 3, 4, 5}, 4},
        {{5, 4, 3, 2, 1}, 0},
        {{1, 3, 2, 1}, 1},
        {{1, 2, 1, 0, -1}, 1},
        {{-3, -2, -1, -2}, 2},
        {{-1, -2, -3}, 0},
        {{0, -1, 1, 0}, 2},
        {{-5, -4, -6, -7}, 1},
        {{1000000000, 999999999}, 0},
    };
    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto nums = testCase.nums;
        int actual = solution.findPeakElement(nums);
        bool valid = actual >= 0 && actual < static_cast<int>(nums.size()) &&
                     (actual == 0 || nums[actual] > nums[actual - 1]) &&
                     (actual + 1 == static_cast<int>(nums.size()) || nums[actual] > nums[actual + 1]);
        bool ok = valid && actual == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < testCase.nums.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << testCase.nums[j];
        }
        cout << "]，预期下标 = " << testCase.expected
             << "，实际下标 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
