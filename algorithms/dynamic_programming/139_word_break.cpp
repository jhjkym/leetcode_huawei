#include <bits/stdc++.h>
using namespace std;

// 139. 单词拆分
// dp[i] 表示字符串前 i 个字符能否由字典中的单词组成。
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    struct TestCase {
        string s;
        vector<string> wordDict;
        bool expected;
    };

    const vector<TestCase> testCases = {
        {"leetcode", {"leet", "code"}, true},
        {"applepenapple", {"apple", "pen"}, true},
        {"catsandog", {"cats", "dog", "sand", "and", "cat"}, false},
        {"a", {"a"}, true},
        {"aaaaaaa", {"aaaa", "aaa"}, true},
        {"cars", {"car", "ca", "rs"}, true},
        {"abcd", {"a", "abc", "b", "cd"}, true},
        {"aaaaab", {"a", "aa", "aaa"}, false},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<string> wordDict = testCases[i].wordDict;
        bool actual = solution.wordBreak(testCases[i].s, wordDict);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha
             << testCases[i].expected << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
