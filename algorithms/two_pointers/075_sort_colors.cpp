#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int i = 0;
        int right = nums.size() - 1;

        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tests = {
        {2, 0, 2, 1, 1, 0},
        {2, 0, 1},
        {0},
        {1},
        {2},
        {0, 0, 1, 1, 2, 2},
        {2, 2, 1, 1, 0, 0},
        {1, 2, 0, 1, 2, 0, 1}
    };
    vector<vector<int>> expected = {
        {0, 0, 1, 1, 2, 2},
        {0, 1, 2},
        {0},
        {1},
        {2},
        {0, 0, 1, 1, 2, 2},
        {0, 0, 1, 1, 2, 2},
        {0, 0, 1, 1, 1, 2, 2}
    };

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        solution.sortColors(tests[i]);
        bool ok = tests[i] == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
