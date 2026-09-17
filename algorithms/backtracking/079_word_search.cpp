#include <bits/stdc++.h>
using namespace std;

// 79. 单词搜索
// 在字符网格中寻找单词，单词字符必须由上下左右相邻单元格依次组成。
// 一个单元格不能重复使用。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：每格试起点；越界不符退；末字匹配成；标记搜四向，恢复再返回。

class Solution {
    int m = 0, n = 0;

    // 从 (i, j) 开始，能否匹配 word[k] 及后面的字符？
    bool dfs(vector<vector<char>>& board, const string& word,
             int i, int j, int k) {
        // 1. 越界或当前字符不匹配。
        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] != word[k]) {
            return false;
        }

        // 2. 当前字符匹配，而且已经是最后一个字符。
        if (k == static_cast<int>(word.size()) - 1) return true;

        // 3. 标记当前格已使用；本题字母不会与 '#' 冲突。
        char saved = board[i][j];
        board[i][j] = '#';

        // 4. 四个方向寻找下一个字符；|| 遇到成功便停止尝试。
        bool found =
            dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i + 1, j, k + 1) ||
            dfs(board, word, i, j - 1, k + 1) ||
            dfs(board, word, i, j + 1, k + 1);

        // 5. 无论成功还是失败，都恢复棋盘，再返回结果。
        board[i][j] = saved;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) return false;
        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        // 每个格子都尝试作为起点。
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    struct TestCase { vector<string> rows; string word; bool expected; };
    const vector<TestCase> testCases = {
        {{"ABCE", "SFCS", "ADEE"}, "ABCCED", true},
        {{"ABCE", "SFCS", "ADEE"}, "SEE", true},
        {{"ABCE", "SFCS", "ADEE"}, "ABCB", false},
        {{"A"}, "A", true}, {{"A"}, "B", false},
        {{"A"}, "AA", false}, {{"AB"}, "BA", true},
        {{"ABC", "DEF", "GHI"}, "ADG", true},
        {{"ABC", "DEF", "GHI"}, "AEI", false},
        {{"AAA", "AAA"}, "AAAAA", true},
        {{"AAA", "AAA"}, "AAAAAA", true},
        {{"ABCD", "EFGH", "IJKL", "MNOP"}, "AFKP", false},
        {{"AB", "CD"}, "ACDB", true},
        {{"AAB", "ABB"}, "AABB", true},
        {{"a1", "2a"}, "a2a", true},
        {{"AB", "CD"}, "", false},
    };
    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<vector<char>> board;
        for (const auto& row : testCases[i].rows) board.emplace_back(row.begin(), row.end());
        const auto original = board;
        bool actual = solution.exist(board, testCases[i].word);
        bool restored = board == original; // 成功和失败路径都必须恢复棋盘。
        bool ok = actual == testCases[i].expected && restored;
        passed += ok;
        cout << "用例 " << i + 1 << ": word = " << quoted(testCases[i].word)
             << "，预期 = " << boolalpha << testCases[i].expected
             << "，实际 = " << actual << "，棋盘恢复 = " << restored
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
