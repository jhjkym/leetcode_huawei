#include <bits/stdc++.h>
using namespace std;

// 36. 有效的数独
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：空格跳过，数字减一；行列宫查重，没重就标记。
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {}; // rows[r][d]：第 r 行是否出现过数字 d+1。
        bool cols[9][9] = {}; // cols[c][d]：第 c 列是否出现过数字 d+1。
        bool boxes[9][9] = {}; // boxes[b][d]：第 b 个九宫格是否出现过数字 d+1。

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                int d = board[r][c] - '1'; // '1'~'9' 映射为下标 0~8。
                int b = (r / 3) * 3 + c / 3; // 九宫格编号：从左到右、从上到下 0~8。
                if (rows[r][d] || cols[c][d] || boxes[b][d]) return false;
                rows[r][d] = cols[c][d] = boxes[b][d] = true;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << boolalpha;

    struct TestCase {
        string name;
        vector<string> rows;
        bool expected;
    };
    vector<string> emptyBoard(9, string(9, '.'));
    vector<TestCase> testCases = {
        {"典型有效棋盘", {"53..7....", "6..195...", ".98....6.", "8...6...3",
                          "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"}, true},
        {"完整有效棋盘", {"534678912", "672195348", "198342567", "859761423",
                          "426853791", "713924856", "961537284", "287419635", "345286179"}, true},
        {"全空棋盘", emptyBoard, true},
    };
    auto addCase = [&](string name, initializer_list<tuple<int, int, char>> cells, bool expected) {
        auto rows = emptyBoard;
        for (auto [r, c, digit] : cells) rows[r][c] = digit;
        testCases.push_back({name, rows, expected});
    };
    addCase("单个数字", {{4, 4, '5'}}, true);
    addCase("同行重复且不同宫", {{0, 0, '1'}, {0, 8, '1'}}, false);
    addCase("同列重复且不同宫", {{0, 0, '2'}, {8, 0, '2'}}, false);
    addCase("同宫重复但不同行列", {{0, 0, '3'}, {1, 1, '3'}}, false);
    addCase("中心宫重复", {{3, 3, '4'}, {5, 5, '4'}}, false);
    addCase("右下宫重复", {{6, 6, '9'}, {8, 8, '9'}}, false);
    addCase("相同数字位于不同行列宫", {{0, 0, '7'}, {4, 4, '7'}, {8, 8, '7'}}, true);
    addCase("跨宫边界", {{2, 2, '6'}, {3, 3, '6'}}, true);
    addCase("数字一和九", {{0, 0, '1'}, {0, 1, '9'}}, true);

    // 没有重复，但 (0,8) 无数字可填：本题仍应判定有效，不要求可解。
    auto unsolvable = emptyBoard;
    unsolvable[0] = "12345678.";
    unsolvable[1][8] = '9';
    testCases.push_back({"无重复但无解", unsolvable, true});
    testCases.push_back({"再次调用空棋盘", emptyBoard, true});

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        vector<vector<char>> board;
        for (const string& row : testCase.rows) board.emplace_back(row.begin(), row.end());
        bool actual = solution.isValidSudoku(board);
        bool ok = actual == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << "（" << testCase.name << "）：预期 = "
             << testCase.expected << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
