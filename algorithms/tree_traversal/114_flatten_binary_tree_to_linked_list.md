# 114. 二叉树展开为链表

- 算法分类：二叉树、递归 DFS、反向前序遍历。
- 数据结构：二叉树、递归栈。
- 对应代码：[114_flatten_binary_tree_to_linked_list.cpp](./114_flatten_binary_tree_to_linked_list.cpp)。
- 掌握状态：反向遍历连接模板。

## 背诵答案

```cpp
class Solution {
    TreeNode* previous = nullptr;

public:
    void flatten(TreeNode* root) {
        previous = nullptr;
        flattenTree(root);
    }

private:
    void flattenTree(TreeNode* root) {
        if (!root) return;

        flattenTree(root->right);
        flattenTree(root->left);
        root->right = previous;
        root->left = nullptr;
        previous = root;
    }
};
```

## 背诵口诀

> 先右、再左；右边接前驱，左边置空，更新前驱。

题目要求最终链表顺序是前序遍历：

```text
根 -> 左 -> 右
```

反过来处理就是：

```text
右 -> 左 -> 根
```

因此先递归右子树，再递归左子树。此时 `previous` 已经指向当前节点在最终链表中的下一个节点：

```cpp
root->right = previous;
root->left = nullptr;
previous = root;
```

## 易错点

- 递归顺序必须是先右后左，不能写成普通的先左后右。
- 每个节点的 `left` 最后都必须设为 `nullptr`。
- `previous` 表示已经展开部分的头节点。
- 入口处要把 `previous` 重置为 `nullptr`，避免同一个 `Solution` 对象多次调用时连接到旧树。
- 题目要求原地修改，不需要返回根节点。

每个节点访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/114_flatten_binary_tree_to_linked_list.cpp -o build/114
./build/114
```
