# leetcode_huawei

C++ 刷题练习，按主要算法归类，在题目总结中标注使用的数据结构。
每道题的源文件包含 `Solution` 和写好的固定测例，运行后显示每例结果及通过总数。

## 题目索引

| 题目 | 算法 | 数据结构 | 代码 | 总结 |
| --- | --- | --- | --- | --- |
| 3. 无重复字符的最长子串 | 滑动窗口、双指针 | 哈希表 | [C++](algorithms/sliding_window/003_longest_substring_without_repeating_characters.cpp) | [题解总结](algorithms/sliding_window/003_longest_substring_without_repeating_characters.md) |
| 438. 找到字符串中所有字母异位词 | 滑动窗口、频次统计 | 26 位频次数组 | [C++](algorithms/sliding_window/438_find_all_anagrams_in_a_string.cpp) | [题解总结](algorithms/sliding_window/438_find_all_anagrams_in_a_string.md) |
| 560. 和为 K 的子数组 | 前缀和、哈希表 | 前缀和频次表 | [C++](algorithms/prefix_sum/560_subarray_sum_equals_k.cpp) | [题解总结](algorithms/prefix_sum/560_subarray_sum_equals_k.md) |
| 239. 滑动窗口最大值 | 滑动窗口、单调队列（忘记做法，待背诵） | 双端队列 `deque` | [C++](algorithms/monotonic_queue/239_sliding_window_maximum.cpp) | [题解总结](algorithms/monotonic_queue/239_sliding_window_maximum.md) |
| 1. 两数之和 | 哈希表查找 | `unordered_map` | [C++](algorithms/hash_table/001_two_sum.cpp) | [题解总结](algorithms/hash_table/001_two_sum.md) |
| 128. 最长连续序列 | 哈希表 | `unordered_set` | [C++](algorithms/hash_table/128_longest_consecutive_sequence.cpp) | [题解总结](algorithms/hash_table/128_longest_consecutive_sequence.md) |
| 554. 砖墙 | 前缀和、哈希计数（不熟悉，待复习） | 二维数组、哈希表 | [C++](algorithms/hash_table/554_brick_wall.cpp) | [题解总结](algorithms/hash_table/554_brick_wall.md) |
| 36. 有效的数独 | 直接寻址判重（不会，待背诵） | 行、列、宫布尔数组 | [C++](algorithms/hash_table/036_valid_sudoku.cpp) | [题解总结](algorithms/hash_table/036_valid_sudoku.md) |
| 215. 数组中的第K个最大元素 | 堆（快速选择待练习） | 小根堆 `priority_queue` | [C++](algorithms/quickselect/215_kth_largest_element_in_an_array.cpp) | [题解总结](algorithms/quickselect/215_kth_largest_element_in_an_array.md) |
| 15. 三数之和 | 排序、双指针 | 数组 | [C++](algorithms/sorting_greedy/015_three_sum.cpp) | [题解总结](algorithms/sorting_greedy/015_three_sum.md) |
| 16. 最接近的三数之和 | 排序、双指针 | 数组 | [C++](algorithms/sorting_greedy/016_three_sum_closest.cpp) | [题解总结](algorithms/sorting_greedy/016_three_sum_closest.md) |
| 20. 有效的括号 | 栈匹配 | `stack<char>` | [C++](algorithms/stack/020_valid_parentheses.cpp) | [题解总结](algorithms/stack/020_valid_parentheses.md) |
| 394. 字符串解码 | 栈解析（不会，背诵模板） | 数字栈、字符串栈 | [C++](algorithms/stack/394_decode_string.cpp) | [题解总结](algorithms/stack/394_decode_string.md) |
| 46. 全排列 | 回溯 | 路径数组、使用标记 | [C++](algorithms/backtracking/046_permutations.cpp) | [题解总结](algorithms/backtracking/046_permutations.md) |
| 17. 电话号码的字母组合 | 回溯 | 字母映射、路径字符串 | [C++](algorithms/backtracking/017_letter_combinations_of_a_phone_number.cpp) | [题解总结](algorithms/backtracking/017_letter_combinations_of_a_phone_number.md) |
| 54. 螺旋矩阵 | 矩阵边界模拟 | 二维数组、结果数组 | [C++](algorithms/matrix_simulation/054_spiral_matrix.cpp) | [题解总结](algorithms/matrix_simulation/054_spiral_matrix.md) |
| 48. 旋转图像 | 矩阵原地变换（不熟，待复习） | 二维数组 | [C++](algorithms/matrix_simulation/048_rotate_image.cpp) | [题解总结](algorithms/matrix_simulation/048_rotate_image.md) |
| 5. 最长回文子串 | 中心扩展、双指针 | 字符串 | [C++](algorithms/center_expansion/005_longest_palindromic_substring.cpp) | [题解总结](algorithms/center_expansion/005_longest_palindromic_substring.md) |
| 6. Z 字形变换 | 字符串模拟（不会，背诵模板） | 按行保存的字符串数组 | [C++](algorithms/string_simulation/006_zigzag_conversion.cpp) | [题解总结](algorithms/string_simulation/006_zigzag_conversion.md) |
| 14. 最长公共前缀 | 字符串扫描（不会，背诵模板） | 字符串数组 | [C++](algorithms/string_simulation/014_longest_common_prefix.cpp) | [题解总结](algorithms/string_simulation/014_longest_common_prefix.md) |
| 43. 字符串相乘 | 竖式乘法模拟（不会，背诵模板） | 数位数组 | [C++](algorithms/string_simulation/043_multiply_strings.cpp) | [题解总结](algorithms/string_simulation/043_multiply_strings.md) |
| 11. 盛最多水的容器 | 双指针 | 数组 | [C++](algorithms/two_pointers/011_container_with_most_water.cpp) | [题解总结](algorithms/two_pointers/011_container_with_most_water.md) |
| 42. 接雨水 | 双指针、前后缀最大值 | 数组 | [C++](algorithms/two_pointers/042_trapping_rain_water.cpp) | [题解总结](algorithms/two_pointers/042_trapping_rain_water.md) |
| 88. 合并两个有序数组 | 逆向双指针 | 数组 | [C++](algorithms/two_pointers/088_merge_sorted_array.cpp) | [题解总结](algorithms/two_pointers/088_merge_sorted_array.md) |
| 125. 验证回文串 | 双指针（isalnum、tolower 没用过，待复习） | 字符串 | [C++](algorithms/two_pointers/125_valid_palindrome.cpp) | [题解总结](algorithms/two_pointers/125_valid_palindrome.md) |
| 56. 合并区间 | 排序、贪心 | 区间数组 | [C++](algorithms/sorting_greedy/056_merge_intervals.cpp) | [题解总结](algorithms/sorting_greedy/056_merge_intervals.md) |
| 57. 插入区间 | 有序区间扫描、合并（不会，待背诵） | 区间数组 | [C++](algorithms/sorting_greedy/057_insert_interval.cpp) | [题解总结](algorithms/sorting_greedy/057_insert_interval.md) |
| 45. 跳跃游戏 II | 贪心（不熟，待复习） | 数组、边界变量 | [C++](algorithms/sorting_greedy/045_jump_game_ii.cpp) | [题解总结](algorithms/sorting_greedy/045_jump_game_ii.md) |
| 678. 有效的括号字符串 | 贪心（待背诵） | `low`、`high` 范围变量 | [C++](algorithms/sorting_greedy/678_valid_parenthesis_string.cpp) | [题解总结](algorithms/sorting_greedy/678_valid_parenthesis_string.md) |
| 70. 爬楼梯 | 动态规划 | 状态数组或滚动变量 | [C++](algorithms/dynamic_programming/070_climbing_stairs.cpp) | [题解总结](algorithms/dynamic_programming/070_climbing_stairs.md) |
| 63. 不同路径 II | 动态规划（不会，待背诵） | 一维状态数组 | [C++](algorithms/dynamic_programming/063_unique_paths_ii.cpp) | [题解总结](algorithms/dynamic_programming/063_unique_paths_ii.md) |
| 221. 最大正方形 | 动态规划（没做过，待背诵） | 二维状态数组 | [C++](algorithms/dynamic_programming/221_maximal_square.cpp) | [题解总结](algorithms/dynamic_programming/221_maximal_square.md) |
| 264. 丑数 II | 动态规划、三指针（不会，待背诵） | 状态数组、三个指针 | [C++](algorithms/dynamic_programming/264_ugly_number_ii.cpp) | [题解总结](algorithms/dynamic_programming/264_ugly_number_ii.md) |
| 300. 最长递增子序列 | 动态规划（待背诵） | 状态数组 `dp` | [C++](algorithms/dynamic_programming/300_longest_increasing_subsequence.cpp) | [题解总结](algorithms/dynamic_programming/300_longest_increasing_subsequence.md) |
| 240. 搜索二维矩阵 II | 矩阵楼梯搜索（不会，待背诵） | 二维数组 | [C++](algorithms/matrix_search/240_search_a_2d_matrix_ii.cpp) | [题解总结](algorithms/matrix_search/240_search_a_2d_matrix_ii.md) |
| 66. 加一 | 数组模拟（不会，待背诵） | `vector<int>` | [C++](algorithms/array_simulation/066_plus_one.cpp) | [题解总结](algorithms/array_simulation/066_plus_one.md) |
| 136. 只出现一次的数字 | 位运算（异或） | 数组、整数变量 | [C++](algorithms/bit_manipulation/136_single_number.cpp) | [题解总结](algorithms/bit_manipulation/136_single_number.md) |
| 146. LRU 缓存 | 哈希表、双向链表（很难不会，需要大量背诵） | `unordered_map`、`list` | [C++](algorithms/hash_table/146_lru_cache.cpp) | [题解总结](algorithms/hash_table/146_lru_cache.md) |
| 160. 相交链表 | 双指针、链表 | 单链表节点 | [C++](algorithms/linked_list/160_intersection_of_two_linked_lists.cpp) | [题解总结](algorithms/linked_list/160_intersection_of_two_linked_lists.md) |
| 162. 寻找峰值 | 二分查找 | 数组 | [C++](algorithms/binary_search/162_find_peak_element.cpp) | [题解总结](algorithms/binary_search/162_find_peak_element.md) |
| 704. 二分查找 | 二分查找 | 升序数组 | [C++](algorithms/binary_search/704_binary_search.cpp) | [题解总结](algorithms/binary_search/704_binary_search.md) |
| 93. 复原 IP 地址 | 回溯分割（不会，背诵模板） | 路径段数组、字符串 | [C++](algorithms/backtracking/093_restore_ip_addresses.cpp) | [题解总结](algorithms/backtracking/093_restore_ip_addresses.md) |
| 79. 单词搜索 | DFS、回溯（不会，待背诵） | 二维网格、递归栈 | [C++](algorithms/backtracking/079_word_search.cpp) | [题解总结](algorithms/backtracking/079_word_search.md) |
| 72. 编辑距离 | 二维动态规划（细节不熟，待复习） | 二维状态数组 | [C++](algorithms/dynamic_programming/072_edit_distance.cpp) | [题解总结](algorithms/dynamic_programming/072_edit_distance.md) |
| 198. 打家劫舍 | 动态规划 | 状态数组或滚动变量 | [C++](algorithms/dynamic_programming/198_house_robber.cpp) | [题解总结](algorithms/dynamic_programming/198_house_robber.md) |
| 179. 最大数 | 贪心、自定义排序比较器（不会，背诵模板） | 字符串数组 | [C++](algorithms/sorting_greedy/179_largest_number.cpp) | [题解总结](algorithms/sorting_greedy/179_largest_number.md) |
| 121. 买卖股票的最佳时机 | 动态规划、一次遍历 | 数组、滚动变量 | [C++](algorithms/dynamic_programming/121_best_time_to_buy_and_sell_stock.cpp) | [题解总结](algorithms/dynamic_programming/121_best_time_to_buy_and_sell_stock.md) |
| 1702. 修改后的最大二进制字符串 | 贪心 | 字符串、计数变量 | [C++](algorithms/sorting_greedy/1702_maximum_binary_string_after_change.cpp) | [题解总结](algorithms/sorting_greedy/1702_maximum_binary_string_after_change.md) |
| 200. 岛屿数量 | 图遍历（递归 DFS） | 二维网格、递归栈 | [C++](algorithms/graph_traversal/200_number_of_islands.cpp) | [题解总结](algorithms/graph_traversal/200_number_of_islands.md) |
| 226. 翻转二叉树 | 二叉树 DFS（不会，待背诵） | 二叉树节点、递归栈 | [C++](algorithms/tree_traversal/226_invert_binary_tree.cpp) | [题解总结](algorithms/tree_traversal/226_invert_binary_tree.md) |
| 994. 腐烂的橘子 | 多源 BFS（不会，待背诵） | 二维网格、队列 | [C++](algorithms/graph_traversal/994_rotting_oranges.cpp) | [题解总结](algorithms/graph_traversal/994_rotting_oranges.md) |
| 721. 账户合并 | 建图、DFS、哈希表（易背诵） | 邻接表、访问集合 | [C++](algorithms/graph_traversal/721_accounts_merge.cpp) | [题解总结](algorithms/graph_traversal/721_accounts_merge.md) |
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
