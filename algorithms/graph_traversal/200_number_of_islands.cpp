#include <bits/stdc++.h>
using namespace std;

// 200. 岛屿数量
// 算法：图遍历（递归 DFS）；数据结构：二维网格、递归栈。
// '1' 表示陆地，'0' 表示水域；只有上下左右相邻的陆地连通。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>& grid){
        if(i<0 || i>= m ||j<0 || j>=n || grid[i][j] == '0'){
            return ;
        }
        grid[i][j] = '0';
        dfs(i-1,j,m,n,grid);
        dfs(i+1,j,m,n,grid);
        dfs(i,j-1,m,n,grid);
        dfs(i,j+1,m,n,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int count = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i,j,m,n,grid);
                }
            }
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 用字符串保存每一行，调用前转换为题目要求的 vector<vector<char>>。
    const vector<pair<vector<string>, int>> testCases = {
        {{"11110", "11010", "11000", "00000"}, 1},
        {{"11000", "11000", "00100", "00011"}, 3},
        {{"0"}, 0},
        {{"1"}, 1},
        {{"000", "000"}, 0},
        {{"111", "111"}, 1},
        {{"10101"}, 3},
        {{"1", "0", "1", "1", "0", "1"}, 3},
        {{"10", "01"}, 2},
        {{"101", "010", "101"}, 5},
        {{"11111", "10001", "10101", "10001", "11111"}, 2},
        {{"11011", "11111", "00000", "10001"}, 3},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [rows, expected] = testCases[i];

        // 每个测例创建独立网格，支持在核心实现中原地标记已访问的陆地。
        vector<vector<char>> grid;
        grid.reserve(rows.size());
        for (const string& row : rows) {
            grid.emplace_back(row.begin(), row.end());
        }

        const int actual = solution.numIslands(grid);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": grid = [";
        for (size_t r = 0; r < rows.size(); ++r) {
            if (r > 0) {
                cout << ", ";
            }
            cout << quoted(rows[r]);
        }
        cout << "]，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
