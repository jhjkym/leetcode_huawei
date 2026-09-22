# 236. 二叉树的最近公共祖先

- 算法分类：二叉树、递归 DFS。
- 数据结构：二叉树、递归栈。
- 对应代码：[236_lowest_common_ancestor_of_a_binary_tree.cpp](./236_lowest_common_ancestor_of_a_binary_tree.cpp)。
- 掌握状态：最近公共祖先模板。

## 背诵答案

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (!left) return right;
    if (!right) return left;
    return root;
}
```

## 背诵口诀

> 遇到空、`p`、`q` 就返回；
> 左空返回右，右空返回左；
> 左右都有，返回当前根。

递归返回值表示：当前子树中找到的 `p`、`q` 或它们的最近公共祖先。

- 左右都为空：当前子树没有目标；
- 只有一边非空：两个目标都在这一边，或这一边找到了一个目标，继续向上传递；
- 左右都非空：`p` 和 `q` 分别位于两侧，当前节点就是最近公共祖先。

如果当前节点本身就是 `p` 或 `q`，立即返回当前节点。这样也能正确处理一个目标是另一个目标祖先的情况。

## 易错点

- 比较的是节点地址 `root == p`，不是节点值。
- 递归必须同时搜索左右子树。
- 左右都有结果时返回当前 `root`。
- 题目保证 `p` 和 `q` 都存在于树中且互不相同。

每个节点最多访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/236_lowest_common_ancestor_of_a_binary_tree.cpp -o build/236
./build/236
```
