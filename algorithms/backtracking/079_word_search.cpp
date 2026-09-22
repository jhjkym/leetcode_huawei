#include <bits/stdc++.h>
using namespace std;

// 79. 单词搜索
// 口诀：每格试起点；越界不符退；末字匹配成；标记搜四向，恢复再返回。

class Solution {
    int m = 0, n = 0, length = 0;

    bool dfs(vector<vector<char>>& board, const string& word,
             int i, int j, int k) {
        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] != word[k]) return false;

        if (k == length - 1) return true;

        char saved = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1);

        board[i][j] = saved;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) return false;
        m = board.size();
        n = board[0].size();
        length = word.size();
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
