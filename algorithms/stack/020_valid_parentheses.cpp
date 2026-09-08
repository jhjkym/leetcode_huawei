#include <bits/stdc++.h>
using namespace std;

// 20. 有效的括号
// 算法：栈匹配；数据结构：stack<char>。
// 判断括号字符串是否按正确顺序闭合。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '('){
                st.push(')');
            }else if(c == '['){
                st.push(']');
            }else if(c == '{'){
                st.push('}');
            }else if(st.empty() || c!=st.top()){
                return false;
            }else{
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<string, bool>> testCases = {
        {"", true},
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([)]", false},
        {"{[]}", true},
        {"((()))", true},
        {"((()", false},
        {"]", false},
        {"[", false},
        {"(){}}{", false},
        {"{[()()]}", true},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        const string& input = testCase.first;
        const bool expected = testCase.second;
        const bool actual = solution.isValid(input);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": s = " << quoted(input)
             << "，预期 = " << (expected ? "true" : "false")
             << "，实际 = " << (actual ? "true" : "false")
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
