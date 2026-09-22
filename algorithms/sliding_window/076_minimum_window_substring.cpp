#include <bits/stdc++.h>
using namespace std;

// 76. 最小覆盖子串
// 滑动窗口：右指针扩张直到覆盖 t，再移动左指针寻找最短窗口。
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        int need[128]{};
        for (char c : t) ++need[c];

        int left = 0, count = static_cast<int>(t.size());
        int start = 0, minLen = INT_MAX;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            // 右边进：先判断，再减。
            if (need[s[right]]-- > 0) --count;

            // 覆盖全：更新答案，左边出。
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    start = left;
                    minLen = right - left + 1;
                }
                // 左边出：先加，再判断。
                if (++need[s[left++]] > 0) ++count;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    const vector<tuple<string, string, string>> testCases = {
        {"ADOBECODEBANC", "ABC", "BANC"},
        {"a", "a", "a"},
        {"a", "aa", ""},
        {"aa", "aa", "aa"},
        {"bba", "ab", "ba"},
        {"abc", "", ""},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto [s, t, expected] = testCases[i];
        string actual = solution.minWindow(s, t);
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = \"" << expected
             << "\"，实际 = \"" << actual << "\"，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
