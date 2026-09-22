#include <bits/stdc++.h>
using namespace std;

// 5. 最长回文子串
// 算法：中心扩展、双指针；数据结构：字符串。
// 返回一个最长的连续回文子串；多个最长答案均可。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            expand(s, i, i, start, maxLength);
            expand(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expand(const string& s, int left, int right,
                int& start, int& maxLength) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        int length = right - left - 1;
        if (length > maxLength) {
            start = left + 1;
            maxLength = length;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 记录最长长度，允许返回任意一个合法的最长回文子串。
    const vector<pair<string, size_t>> testCases = {
        {"babad", 3},
        {"cbbd", 2},
        {"a", 1},
        {"ac", 1},
        {"aaaa", 4},
        {"racecar", 7},
        {"abba", 4},
        {"forgeeksskeegfor", 10},
        {"abacdfgdcaba", 3},
        {"abcddcbaxyz", 8},
        {"xyzabcddcba", 8},
        {"a1b1a", 5},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expectedLength] = testCases[i];
        const string actual = solution.longestPalindrome(input);
        const bool isSubstring = input.find(actual) != string::npos;
        const bool isPalindrome = equal(actual.begin(), actual.end(), actual.rbegin());
        const bool ok = actual.size() == expectedLength && isSubstring && isPalindrome;
        passed += ok;

        cout << "用例 " << i + 1 << ": s = " << quoted(input)
             << "，预期最长长度 = " << expectedLength
             << "，实际 = " << quoted(actual)
             << "（长度 " << actual.size() << "）"
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
        if (!ok) {
            cout << "  长度正确：" << (actual.size() == expectedLength ? "是" : "否")
                 << "，是原串子串：" << (isSubstring ? "是" : "否")
                 << "，是回文：" << (isPalindrome ? "是" : "否") << '\n';
        }
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
