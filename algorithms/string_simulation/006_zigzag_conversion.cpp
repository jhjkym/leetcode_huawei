#include <bits/stdc++.h>
using namespace std;

// 6. Z 字形变换
// 算法：字符串模拟；数据结构：按行保存的字符串数组。
// 将字符串按指定行数排列成 Z 字形，再从上到下逐行读取。
// 填写 convert 后，直接运行即可执行 main 中的固定测例。

class Solution {
public:
    string convert(string s, int numRows) {
        // TODO: 在这里填写核心实现。
        
        return {}; // 占位返回值，完成实现后替换。
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        string input;
        int numRows;
        string expected;
    };

    const vector<TestCase> testCases = {
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"PAYPALISHIRING", 1, "PAYPALISHIRING"},
        {"A", 1, "A"},
        {"AB", 5, "AB"},
        {"AB", 2, "AB"},
        {"ABCDE", 2, "ACEBD"},
        {"ABCDE", 3, "AEBDC"},
        {"ABCDEFGH", 4, "AGBFHCED"},
        {"ABCDEF", 6, "ABCDEF"},
        {"AAAAAA", 3, "AAAAAA"},
        {"A,B.C", 2, "ABC,."},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        const string actual = solution.convert(testCase.input, testCase.numRows);
        const bool ok = actual == testCase.expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": s = " << quoted(testCase.input)
             << "，numRows = " << testCase.numRows
             << "，预期 = " << quoted(testCase.expected)
             << "，实际 = " << quoted(actual)
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
