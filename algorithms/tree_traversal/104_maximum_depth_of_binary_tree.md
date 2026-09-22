# 104. 二叉树的最大深度

- 算法分类：二叉树、递归 DFS。
- 数据结构：二叉树、递归栈。
- 对应代码：[104_maximum_depth_of_binary_tree.cpp](./104_maximum_depth_of_binary_tree.cpp)。
- 掌握状态：树高递归模板。

## 背诵答案

```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
```

## 背诵口诀

> 空树是 `0`；左右取最大，再加当前一层。

递归含义是：`maxDepth(root)` 返回以 `root` 为根的树的最大深度。

- 空节点没有层数，返回 `0`；
- 非空节点分别计算左右子树深度；
- 选择较深的一边，再加上当前节点这一层。

状态转移为：

```text
树的最大深度 = max(左子树深度, 右子树深度) + 1
```

## 易错点

- 空树返回 `0`，单节点树返回 `1`。
- 最后必须加 `1`，表示当前根节点所在的一层。
- 求最大深度使用 `max`，不是把左右深度相加。

每个节点访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`，其中 `h` 是树高。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/104_maximum_depth_of_binary_tree.cpp -o build/104
./build/104
```
