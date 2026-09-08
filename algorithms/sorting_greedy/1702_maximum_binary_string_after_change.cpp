#include <bits/stdc++.h>
using namespace std;

// 1702. 修改后的最大二进制字符串
// 算法：贪心；数据结构：字符串、计数变量。
// 按题目允许的操作得到字典序最大的二进制字符串。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    string maximumBinaryString(string binary) {
        int firstZero = -1,count = 0;
        for(int i = 0;i < binary.size();i++){
            if(binary[i] == '0'){
                count ++;
                if(firstZero == -1){
                    firstZero = i;
                }
            }
        }
        if(firstZero == -1 || count == 1){
            return binary;
        }
        string ans(binary.size(),'1');
        ans[firstZero+count-1] = '0';
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<string, string>> testCases = {
        {"000110", "111011"},
        {"01", "01"},
        {"00", "10"},
        {"0000", "1110"},
        {"1111", "1111"},
        {"1000", "1110"},
        {"101010", "111011"},
        {"001011", "110111"},
        {"01010", "11011"},
        {"110011", "111011"},
        {"001100111", "111011111"},
        {"011111", "011111"},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        const string actual = solution.maximumBinaryString(input);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": binary = " << quoted(input)
             << "，预期 = " << quoted(expected)
             << "，实际 = " << quoted(actual)
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
