#include <bits/stdc++.h>
using namespace std;

// 215. 数组中的第K个最大元素
// 返回数组按降序排列后的第 k 个元素，重复元素也参与排名。
// 当前解法：大小为 k 的小根堆，保存遍历过的元素中最大的 k 个。
// 时间 O(n log(k + 1))，空间 O(k)；尚未达到平均 O(n) 的练习目标。
// 16 组固定测例全部通过。

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num : nums){
            if(pq.size() < k){
                pq.push(num);
            }else{
                if(pq.top() < num){
                pq.pop();
                pq.push(num);
                }
            }
        }
        return pq.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<int> nums;
        int k;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{3, 2, 1, 5, 6, 4}, 2, 5},
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},
        {{7}, 1, 7},
        {{1, 2}, 1, 2},
        {{1, 2}, 2, 1},
        {{5, 5, 5, 5}, 3, 5},
        {{9, 9, 8, 7}, 2, 9},
        {{1, 2, 3, 4, 5}, 3, 3},
        {{5, 4, 3, 2, 1}, 4, 2},
        {{-5, -1, -3, -2, -4}, 2, -2},
        {{0, -1, 2, -3, 2}, 3, 0},
        {{0, 0, 0}, 1, 0},
        {{4, 1, 7, 3, 9}, 1, 9},
        {{4, 1, 7, 3, 9}, 5, 1},
        {{-10000, 10000, 0, 10000}, 2, 10000},
        {{2, 1, 2, 1, 2, 1}, 4, 1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        auto nums = testCase.nums;
        const int actual = solution.findKthLargest(nums, testCase.k);
        const bool ok = actual == testCase.expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < testCase.nums.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << testCase.nums[j];
        }
        cout << "]，k = " << testCase.k
             << "，预期 = " << testCase.expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
