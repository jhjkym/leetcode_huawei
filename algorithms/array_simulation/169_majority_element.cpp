#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tests = {
        {3, 2, 3},
        {2, 2, 1, 1, 1, 2, 2},
        {1},
        {1, 1},
        {-1, -1, 2},
        {6, 5, 5},
        {4, 4, 2, 4, 3, 4, 4},
        {0, 0, 1, 0, 2}
    };
    vector<int> expected = {3, 2, 1, 1, -1, 5, 4, 0};

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        int result = solution.majorityElement(tests[i]);
        bool ok = result == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
