# Hot 100 题型与背诵指南

仓库中的 LeetCode Hot 100 已全部覆盖：**100 / 100**。

这份清单不按题号背，而是把 100 题压缩成少量可复用的母模板。复习时先记“看到什么特征，用什么模板”，再记每题的特殊处理。

## 一、先背这些母模板

| 母模板 | 识别信号 | 核心动作 | 代表题 |
| --- | --- | --- | --- |
| 哈希查找 | 查另一个数、判重、计数 | 边遍历边查表 | 1、49、128 |
| 相向双指针 | 有序数组、首尾决策 | 根据条件移动左右指针 | 11、15、42 |
| 滑动窗口 | 连续子串、最长或最短 | 右边扩张，条件不满足时收缩左边 | 3、438、76 |
| 前缀和 + 哈希 | 连续子数组的和 | 查找 `prefix - k` | 560、437 |
| 原地数组 | 要求 `O(1)` 空间 | 下标归位、交换、翻转 | 41、48、75、189 |
| 链表哑节点 | 头节点可能变化 | `dummy` 统一处理头节点 | 19、21、24、25 |
| 链表快慢指针 | 中点、倒数、环 | 快二慢一或固定间距 | 19、141、142、234 |
| 二叉树递归 | 子树问题与原问题相同 | 明确递归返回值，再组合左右结果 | 104、543、124、236 |
| BFS | 分层、最短步数、扩散 | 队列按层处理 | 102、994 |
| 回溯 | 枚举所有组合或路径 | 选择、递归、撤销选择 | 46、78、39、79 |
| 二分查找 | 有序、答案有单调性 | 明确区间和收缩规则 | 35、34、33、153 |
| 单调栈 | 下一个更大、左右边界 | 栈中保存仍未找到答案的下标 | 739、84 |
| 堆 | 动态维护前 K 个或中位数 | 小根堆保留大值，双堆维护两半 | 215、347、295 |
| 贪心 | 当前选择不会破坏未来最优 | 维护最远位置或当前区间 | 55、45、763 |
| 动态规划 | 最优解依赖较小规模答案 | 定义状态、初始化、转移、返回 | 53、62、322、1143 |

## 二、模板代码骨架

### 1. 滑动窗口

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // 加入右端点
    while (窗口不满足条件) {
        // 移除左端点
        left++;
    }
    // 更新答案
}
```

口诀：**右边负责扩，左边负责缩，每轮更新答案。**

### 2. 回溯

```cpp
void dfs(当前状态) {
    if (满足结束条件) {
        ans.push_back(path);
        return;
    }

    for (所有选择) {
        做选择;
        dfs(下一个状态);
        撤销选择;
    }
}
```

口诀：**做选择，进递归，撤销选择。**

### 3. 二分查找左边界

```cpp
int left = 0;
int right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) {
        left = mid + 1;
    } else {
        right = mid;
    }
}
```

口诀：**左闭右开；小了加一，否则收右；最后 left 是第一个不小于目标的位置。**

### 4. 网格 DFS

```cpp
void dfs(int i, int j) {
    if (越界 || 不能访问) return;
    标记已访问;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}
```

口诀：**先判边界，再做标记，然后走四方。**

### 5. 二叉树递归

```cpp
返回类型 dfs(TreeNode* root) {
    if (root == nullptr) return 空树结果;
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    更新全局答案;
    return 当前节点要交给父节点的结果;
}
```

口诀：**先问左右子树要答案，再处理当前节点；分清全局答案和向上返回值。**

### 6. 单调栈

```cpp
for (int i = 0; i < n; i++) {
    while (!st.empty() && 当前元素让栈顶得到答案) {
        int index = st.top();
        st.pop();
        更新 index 的答案;
    }
    st.push(i);
}
```

口诀：**栈中存下标；新元素负责给栈顶结算。**

### 7. 0/1 背包与完全背包

```cpp
// 0/1 背包：每个物品只能用一次
for (int num : nums)
    for (int j = target; j >= num; j--)
        更新 dp[j];

// 完全背包：每个物品可以重复使用
for (int num : nums)
    for (int j = num; j <= target; j++)
        更新 dp[j];
```

口诀：**只能一次倒着走，可以重复正着走。**

### 8. Floyd 判环

```cpp
do {
    slow = next(slow);
    fast = next(next(fast));
} while (slow != fast);

一个指针回起点;
while (两个指针不相等) {
    两者各走一步;
}
```

口诀：**快二慢一先相遇，一个回头同步走，再相遇就是入口。**

## 三、Hot 100 分类清单

### 1. 哈希与集合（4 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [1. 两数之和](algorithms/hash_table/001_two_sum.md) | 查 `target - nums[i]`，查到后再返回 |
| [49. 字母异位词分组](algorithms/hash_table/049_group_anagrams.md) | 排序后的字符串作为哈希键 |
| [128. 最长连续序列](algorithms/hash_table/128_longest_consecutive_sequence.md) | 只从没有前驱的数字开始向后数 |
| [283. 移动零](algorithms/hash_table/283_move_zeroes.md) | 慢指针指向下一个非零数应放的位置 |

### 2. 双指针（3 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [11. 盛最多水的容器](algorithms/two_pointers/011_container_with_most_water.md) | 计算面积后移动较短边 |
| [15. 三数之和](algorithms/sorting_greedy/015_three_sum.md) | 排序，固定一个数，左右夹逼并去重 |
| [42. 接雨水](algorithms/two_pointers/042_trapping_rain_water.md) | 哪边最大值更小，就结算哪边 |

### 3. 滑动窗口（3 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [3. 无重复字符的最长子串](algorithms/sliding_window/003_longest_substring_without_repeating_characters.md) | 右边加入，重复时收缩左边 |
| [438. 找到字符串中所有字母异位词](algorithms/sliding_window/438_find_all_anagrams_in_a_string.md) | 固定长度窗口比较字符频次 |
| [76. 最小覆盖子串](algorithms/sliding_window/076_minimum_window_substring.md) | 满足覆盖后不断收缩并更新最短答案 |

### 4. 前缀和（1 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [560. 和为 K 的子数组](algorithms/prefix_sum/560_subarray_sum_equals_k.md) | 当前前缀和找 `sum - k`，先查询再记录 |

### 5. 普通数组（5 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [53. 最大子数组和](algorithms/dynamic_programming/053_maximum_subarray.md) | 当前和取“自己开始”与“接上前面”的较大值 |
| [56. 合并区间](algorithms/sorting_greedy/056_merge_intervals.md) | 按左端点排序，重叠就扩展右端点 |
| [189. 轮转数组](algorithms/array_simulation/189_rotate_array.md) | 整体翻转，再翻转前后两段 |
| [238. 除了自身以外数组的乘积](algorithms/prefix_sum/238_product_of_array_except_self.md) | 答案先存前缀积，再乘滚动后缀积 |
| [41. 缺失的第一个正数](algorithms/hash_table/041_first_missing_positive.md) | 把数字 `x` 放到下标 `x - 1` |

### 6. 矩阵（4 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [73. 矩阵置零](algorithms/matrix_simulation/073_set_matrix_zeroes.md) | 第一行和第一列充当标记数组 |
| [54. 螺旋矩阵](algorithms/matrix_simulation/054_spiral_matrix.md) | 上右下左走一圈，每走一边收缩边界 |
| [48. 旋转图像](algorithms/matrix_simulation/048_rotate_image.md) | 先沿主对角线转置，再左右翻转 |
| [240. 搜索二维矩阵 II](algorithms/matrix_search/240_search_a_2d_matrix_ii.md) | 从右上角开始，大了向左，小了向下 |

### 7. 链表（14 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [160. 相交链表](algorithms/linked_list/160_intersection_of_two_linked_lists.md) | 两指针走完自己的链表后切换到另一条 |
| [206. 反转链表](algorithms/linked_list/206_reverse_linked_list.md) | 保存 next，当前指向 prev，双指针前进 |
| [234. 回文链表](algorithms/linked_list/234_palindrome_linked_list.md) | 快慢找中点，反转后半段，再逐个比较 |
| [141. 环形链表](algorithms/linked_list/141_linked_list_cycle.md) | 快二慢一，能相遇就有环 |
| [142. 环形链表 II](algorithms/linked_list/142_linked_list_cycle_ii.md) | 相遇后一个回头，同速再走找到入口 |
| [21. 合并两个有序链表](algorithms/linked_list/021_merge_two_sorted_lists.md) | 哑节点接较小节点，最后接剩余部分 |
| [2. 两数相加](algorithms/linked_list/002_add_two_numbers.md) | 竖式加法：两数加进位，取余建节点 |
| [19. 删除链表的倒数第 N 个结点](algorithms/linked_list/019_remove_nth_node_from_end_of_list.md) | 快指针先走 `n` 步，再同步走 |
| [24. 两两交换链表中的节点](algorithms/linked_list/024_swap_nodes_in_pairs.md) | 用哑节点，每轮重连三个指针 |
| [25. K 个一组翻转链表](algorithms/linked_list/025_reverse_nodes_in_k_group.md) | 先找组尾，不足 K 个不翻转 |
| [138. 随机链表的复制](algorithms/linked_list/138_copy_list_with_random_pointer.md) | 哈希表建立原节点到新节点的映射 |
| [148. 排序链表](algorithms/linked_list/148_sort_list.md) | 快慢切半，递归排序，两两归并 |
| [23. 合并 K 个升序链表](algorithms/linked_list/023_merge_k_sorted_lists.md) | 像归并排序一样两两合并 |
| [146. LRU 缓存](algorithms/hash_table/146_lru_cache.md) | 哈希表负责定位，双向链表负责最近使用顺序 |

### 8. 二叉树（15 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [94. 二叉树的中序遍历](algorithms/tree_traversal/094_binary_tree_inorder_traversal.md) | 左、根、右 |
| [104. 二叉树的最大深度](algorithms/tree_traversal/104_maximum_depth_of_binary_tree.md) | `1 + max(左深度, 右深度)` |
| [226. 翻转二叉树](algorithms/tree_traversal/226_invert_binary_tree.md) | 交换左右子树，再递归处理 |
| [101. 对称二叉树](algorithms/tree_traversal/101_symmetric_tree.md) | 外侧对外侧，内侧对内侧 |
| [543. 二叉树的直径](algorithms/tree_traversal/543_diameter_of_binary_tree.md) | 全局更新左右深度之和，向上返回较大深度 |
| [102. 二叉树的层序遍历](algorithms/tree_traversal/102_binary_tree_level_order_traversal.md) | 先记录本层队列大小，再处理整层 |
| [108. 将有序数组转换为二叉搜索树](algorithms/tree_traversal/108_convert_sorted_array_to_binary_search_tree.md) | 中点作为根，左右区间递归建树 |
| [98. 验证二叉搜索树](algorithms/tree_traversal/098_validate_binary_search_tree.md) | 每个节点必须位于递归传下来的上下界内 |
| [230. 二叉搜索树中第 K 小的元素](algorithms/tree_traversal/230_kth_smallest_element_in_a_bst.md) | BST 中序遍历是升序，第 K 个即答案 |
| [199. 二叉树的右视图](algorithms/tree_traversal/199_binary_tree_right_side_view.md) | 层序遍历记录每层最后一个节点 |
| [114. 二叉树展开为链表](algorithms/tree_traversal/114_flatten_binary_tree_to_linked_list.md) | 右、左、根反向前序，用 prev 串起来 |
| [105. 从前序与中序遍历序列构造二叉树](algorithms/tree_traversal/105_construct_binary_tree_from_preorder_and_inorder_traversal.md) | 前序定根，中序切分左右子树 |
| [437. 路径总和 III](algorithms/tree_traversal/437_path_sum_iii.md) | 树上前缀和，进入加一，退出减一 |
| [236. 二叉树的最近公共祖先](algorithms/tree_traversal/236_lowest_common_ancestor_of_a_binary_tree.md) | 左右都找到就返回当前，只找到一边就传上去 |
| [124. 二叉树中的最大路径和](algorithms/tree_traversal/124_binary_tree_maximum_path_sum.md) | 全局用左右贡献，向上只能选一边贡献 |

### 9. 图论（4 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [200. 岛屿数量](algorithms/graph_traversal/200_number_of_islands.md) | 遇到陆地答案加一，DFS 淹掉整座岛 |
| [994. 腐烂的橘子](algorithms/graph_traversal/994_rotting_oranges.md) | 所有腐烂橘子同时入队，做多源 BFS |
| [207. 课程表](algorithms/graph_traversal/207_course_schedule.md) | 入度为零入队，处理数量等于课程数则无环 |
| [208. 实现 Trie](data_structures/trie/208_implement_trie_prefix_tree.md) | 每个节点保存 26 个孩子和结尾标记 |

### 10. 回溯（8 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [46. 全排列](algorithms/backtracking/046_permutations.md) | 用 `used` 标记已经放入路径的数字 |
| [78. 子集](algorithms/backtracking/078_subsets.md) | 每到一个节点都收集当前路径 |
| [17. 电话号码的字母组合](algorithms/backtracking/017_letter_combinations_of_a_phone_number.md) | 每层处理一个数字，枚举对应字母 |
| [39. 组合总和](algorithms/backtracking/039_combination_sum.md) | 下一层仍从 `i` 开始，表示可以重复选择 |
| [22. 括号生成](algorithms/backtracking/022_generate_parentheses.md) | 左括号未满就加，右括号少于左括号才加 |
| [79. 单词搜索](algorithms/backtracking/079_word_search.md) | 标记当前格，搜索四方，返回前恢复现场 |
| [131. 分割回文串](algorithms/backtracking/131_palindrome_partitioning.md) | 枚举结束位置，是回文才继续分割 |
| [51. N 皇后](algorithms/backtracking/051_n_queens.md) | 按行放皇后，检查列和两条对角线 |

### 11. 二分查找（6 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [35. 搜索插入位置](algorithms/binary_search/035_search_insert_position.md) | 找第一个大于等于目标的位置 |
| [74. 搜索二维矩阵](algorithms/matrix_search/074_search_a_2d_matrix.md) | 把矩阵视为一维数组，行列由除法取模得到 |
| [34. 查找元素的第一个和最后一个位置](algorithms/binary_search/034_find_first_and_last_position_of_element_in_sorted_array.md) | 两次左边界：`target` 与 `target + 1` |
| [33. 搜索旋转排序数组](algorithms/binary_search/033_search_in_rotated_sorted_array.md) | 每次先判断哪一半有序，再判断目标在哪边 |
| [153. 寻找旋转排序数组中的最小值](algorithms/binary_search/153_find_minimum_in_rotated_sorted_array.md) | 中间值大于右端，最小值在右边，否则在左边含中点 |
| [4. 寻找两个正序数组的中位数](algorithms/binary_search/004_median_of_two_sorted_arrays.md) | 二分较短数组的分割线，使左半最大值不大于右半最小值 |

### 12. 栈（5 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [20. 有效的括号](algorithms/stack/020_valid_parentheses.md) | 左括号入栈，右括号必须匹配栈顶 |
| [155. 最小栈](data_structures/stack/155_min_stack.md) | 辅助栈同步保存当前位置的最小值 |
| [394. 字符串解码](algorithms/stack/394_decode_string.md) | 遇 `[` 保存数字和旧字符串，遇 `]` 拼接 |
| [739. 每日温度](algorithms/monotonic_stack/739_daily_temperatures.md) | 递减栈等待右边第一个更高温度 |
| [84. 柱状图中最大的矩形](algorithms/monotonic_stack/084_largest_rectangle_in_histogram.md) | 递增栈遇矮柱结算高度，宽度看新栈顶 |

### 13. 堆（3 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [215. 数组中的第 K 个最大元素](algorithms/quickselect/215_kth_largest_element_in_an_array.md) | 小根堆只保留最大的 K 个数字 |
| [347. 前 K 个高频元素](algorithms/hash_table/347_top_k_frequent_elements.md) | 先统计频率，再按频率放入桶或堆 |
| [295. 数据流的中位数](data_structures/heap/295_find_median_from_data_stream.md) | 大顶堆存小半，小顶堆存大半，并保持数量平衡 |

### 14. 贪心（4 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [121. 买卖股票的最佳时机](algorithms/dynamic_programming/121_best_time_to_buy_and_sell_stock.md) | 维护历史最低价，用当前价计算利润 |
| [55. 跳跃游戏](algorithms/sorting_greedy/055_jump_game.md) | 维护最远可达位置，当前位置不能到达就失败 |
| [45. 跳跃游戏 II](algorithms/sorting_greedy/045_jump_game_ii.md) | 当前层结束时增加一步，并更新下一层边界 |
| [763. 划分字母区间](algorithms/sorting_greedy/763_partition_labels.md) | 维护区间内字符的最远末位置，到达末位置就切分 |

### 15. 动态规划（15 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [70. 爬楼梯](algorithms/dynamic_programming/070_climbing_stairs.md) | 当前方法数等于前两级方法数之和 |
| [118. 杨辉三角](algorithms/dynamic_programming/118_pascals_triangle.md) | 两边是一，中间等于上一行左上加右上 |
| [198. 打家劫舍](algorithms/dynamic_programming/198_house_robber.md) | 当前取“不偷当前”与“偷当前加前前家”的较大值 |
| [279. 完全平方数](algorithms/dynamic_programming/279_perfect_squares.md) | 完全背包求组成目标的最少物品数 |
| [322. 零钱兑换](algorithms/dynamic_programming/322_coin_change.md) | 完全背包：金额正序，取最少硬币数 |
| [139. 单词拆分](algorithms/dynamic_programming/139_word_break.md) | 枚举分割点，前缀可拆且后段在字典中 |
| [300. 最长递增子序列](algorithms/dynamic_programming/300_longest_increasing_subsequence.md) | `dp[i]` 从所有更小的前驱转移 |
| [152. 乘积最大子数组](algorithms/dynamic_programming/152_maximum_product_subarray.md) | 同时维护最大积和最小积，负数会让二者交换 |
| [416. 分割等和子集](algorithms/dynamic_programming/416_partition_equal_subset_sum.md) | 总和取一半，转成 0/1 背包，容量倒序 |
| [32. 最长有效括号](algorithms/stack/032_longest_valid_parentheses.md) | 栈先放 `-1`，空了换边界，不空算长度 |
| [62. 不同路径](algorithms/dynamic_programming/062_unique_paths.md) | 当前路径数等于上方加左方 |
| [64. 最小路径和](algorithms/dynamic_programming/064_minimum_path_sum.md) | 当前等于上左最小值加当前格子 |
| [5. 最长回文子串](algorithms/center_expansion/005_longest_palindromic_substring.md) | 每个位置分别做奇数和偶数中心扩展 |
| [1143. 最长公共子序列](algorithms/dynamic_programming/1143_longest_common_subsequence.md) | 相同左上加一，不同取上左最大值 |
| [72. 编辑距离](algorithms/dynamic_programming/072_edit_distance.md) | 相同抄左上，不同取上、左、左上最小值加一 |

### 16. 技巧题（6 题）

| 题目 | 一句话记忆 |
| --- | --- |
| [136. 只出现一次的数字](algorithms/bit_manipulation/136_single_number.md) | 所有数字异或，成对抵消 |
| [169. 多数元素](algorithms/array_simulation/169_majority_element.md) | 票数归零换候选，相同加一，不同减一 |
| [75. 颜色分类](algorithms/two_pointers/075_sort_colors.md) | 0 换左边，2 换右边，遇 2 不移动当前指针 |
| [31. 下一个排列](algorithms/array_simulation/031_next_permutation.md) | 找下降点，交换刚大一点的数，翻转后缀 |
| [287. 寻找重复数](algorithms/two_pointers/287_find_the_duplicate_number.md) | 数值当下标构成链表，用 Floyd 找环入口 |
| [239. 滑动窗口最大值](algorithms/monotonic_queue/239_sliding_window_maximum.md) | 单调递减队列，队首始终是窗口最大值 |

## 四、推荐背诵顺序

不要按照 1 到 1143 的题号顺序背。建议分四轮：

1. **基础模板**：哈希、双指针、滑动窗口、普通栈、二分、链表反转、树 DFS/BFS。
2. **成组记忆**：回溯 8 题、链表 14 题、树 15 题、动态规划 15 题。
3. **数据结构专题**：单调栈、单调队列、堆、Trie、LRU、拓扑排序。
4. **难题单独突破**：4、25、41、42、76、84、124、146、239、287、295、437。

每道题只检查四件事：

1. 能否在 10 秒内说出题型。
2. 能否说出状态或指针的含义。
3. 能否默写核心循环或递归。
4. 能否说出一个最容易写错的细节。

## 五、最后速记

- 连续子串：优先想滑动窗口。
- 连续子数组和：优先想前缀和。
- 有序数组查找：优先想二分或双指针。
- 全部方案：优先想回溯。
- 最少、最多、可不可行：优先想动态规划或贪心。
- 下一个更大、左右第一个更小：优先想单调栈。
- 动态前 K 个、中位数：优先想堆。
- 树题：先写空节点，再问左右子树要什么。
- 链表头可能变化：先放哑节点。
- 每个元素只能用一次的背包：容量倒序。
