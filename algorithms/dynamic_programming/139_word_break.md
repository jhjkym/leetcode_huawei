# 139. 单词拆分

- 算法分类：动态规划、字符串分割。
- 数据结构：状态数组、哈希集合。
- 对应代码：[139_word_break.cpp](./139_word_break.cpp)。
- 掌握状态：前缀动态规划模板。

## 背诵答案

```cpp
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && words.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
```

## 背诵口诀

> `dp[i]` 表示前 `i` 个字符能拆分；
> 枚举最后一个单词的起点 `j`；
> 前面能拆，最后一段在字典中，当前就能拆。

状态转移条件是：

```cpp
dp[j] && words.count(s.substr(j, i - j))
```

- `dp[j]`：下标 `[0, j)` 的前缀可以成功拆分；
- `s.substr(j, i - j)`：最后一段 `[j, i)` 是字典中的单词。

两者同时成立，就令 `dp[i] = true`。

## 为什么 `dp[0] = true`

空前缀不需要任何单词就能完成拆分。它是状态转移的起点，使字符串开头本身就是一个字典单词时能够得到 `true`。

## 易错点

- `dp` 长度是 `n + 1`，`dp[i]` 对应前 `i` 个字符。
- `substr` 的第二个参数是长度，所以写成 `i - j`。
- 找到一种合法拆分后即可 `break`。
- 字典转换为 `unordered_set`，便于快速查询单词是否存在。
- 字典单词允许重复使用。

共有 `O(n²)` 个分割位置；考虑 `substr` 创建字符串的成本，最坏时间复杂度为 `O(n³)`，空间复杂度为 `O(n + 字典大小)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/139_word_break.cpp -o build/139
./build/139
```
