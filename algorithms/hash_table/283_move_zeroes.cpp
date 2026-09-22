#include <bits/stdc++.h>
using namespace std;

// 283. 移动零
// 将所有 0 移动到数组末尾，同时保持非零元素的相对顺序。
// 算法：用 write 指向下一个非零元素应写入的位置，扫描并交换。
// 时间复杂度 O(n)，空间复杂度 O(1)。

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[fast], nums[slow++]);
            }
        }
    }
};

static void printVector(const vector<int>& nums) {
    cout << '[';
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << nums[i];
    }
    cout << ']';
}

int main() {
    const vector<pair<vector<int>, vector<int>>> testCases = {
        {{0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}},
        {{0}, {0}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2, 3}, {1, 2, 3}},
        {{0, 0, 0}, {0, 0, 0}},
        {{0, 1}, {1, 0}},
        {{1, 0}, {1, 0}},
        {{0, 0, 1}, {1, 0, 0}},
        {{1, 0, 0}, {1, 0, 0}},
        {{4, 0, 5, 0, 0, 6}, {4, 5, 6, 0, 0, 0}},
        {{-1, 0, -2, 0, 3}, {-1, -2, 3, 0, 0}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].first;
        solution.moveZeroes(nums);
        const bool ok = nums == testCases[i].second;
        passed += ok;

        cout << "用例 " << i + 1 << ": 输入 = ";
        printVector(testCases[i].first);
        cout << "，预期 = ";
        printVector(testCases[i].second);
        cout << "，实际 = ";
        printVector(nums);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
