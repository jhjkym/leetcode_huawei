#include <bits/stdc++.h>
using namespace std;

// 14. 最长公共前缀
// 算法：字符串扫描；数据结构：字符串数组 vector<string>。
// 返回所有字符串的最长公共前缀，不存在时返回空字符串。
// 背诵模板：以首串为基准，逐列比较，越界或不同就返回前缀。
// 掌握状态：不会，待复习背诵。

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (size_t i = 0; i < strs[0].size(); ++i) {
            for (size_t j = 1; j < strs.size(); ++j) {
                // 先检查长度，再访问字符，避免越界。
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0]; // 首串全部匹配，它就是最长公共前缀。
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<string> input;
        string expected;
    };

    const vector<TestCase> testCases = {
        {{"flower", "flow", "flight"}, "fl"},
        {{"dog", "racecar", "car"}, ""},
        {{"hello"}, "hello"},
        {{""}, ""},
        {{"", "abc"}, ""},
        {{"abc", ""}, ""},
        {{"same", "same", "same"}, "same"},
        {{"ab", "abcd", "abc"}, "ab"},
        {{"abcd", "abc", "ab"}, "ab"},
        {{"apple", "ape", "axis"}, "a"},
        {{"a", "b"}, ""},
        {{"interview", "internet", "internal"}, "inter"},
        {{"prefix", "prefixes", "preform"}, "pref"},
        {{"abc", "xbc"}, ""},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        vector<string> input = testCase.input;
        const string actual = solution.longestCommonPrefix(input);
        const bool ok = actual == testCase.expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": strs = [";
        for (size_t j = 0; j < testCase.input.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << quoted(testCase.input[j]);
        }
        cout << "]，预期 = " << quoted(testCase.expected)
             << "，实际 = " << quoted(actual)
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
