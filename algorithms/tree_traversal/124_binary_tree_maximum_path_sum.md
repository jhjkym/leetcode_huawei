# 124. 二叉树中的最大路径和

- 算法分类：二叉树、递归 DFS、树形动态规划。
- 数据结构：二叉树、递归栈。
- 对应代码：[124_binary_tree_maximum_path_sum.cpp](./124_binary_tree_maximum_path_sum.cpp)。
- 掌握状态：树上最大路径模板。

## 背诵答案

```cpp
class Solution {
    int ans = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        gain(root);
        return ans;
    }

private:
    int gain(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, gain(root->left));
        int right = max(0, gain(root->right));
        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }
};
```

## 背诵口诀

> 负贡献不要；
> 更新答案时左右都要，向上返回时只能选一边。

`gain(root)` 表示从当前节点开始，只向下走所能得到的最大路径和。

负数子树只会让路径和变小，所以贡献至少取 `0`：

```cpp
int left = max(0, gain(root->left));
int right = max(0, gain(root->right));
```

以当前节点为最高点的完整路径可以同时连接左右子树：

```cpp
ans = max(ans, root->val + left + right);
```

但向父节点返回的路径不能分叉，所以只能选择左右贡献较大的一边：

```cpp
return root->val + max(left, right);
```

## 易错点

- `ans` 必须初始化为 `INT_MIN`，不能初始化为 `0`，因为整棵树可能全是负数。
- 更新全局答案时可以同时使用左右两边。
- 向父节点返回时只能选择一边，否则路径会出现分叉。
- 每次入口调用都要重置 `ans`。
- 路径至少包含一个节点。

每个节点访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`。

## 与第 543 题的关系

两题模板相同：递归函数向上返回单边最优值，同时用左右两边更新全局答案。第 543 题累加的是边数，本题累加的是节点值，并且要丢弃负贡献。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/124_binary_tree_maximum_path_sum.cpp -o build/124
./build/124
```
