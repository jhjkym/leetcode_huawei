#include <bits/stdc++.h>
using namespace std;

// 438. 找到字符串中所有字母异位词
// 滑动窗口：窗口长度始终等于 p 的长度。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(p.size());
        int left = 0;
        vector<int> result;
        if (m < n) return result;

        // cnt[c] 表示当前窗口还缺少多少个字符 c。
        int cnt[26]{};
        for (char c : p) ++cnt[c - 'a'];

        for (int right = 0; right < m; ++right) {
            char c = s[right];
            --cnt[c - 'a'];

            // 某字符数量超出 p 的需求时，持续移除窗口左端。
            while (cnt[c - 'a'] < 0) {
                ++cnt[s[left] - 'a'];
                ++left;
            }

            // 窗口长度等于 p，且没有字符超量，因此它就是异位词。
            if (right - left + 1 == n) result.push_back(left);
        }
        return result;
    }
};

int main() {
    const vector<tuple<string, string, vector<int>>> testCases = {
        {"cbaebabacd", "abc", {0, 6}},
        {"abab", "ab", {0, 1, 2}},
        {"baa", "aa", {1}},
        {"", "a", {}},
        {"a", "a", {0}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto [s, p, expected] = testCases[i];
        vector<int> actual = solution.findAnagrams(s, p);
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = [";
        for (size_t j = 0; j < expected.size(); ++j) cout << (j ? ", " : "") << expected[j];
        cout << "]，实际 = [";
        for (size_t j = 0; j < actual.size(); ++j) cout << (j ? ", " : "") << actual[j];
        cout << "]，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
