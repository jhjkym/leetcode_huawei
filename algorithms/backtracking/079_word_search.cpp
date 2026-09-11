#include <bits/stdc++.h>
using namespace std;

// 79. 单词搜索
// 在字符网格中寻找单词，单词字符必须由上下左右相邻单元格依次组成。
// 一个单元格不能重复使用。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：找到起点搜四方，匹配标记，失败恢复。

class Solution {
    int m = 0, n = 0;
    string word;
    vector<vector<char>>* boardPtr = nullptr;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(int x, int y, int index) {
        if (index == static_cast<int>(word.size())) return true;
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        auto& board = *boardPtr;
        if (board[x][y] != word[index]) return false;

        char saved = board[x][y];
        board[x][y] = '#'; // 标记已使用，防止同一格重复进入路径。
        for (const auto& dir : dirs) {
            if (dfs(x + dir[0], y + dir[1], index + 1)) return true;
        }
        board[x][y] = saved; // 当前方向失败，恢复现场。
        return index + 1 == static_cast<int>(word.size());
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) return false;
        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        this->word = word;
        boardPtr = &board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) return true;
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
        bool actual = solution.exist(board, testCases[i].word);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": word = " << quoted(testCases[i].word)
             << "，预期 = " << boolalpha << testCases[i].expected
             << "，实际 = " << actual << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
