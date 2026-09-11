#include <bits/stdc++.h>
using namespace std;

// 43. 字符串相乘
// 算法：竖式乘法模拟；数据结构：数位数组 vector<int>。
// 背诵模板：倒序两重循环，个位放 i+j+1，进位加到 i+j。
// 掌握状态：不会，待复习背诵。

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = static_cast<int>(num1.size());
        int n = static_cast<int>(num2.size());
        vector<int> digits(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int sum = (num1[i] - '0') * (num2[j] - '0')
                          + digits[i + j + 1];
                digits[i + j + 1] = sum % 10; // 当前位留个位
                digits[i + j] += sum / 10;    // 左边一位累加进位
            }
        }

        string result;
        for (int digit : digits) {
            if (result.empty() && digit == 0) continue; // 跳过前导零
            result += char('0' + digit);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        string num1;
        string num2;
        string expected;
    };

    const vector<TestCase> testCases = {
        {"2", "3", "6"},
        {"123", "456", "56088"},
        {"0", "123", "0"},
        {"456", "0", "0"},
        {"0", "0", "0"},
        {"1", "987654321", "987654321"},
        {"987654321", "1", "987654321"},
        {"9", "9", "81"},
        {"99", "99", "9801"},
        {"12", "34", "408"},
        {"100", "1000", "100000"},
        {"101", "101", "10201"},
        {"999", "9", "8991"},
        {"9", "999", "8991"},
        {"123456789", "987654321", "121932631112635269"},
        {string(200, '9'), "9", "8" + string(199, '9') + "1"},
        {"1" + string(199, '0'), "1" + string(199, '0'),
         "1" + string(398, '0')},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        const string actual = solution.multiply(testCase.num1, testCase.num2);
        const bool ok = actual == testCase.expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": num1 = " << quoted(testCase.num1)
             << "，num2 = " << quoted(testCase.num2)
             << "，预期 = " << quoted(testCase.expected)
             << "，实际 = " << quoted(actual)
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
