#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> tests = {
        "", "()", ")()())", "(()", "()(())", "(()())", "((()))", "())((())"
    };
    vector<int> expected = {0, 2, 4, 2, 6, 6, 6, 4};

    int testCount = tests.size();
    int passed = 0;
    for (int i = 0; i < testCount; i++) {
        int result = solution.longestValidParentheses(tests[i]);
        bool ok = result == expected[i];
        passed += ok;
        cout << "测试 " << i + 1 << ": " << (ok ? "通过" : "失败") << '\n';
    }

    cout << "通过：" << passed << '/' << testCount << '\n';
    return passed == testCount ? 0 : 1;
}
