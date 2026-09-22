# 101. 对称二叉树

- 算法分类：二叉树、递归 DFS。
- 数据结构：二叉树、递归栈。
- 对应代码：[101_symmetric_tree.cpp](./101_symmetric_tree.cpp)。
- 掌握状态：镜像递归模板。

## 背诵答案

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;

        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};
```

## 背诵口诀

> 都为空，真；一个为空，假；值不同，假；
> 外侧对外侧，内侧对内侧。

判断两棵树是否互为镜像，需要同时满足：

```cpp
left->val == right->val
isMirror(left->left, right->right) // 外侧
isMirror(left->right, right->left) // 内侧
```

## 易错点

- 不是分别判断左右子树内部是否对称，而是判断左右子树是否互为镜像。
- 必须先判断空指针，再访问节点值。
- 两个节点都为空时返回 `true`；只有一个为空时返回 `false`。
- 第二组递归参数是交叉的：`left->right` 对 `right->left`。
- 空树视为对称树。

每个节点最多访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/101_symmetric_tree.cpp -o build/101
./build/101
```
