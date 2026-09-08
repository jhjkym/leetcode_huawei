#include <bits/stdc++.h>
using namespace std;

// 121. 买卖股票的最佳时机
// 算法：动态规划（一次遍历维护历史最低价）；数据结构：数组、滚动变量。
// 只允许买入一次并在之后某天卖出一次，返回能获得的最大利润；无法获利时返回 0。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // TODO: 在这里填写核心实现。
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int price : prices){
            minPrice = min(minPrice,price);
            maxProfit = max(maxProfit,price - minPrice);
        }
        return maxProfit; // 占位返回值，完成实现后替换。
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, int>> testCases = {
        {{7, 1, 5, 3, 6, 4}, 5},
        {{7, 6, 4, 3, 1}, 0},
        {{1}, 0},
        {{0, 0}, 0},
        {{2, 2, 2, 2}, 0},
        {{1, 2}, 1},
        {{2, 1}, 0},
        {{1, 2, 3, 4, 5}, 4},
        {{5, 4, 3, 2, 1}, 0},
        {{3, 2, 6, 5, 0, 3}, 4},
        {{2, 4, 1, 7}, 6},
        {{10000, 0, 10000}, 10000},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto prices = testCases[i].first;
        const int expected = testCases[i].second;
        const int actual = solution.maxProfit(prices);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": prices = [";
        for (size_t j = 0; j < prices.size(); ++j) {
            if (j) cout << ", ";
            cout << prices[j];
        }
        cout << "]，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
