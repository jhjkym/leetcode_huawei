# 678. 有效的括号字符串

- 算法分类：贪心。
- 数据结构：两个计数变量 `low`、`high`。
- 对应代码：[678_valid_parenthesis_string.cpp](./678_valid_parenthesis_string.cpp)。
- 掌握状态：贪心范围模板。

## 背诵答案

```cpp
bool checkValidString(string s) {
    int low = 0, high = 0;
    for (char c : s) {
        if (c == '(') ++low, ++high;
        else if (c == ')') low = max(0, low - 1), --high;
        else low = max(0, low - 1), ++high;
        if (high < 0) return false;
    }
    return low == 0;
}
```

`low` 和 `high` 表示扫描当前前缀后，未匹配左括号数量的最小值和最大值。`*` 当作 `)` 会让数量减一，当作 `(` 会让数量加一，也可以当作空字符。`low` 不能小于 0，因为不能保留负数个左括号。

如果 `high < 0`，说明右括号太多，即使把所有星号当作左括号也无法匹配，立即失败。扫描结束时只有 `low == 0` 才能保证存在一种选择使所有括号匹配。

时间复杂度 `O(n)`，空间复杂度 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sorting_greedy/678_valid_parenthesis_string.cpp -o build/678
./build/678
```
