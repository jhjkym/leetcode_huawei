# 125. 验证回文串

- 算法分类：双指针。
- 数据结构：字符串。
- 对应代码：[125_valid_palindrome.cpp](./125_valid_palindrome.cpp)。
- 掌握状态：已提供答案模板，待复习背诵。
- 函数使用状态：**`isalnum`、`tolower` 以前没用过，需重点复习。**
- 测试说明：现有 16 组固定测例已全部通过。

## 题意

忽略大小写和非字母数字字符，判断字符串是否正着读、反着读都一样。
数字需要保留；处理后为空字符串也算回文串。本题输入为可打印 ASCII 字符。

- `"A man, a plan, a canal: Panama"` → `true`。
- `"race a car"` → `false`。
- `" "` → `true`。
- `"0P"` → `false`，数字不能跳过。

## 背诵模板

**左右两头站，符号跳过去；转小写再比较，不同返回假；两端往中走，走完返回真。**

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) ++left;
            while (left < right && !isalnum(s[right])) --right;

            if (tolower(s[left]) != tolower(s[right])) return false;

            ++left;
            --right;
        }
        return true;
    }
};
```

## 没用过的函数：重点复习

这两个函数来自 `<cctype>`，当前代码的 `<bits/stdc++.h>` 已包含它。

| 函数 | 作用 | 返回值 | 例子 |
| --- | --- | --- | --- |
| `isalnum(c)` | 判断是否为字母或数字 | 是则返回非零 `int`，否则返回 `0` | `'A'`、`'a'`、`'7'` 为非零；空格、逗号为 `0` |
| `tolower(c)` | 将大写字母转为小写，其他字符保持原样 | 转换后的字符编码，类型为 `int` | `'A'` → `'a'`，`'7'` → `'7'` |

### isalnum：判断能不能参与比较

```cpp
!isalnum(s[left]) // 当前字符不是字母或数字，需要跳过
```

不要写 `isalnum(c) == 1`，因为它只保证真时返回非零值，不保证恰好是 `1`。

### tolower：忽略大小写比较

```cpp
tolower(s[left]) != tolower(s[right])
```

比较两端转成小写后的结果。例如 `'A'` 和 `'a'` 转换后相等。
`tolower` 不会修改原字符串，只返回转换结果。

本题字符范围允许直接传入 `char`。对于可能含负 `char` 值的其他输入，应先转换为 `unsigned char`，例如 `tolower(static_cast<unsigned char>(c))`；`isalnum` 同理。

## 其他接口和语法

| 用法 | 说明 |
| --- | --- |
| `s.size()` | 返回字符串长度，类型为无符号整数 `size_t` |
| `static_cast<int>(x)` | 显式类型转换语法，不是函数；这里先转换再减一，避免空串时无符号下溢 |
| `boolalpha` | 输出格式控制符，让布尔值显示为 `true/false` |
| `quoted(input)` | 来自 `<iomanip>`，输出带双引号的字符串，并转义内部双引号和反斜杠 |
| `ios::sync_with_stdio(false)` | 关闭 C++ 流与 C 标准输入输出的同步 |
| `cin.tie(nullptr)` | 解除 `cin` 与 `cout` 的绑定，读输入前不再自动刷新 `cout` |

## 易错点与复杂度

- 两个内层循环也要检查 `left < right`，避免跳过符号时越界。
- `&&` 从左到右短路求值，范围检查要放在字符访问前面。
- 不需要实际删除字符，通过移动指针跳过即可。
- 两端匹配后，两个指针都要移动。
- 全是符号或空格时，两指针相遇，最终返回 `true`。
- 时间复杂度为 `O(n)`；算法辅助空间为 `O(1)`，按值传参 `string s` 产生的字符串副本另占 `O(n)` 空间。

## 编译运行

在仓库根目录执行：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/two_pointers/125_valid_palindrome.cpp -o build/125
./build/125
```
