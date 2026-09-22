#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tests = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 1, 5},
        {1},
        {1, 3, 2},
        {2, 3, 1},
        {1, 5, 1},
        {2, 2, 0, 4, 3, 1}
    };
    vector<vector<int>> expected = {
        {1, 3, 2},
        {1, 2, 3},
        {1, 5, 1},
        {1},
        {2, 1, 3},
        {3, 1, 2},
        {5, 1, 1},
        {2, 2, 1, 0, 3, 4}
    };

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        solution.nextPermutation(tests[i]);
        bool ok = tests[i] == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
