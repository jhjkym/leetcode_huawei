#include <bits/stdc++.h>
using namespace std;

// 17. 电话号码的字母组合
// 按电话按键映射，为每个数字选择一个字母，返回所有组合，顺序不限。
// 2: abc, 3: def, 4: ghi, 5: jkl, 6: mno, 7: pqrs, 8: tuv, 9: wxyz。
// 核心实现已完成，16 组固定测例全部通过。

class Solution {
public:
    vector<string> key = {"","", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtracking(int index,vector<string> &ans,string path,string digits){
        if(index == digits.size()){
            ans.push_back(path);
            return ;
        }
        int digit = digits[index]-'0';
        string str = key[digit];
        for(char c : str){
            path+=c;
            backtracking(index +1,ans,path,digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string path;
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        backtracking(0,ans,path,digits);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        string digits;
        vector<string> expected;
    };
    const vector<TestCase> testCases = {
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        {"", {}},
        {"2", {"a", "b", "c"}},
        {"3", {"d", "e", "f"}},
        {"4", {"g", "h", "i"}},
        {"5", {"j", "k", "l"}},
        {"6", {"m", "n", "o"}},
        {"7", {"p", "q", "r", "s"}},
        {"8", {"t", "u", "v"}},
        {"9", {"w", "x", "y", "z"}},
        {"22", {"aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc"}},
        {"79", {"pw", "px", "py", "pz", "qw", "qx", "qy", "qz",
                "rw", "rx", "ry", "rz", "sw", "sx", "sy", "sz"}},
        {"92", {"wa", "wb", "wc", "xa", "xb", "xc",
                "ya", "yb", "yc", "za", "zb", "zc"}},
        {"234", {"adg", "adh", "adi", "aeg", "aeh", "aei", "afg", "afh", "afi",
                 "bdg", "bdh", "bdi", "beg", "beh", "bei", "bfg", "bfh", "bfi",
                 "cdg", "cdh", "cdi", "ceg", "ceh", "cei", "cfg", "cfh", "cfi"}},
        {"2", {"a", "b", "c"}},
        {"", {}},
    };

    auto printStrings = [](const vector<string>& values) {
        cout << '[';
        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << quoted(values[i]);
        }
        cout << ']';
    };

    Solution solution; // 复用对象，检查成员变量是否在每次调用时正确重置。
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto actual = solution.letterCombinations(testCase.digits);
        auto expected = testCase.expected;
        // 题目允许任意输出顺序；排序后比较，仍能检测重复或遗漏结果。
        sort(actual.begin(), actual.end());
        sort(expected.begin(), expected.end());
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": digits = " << quoted(testCase.digits)
             << "，预期 = ";
        printStrings(expected);
        cout << "，实际 = ";
        printStrings(actual);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
