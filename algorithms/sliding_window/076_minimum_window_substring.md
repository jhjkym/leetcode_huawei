# 76. 最小覆盖子串

- 算法分类：滑动窗口、双指针、频次统计。
- 数据结构：字符频次数组。
- 对应代码：[076_minimum_window_substring.cpp](./076_minimum_window_substring.cpp)。
- 掌握状态：可变长度滑动窗口模板。

## 背诵答案

```cpp
string minWindow(string s, string t) {
    if (t.empty()) return "";

    int need[128]{};
    for (char c : t) need[c]++;

    int left = 0, count = t.size();
    int start = 0, minLen = INT_MAX;
    for (int right = 0; right < s.size(); ++right) {
        if (need[s[right]]-- > 0) count--;

        while (count == 0) {
            if (right - left + 1 < minLen) {
                start = left;
                minLen = right - left + 1;
            }
            if (++need[s[left++]] > 0) count++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

`need[c]` 表示当前窗口还缺少多少个字符 `c`，`count` 表示总共还缺少多少个字符（包含重复字符）。

- 右指针加入字符：若减一前 `need[c] > 0`，它补上了一个缺失字符，令 `count--`。
- 当 `count == 0` 时，当前窗口已经覆盖 `t`，持续移动左指针以寻找更短答案。
- 左端字符移出后令 `need[c]++`；若结果大于 `0`，说明窗口重新缺少该字符，停止收缩。

## 背诵口诀

> 右边进：先判断，再减；
> 覆盖全：更新答案，左边出；
> 左边出：先加，再判断。

只需记住两个关键表达式：

```cpp
if (need[s[right]]-- > 0) count--;  // 进入的是缺少字符
if (++need[s[left++]] > 0) count++; // 移出后重新缺少
```

两个指针都只向右移动一次，时间复杂度为 `O(|s| + |t|)`，空间复杂度为 `O(1)`。

## 易错点

- `count` 统计字符总数而不是字符种类，因此能正确处理 `t = "AABC"` 这样的重复字符。
- 多余字符对应的 `need` 可以为负数；移出它们不会让窗口失效。
- 没有合法窗口时返回空字符串。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sliding_window/076_minimum_window_substring.cpp -o build/076
./build/076
```
