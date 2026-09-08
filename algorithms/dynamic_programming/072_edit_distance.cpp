#include <bits/stdc++.h>
using namespace std;

// 72. 编辑距离
// 算法：二维动态规划；数据结构：二维状态数组（可滚动为一维）。
// 每次可以插入、删除或替换一个字符，求把 word1 转成 word2 的最少操作数。
// 直接运行即可执行 main 中的固定测例。
// 掌握状态：细节不熟，待复习。
// 易错细节：第 0 行第 0 列要初始化为 i、j；dp 尺寸 (m+1)×(n+1)，字符用 i-1、j-1；
//           字符相等时直接继承左上角不加 1；不等时三个方向都要参与 min。

class Solution {
public:
    int minDistance(string word1, string word2) {
        // TODO: 在这里填写核心实现。
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i = 0;i <= m;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j <= n;j++){
            dp[0][j] = j;
        }
        for(int i = 1 ;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[m][n]; // 占位返回值，完成实现后替换。
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<tuple<string, string, int>> testCases = {
        {"horse", "ros", 3},
        {"intention", "execution", 5},
        {"", "", 0},
        {"", "abc", 3},
        {"abc", "", 3},
        {"a", "a", 0},
        {"a", "b", 1},
        {"abc", "abc", 0},
        {"pneumonia", "pneumonic", 1},
        {"sunday", "saturday", 3},
        {"kitten", "sitting", 3},
        {"plasma", "altruism", 6},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [word1, word2, expected] = testCases[i];
        const int actual = solution.minDistance(word1, word2);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": word1 = " << quoted(word1)
             << "，word2 = " << quoted(word2)
             << "，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
