#include <bits/stdc++.h>
using namespace std;

// 51. N 皇后
// 逐行放置皇后，用数组记录列和两条对角线是否被占用。
class Solution {
    int n = 0;
    vector<string> board;
    vector<bool> columns;
    vector<bool> diagonal1;
    vector<bool> diagonal2;
    vector<vector<string>> ans;

public:
    vector<vector<string>> solveNQueens(int size) {
        n = size;
        board.assign(n, string(n, '.'));
        columns.assign(n, false);
        diagonal1.assign(2 * n - 1, false);
        diagonal2.assign(2 * n - 1, false);
        ans.clear();
        backtrack(0);
        return ans;
    }

private:
    void backtrack(int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (columns[col] || diagonal1[d1] || diagonal2[d2]) continue;

            board[row][col] = 'Q';
            columns[col] = diagonal1[d1] = diagonal2[d2] = true;

            backtrack(row + 1);

            board[row][col] = '.';
            columns[col] = diagonal1[d1] = diagonal2[d2] = false;
        }
    }
};

bool isValidBoard(const vector<string>& board) {
    int n = board.size();
    vector<bool> columns(n, false);
    vector<bool> diagonal1(2 * n - 1, false);
    vector<bool> diagonal2(2 * n - 1, false);

    for (int row = 0; row < n; ++row) {
        int queens = 0;
        for (int col = 0; col < n; ++col) {
            if (board[row][col] != 'Q') continue;
            queens++;
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (columns[col] || diagonal1[d1] || diagonal2[d2]) return false;
            columns[col] = diagonal1[d1] = diagonal2[d2] = true;
        }
        if (queens != 1) return false;
    }
    return true;
}

int main() {
    const vector<pair<int, size_t>> testCases = {
        {1, 1},
        {2, 0},
        {3, 0},
        {4, 2},
        {5, 10},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        int n = testCases[i].first;
        size_t expectedCount = testCases[i].second;
        vector<vector<string>> actual = solution.solveNQueens(n);

        bool allValid = true;
        for (const vector<string>& board : actual) {
            if (!isValidBoard(board)) allValid = false;
        }
        bool ok = actual.size() == expectedCount && allValid;
        passed += ok;
        cout << "用例 " << i + 1 << "：n = " << n
             << "，预期方案数 = " << expectedCount
             << "，实际方案数 = " << actual.size() << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
