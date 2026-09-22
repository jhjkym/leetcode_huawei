#include <bits/stdc++.h>
using namespace std;

// 322. 零钱兑换
// dp[i] 表示凑出金额 i 所需的最少硬币数量。
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    struct TestCase {
        vector<int> coins;
        int amount;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{1, 2, 5}, 11, 3},
        {{2}, 3, -1},
        {{1}, 0, 0},
        {{1}, 2, 2},
        {{2, 5, 10, 1}, 27, 4},
        {{3, 7}, 14, 2},
        {{5, 7}, 1, -1},
        {{186, 419, 83, 408}, 6249, 20},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> coins = testCases[i].coins;
        int actual = solution.coinChange(coins, testCases[i].amount);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
