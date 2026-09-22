#include <bits/stdc++.h>
using namespace std;

// 131. 分割回文串
// 枚举当前子串的结束位置，只有回文串才能加入路径。
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(s, 0, path, ans);
        return ans;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path,
                   vector<vector<string>>& ans) {
        int n = s.size();
        if (start == n) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < n; ++end) {
            if (!isPalindrome(s, start, end)) continue;

            path.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, path, ans);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    struct TestCase {
        string s;
        vector<vector<string>> expected;
    };

    const vector<TestCase> testCases = {
        {"aab", {{"a", "a", "b"}, {"aa", "b"}}},
        {"a", {{"a"}}},
        {"efe", {{"e", "f", "e"}, {"efe"}}},
        {"abba", {{"a", "b", "b", "a"}, {"a", "bb", "a"}, {"abba"}}},
        {"abc", {{"a", "b", "c"}}},
        {"", {{}}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<vector<string>> actual = solution.partition(testCases[i].s);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期方案数 = "
             << testCases[i].expected.size() << "，实际方案数 = "
             << actual.size() << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
