#include <bits/stdc++.h>
using namespace std;

// 347. 前 K 个高频元素
// 桶排序：下标表示频率，桶中保存具有该频率的数字。
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int num : nums) frequency[num]++;

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (const auto& [num, count] : frequency) {
            buckets[count].push_back(num);
        }

        vector<int> ans;
        for (int count = n; count >= 1 && k > 0; count--) {
            for (int num : buckets[count]) {
                ans.push_back(num);
                k--;
                if (k == 0) break;
            }
        }
        return ans;
    }
};

int main() {
    struct TestCase {
        vector<int> nums;
        int k;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
        {{1}, 1, {1}},
        {{1, 2}, 2, {1, 2}},
        {{4, 4, 4, 4, 2, 2, 3}, 1, {4}},
        {{-1, -1, 2, 2, 2, 3}, 2, {-1, 2}},
        {{5, 3, 1, 1, 1, 3, 5, 5, 5}, 2, {1, 5}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].nums;
        vector<int> actual = solution.topKFrequent(nums, testCases[i].k);
        vector<int> expected = testCases[i].expected;
        sort(actual.begin(), actual.end());
        sort(expected.begin(), expected.end());
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
