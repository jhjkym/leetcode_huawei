# leetcode_huawei

C++ 刷题练习，按主要算法归类，在题目总结中标注使用的数据结构。
每道题的源文件包含 `Solution` 和写好的固定测例，运行后显示每例结果及通过总数。

Hot 100 的题型归纳、母模板和背诵顺序见：[Hot 100 题型与背诵指南](HOT100_STUDY_GUIDE.md)。

## 题目索引

| 题目 | 算法 | 数据结构 | 代码 | 总结 |
| --- | --- | --- | --- | --- |
| 3. 无重复字符的最长子串 | 滑动窗口、双指针 | 哈希表 | [C++](algorithms/sliding_window/003_longest_substring_without_repeating_characters.cpp) | [题解总结](algorithms/sliding_window/003_longest_substring_without_repeating_characters.md) |
| 76. 最小覆盖子串 | 滑动窗口、双指针 | 字符频次数组 | [C++](algorithms/sliding_window/076_minimum_window_substring.cpp) | [题解总结](algorithms/sliding_window/076_minimum_window_substring.md) |
| 438. 找到字符串中所有字母异位词 | 滑动窗口、频次统计 | 26 位频次数组 | [C++](algorithms/sliding_window/438_find_all_anagrams_in_a_string.cpp) | [题解总结](algorithms/sliding_window/438_find_all_anagrams_in_a_string.md) |
| 560. 和为 K 的子数组 | 前缀和、哈希表 | 前缀和频次表 | [C++](algorithms/prefix_sum/560_subarray_sum_equals_k.cpp) | [题解总结](algorithms/prefix_sum/560_subarray_sum_equals_k.md) |
| 238. 除了自身以外数组的乘积 | 前缀积、后缀积 | 数组、滚动变量 | [C++](algorithms/prefix_sum/238_product_of_array_except_self.cpp) | [题解总结](algorithms/prefix_sum/238_product_of_array_except_self.md) |
| 239. 滑动窗口最大值 | 滑动窗口、单调队列（忘记做法，待背诵） | 双端队列 `deque` | [C++](algorithms/monotonic_queue/239_sliding_window_maximum.cpp) | [题解总结](algorithms/monotonic_queue/239_sliding_window_maximum.md) |
| 1. 两数之和 | 哈希表查找 | `unordered_map` | [C++](algorithms/hash_table/001_two_sum.cpp) | [题解总结](algorithms/hash_table/001_two_sum.md) |
| 41. 缺失的第一个正数 | 原地哈希、交换归位 | 数组 | [C++](algorithms/hash_table/041_first_missing_positive.cpp) | [题解总结](algorithms/hash_table/041_first_missing_positive.md) |
| 49. 字母异位词分组 | 哈希表、排序 | `unordered_map` | [C++](algorithms/hash_table/049_group_anagrams.cpp) | [题解总结](algorithms/hash_table/049_group_anagrams.md) |
| 347. 前 K 个高频元素 | 哈希计数、桶排序 | `unordered_map`、二维桶数组 | [C++](algorithms/hash_table/347_top_k_frequent_elements.cpp) | [题解总结](algorithms/hash_table/347_top_k_frequent_elements.md) |
| 128. 最长连续序列 | 哈希表 | `unordered_set` | [C++](algorithms/hash_table/128_longest_consecutive_sequence.cpp) | [题解总结](algorithms/hash_table/128_longest_consecutive_sequence.md) |
| 554. 砖墙 | 前缀和、哈希计数（不熟悉，待复习） | 二维数组、哈希表 | [C++](algorithms/hash_table/554_brick_wall.cpp) | [题解总结](algorithms/hash_table/554_brick_wall.md) |
| 36. 有效的数独 | 直接寻址判重（不会，待背诵） | 行、列、宫布尔数组 | [C++](algorithms/hash_table/036_valid_sudoku.cpp) | [题解总结](algorithms/hash_table/036_valid_sudoku.md) |
| 215. 数组中的第K个最大元素 | 堆（快速选择待练习） | 小根堆 `priority_queue` | [C++](algorithms/quickselect/215_kth_largest_element_in_an_array.cpp) | [题解总结](algorithms/quickselect/215_kth_largest_element_in_an_array.md) |
| 15. 三数之和 | 排序、双指针 | 数组 | [C++](algorithms/sorting_greedy/015_three_sum.cpp) | [题解总结](algorithms/sorting_greedy/015_three_sum.md) |
| 16. 最接近的三数之和 | 排序、双指针 | 数组 | [C++](algorithms/sorting_greedy/016_three_sum_closest.cpp) | [题解总结](algorithms/sorting_greedy/016_three_sum_closest.md) |
| 20. 有效的括号 | 栈匹配 | `stack<char>` | [C++](algorithms/stack/020_valid_parentheses.cpp) | [题解总结](algorithms/stack/020_valid_parentheses.md) |
| 32. 最长有效括号 | 栈、边界下标 | `stack<int>` | [C++](algorithms/stack/032_longest_valid_parentheses.cpp) | [题解总结](algorithms/stack/032_longest_valid_parentheses.md) |
| 155. 最小栈 | 栈、辅助状态 | 数据栈、最小值栈 | [C++](data_structures/stack/155_min_stack.cpp) | [题解总结](data_structures/stack/155_min_stack.md) |
| 394. 字符串解码 | 栈解析（不会，背诵模板） | 数字栈、字符串栈 | [C++](algorithms/stack/394_decode_string.cpp) | [题解总结](algorithms/stack/394_decode_string.md) |
| 46. 全排列 | 回溯 | 路径数组、使用标记 | [C++](algorithms/backtracking/046_permutations.cpp) | [题解总结](algorithms/backtracking/046_permutations.md) |
| 22. 括号生成 | 回溯、剪枝 | 路径字符串、递归栈 | [C++](algorithms/backtracking/022_generate_parentheses.cpp) | [题解总结](algorithms/backtracking/022_generate_parentheses.md) |
| 39. 组合总和 | 回溯、排序剪枝 | 路径数组、递归栈 | [C++](algorithms/backtracking/039_combination_sum.cpp) | [题解总结](algorithms/backtracking/039_combination_sum.md) |
| 51. N 皇后 | 回溯、剪枝 | 棋盘、列与对角线占用数组 | [C++](algorithms/backtracking/051_n_queens.cpp) | [题解总结](algorithms/backtracking/051_n_queens.md) |
| 78. 子集 | 回溯 | 路径数组、递归栈 | [C++](algorithms/backtracking/078_subsets.cpp) | [题解总结](algorithms/backtracking/078_subsets.md) |
| 17. 电话号码的字母组合 | 回溯 | 字母映射、路径字符串 | [C++](algorithms/backtracking/017_letter_combinations_of_a_phone_number.cpp) | [题解总结](algorithms/backtracking/017_letter_combinations_of_a_phone_number.md) |
| 54. 螺旋矩阵 | 矩阵边界模拟 | 二维数组、结果数组 | [C++](algorithms/matrix_simulation/054_spiral_matrix.cpp) | [题解总结](algorithms/matrix_simulation/054_spiral_matrix.md) |
| 48. 旋转图像 | 矩阵原地变换（不熟，待复习） | 二维数组 | [C++](algorithms/matrix_simulation/048_rotate_image.cpp) | [题解总结](algorithms/matrix_simulation/048_rotate_image.md) |
| 73. 矩阵置零 | 矩阵模拟、原地标记 | 二维数组 | [C++](algorithms/matrix_simulation/073_set_matrix_zeroes.cpp) | [题解总结](algorithms/matrix_simulation/073_set_matrix_zeroes.md) |
| 5. 最长回文子串 | 中心扩展、双指针 | 字符串 | [C++](algorithms/center_expansion/005_longest_palindromic_substring.cpp) | [题解总结](algorithms/center_expansion/005_longest_palindromic_substring.md) |
| 6. Z 字形变换 | 字符串模拟（不会，背诵模板） | 按行保存的字符串数组 | [C++](algorithms/string_simulation/006_zigzag_conversion.cpp) | [题解总结](algorithms/string_simulation/006_zigzag_conversion.md) |
| 14. 最长公共前缀 | 字符串扫描（不会，背诵模板） | 字符串数组 | [C++](algorithms/string_simulation/014_longest_common_prefix.cpp) | [题解总结](algorithms/string_simulation/014_longest_common_prefix.md) |
| 43. 字符串相乘 | 竖式乘法模拟（不会，背诵模板） | 数位数组 | [C++](algorithms/string_simulation/043_multiply_strings.cpp) | [题解总结](algorithms/string_simulation/043_multiply_strings.md) |
| 11. 盛最多水的容器 | 双指针 | 数组 | [C++](algorithms/two_pointers/011_container_with_most_water.cpp) | [题解总结](algorithms/two_pointers/011_container_with_most_water.md) |
| 42. 接雨水 | 双指针、前后缀最大值 | 数组 | [C++](algorithms/two_pointers/042_trapping_rain_water.cpp) | [题解总结](algorithms/two_pointers/042_trapping_rain_water.md) |
| 88. 合并两个有序数组 | 逆向双指针 | 数组 | [C++](algorithms/two_pointers/088_merge_sorted_array.cpp) | [题解总结](algorithms/two_pointers/088_merge_sorted_array.md) |
| 125. 验证回文串 | 双指针（isalnum、tolower 没用过，待复习） | 字符串 | [C++](algorithms/two_pointers/125_valid_palindrome.cpp) | [题解总结](algorithms/two_pointers/125_valid_palindrome.md) |
| 75. 颜色分类 | 双指针、荷兰国旗 | 数组、三个下标 | [C++](algorithms/two_pointers/075_sort_colors.cpp) | [题解总结](algorithms/two_pointers/075_sort_colors.md) |
| 287. 寻找重复数 | Floyd 判圈、快慢指针 | 数组模拟链表 | [C++](algorithms/two_pointers/287_find_the_duplicate_number.cpp) | [题解总结](algorithms/two_pointers/287_find_the_duplicate_number.md) |
| 31. 下一个排列 | 数组模拟、双指针 | 原地数组 | [C++](algorithms/array_simulation/031_next_permutation.cpp) | [题解总结](algorithms/array_simulation/031_next_permutation.md) |
| 56. 合并区间 | 排序、贪心 | 区间数组 | [C++](algorithms/sorting_greedy/056_merge_intervals.cpp) | [题解总结](algorithms/sorting_greedy/056_merge_intervals.md) |
| 57. 插入区间 | 有序区间扫描、合并（不会，待背诵） | 区间数组 | [C++](algorithms/sorting_greedy/057_insert_interval.cpp) | [题解总结](algorithms/sorting_greedy/057_insert_interval.md) |
| 45. 跳跃游戏 II | 贪心（不熟，待复习） | 数组、边界变量 | [C++](algorithms/sorting_greedy/045_jump_game_ii.cpp) | [题解总结](algorithms/sorting_greedy/045_jump_game_ii.md) |
| 55. 跳跃游戏 | 贪心 | 数组、最远位置变量 | [C++](algorithms/sorting_greedy/055_jump_game.cpp) | [题解总结](algorithms/sorting_greedy/055_jump_game.md) |
| 678. 有效的括号字符串 | 贪心（待背诵） | `low`、`high` 范围变量 | [C++](algorithms/sorting_greedy/678_valid_parenthesis_string.cpp) | [题解总结](algorithms/sorting_greedy/678_valid_parenthesis_string.md) |
| 763. 划分字母区间 | 贪心、区间划分 | 字符最后位置数组 | [C++](algorithms/sorting_greedy/763_partition_labels.cpp) | [题解总结](algorithms/sorting_greedy/763_partition_labels.md) |
| 53. 最大子数组和 | 动态规划、Kadane 算法 | 数组、滚动变量 | [C++](algorithms/dynamic_programming/053_maximum_subarray.cpp) | [题解总结](algorithms/dynamic_programming/053_maximum_subarray.md) |
| 70. 爬楼梯 | 动态规划 | 状态数组或滚动变量 | [C++](algorithms/dynamic_programming/070_climbing_stairs.cpp) | [题解总结](algorithms/dynamic_programming/070_climbing_stairs.md) |
| 62. 不同路径 | 动态规划 | 一维状态数组 | [C++](algorithms/dynamic_programming/062_unique_paths.cpp) | [题解总结](algorithms/dynamic_programming/062_unique_paths.md) |
| 63. 不同路径 II | 动态规划（不会，待背诵） | 一维状态数组 | [C++](algorithms/dynamic_programming/063_unique_paths_ii.cpp) | [题解总结](algorithms/dynamic_programming/063_unique_paths_ii.md) |
| 64. 最小路径和 | 动态规划 | 一维状态数组 | [C++](algorithms/dynamic_programming/064_minimum_path_sum.cpp) | [题解总结](algorithms/dynamic_programming/064_minimum_path_sum.md) |
| 221. 最大正方形 | 动态规划（没做过，待背诵） | 二维状态数组 | [C++](algorithms/dynamic_programming/221_maximal_square.cpp) | [题解总结](algorithms/dynamic_programming/221_maximal_square.md) |
| 264. 丑数 II | 动态规划、三指针（不会，待背诵） | 状态数组、三个指针 | [C++](algorithms/dynamic_programming/264_ugly_number_ii.cpp) | [题解总结](algorithms/dynamic_programming/264_ugly_number_ii.md) |
| 279. 完全平方数 | 动态规划、完全背包 | 一维状态数组 | [C++](algorithms/dynamic_programming/279_perfect_squares.cpp) | [题解总结](algorithms/dynamic_programming/279_perfect_squares.md) |
| 300. 最长递增子序列 | 动态规划 | 状态数组 `dp` | [C++](algorithms/dynamic_programming/300_longest_increasing_subsequence.cpp) | [题解总结](algorithms/dynamic_programming/300_longest_increasing_subsequence.md) |
| 322. 零钱兑换 | 动态规划、完全背包 | 一维状态数组 | [C++](algorithms/dynamic_programming/322_coin_change.cpp) | [题解总结](algorithms/dynamic_programming/322_coin_change.md) |
| 416. 分割等和子集 | 动态规划、0/1 背包 | 一维状态数组 | [C++](algorithms/dynamic_programming/416_partition_equal_subset_sum.cpp) | [题解总结](algorithms/dynamic_programming/416_partition_equal_subset_sum.md) |
| 1143. 最长公共子序列 | 动态规划 | 二维状态数组 | [C++](algorithms/dynamic_programming/1143_longest_common_subsequence.cpp) | [题解总结](algorithms/dynamic_programming/1143_longest_common_subsequence.md) |
| 240. 搜索二维矩阵 II | 矩阵楼梯搜索（不会，待背诵） | 二维数组 | [C++](algorithms/matrix_search/240_search_a_2d_matrix_ii.cpp) | [题解总结](algorithms/matrix_search/240_search_a_2d_matrix_ii.md) |
| 74. 搜索二维矩阵 | 二分查找、矩阵一维化 | 二维矩阵 | [C++](algorithms/matrix_search/074_search_a_2d_matrix.cpp) | [题解总结](algorithms/matrix_search/074_search_a_2d_matrix.md) |
| 66. 加一 | 数组模拟（不会，待背诵） | `vector<int>` | [C++](algorithms/array_simulation/066_plus_one.cpp) | [题解总结](algorithms/array_simulation/066_plus_one.md) |
| 189. 轮转数组 | 数组模拟、三次翻转 | `vector<int>` | [C++](algorithms/array_simulation/189_rotate_array.cpp) | [题解总结](algorithms/array_simulation/189_rotate_array.md) |
| 136. 只出现一次的数字 | 位运算（异或） | 数组、整数变量 | [C++](algorithms/bit_manipulation/136_single_number.cpp) | [题解总结](algorithms/bit_manipulation/136_single_number.md) |
| 169. 多数元素 | 摩尔投票 | 候选人与票数变量 | [C++](algorithms/array_simulation/169_majority_element.cpp) | [题解总结](algorithms/array_simulation/169_majority_element.md) |
| 146. LRU 缓存 | 哈希表、双向链表 | `unordered_map`、`list` | [C++](algorithms/hash_table/146_lru_cache.cpp) | [题解总结](algorithms/hash_table/146_lru_cache.md) |
| 2. 两数相加 | 链表、竖式加法模拟 | 单链表、哑节点 | [C++](algorithms/linked_list/002_add_two_numbers.cpp) | [题解总结](algorithms/linked_list/002_add_two_numbers.md) |
| 19. 删除链表的倒数第 N 个结点 | 链表、快慢指针 | 单链表、哑节点 | [C++](algorithms/linked_list/019_remove_nth_node_from_end_of_list.cpp) | [题解总结](algorithms/linked_list/019_remove_nth_node_from_end_of_list.md) |
| 21. 合并两个有序链表 | 链表、双指针 | 单链表、哑节点 | [C++](algorithms/linked_list/021_merge_two_sorted_lists.cpp) | [题解总结](algorithms/linked_list/021_merge_two_sorted_lists.md) |
| 23. 合并 K 个升序链表 | 链表、两两归并 | 单链表、哑节点 | [C++](algorithms/linked_list/023_merge_k_sorted_lists.cpp) | [题解总结](algorithms/linked_list/023_merge_k_sorted_lists.md) |
| 24. 两两交换链表中的节点 | 链表、迭代 | 单链表、哑节点 | [C++](algorithms/linked_list/024_swap_nodes_in_pairs.cpp) | [题解总结](algorithms/linked_list/024_swap_nodes_in_pairs.md) |
| 25. K 个一组翻转链表 | 链表、分组反转 | 单链表、哑节点 | [C++](algorithms/linked_list/025_reverse_nodes_in_k_group.cpp) | [题解总结](algorithms/linked_list/025_reverse_nodes_in_k_group.md) |
| 138. 随机链表的复制 | 链表、哈希表 | 单链表、`unordered_map` | [C++](algorithms/linked_list/138_copy_list_with_random_pointer.cpp) | [题解总结](algorithms/linked_list/138_copy_list_with_random_pointer.md) |
| 141. 环形链表 | Floyd 判圈、快慢指针 | 单链表节点 | [C++](algorithms/linked_list/141_linked_list_cycle.cpp) | [题解总结](algorithms/linked_list/141_linked_list_cycle.md) |
| 142. 环形链表 II | Floyd 判圈、快慢指针 | 单链表节点 | [C++](algorithms/linked_list/142_linked_list_cycle_ii.cpp) | [题解总结](algorithms/linked_list/142_linked_list_cycle_ii.md) |
| 148. 排序链表 | 归并排序、快慢指针 | 单链表、哑节点 | [C++](algorithms/linked_list/148_sort_list.cpp) | [题解总结](algorithms/linked_list/148_sort_list.md) |
| 160. 相交链表 | 双指针、链表 | 单链表节点 | [C++](algorithms/linked_list/160_intersection_of_two_linked_lists.cpp) | [题解总结](algorithms/linked_list/160_intersection_of_two_linked_lists.md) |
| 206. 反转链表 | 链表、迭代 | 单链表节点、三指针 | [C++](algorithms/linked_list/206_reverse_linked_list.cpp) | [题解总结](algorithms/linked_list/206_reverse_linked_list.md) |
| 234. 回文链表 | 快慢指针、反转链表 | 单链表节点 | [C++](algorithms/linked_list/234_palindrome_linked_list.cpp) | [题解总结](algorithms/linked_list/234_palindrome_linked_list.md) |
| 162. 寻找峰值 | 二分查找 | 数组 | [C++](algorithms/binary_search/162_find_peak_element.cpp) | [题解总结](algorithms/binary_search/162_find_peak_element.md) |
| 4. 寻找两个正序数组的中位数 | 二分查找、数组分割 | 两个升序数组 | [C++](algorithms/binary_search/004_median_of_two_sorted_arrays.cpp) | [题解总结](algorithms/binary_search/004_median_of_two_sorted_arrays.md) |
| 33. 搜索旋转排序数组 | 二分查找、旋转数组 | 数组 | [C++](algorithms/binary_search/033_search_in_rotated_sorted_array.cpp) | [题解总结](algorithms/binary_search/033_search_in_rotated_sorted_array.md) |
| 34. 在排序数组中查找元素的第一个和最后一个位置 | 二分查找、左右边界 | 升序数组 | [C++](algorithms/binary_search/034_find_first_and_last_position_of_element_in_sorted_array.cpp) | [题解总结](algorithms/binary_search/034_find_first_and_last_position_of_element_in_sorted_array.md) |
| 35. 搜索插入位置 | 二分查找、左边界 | 升序数组 | [C++](algorithms/binary_search/035_search_insert_position.cpp) | [题解总结](algorithms/binary_search/035_search_insert_position.md) |
| 153. 寻找旋转排序数组中的最小值 | 二分查找、旋转数组 | 数组 | [C++](algorithms/binary_search/153_find_minimum_in_rotated_sorted_array.cpp) | [题解总结](algorithms/binary_search/153_find_minimum_in_rotated_sorted_array.md) |
| 704. 二分查找 | 二分查找 | 升序数组 | [C++](algorithms/binary_search/704_binary_search.cpp) | [题解总结](algorithms/binary_search/704_binary_search.md) |
| 93. 复原 IP 地址 | 回溯分割（不会，背诵模板） | 路径段数组、字符串 | [C++](algorithms/backtracking/093_restore_ip_addresses.cpp) | [题解总结](algorithms/backtracking/093_restore_ip_addresses.md) |
| 79. 单词搜索 | DFS、回溯 | 二维网格、递归栈 | [C++](algorithms/backtracking/079_word_search.cpp) | [题解总结](algorithms/backtracking/079_word_search.md) |
| 131. 分割回文串 | 回溯、双指针判断回文 | 路径数组、递归栈 | [C++](algorithms/backtracking/131_palindrome_partitioning.cpp) | [题解总结](algorithms/backtracking/131_palindrome_partitioning.md) |
| 72. 编辑距离 | 动态规划 | 二维状态数组 | [C++](algorithms/dynamic_programming/072_edit_distance.cpp) | [题解总结](algorithms/dynamic_programming/072_edit_distance.md) |
| 198. 打家劫舍 | 动态规划 | 状态数组或滚动变量 | [C++](algorithms/dynamic_programming/198_house_robber.cpp) | [题解总结](algorithms/dynamic_programming/198_house_robber.md) |
| 179. 最大数 | 贪心、自定义排序比较器（不会，背诵模板） | 字符串数组 | [C++](algorithms/sorting_greedy/179_largest_number.cpp) | [题解总结](algorithms/sorting_greedy/179_largest_number.md) |
| 121. 买卖股票的最佳时机 | 动态规划、一次遍历 | 数组、滚动变量 | [C++](algorithms/dynamic_programming/121_best_time_to_buy_and_sell_stock.cpp) | [题解总结](algorithms/dynamic_programming/121_best_time_to_buy_and_sell_stock.md) |
| 118. 杨辉三角 | 动态规划、数组模拟 | 二维数组 | [C++](algorithms/dynamic_programming/118_pascals_triangle.cpp) | [题解总结](algorithms/dynamic_programming/118_pascals_triangle.md) |
| 139. 单词拆分 | 动态规划、字符串分割 | 状态数组、哈希集合 | [C++](algorithms/dynamic_programming/139_word_break.cpp) | [题解总结](algorithms/dynamic_programming/139_word_break.md) |
| 152. 乘积最大子数组 | 动态规划、滚动变量 | 数组、最大最小状态 | [C++](algorithms/dynamic_programming/152_maximum_product_subarray.cpp) | [题解总结](algorithms/dynamic_programming/152_maximum_product_subarray.md) |
| 1702. 修改后的最大二进制字符串 | 贪心 | 字符串、计数变量 | [C++](algorithms/sorting_greedy/1702_maximum_binary_string_after_change.cpp) | [题解总结](algorithms/sorting_greedy/1702_maximum_binary_string_after_change.md) |
| 200. 岛屿数量 | 图遍历（递归 DFS） | 二维网格、递归栈 | [C++](algorithms/graph_traversal/200_number_of_islands.cpp) | [题解总结](algorithms/graph_traversal/200_number_of_islands.md) |
| 207. 课程表 | 拓扑排序、BFS | 邻接表、入度数组、队列 | [C++](algorithms/graph_traversal/207_course_schedule.cpp) | [题解总结](algorithms/graph_traversal/207_course_schedule.md) |
| 208. 实现 Trie（前缀树） | 前缀树、字符串查找 | Trie、孩子指针数组 | [C++](data_structures/trie/208_implement_trie_prefix_tree.cpp) | [题解总结](data_structures/trie/208_implement_trie_prefix_tree.md) |
| 295. 数据流的中位数 | 双堆、数据流 | 大顶堆、小顶堆 | [C++](data_structures/heap/295_find_median_from_data_stream.cpp) | [题解总结](data_structures/heap/295_find_median_from_data_stream.md) |
| 94. 二叉树的中序遍历 | 二叉树、递归 DFS | 二叉树、递归栈 | [C++](algorithms/tree_traversal/094_binary_tree_inorder_traversal.cpp) | [题解总结](algorithms/tree_traversal/094_binary_tree_inorder_traversal.md) |
| 98. 验证二叉搜索树 | 二叉树、递归 DFS、上下界 | 二叉搜索树、递归栈 | [C++](algorithms/tree_traversal/098_validate_binary_search_tree.cpp) | [题解总结](algorithms/tree_traversal/098_validate_binary_search_tree.md) |
| 101. 对称二叉树 | 二叉树、递归 DFS | 二叉树、递归栈 | [C++](algorithms/tree_traversal/101_symmetric_tree.cpp) | [题解总结](algorithms/tree_traversal/101_symmetric_tree.md) |
| 102. 二叉树的层序遍历 | 二叉树、BFS | 二叉树、队列 | [C++](algorithms/tree_traversal/102_binary_tree_level_order_traversal.cpp) | [题解总结](algorithms/tree_traversal/102_binary_tree_level_order_traversal.md) |
| 104. 二叉树的最大深度 | 二叉树、递归 DFS | 二叉树、递归栈 | [C++](algorithms/tree_traversal/104_maximum_depth_of_binary_tree.cpp) | [题解总结](algorithms/tree_traversal/104_maximum_depth_of_binary_tree.md) |
| 105. 从前序与中序遍历序列构造二叉树 | 二叉树、递归、分治 | 数组、哈希表 | [C++](algorithms/tree_traversal/105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp) | [题解总结](algorithms/tree_traversal/105_construct_binary_tree_from_preorder_and_inorder_traversal.md) |
| 108. 将有序数组转换为二叉搜索树 | 二叉树、分治 | 有序数组、二叉搜索树 | [C++](algorithms/tree_traversal/108_convert_sorted_array_to_binary_search_tree.cpp) | [题解总结](algorithms/tree_traversal/108_convert_sorted_array_to_binary_search_tree.md) |
| 114. 二叉树展开为链表 | 二叉树、递归 DFS、反向前序遍历 | 二叉树、递归栈 | [C++](algorithms/tree_traversal/114_flatten_binary_tree_to_linked_list.cpp) | [题解总结](algorithms/tree_traversal/114_flatten_binary_tree_to_linked_list.md) |
| 124. 二叉树中的最大路径和 | 二叉树、递归 DFS、树形动态规划 | 二叉树、递归栈 | [C++](algorithms/tree_traversal/124_binary_tree_maximum_path_sum.cpp) | [题解总结](algorithms/tree_traversal/124_binary_tree_maximum_path_sum.md) |
| 199. 二叉树的右视图 | 二叉树、BFS、层序遍历 | 二叉树、队列 | [C++](algorithms/tree_traversal/199_binary_tree_right_side_view.cpp) | [题解总结](algorithms/tree_traversal/199_binary_tree_right_side_view.md) |
| 226. 翻转二叉树 | 二叉树、递归 DFS | 二叉树节点、递归栈 | [C++](algorithms/tree_traversal/226_invert_binary_tree.cpp) | [题解总结](algorithms/tree_traversal/226_invert_binary_tree.md) |
| 230. 二叉搜索树中第 K 小的元素 | 二叉搜索树、迭代中序遍历 | 二叉树、栈 | [C++](algorithms/tree_traversal/230_kth_smallest_element_in_a_bst.cpp) | [题解总结](algorithms/tree_traversal/230_kth_smallest_element_in_a_bst.md) |
| 236. 二叉树的最近公共祖先 | 二叉树、递归 DFS | 二叉树、递归栈 | [C++](algorithms/tree_traversal/236_lowest_common_ancestor_of_a_binary_tree.cpp) | [题解总结](algorithms/tree_traversal/236_lowest_common_ancestor_of_a_binary_tree.md) |
| 437. 路径总和 III | 二叉树、DFS、前缀和 | 二叉树、哈希表 | [C++](algorithms/tree_traversal/437_path_sum_iii.cpp) | [题解总结](algorithms/tree_traversal/437_path_sum_iii.md) |
| 543. 二叉树的直径 | 二叉树、递归 DFS | 二叉树、递归栈 | [C++](algorithms/tree_traversal/543_diameter_of_binary_tree.cpp) | [题解总结](algorithms/tree_traversal/543_diameter_of_binary_tree.md) |
| 994. 腐烂的橘子 | 多源 BFS（不会，待背诵） | 二维网格、队列 | [C++](algorithms/graph_traversal/994_rotting_oranges.cpp) | [题解总结](algorithms/graph_traversal/994_rotting_oranges.md) |
| 721. 账户合并 | 建图、DFS、哈希表（易背诵） | 邻接表、访问集合 | [C++](algorithms/graph_traversal/721_accounts_merge.cpp) | [题解总结](algorithms/graph_traversal/721_accounts_merge.md) |
| 739. 每日温度 | 单调栈 | 栈、数组 | [C++](algorithms/monotonic_stack/739_daily_temperatures.cpp) | [题解总结](algorithms/monotonic_stack/739_daily_temperatures.md) |
| 84. 柱状图中最大的矩形 | 单调栈 | 保存下标的递增栈 | [C++](algorithms/monotonic_stack/084_largest_rectangle_in_histogram.cpp) | [题解总结](algorithms/monotonic_stack/084_largest_rectangle_in_histogram.md) |

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
