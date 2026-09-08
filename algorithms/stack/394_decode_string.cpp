#include <bits/stdc++.h>
using namespace std;

// 394. 字符串解码
// 算法：栈解析；数据结构：数字栈、字符串栈。
// 将形如 k[encoded_string] 的嵌套编码还原为原字符串。
// 直接运行即可执行 main 中的固定测例。
// 背诵模板：数字栈 + 字符串栈。
// 掌握状态：不会，待复习背诵。

class Solution {
public:
    string decodeString(string s) {
        stack<int> repeatStack;       // 每一层 '[' 对应的重复次数
        stack<string> previousStack;  // 每一层 '[' 之前已经拼好的前缀
        string current;               // 当前这一层正在构造的字符串
        int number = 0;               // 正在读取的多位数字

        for (char c : s) {
            if (isdigit(c)) {
                // 连续数字组成完整次数，例如 "12" -> 12。
                number = number * 10 + (c - '0');
            } else if (c == '[') {
                // 进入新层：先保存外层状态，再从空字符串开始解析括号内容。
                repeatStack.push(number);
                previousStack.push(current);
                number = 0;
                current="";
            } else if (c == ']') {
                // 结束当前层：取出次数和外层前缀，把当前内容重复后接回去。
                const int repeat = repeatStack.top();
                repeatStack.pop();
                string prefix = previousStack.top();
                previousStack.pop();

                string expanded;
                for (int i = 0; i < repeat; ++i) {
                    expanded += current;
                }
                current = prefix + expanded;
            } else {
                // 普通字母直接追加到当前层。
                current += c;
            }
        }

        return current;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<string, string>> testCases = {
        {"3[a]2[bc]", "aaabcbc"},
        {"3[a2[c]]", "accaccacc"},
        {"2[abc]3[cd]ef", "abcabccdcdcdef"},
        {"abc3[cd]xyz", "abccdcdcdxyz"},
        {"10[a]", string(10, 'a')},
        {"1[a]", "a"},
        {"2[ab3[c]]", "abcccabccc"},
        {"2[3[a]b]", "aaabaaab"},
        {"2[x]3[y2[z]]", "xxyzzyzzyzz"},
        {"abc", "abc"},
        {"2[a]2[b]2[c]", "aabbcc"},
        {"3[z]2[2[y]pq4[2[jk]e1[f]]]ef",
         "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef"},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        const string& input = testCase.first;
        const string& expected = testCase.second;
        const string actual = solution.decodeString(input);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": s = " << quoted(input)
             << "，预期长度 = " << expected.size()
             << "，实际长度 = " << actual.size()
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
        if (!ok) {
            cout << "  预期 = " << quoted(expected)
                 << "\n  实际 = " << quoted(actual) << '\n';
        }
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
