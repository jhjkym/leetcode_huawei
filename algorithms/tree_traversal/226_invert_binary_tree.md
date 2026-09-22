# 226. 翻转二叉树

- 算法分类：二叉树、递归 DFS。
- 数据结构：二叉树、递归栈。
- 对应代码：[226_invert_binary_tree.cpp](./226_invert_binary_tree.cpp)。
- 掌握状态：二叉树递归模板。

## 题解

给定一棵二叉树，将每个节点的左子树和右子树交换，返回翻转后的根节点。
可以使用递归 DFS 或队列 BFS。练习时先完成递归版本：空节点直接返回；交换左右子树后递归处理新的左右子树。

**口诀：空节点返回；交换左右；递归两边。**

## 代码

递归模板：

```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
```

`invertTree(root)` 的含义是：**把以 `root` 为根的整棵树翻转，并返回翻转后的根节点**。

以这棵树为例：

```text
    4                 4
   / \               / \
  2   7     →       7   2
 / \ / \           / \ / \
1  3 6  9          9  6 3  1
```

处理根节点 `4` 时，先交换得到左子树 `7`、右子树 `2`；再递归翻转 `7` 和 `2` 各自的孩子。子树完成后，整棵树就完成翻转。

递归的终止条件是 `root == nullptr`。叶子节点虽然左右孩子都是空指针，但仍会先交换两个空指针，然后递归两次并返回自己。

## 测试用例

固定测试覆盖：

- 完整平衡树、普通三节点树。
- 空树、单节点树。
- 只有左子树或只有右子树。
- 不平衡树、负数、零和重复结构。

测试使用层序数组表示树，`null` 表示空孩子；翻转后再次层序遍历，直接与预期数组比较。

## 测试结果

10 组固定测试全部通过。

## 复杂度

每个节点访问一次，时间复杂度 `O(n)`；递归栈空间 `O(h)`，`h` 为树高。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/226_invert_binary_tree.cpp -o build/226
./build/226
```
