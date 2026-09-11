# leetcode_huawei

C++ 刷题练习，按主要算法归类，在题目总结中标注使用的数据结构。
每道题的源文件包含 `Solution` 和写好的固定测例，运行后显示每例结果及通过总数。

## 题目索引

| 题目 | 算法 | 数据结构 | 代码 | 总结 |
| --- | --- | --- | --- | --- |
| 3. 无重复字符的最长子串 | 滑动窗口、双指针 | 哈希表 | [C++](algorithms/sliding_window/003_longest_substring_without_repeating_characters.cpp) | [题解总结](algorithms/sliding_window/003_longest_substring_without_repeating_characters.md) |
| 1. 两数之和 | 哈希表查找 | `unordered_map` | [C++](algorithms/hash_table/001_two_sum.cpp) | [题解总结](algorithms/hash_table/001_two_sum.md) |
| 15. 三数之和 | 排序、双指针 | 数组 | [C++](algorithms/sorting_greedy/015_three_sum.cpp) | [题解总结](algorithms/sorting_greedy/015_three_sum.md) |
| 20. 有效的括号 | 栈匹配 | `stack<char>` | [C++](algorithms/stack/020_valid_parentheses.cpp) | [题解总结](algorithms/stack/020_valid_parentheses.md) |
| 394. 字符串解码 | 栈解析（不会，背诵模板） | 数字栈、字符串栈 | [C++](algorithms/stack/394_decode_string.cpp) | [题解总结](algorithms/stack/394_decode_string.md) |
| 46. 全排列 | 回溯 | 路径数组、使用标记 | [C++](algorithms/backtracking/046_permutations.cpp) | [题解总结](algorithms/backtracking/046_permutations.md) |
| 54. 螺旋矩阵 | 矩阵边界模拟 | 二维数组、结果数组 | [C++](algorithms/matrix_simulation/054_spiral_matrix.cpp) | [题解总结](algorithms/matrix_simulation/054_spiral_matrix.md) |
| 5. 最长回文子串 | 中心扩展、双指针 | 字符串 | [C++](algorithms/center_expansion/005_longest_palindromic_substring.cpp) | [题解总结](algorithms/center_expansion/005_longest_palindromic_substring.md) |
| 6. Z 字形变换 | 字符串模拟（不会，背诵模板） | 按行保存的字符串数组 | [C++](algorithms/string_simulation/006_zigzag_conversion.cpp) | [题解总结](algorithms/string_simulation/006_zigzag_conversion.md) |
| 14. 最长公共前缀 | 字符串扫描（不会，背诵模板） | 字符串数组 | [C++](algorithms/string_simulation/014_longest_common_prefix.cpp) | [题解总结](algorithms/string_simulation/014_longest_common_prefix.md) |
| 43. 字符串相乘 | 竖式乘法模拟（不会，背诵模板） | 数位数组 | [C++](algorithms/string_simulation/043_multiply_strings.cpp) | [题解总结](algorithms/string_simulation/043_multiply_strings.md) |
| 11. 盛最多水的容器 | 双指针 | 数组 | [C++](algorithms/two_pointers/011_container_with_most_water.cpp) | [题解总结](algorithms/two_pointers/011_container_with_most_water.md) |
| 42. 接雨水 | 双指针、前后缀最大值 | 数组 | [C++](algorithms/two_pointers/042_trapping_rain_water.cpp) | [题解总结](algorithms/two_pointers/042_trapping_rain_water.md) |
| 56. 合并区间 | 排序、贪心 | 区间数组 | [C++](algorithms/sorting_greedy/056_merge_intervals.cpp) | [题解总结](algorithms/sorting_greedy/056_merge_intervals.md) |
| 70. 爬楼梯 | 动态规划 | 状态数组或滚动变量 | [C++](algorithms/dynamic_programming/070_climbing_stairs.cpp) | [题解总结](algorithms/dynamic_programming/070_climbing_stairs.md) |
| 93. 复原 IP 地址 | 回溯分割（不会，背诵模板） | 路径段数组、字符串 | [C++](algorithms/backtracking/093_restore_ip_addresses.cpp) | [题解总结](algorithms/backtracking/093_restore_ip_addresses.md) |
| 72. 编辑距离 | 二维动态规划（细节不熟，待复习） | 二维状态数组 | [C++](algorithms/dynamic_programming/072_edit_distance.cpp) | [题解总结](algorithms/dynamic_programming/072_edit_distance.md) |
| 198. 打家劫舍 | 动态规划 | 状态数组或滚动变量 | [C++](algorithms/dynamic_programming/198_house_robber.cpp) | [题解总结](algorithms/dynamic_programming/198_house_robber.md) |
| 179. 最大数 | 贪心、自定义排序比较器（不会，背诵模板） | 字符串数组 | [C++](algorithms/sorting_greedy/179_largest_number.cpp) | [题解总结](algorithms/sorting_greedy/179_largest_number.md) |
| 121. 买卖股票的最佳时机 | 动态规划、一次遍历 | 数组、滚动变量 | [C++](algorithms/dynamic_programming/121_best_time_to_buy_and_sell_stock.cpp) | [题解总结](algorithms/dynamic_programming/121_best_time_to_buy_and_sell_stock.md) |
| 1702. 修改后的最大二进制字符串 | 贪心 | 字符串、计数变量 | [C++](algorithms/sorting_greedy/1702_maximum_binary_string_after_change.cpp) | [题解总结](algorithms/sorting_greedy/1702_maximum_binary_string_after_change.md) |
| 200. 岛屿数量 | 图遍历（递归 DFS） | 二维网格、递归栈 | [C++](algorithms/graph_traversal/200_number_of_islands.cpp) | [题解总结](algorithms/graph_traversal/200_number_of_islands.md) |
| 739. 每日温度 | 单调栈 | 栈、数组 | [C++](algorithms/monotonic_stack/739_daily_temperatures.cpp) | [题解总结](algorithms/monotonic_stack/739_daily_temperatures.md) |

## 目录约定

按主要解法放入 `algorithms/<算法分类>/`，代码和同名 Markdown 总结放在一起。
以某种数据结构本身为练习重点的题目可放入 `data_structures/<数据结构分类>/`。
一道题只保留一份代码，其余算法和数据结构标签记录在索引与总结中。

## 编译与运行

在仓库根目录使用支持 C++17 的 GCC 编译器运行：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sliding_window/003_longest_substring_without_repeating_characters.cpp -o build/003
./build/003
```

第 1 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/hash_table/001_two_sum.cpp -o build/001
./build/001
```

第 15 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sorting_greedy/015_three_sum.cpp -o build/015
./build/015
```

第 20 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/stack/020_valid_parentheses.cpp -o build/020
./build/020
```

第 394 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/stack/394_decode_string.cpp -o build/394
./build/394
```

第 46 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/046_permutations.cpp -o build/046
./build/046
```

第 54 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/matrix_simulation/054_spiral_matrix.cpp -o build/054
./build/054
```

第 5 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/center_expansion/005_longest_palindromic_substring.cpp -o build/005
./build/005
```

第 6 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/string_simulation/006_zigzag_conversion.cpp -o build/006
./build/006
```

第 14 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/string_simulation/014_longest_common_prefix.cpp -o build/014
./build/014
```

第 43 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/string_simulation/043_multiply_strings.cpp -o build/043
./build/043
```

第 11 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/two_pointers/011_container_with_most_water.cpp -o build/011
./build/011
```

第 42 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/two_pointers/042_trapping_rain_water.cpp -o build/042
./build/042
```

第 56 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sorting_greedy/056_merge_intervals.cpp -o build/056
./build/056
```

第 70 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/070_climbing_stairs.cpp -o build/070
./build/070
```

第 1702 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sorting_greedy/1702_maximum_binary_string_after_change.cpp -o build/1702
./build/1702
```

第 200 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/graph_traversal/200_number_of_islands.cpp -o build/200
./build/200
```

第 739 题的编译与运行命令：

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/monotonic_stack/739_daily_temperatures.cpp -o build/739
./build/739
```

测例已写在 `main` 中，无需手动输入；全部通过时退出码为 `0`，有失败时为 `1`。
第 5 题接受任意合法的最长回文子串，会同时检查长度、回文性质以及是否为输入的连续子串。
核心实现带有 `TODO` 的题目需要先完成函数，才能通过测例。
编译产物统一放在已忽略的 `build/` 目录，避免散落在题目目录中。
只检查语法、不生成可执行文件时，可以运行：

```bash
g++ -std=c++17 -fsyntax-only algorithms/sliding_window/003_longest_substring_without_repeating_characters.cpp
```
