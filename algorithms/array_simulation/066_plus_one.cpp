#include <bits/stdc++.h>
using namespace std;

// 66. 加一
// digits 按高位到低位存储一个非负整数，返回该整数加一后的各位数字。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：从后往前加；不是九就加一返回；全是九则开头补一。
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 2, 3}, {1, 2, 4}},
        {{4, 3, 2, 1}, {4, 3, 2, 2}},
        {{9}, {1, 0}},
        {{0}, {1}},
        {{1}, {2}},
        {{9, 9}, {1, 0, 0}},
        {{9, 9, 9}, {1, 0, 0, 0}},
        {{1, 0, 0, 0}, {1, 0, 0, 1}},
        {{8, 9, 9}, {9, 0, 0}},
        {{2, 9, 9, 9}, {3, 0, 0, 0}},
        {{5, 6, 7, 8, 9}, {5, 6, 7, 9, 0}},
        {{9, 0, 9}, {9, 1, 0}},
        {{1, 9, 9, 9, 9}, {2, 0, 0, 0, 0}},
        {{7, 8, 9}, {7, 9, 0}},
        {{3, 0, 0, 9}, {3, 0, 1, 0}},
        {{9, 9, 9, 9, 9, 9}, {1, 0, 0, 0, 0, 0, 0}},
    };
    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto digits = input;
        auto actual = solution.plusOne(digits);
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": digits = [";
        for (size_t j = 0; j < input.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << input[j];
        }
        cout << "]，预期 = [";
        for (size_t j = 0; j < expected.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << expected[j];
        }
        cout << "]，实际 = [";
        for (size_t j = 0; j < actual.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << actual[j];
        }
        cout << "]，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
