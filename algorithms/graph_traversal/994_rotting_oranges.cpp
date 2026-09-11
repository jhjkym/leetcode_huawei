#include <bits/stdc++.h>
using namespace std;

// 994. 腐烂的橘子
// 算法：多源 BFS；数据结构：二维网格、队列。
// 掌握状态：不会，已提供答案模板，待复习背诵。
// 口诀：烂橘先入队，鲜橘数清楚；一层一分钟，入队就标烂；剩鲜返负一。

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        queue<pair<int, int>> q; // 保存腐烂橘子的行、列坐标。
        int fresh = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
            }
        }

        int minutes = 0;
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty() && fresh > 0) {
            // 固定本层数量，新入队的橘子要等下一分钟才向外传播。
            int size = static_cast<int>(q.size());
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); // C++17 结构化绑定，取出行、列。
                q.pop(); // front() 只读取，pop() 才删除，且不返回元素。
                for (const auto& dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2; // 入队前标记，避免被多个邻居重复入队。
                    --fresh;
                    q.push({nx, ny});
                }
            }
            ++minutes;
        }
        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<vector<int>> grid;
        int expected;
    };
    const vector<TestCase> testCases = {
        {{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4},
        {{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1},
        {{{0, 2}}, 0},
        {{{0}}, 0},
        {{{1}}, -1},
        {{{2}}, 0},
        {{{1, 1}, {1, 1}}, -1},
        {{{2, 2}, {2, 2}}, 0},
        {{{2, 1, 1, 1}}, 3},
        {{{2}, {1}, {1}, {1}}, 3},
        {{{2, 1, 1, 1, 2}}, 2},
        {{{2, 0, 1}}, -1},
        {{{2, 0}, {0, 1}}, -1},
        {{{1, 1, 1}, {1, 2, 1}, {1, 1, 1}}, 2},
        {{{2, 1}, {1, 1}}, 2},
        {{{2, 1, 2}}, 1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        auto grid = testCase.grid; // 算法会修改网格，复制后再调用。
        int actual = solution.orangesRotting(grid);
        bool ok = actual == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": grid = [";
        for (size_t r = 0; r < testCase.grid.size(); ++r) {
            if (r > 0) cout << ", ";
            cout << '[';
            for (size_t c = 0; c < testCase.grid[r].size(); ++c) {
                if (c > 0) cout << ", ";
                cout << testCase.grid[r][c];
            }
            cout << ']';
        }
        cout << "]，预期 = " << testCase.expected << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
