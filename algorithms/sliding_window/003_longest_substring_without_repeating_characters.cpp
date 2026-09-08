#include <bits/stdc++.h>
using namespace std;

// 3. 无重复字符的最长子串
// 算法：滑动窗口；数据结构：哈希表。
// 直接运行即可执行 main 中的固定测例。
// 每个测例会显示输入、预期值、实际值和是否通过。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;
        int left = 0;
        int length = 0;
        for(int right = 0; right < s.size();right++){
            char c = s[right];
            while(last.count(c) && last[c] >= left){
                left = last[c]+1;
            }
            length = max(length,right-left+1);
            last[c] = right;
        }  

        return length;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<string, int>> testCases = {
        {"", 0},
        {"a", 1},
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
        {"abcdef", 6},
        {"abba", 2},
        {"dvdf", 3},
        {"tmmzuxt", 5},
        {" ", 1},
        {"a b!a", 4},
        {"aA1!a", 4},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        const int actual = solution.lengthOfLongestSubstring(input);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": s = " << quoted(input)
             << "，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
