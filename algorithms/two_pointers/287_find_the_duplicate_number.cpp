#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tests = {
        {1, 3, 4, 2, 2},
        {3, 1, 3, 4, 2},
        {3, 3, 3, 3, 3},
        {1, 1},
        {1, 1, 2},
        {2, 1, 2},
        {4, 3, 1, 4, 2},
        {2, 5, 9, 6, 9, 3, 8, 9, 7, 1}
    };
    vector<int> expected = {2, 3, 3, 1, 1, 2, 4, 9};

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        int result = solution.findDuplicate(tests[i]);
        bool ok = result == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
