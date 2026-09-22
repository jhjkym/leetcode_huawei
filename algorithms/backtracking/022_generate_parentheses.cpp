#include <bits/stdc++.h>
using namespace std;

// 22. 括号生成
// 左括号没用完就能放；右括号数量小于左括号时才能放。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        backtrack(n, 0, 0, path, ans);
        return ans;
    }

private:
    void backtrack(int n, int left, int right, string& path,
                   vector<string>& ans) {
        if (left == n && right == n) {
            ans.push_back(path);
            return;
        }

        if (left < n) {
            path.push_back('(');
            backtrack(n, left + 1, right, path, ans);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtrack(n, left, right + 1, path, ans);
            path.pop_back();
        }
    }
};

int main() {
    const vector<pair<int, vector<string>>> testCases = {
        {1, {"()"}},
        {2, {"(())", "()()"}},
        {3, {"((()))", "(()())", "(())()", "()(())", "()()()"}},
        {0, {""}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<string> actual = solution.generateParenthesis(testCases[i].first);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期数量 = "
             << testCases[i].second.size() << "，实际数量 = "
             << actual.size() << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
