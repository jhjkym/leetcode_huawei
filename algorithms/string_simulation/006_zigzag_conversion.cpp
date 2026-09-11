#include <bits/stdc++.h>
using namespace std;

// 6. Z 字形变换
// 算法：字符串模拟；数据结构：按行保存的字符串数组。
// 将字符串按指定行数排列成 Z 字形，再从上到下逐行读取。
// 背诵模板：按行存字符 + 首尾转向 + 按行拼接。
// 掌握状态：不会，待复习背诵。

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= static_cast<int>(s.size())) return s;

        vector<string> rows(numRows);
        int currentRow = 0;
        int direction = 1;

        for (char c : s) {
            rows[currentRow] += c;                 // 先放字符
            if (currentRow == 0) direction = 1;    // 顶行向下
            if (currentRow == numRows - 1) direction = -1; // 底行向上
            currentRow += direction;              // 再移动行号
        }

        string result;
        for (const string& row : rows) result += row;
        return result;
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
