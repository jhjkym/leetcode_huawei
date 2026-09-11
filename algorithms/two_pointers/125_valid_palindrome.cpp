#include <bits/stdc++.h>
using namespace std;

// 125. 验证回文串
// 将大写字母转换为小写字母，并移除所有非字母数字字符后，判断是否为回文串。
// 字母和数字都需要保留；处理后为空字符串时也属于回文串。
// 背诵模板：左右夹逼，跳过符号，忽略大小写比较，不同返回 false。
// 掌握状态：待复习背诵。直接运行即可执行 main 中的固定测例。
// 函数使用状态：isalnum、tolower 以前没用过，需重点复习用法和返回值。

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        // s.size()：返回字符串长度，类型为无符号整数 size_t。
        // static_cast<int>(...)：显式转换成 int（是类型转换语法，不是函数）。
        // 先转 int 再减 1，空串时得到 -1，避免无符号整数下溢。
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            // isalnum(c)：<cctype> 中的函数，判断 c 是否为字母或数字。
            // 是则返回非零值（不一定是 1），否则返回 0。
            // 例如 'A'、'a'、'7' 返回非零值；空格、逗号返回 0。
            // !isalnum(c) 表示“不是字母或数字”，因此跳过该字符。
            // && 从左到右短路求值：left < right 不成立时，不再访问字符。
            while (left < right && !isalnum(s[left])) ++left;
            while (left < right && !isalnum(s[right])) --right;

            // tolower(c)：<cctype> 中的函数，返回对应小写字符的编码，类型为 int。
            // 例如 'A' → 'a'；小写字母、数字等保持原样。
            // 它只返回转换结果，不会修改原字符串，所以可以直接比较返回值。
            // 本题输入限定为可打印 ASCII 字符，可以直接传入 s[left/right]。
            // 若处理可能含负 char 值的其他输入，调用这两个函数前应先转 unsigned char。
            if (tolower(s[left]) != tolower(s[right])) return false;

            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    // 关闭 C++ 流与 C 标准输入输出的同步，常用于加速输入输出。
    ios::sync_with_stdio(false);
    // 解除 cin 与 cout 的绑定，读取输入前不再自动刷新 cout。
    cin.tie(nullptr);
    // boolalpha：输出格式控制符，让 bool 显示为 true/false，而不是 1/0。
    cout << boolalpha;

    const vector<pair<string, bool>> testCases = {
        {"A man, a plan, a canal: Panama", true},
        {"race a car", false},
        {" ", true},
        {".,!", true},
        {"a", true},
        {"Aa", true},
        {"ab", false},
        {"aba", true},
        {"abba", true},
        {"0P", false},
        {"121", true},
        {"123", false},
        {"1a2A1", true},
        {"a1", false},
        {".,a!", true},
        {"No lemon, no melon", true},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        const bool actual = solution.isPalindrome(input);
        const bool ok = actual == expected;
        passed += ok;

        // quoted(input)：<iomanip> 中的输出辅助函数，给字符串加双引号，
        // 并转义内部的双引号和反斜杠，方便看清测试输入；不会修改 input。
        cout << "用例 " << i + 1 << ": s = " << quoted(input)
             << "，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
