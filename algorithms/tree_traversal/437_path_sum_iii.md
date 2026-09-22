# 437. 路径总和 III

- 算法分类：二叉树、DFS、前缀和。
- 数据结构：二叉树、哈希表、递归栈。
- 对应代码：[437_path_sum_iii.cpp](./437_path_sum_iii.cpp)。
- 掌握状态：树上前缀和模板。

## 背诵答案

```cpp
class Solution {
    unordered_map<long long, int> prefix;

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix.clear();
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }

private:
    int dfs(TreeNode* root, long long sum, int target) {
        if (!root) return 0;

        sum += root->val;
        int count = prefix[sum - target];

        prefix[sum]++;
        count += dfs(root->left, sum, target);
        count += dfs(root->right, sum, target);
        prefix[sum]--;

        return count;
    }
};
```

## 背诵口诀

> 当前和减目标，查找以前的和；
> 递归前加一，回溯后减一。

从根节点到当前节点的前缀和为 `sum`。如果祖先位置存在前缀和：

```text
oldSum = sum - target
```

那么从该祖先的下一个节点到当前节点的路径和就是 `target`。`prefix[sum - target]` 记录这样的祖先共有多少个。

## 为什么初始化 `prefix[0] = 1`

它表示根节点之前存在一个前缀和为 `0` 的位置。这样，当从根节点开始的路径和正好等于目标值时：

```cpp
prefix[sum - target] == prefix[0]
```

这条路径就能被统计。

## 为什么回溯时减一

哈希表只能保存当前递归路径上的前缀和。离开当前节点时执行：

```cpp
prefix[sum]--;
```

否则左子树的前缀和可能被右子树错误使用，统计出并不存在的横跨路径。

## 易错点

- 路径可以从任意节点开始，但必须从父节点向子节点连续延伸。
- 查询 `prefix[sum - target]` 要放在 `prefix[sum]++` 之前。
- 递归结束后必须回溯计数。
- 前缀和使用 `long long`，避免多节点累加时溢出。
- 每次入口调用都要清空哈希表。

每个节点访问一次，哈希表操作平均为 `O(1)`，时间复杂度为 `O(n)`；哈希表和递归栈空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/437_path_sum_iii.cpp -o build/437
./build/437
```
