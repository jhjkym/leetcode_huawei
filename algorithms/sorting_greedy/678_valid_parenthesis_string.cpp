#include <bits/stdc++.h>
using namespace std;

// 678. 有效的括号字符串
// 贪心：维护当前前缀中左括号数量的可能范围 [low, high]。
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // 把 * 尽量当作 ')' 时，最少剩余左括号数
        int high = 0;  // 把 * 尽量当作 '(' 时，最多剩余左括号数

        for (char c : s) {
            if (c == '(') {
                ++low;
                ++high;
            } else if (c == ')') {
                low = max(0, low - 1);
                --high;
            } else { // '*': 可以当作 '(', ')' 或空字符
                low = max(0, low - 1);
                ++high;
            }

            // high < 0 表示即使把所有 * 当作 '(' 也无法匹配。
            if (high < 0) return false;
        }
        // 最少仍有未匹配的左括号，说明无法全部闭合。
        return low == 0;
    }
};

int main() {
    const vector<pair<string, bool>> testCases = {
        {"()", true}, {"(*)", true}, {"(*))", true},
        {"(", false}, {"((", false}, {"())", false},
        {"*", true}, {"(((******))", true}, {"())*", false},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        bool actual = solution.checkValidString(testCases[i].first);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha << testCases[i].second
             << "，实际 = " << actual << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
